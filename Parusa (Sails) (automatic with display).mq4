//+------------------------------------------------------------------+
//|                                                       Parusa.mq4 |
//|                                  Copyright © 2009, Yuri Kaminski.|
//|                                                                  |
//+------------------------------------------------------------------+
#property copyright "Yuri Kaminski 2009"
#property link      "classified"

extern double TakeProfit = 150;
extern double Lots = 0.1;
extern double StopLoss = 60;
extern double TrailingStop = 40;

extern int factor_of_MaPerioud = 1;
extern int Number_Of_Ma = 2;
extern int First_Ma_Perioud = 1;
extern int sum_for_buy = 0;
extern int sum_for_sell = 0;
extern int number_of_open_trades = 1;
extern int SMA_EMA = 0;
extern int sail_choice = 0;
extern bool relative_range = true;

extern int MagicNumber = 777;

int MaPerioud = 1;
int sum = 0;
int MinSum = 0;
int MaxSum = 0;
int MaxSum_Last = 0;
int MinSum_Last = 0;
int function_return = 0;

string Script_Start_Time;

static int prevtime = 0;

//+------------------------------------------------------------------+
//| expert start function                                            |
//+------------------------------------------------------------------+
int start()
  {
   
   Script_Start_Time = TimeToStr(TimeLocal(),TIME_DATE|TIME_MINUTES);
   
   
   int cnt, ticket = -1, total, spread = 3;
   
   
   if(prevtime == Time[0]) 
       return(0);
   prevtime = Time[0];
   
   if(IsTradeAllowed()) 
     {
       RefreshRates();
       spread = MarketInfo(Symbol(), MODE_SPREAD);
     } 
   else 
     {
       prevtime = Time[1];
       return(0);
     }
     
     
   if(sail_choice == 0)  
      function_return = Simple_Step_Sail();
   if(sail_choice == 1)
      function_return = Simple_Step_Extended_Sail();
   if(sail_choice == 2)
      function_return = One_Count_per_Ma_Sail(); 
   if(sail_choice == 3)
      function_return = One_Count_per_Ma_Extended_Sail();
   
   total = OrdersTotal();
   
   
   Comment( 
   "\nscript start time ", Script_Start_Time,
   "\nsum for buy ", sum_for_buy,
   "\nsum for sell ", sum_for_sell,
   "\nsum ", sum,
   "\nfunction return ", function_return);
   //Sleep(100);
   
   
   
   
   
   if(total < number_of_open_trades) {
      // no opened orders identified
     if(OrderSymbol() == Symbol() && OrderMagicNumber() == MagicNumber) 
      if(AccountFreeMargin() < (1000 * Lots)) {
         Print("We have no money. Free Margin = ", AccountFreeMargin());
         return(0);  
      }
      
      // check for long position (BUY) possibility
      if(function_return > sum_for_buy) {
         sum = 0;
         MinSum = 0;
         MaxSum = 0;
         MaxSum_Last = 0;
         MinSum_Last = 0; 
         ticket = OrderSend(Symbol(), OP_BUY, Lots, Ask, 3, Bid - StopLoss * Point, Ask + TakeProfit * Point, "Parusa v1.2", MagicNumber, 0, Green);
         if(ticket > 0) {
            if(OrderSelect(ticket, SELECT_BY_TICKET, MODE_TRADES)) 
            Print("BUY order opened : ",OrderOpenPrice());
         }
         else {
           Print("Error opening BUY order : ",GetLastError()); 
           Sleep(30000);
           prevtime = Time[1];
           return(0); 
         }
      }
      
      // check for short position (SELL) possibility
      if(function_return < sum_for_sell) {
        sum = 0;
        MinSum = 0;
        MaxSum = 0;
        MaxSum_Last = 0;
        MinSum_Last = 0;
        ticket = OrderSend(Symbol(), OP_SELL, Lots, Bid, 3, Ask + StopLoss * Point, Bid - TakeProfit * Point, "Parusa v1.2", MagicNumber, 0, Red);
        if(ticket > 0) {
            if(OrderSelect(ticket, SELECT_BY_TICKET, MODE_TRADES)) 
            Print("SELL order opened : ",OrderOpenPrice());
        }
        else  {
           Print("Error opening BUY order : ",GetLastError()); 
           Sleep(30000);
           prevtime = Time[1];
           return(0); 
        }
      }
     return(0);
   }

for(cnt = 0; cnt < total; cnt++) {
      OrderSelect(cnt, SELECT_BY_POS, MODE_TRADES);
      if(OrderType() <= OP_SELL &&   // check for opened position 
         OrderSymbol() == Symbol())  // check for symbol
        {
         if(OrderType() == OP_BUY)   // long position is opened
            // check for trailing stop
            if(TrailingStop > 0)  
              {                 
               if(Bid - OrderOpenPrice() > Point * TrailingStop)
                 {
                  if(OrderStopLoss() < Bid - Point * TrailingStop)
                    {
                     OrderModify(OrderTicket(), OrderOpenPrice(), Bid - Point * TrailingStop, OrderTakeProfit(), 0 , Green);
                     Sleep(30000);
                     prevtime = Time[1];
                     return(0);
                    }
                 }
              }
           }
         if(OrderType() == OP_SELL)// go to short position
            // check for trailing stop
            if(TrailingStop > 0)  
              {                 
               if((OrderOpenPrice() - Ask) > ( Point * TrailingStop))
                 {
                  if((OrderStopLoss() > (Ask + Point * TrailingStop)) || (OrderStopLoss() == 0))
                    {
                     OrderModify(OrderTicket(), OrderOpenPrice(), Ask + Point * TrailingStop, OrderTakeProfit(), 0, Red);
                     Sleep(30000);
                     prevtime = Time[1];
                     return(0);
                    }
              }        
        }
     }
   return(0);
}


double Simple_Step_Sail() 
{
   double MaArray[100], MaArray_a_Moment_Ago[100];
   for(int i = 0; i < Number_Of_Ma; i++) {
      if(i == 0) {
         MaArray[i] = iMA(NULL, 0, First_Ma_Perioud, 0, MODE_SMA,PRICE_OPEN, 0);
         MaArray_a_Moment_Ago[i] = iMA(NULL, 0, First_Ma_Perioud, 0, MODE_SMA,PRICE_OPEN, 1);
      }   
      if(i == 1) {
         MaArray[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud, 0, MODE_SMA,PRICE_OPEN, 0); 
         MaArray_a_Moment_Ago[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud, 0, MODE_SMA,PRICE_OPEN, 1);
      } 
      if(i > 1) {
         MaArray[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud * i, 0, MODE_SMA,PRICE_OPEN, 0); 
         MaArray_a_Moment_Ago[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud * i, 0, MODE_SMA,PRICE_OPEN, 1);
      }
   }
   
   for(i = 0; i < Number_Of_Ma; i++) 
      for(int j = i; j < Number_Of_Ma; j++) {
         if(i == 0) {
            if( (MaArray[i] < MaArray[j + 1]) && (MaArray_a_Moment_Ago[i] > MaArray_a_Moment_Ago[j + 1]) )
               sum -= (j + 1);
            if( (MaArray[i] > MaArray[j + 1]) && (MaArray_a_Moment_Ago[i] < MaArray_a_Moment_Ago[j + 1]) )
               sum += (j + 1);
          }
          else {
            if( (MaArray[i] < MaArray[j + 1]) && (MaArray_a_Moment_Ago[i] > MaArray_a_Moment_Ago[j + 1]) )
               sum -= (j + 1 + i * 10);
            if( (MaArray[i] > MaArray[j + 1]) && (MaArray_a_Moment_Ago[i] < MaArray_a_Moment_Ago[j + 1]) )
               sum += (j + 1 + i * 10);
          }
            
      }
   if(relative_range) {
      if(sum >= MaxSum) {
         MaxSum = sum;
         MaxSum_Last = 1;
         MinSum_Last = 0;
         return(sum - MinSum);
      }
      if(sum <= MinSum) {
         MinSum = sum;
         MaxSum_Last = 0;
         MinSum_Last = 1;
         return(sum - MaxSum);
      }
      if(sum < MaxSum && sum > MinSum)
         if(MinSum_Last == 1)
           return(sum - MinSum);
         if(MaxSum_Last == 1)
           return(sum - MaxSum);
   }
   else      
      return(sum);
}

double One_Count_per_Ma_Sail() 
{
   double MaArray[100], MaArray_a_Moment_Ago[100];
   int counter = 0;
   
   for(int i = 0; i < Number_Of_Ma; i++) {
      if(i == 0) {
         MaArray[i] = iMA(NULL, 0, First_Ma_Perioud, 0, MODE_SMA,PRICE_OPEN, 0);
         MaArray_a_Moment_Ago[i] = iMA(NULL, 0, First_Ma_Perioud, 0, MODE_SMA,PRICE_OPEN, 1);
      }   
      if(i == 1) {
         MaArray[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud, 0, MODE_SMA,PRICE_OPEN, 0); 
         MaArray_a_Moment_Ago[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud, 0, MODE_SMA,PRICE_OPEN, 1);
      } 
      if(i > 1) {
         MaArray[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud * i, 0, MODE_SMA,PRICE_OPEN, 0); 
         MaArray_a_Moment_Ago[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud * i, 0, MODE_SMA,PRICE_OPEN, 1);
      }
   }
   
   for(i = 0; i < Number_Of_Ma; i++) 
      for(int j = i; j < Number_Of_Ma; j++) {
            counter++;
            if( (MaArray[i] < MaArray[j + 1]) && (MaArray_a_Moment_Ago[i] > MaArray_a_Moment_Ago[j + 1]) )
               sum -= counter;
            if( (MaArray[i] > MaArray[j + 1]) && (MaArray_a_Moment_Ago[i] < MaArray_a_Moment_Ago[j + 1]) )
               sum += counter;      
      }
   counter = 0;
   if(relative_range) {
      if(sum >= MaxSum) {
         MaxSum = sum;
         MaxSum_Last = 1;
         MinSum_Last = 0;
         return(sum - MinSum);
      }
      if(sum <= MinSum) {
         MinSum = sum;
         MaxSum_Last = 0;
         MinSum_Last = 1;
         return(sum - MaxSum);
      }
      if(sum < MaxSum && sum > MinSum)
         if(MinSum_Last == 1)
           return(sum - MinSum);
         if(MaxSum_Last == 1)
           return(sum - MaxSum);
   }
   else      
      return(sum);
}


double Simple_Step_Extended_Sail()
{
   double MaArray[100], MaArray_a_Moment_Ago[100];
   for(int i = 0; i < Number_Of_Ma * 2; i++) {
      if(i == 0) {
         MaArray[i] = iMA(NULL, 0, First_Ma_Perioud, 0, MODE_SMA,PRICE_OPEN, 0);
         MaArray_a_Moment_Ago[i] = iMA(NULL, 0, First_Ma_Perioud, 0, MODE_SMA,PRICE_OPEN, 1);
      }   
      if(i == 1) {
         MaArray[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud, 0, MODE_SMA,PRICE_OPEN, 0); 
         MaArray_a_Moment_Ago[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud, 0, MODE_SMA,PRICE_OPEN, 1);
      } 
      if(i > 1) {
         MaArray[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud * i, 0, MODE_SMA,PRICE_OPEN, 0); 
         MaArray_a_Moment_Ago[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud * i, 0, MODE_SMA,PRICE_OPEN, 1);
      }
   }
   
   for(i = 0; i < Number_Of_Ma; i++) 
      for(int j = i; j < Number_Of_Ma + i; j++) {
         if(i == 0) {
            if( (MaArray[i] < MaArray[j + 1]) && (MaArray_a_Moment_Ago[i] > MaArray_a_Moment_Ago[j + 1]) )
               sum -= (j + 1);
            if( (MaArray[i] > MaArray[j + 1]) && (MaArray_a_Moment_Ago[i] < MaArray_a_Moment_Ago[j + 1]) )
               sum += (j + 1);
          }
          else {
            if( (MaArray[i] < MaArray[j + 1]) && (MaArray_a_Moment_Ago[i] > MaArray_a_Moment_Ago[j + 1]) )
               sum -= (j + 1 + i * 10);
            if( (MaArray[i] > MaArray[j + 1]) && (MaArray_a_Moment_Ago[i] < MaArray_a_Moment_Ago[j + 1]) )
               sum += (j + 1 + i * 10);
          }
            
      }
   if(relative_range) {
      if(sum >= MaxSum) {
         MaxSum = sum;
         MaxSum_Last = 1;
         MinSum_Last = 0;
         return(sum - MinSum);
      }
      if(sum <= MinSum) {
         MinSum = sum;
         MaxSum_Last = 0;
         MinSum_Last = 1;
         return(sum - MaxSum);
      }
      if(sum < MaxSum && sum > MinSum)
         if(MinSum_Last == 1)
           return(sum - MinSum);
         if(MaxSum_Last == 1)
           return(sum - MaxSum);
   }
   else      
      return(sum);
}


double One_Count_per_Ma_Extended_Sail() 
{
   double MaArray[100], MaArray_a_Moment_Ago[100];
   int counter = 0;
   
   for(int i = 0; i < Number_Of_Ma * 2; i++) {
      if(i == 0) {
         MaArray[i] = iMA(NULL, 0, First_Ma_Perioud, 0, MODE_SMA,PRICE_OPEN, 0);
         MaArray_a_Moment_Ago[i] = iMA(NULL, 0, First_Ma_Perioud, 0, MODE_SMA,PRICE_OPEN, 1);
      }   
      if(i == 1) {
         MaArray[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud, 0, MODE_SMA,PRICE_OPEN, 0); 
         MaArray_a_Moment_Ago[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud, 0, MODE_SMA,PRICE_OPEN, 1);
      } 
      if(i > 1) {
         MaArray[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud * i, 0, MODE_SMA,PRICE_OPEN, 0); 
         MaArray_a_Moment_Ago[i] = iMA(NULL, 0, First_Ma_Perioud + factor_of_MaPerioud * i, 0, MODE_SMA,PRICE_OPEN, 1);
      }
   }
   
   for(i = 0; i < Number_Of_Ma; i++) 
      for(int j = i; j < Number_Of_Ma + i; j++) {
            counter++;
            if( (MaArray[i] < MaArray[j + 1]) && (MaArray_a_Moment_Ago[i] > MaArray_a_Moment_Ago[j + 1]) )
               sum -= counter;
            if( (MaArray[i] > MaArray[j + 1]) && (MaArray_a_Moment_Ago[i] < MaArray_a_Moment_Ago[j + 1]) )
               sum += counter;      
      }
   counter = 0;
   if(relative_range) {
      if(sum >= MaxSum) {
         MaxSum = sum;
         MaxSum_Last = 1;
         MinSum_Last = 0;
         return(sum - MinSum);
      }
      if(sum <= MinSum) {
         MinSum = sum;
         MaxSum_Last = 0;
         MinSum_Last = 1;
         return(sum - MaxSum);
      }
      if(sum < MaxSum && sum > MinSum)
         if(MinSum_Last == 1)
           return(sum - MinSum);
         if(MaxSum_Last == 1)
           return(sum - MaxSum);
   }
   else      
      return(sum);
}
         

