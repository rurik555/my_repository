#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <ctype.h>
#include <io.h>
#include <string.h>
#include <math.h>
#include <windows.h>


int initialiazing();
//int initialiazing_words_expressions_for_thesaurus();
int initialiazing_sentences();
int filtrating();
//int filtratings_words_expressions_for_thesaurus();
//void find_words();
//int save_print_words();
//void find_expressions();
//int save_print_expressions();
//void bubble_sort_words_inc();
//void bubble_sort_words_dec();
//void bubble_sort_words_dec_scores();
//void bubble_sort_words_abc();
//void bubble_sort_expressions_dec();
//void bubble_sort_expressions_inc();
//void bubble_sort_expressions_abc();
//void bubble_sort_expressions_dec_scores();
void find_sentences();
void show_saved_sentences();
int save_sentences();
void clearscreen();
//void thesaurus();
int sentences_alignment();
//int text_test();
void load_stack_words_data();
void initializing_text_test();
bool words_of_the_sentence_difficulty_score();
long words_of_the_sentence_difficulty_score_calculation();


struct EXPRESSIONS {
		char expression[101];
		int expression_repeatings;
      int expression_score;
};

struct WORDS {
		char word[41];
		long word_repeatings;
      long word_score;
};

struct SENTENCES {
      char sentence[1001];
      char input_to_find[101];
      long number_of_sentences;
};

struct WORDS_DATA {
      char word[41];
      long word_score;
};

struct CURRENT_SENTENCE {
      char word[41];
};

struct CURRENT_INPUT {
      char word[41];
};


char long text_for_words[51000000],
			 text_for_expressions[51000000],
          text_for_sentences[51000000],
          common_text[51000000],
          initial_words_data_array[5000000],
          corrected_words_data_array[5000000],
          words_scores_data_array[500000];

char choice_t,
     key, ans = 'n',
	  buffer_word[41],
     buffer_string_for_word_score[41],
     ch,
     text_location[41],
     text_location_words_expressions_for_thesaurus[41],
     *regular_text_location = "c:\\tutor\\data\\text_data",
     input[101],
     current_input[101];

long counter_for_different_repeatings = 0,
	  copy_counter_for_different_repeatings,
     total_words_counter = 0,
     copy_real_text_length = 0,
     i = 0,
     buffer_word_counter = 0,
     letters_counter = 0,
     copy_space_counter = 0,
     word_counter = 0,
     real_text_length_for_words = 0,
     total_text_counter = 0,
     space_counter = 0,
     buffer_counter = 0,
     i_counter = 0,
     counter_for_different_words = 0,
     expr_rep_counter = 0,
     file_size = 0,
     number_of_saved_sentences = 0,
     number_of_saved_inputs = 0,
     number_of_text_segments = 0,
     inputs_counter = 0,
     data_words_stack_counter = 0,
     beginning_of_the_sentence = 0,
     end_of_the_sentence = 0,
     input_string_score,
     minimum_words_score = 0,
     previous_minimum_words_score,
     maximum_words_score = 70288;

int number_of_words = 2,
	 min_number_of_repeatings = 2,
    filtrating_flag = 0,
    total_words_in_the_current_sentence = 0;

bool scan_file_for_not_ansi = false,
     cut_sentences = true,
     thesaurus_function = false,
     thesaurus_words = false,
     thesaurus_expressions = false,
     stack_words_flag = false,
     stack_expressions_flag = false,
     asterisk = true,
     thesaurus_sentences_expressions_flag = false,
     number_the_inputs = true,
     auto_increase = false,
     choice_flag = false,
     text_test_flag = false,
     text_test_flag_for_menu = false,
     words_flag = true,
     check_input_flag = true;

FILE *source;
FILE *destination_words;
FILE *destination_expressions;
FILE *destination_sentences;
FILE *source_words_data;
FILE *source_words_scores_data;

WORDS data_base_words[100000];
EXPRESSIONS data_base_expressions[50000][2];
SENTENCES data_base_sentences[20000];
WORDS_DATA words_data_stack[100000];
WORDS_DATA words_scores_data[100000];
CURRENT_SENTENCE words_of_the_current_sentence[200];
CURRENT_INPUT words_of_the_current_input[10];


void main()
{
   char answer,
        choice;

	int  counter = 1;


   textbackground(3);

//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD bufferSize = {80, 44};
   SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);
   SetConsoleTextAttribute(hConsoleOutput, 63);

//------------------------------------------------------------------------------

   CONSOLE_CURSOR_INFO cciInfo;

   cciInfo.dwSize = 5;
   cciInfo.bVisible = false;

   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

//------------------------------------------------------------------------------

   SetConsoleTitle( "Tutor" );

   while(1) {
   	if(!initialiazing()) {
   		filtrating_flag = filtrating();
         if(filtrating_flag == 2)
            break;
         if(filtrating_flag == 0) {
   			clrscr();
   			//cout << "1 - words\n";
   			//cout << "2 - expressions\n";
   			//cout << "3 - sentences\n";
            //if(thesaurus_function == true)
            //	cout << "4 - thesaurus\n";
            //else {
            //	SetConsoleTextAttribute(hConsoleOutput, 55);
            //   cout << "4 - thesaurus\n";
            //}
            //SetConsoleTextAttribute(hConsoleOutput, 63);
            //if(text_test_flag_for_menu == true)
            //	cout << "5 - text test\n";
            //else {
            //	SetConsoleTextAttribute(hConsoleOutput, 55);
            //   cout << "5 - text test\n";
            //}
            SetConsoleTextAttribute(hConsoleOutput, 63);
   			//cout << "\nBACKSPACE - return to the previous screen\n";
   			//cout << "ESCAPE - exit the program";

            choice = 51;

   			while(1) {
      			//choice = getch();
      			if(choice == 49)
         			break;
      			if(choice == 50)
         			break;
      			if(choice == 51)
         			break;
               if(choice == 52 && thesaurus_function == true)
         			break;
               if(text_test_flag_for_menu == true)
               	if(choice == 53)
         				break;
      			if(choice == 8)
         			break;
      			if(choice == 27)
         			break;
   			}
            if(choice == 49) {
					//find_words();
               if(total_words_counter > 0 ) {
   					//save_print_words();
               	if(choice_t == 13) {
                  	thesaurus_function = true;
                  	thesaurus_words = true;
                  	strcpy(text_location_words_expressions_for_thesaurus, text_location);
               		//thesaurus();
               	}
               }
     	 			break;
   			}

   			if(choice == 50) {
					//find_expressions();
               if(counter_for_different_repeatings > 0) {
   				   //save_print_expressions();
                  if(choice_t == 13) {
                     thesaurus_function = true;
                  	thesaurus_expressions = true;
                  	strcpy(text_location_words_expressions_for_thesaurus, text_location);
               		//thesaurus();
               	}
               }
      			break;
   			}

   			if(choice == 51) {
               thesaurus_function = false;
               find_sentences();
               if(number_of_saved_sentences > 0)
      				save_sentences();
      			break;
   			}

            if(choice == 52) {
            	thesaurus_function = true;
               //thesaurus();
               break;
            }

            if(choice == 53) {
               //text_test();
               break;
            }

            if(choice == 27)
         			break;
         }
         else
         	break;
      }
      else
      	break;
   }

	fclose(source);
	fclose(destination_words);
   fclose(destination_expressions);
   fclose(destination_sentences);
   fclose(source_words_data);
   fclose(source_words_scores_data);

   clrscr();
   SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);
   cout << "Tutor version 2.0, Copyright Yuri Kaminsky. 2012";
   getch();
}


int initialiazing()
{
	int j = 0,
   	 t = 0;

   char answer = ' ';


//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;;
   CONSOLE_CURSOR_INFO cciInfo;
   cciInfo.dwSize = 20;
   cciInfo.bVisible = false;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

//------------------------------------------------------------------------------

   for(i = 0; i < 20000; i++) {
   	data_base_words[i].word_repeatings = 0;
      data_base_words[i].word_score = 0;
      while(j < 40) {
      	data_base_words[i].word[j] = ' ';
         j++;
      }
      j = 0;
   }

   for(int h = 0; h < 2; h++) {
   	for(j = 0; j < 50000; j++) {
      data_base_expressions[j][h].expression_repeatings = 0;
      	for(i = 0; i < 100; i++)
         	data_base_expressions[j][h].expression[i] = ' ';
      }
   }

   i = 0;

   for(int s = 0; s < 20000; s++) {
      data_base_sentences[s].number_of_sentences = 0;
      while(t < 1000) {
         data_base_sentences[s].sentence[t] = ' ';
         t++;
      }
      while(i < 100) {
         data_base_sentences[s].input_to_find[i] = ' ';
         i++;
      }
      t = 0;
      i = 0;
   }

	for(i = 0; i < 51000000; i++) {
		text_for_words[i] = ' ';
      text_for_expressions[i] = ' ';
      text_for_sentences[i] = ' ';
   }

	for(i = 0; i < 40; i++)
		buffer_word[i] = text_location[i] = ' ';

   clrscr();
   //cout << "ENTER - continue\n";
   //cout << "BACKSPACE - enter the file's location\n";
   //cout << "ESCAPE - exit the program";

   answer = 13;

   while(1) {
      //answer = getch();
      if(answer == 13) {
         text_test_flag_for_menu = false;
         thesaurus_function = true;
         break;
      }
      if(answer == 8) {
         text_test_flag_for_menu = true;
         thesaurus_function = false;
         break;
      }
      if(answer == 27)
      	return 1;
   }

   if(answer == 8) {
      while(1) {
      	clrscr();
      	scan_file_for_not_ansi = true;
         cciInfo.bVisible = true;
   		SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
      	cout << "enter the file's location\n\n";
         SetConsoleTextAttribute(hConsoleOutput, 14);
      	cin >> text_location;
         SetConsoleTextAttribute(hConsoleOutput, 63);
      	source = fopen(text_location, "rt");
	   	if(source == NULL) {
            cciInfo.bVisible = false;
   			SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
		   	cout << "\n" << "error opening the source file!" << "\n\n";
            cout << "press BACKSPACE to enter the file's location or ESCAPE to exit";
         	answer = getch();
      	}
         else
         	return 0;
         if(answer == 8)
         	continue;
         if(answer == 27)
         	return 1;
      }
   }
   else {
	   source = fopen(regular_text_location, "rt");
	   if(source == NULL) {
      	cciInfo.bVisible = false;
   		SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
		   cout << "\n" << "error opening the source file! Program terminated!" << "\n";
         getch();
		   return(1);
	   }
   }
   return(0);
}


int initialiazing_sentences()
{
	int t = 0;

   char answer = ' ';


//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;;
   CONSOLE_CURSOR_INFO cciInfo;
   cciInfo.dwSize = 20;
   cciInfo.bVisible = false;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

//------------------------------------------------------------------------------

   i = 0;

   for(int s = 0; s < 20000; s++) {
      data_base_sentences[s].number_of_sentences = 0;
      while(t < 1000) {
         data_base_sentences[s].sentence[t] = ' ';
         t++;
      }
      while(i < 100) {
         data_base_sentences[s].input_to_find[i] = ' ';
         i++;
      }
      t = 0;
      i = 0;
   }

	for(i = 0; i < 51000000; i++) {
		text_for_words[i] = ' ';
      text_for_expressions[i] = ' ';
      text_for_sentences[i] = ' ';
   }

	for(i = 0; i < 40; i++)
		buffer_word[i] = text_location[i] = ' ';

   while(1) {
   	clrscr();
   	scan_file_for_not_ansi = true;
   	cciInfo.bVisible = true;
   	SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
   	cout << "enter the file's location\n\n";
   	SetConsoleTextAttribute(hConsoleOutput, 14);
   	cin >> text_location;
   	SetConsoleTextAttribute(hConsoleOutput, 63);
   	source = fopen(text_location, "rt");
   	if(source == NULL) {
   		cciInfo.bVisible = false;
      	SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
      	cout << "\n" << "error opening the source file!" << "\n\n";
      	cout << "press BACKSPACE to enter the file's location or ESCAPE to exit";
      	answer = getch();
   	}
   	else
   		return 0;
   	if(answer == 8)
      	continue;
      if(answer == 27)
      	return 1;
      }
}


int sentences_alignment()
{
	int t = 0;

   char answer = ' ';


//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;;
   CONSOLE_CURSOR_INFO cciInfo;
   cciInfo.dwSize = 20;
   cciInfo.bVisible = false;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

//------------------------------------------------------------------------------

   i = 0;

   for(int s = 0; s < 20000; s++) {
      data_base_sentences[s].number_of_sentences = 0;
      while(t < 1000) {
         data_base_sentences[s].sentence[t] = ' ';
         t++;
      }
      while(i < 100) {
         data_base_sentences[s].input_to_find[i] = ' ';
         i++;
      }
      t = 0;
      i = 0;
   }

	for(i = 0; i < 51000000; i++) {
		text_for_words[i] = ' ';
      text_for_expressions[i] = ' ';
      text_for_sentences[i] = ' ';
   }

	for(i = 0; i < 40; i++)
		buffer_word[i] = text_location[i] = ' ';

   return(0);
}


/*
int initialiazing_words_expressions_for_thesaurus()
{
	int j = 0;

	char answer = ' ';


//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;;
   CONSOLE_CURSOR_INFO cciInfo;
   cciInfo.dwSize = 20;
   cciInfo.bVisible = false;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

//------------------------------------------------------------------------------

	for(i = 0; i < 20000; i++) {
		data_base_words[i].word_repeatings = 0;
      data_base_words[i].word_score = 0;
		while(j < 40) {
			data_base_words[i].word[j] = ' ';
			j++;
		}
		j = 0;
	}

   for(int h = 0; h < 2; h++) {
   	for(j = 0; j < 50000; j++) {
         data_base_expressions[j][h].expression_repeatings = 0;
   		for(i = 0; i < 100; i++)
      		data_base_expressions[j][h].expression[i] = ' ';
      }
   }

	for(i = 0; i < 51000000; i++) {
		text_for_words[i] = ' ';
      text_for_expressions[i] = ' ';
   }

	for(i = 0; i < 40; i++)
		buffer_word[i] = text_location_words_expressions_for_thesaurus[i] = ' ';

   clrscr();

   while(1) {
   	clrscr();
      scan_file_for_not_ansi = true;
      cciInfo.bVisible = true;
      SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
      cout << "enter the file's location\n\n";
      SetConsoleTextAttribute(hConsoleOutput, 14);
      cin >> text_location_words_expressions_for_thesaurus;
      SetConsoleTextAttribute(hConsoleOutput, 63);
      source = fopen( text_location_words_expressions_for_thesaurus, "rt" );
      if(source == NULL) {
      	cciInfo.bVisible = false;
         SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
         cout << "\n" << "error opening the source file!" << "\n\n";
         cout << "press BACKSPACE to enter the file's location or ESCAPE to exit";
         answer = getch();
      }
      else
      	return 0;
      if(answer == 8)
      	continue;
      if(answer == 27)
      	return 1;
   }
}
*/


int filtrating()
{
   char choice;

   bool go_on = false,
        replace_with_spaces = false;

   long j,
   	  i;


//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;;
   CONSOLE_CURSOR_INFO cciInfo;
   cciInfo.dwSize = 20;
   cciInfo.bVisible = false;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

//------------------------------------------------------------------------------

   clrscr();
   cout << "loading...";
   i = 0;
   ch = ' ';
	while (ch != EOF) {
   	ch = fgetc(source);
      if(scan_file_for_not_ansi == true && go_on == false) {
      	if(ch > 127 || (ch < 0 && ch != EOF)) {
         	cout <<"\n\n";
            SetConsoleTextAttribute(hConsoleOutput, 206);
            cout << "---------------------------------------------------\n";
            cout << "| WARNING!                                        |\n";
            cout << "| the file contains symbols that are not in ANSI, |\n";
            cout << "| this may worsen the program performance!        |\n";
            cout << "---------------------------------------------------\n\n";
            SetConsoleTextAttribute(hConsoleOutput, 63);
            cout << "ENTER - continue anyway\n";
            cout << "SPACE - replace the wrong symbols with spaces\n";
            //cout << "BACKSPACE - return to the previous menu\n"; //dodelat
            cout << "ESCAPE - exit the program\n";
            while(1) {
            	choice = getch();
               if(choice == 13) {
               	go_on = true;
                  break;
               }
               if(choice == 32) {
               	go_on = true;
                  replace_with_spaces = true;
                  break;
               }
               if(choice == 27)
               	return 2;
            }
         }
      }
      if(replace_with_spaces == true)
      	if(ch > 127 || (ch < 0 && ch != EOF))
         	ch = ' ';
      if(ch >= 0 && ch <= 32)
      	ch = ' ';
      common_text[i] = ch;
      i++;
	}

   file_size = filelength(fileno(source));
   real_text_length_for_words = file_size;

   j = 0;
   i = 0;

   while(i < real_text_length_for_words) {
      while(common_text[i] == ' ' && common_text[i + 1] == ' ') {
         i++;
      }
      text_for_sentences[j] = common_text[i];
      i++;
      j++;
   }

   i = 0;
   while(i < real_text_length_for_words) {
      text_for_words[i] = text_for_sentences[i];
      i++;
   }

   i = 0;
   while(i < real_text_length_for_words) {
      if(text_for_words[i] >= 65 && text_for_words[i] <= 90)
         text_for_words[i] = tolower(text_for_words[i]);
      if(!(text_for_words[i] > 96 && text_for_words[i] < 123) && text_for_words[i] != 39)
         text_for_words[i] = ' ';
      if(i >= 2 ) {
         if(text_for_words[i - 2] == ' ' && text_for_words[i - 1] == 39 && text_for_words[i] == ' ')
            text_for_words[i - 1] = ' ';
         if(text_for_words[i - 2] != ' ' &&  text_for_words[i - 1] == 39 && text_for_words[i] == ' ')
            text_for_words[i - 1] = ' ';
         if(text_for_words[i - 2] == ' ' &&  text_for_words[i - 1] == 39 && text_for_words[i] != ' ')
            text_for_words[i - 1] = ' ';
         if((text_for_words[i - 2] >= 65 && text_for_words[i - 2] <= 90) && text_for_words[i - 1] == 39
         && (text_for_words[i] < 65 || text_for_words[i] > 90))
            text_for_words[i - 1] = ' ';
         if((text_for_words[i - 2] < 65 || text_for_words[i - 2] > 90) && text_for_words[i - 1] == 39
         && (text_for_words[i] >= 65 && text_for_words[i] <= 90))
            text_for_words[i - 1] = ' ';
      }
      //RAZOBRATSA
      i++;
   }

   i = 0;
   while(i < real_text_length_for_words) {
   	text_for_expressions[i] = text_for_words[i];
      i++;
   }

   copy_real_text_length = real_text_length_for_words;
   clrscr();
   return 0;
}

/*
int filtratings_words_expressions_for_thesaurus()
{
   char choice;

   bool go_on = false,
        replace_with_spaces = false;

   long i;


//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;;
   CONSOLE_CURSOR_INFO cciInfo;
   cciInfo.dwSize = 20;
   cciInfo.bVisible = false;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

//------------------------------------------------------------------------------

   clrscr();
   cout << "loading...";
   i = 0;
   ch = ' ';
	while (ch != EOF) {
   	ch = fgetc(source);
      if(scan_file_for_not_ansi == true && go_on == false)
      	if(ch > 127 || (ch < 0 && ch != EOF)) {
         	cout <<"\n\n";
            SetConsoleTextAttribute(hConsoleOutput, 206);
            cout << "---------------------------------------------------\n";
            cout << "| WARNING!                                        |\n";
            cout << "| the file contains symbols that are not in ANSI, |\n";
            cout << "| this may worsen the program performance!        |\n";
            cout << "---------------------------------------------------\n\n";
            SetConsoleTextAttribute(hConsoleOutput, 63);
            cout << "ENTER - continue anyway\n";
            cout << "SPACE - replace the wrong symbols with spaces\n";
            cout << "BACKSPACE - return to the previous menu\n";
            cout << "ESCAPE - exit the program\n";
            while(1) {
            	choice = getch();
               if(choice == 13) {
               	go_on = true;
                  break;
               }
               if(choice == 32) {
               	go_on = true;
                  replace_with_spaces = true;
                  break;
               }
               if(choice == 8)
               	return 1;
               if(choice == 27)
               	return 2;
            }
         }
      if(replace_with_spaces == true)
      	if(ch > 127 || (ch < 0 && ch != EOF))
         	ch = ' ';
      if(ch >= 0 && ch <= 32)
      	ch = ' ';
      text_for_words[i] = ch;
      i++;
	}

   file_size = filelength(fileno(source));
   real_text_length_for_words = file_size;

   i = 0;
   while(i < real_text_length_for_words) {
      if(text_for_words[i] >= 65 && text_for_words[i] <= 90)
         text_for_words[i] = tolower(text_for_words[i]);
      if(!(text_for_words[i] > 96 && text_for_words[i] < 123) && text_for_words[i] != 39)
         text_for_words[i] = ' ';
      if(i >= 2 ) {
         if(text_for_words[i - 2] == ' ' && text_for_words[i - 1] == 39 && text_for_words[i] == ' ')
            text_for_words[i - 1] = ' ';
         if(text_for_words[i - 2] != ' ' &&  text_for_words[i - 1] == 39 && text_for_words[i] == ' ')
            text_for_words[i - 1] = ' ';
         if(text_for_words[i - 2] == ' ' &&  text_for_words[i - 1] == 39 && text_for_words[i] != ' ')
            text_for_words[i - 1] = ' ';
         if((text_for_words[i - 2] >= 65 && text_for_words[i - 2] <= 90) && text_for_words[i - 1] == 39
         && (text_for_words[i] < 65 || text_for_words[i] > 90))
            text_for_words[i - 1] = ' ';
         if((text_for_words[i - 2] < 65 || text_for_words[i - 2] > 90) && text_for_words[i - 1] == 39
         && (text_for_words[i] >= 65 && text_for_words[i] <= 90))
            text_for_words[i - 1] = ' ';
      }
      //RAZOBRATSA
      i++;
   }

   i = 0;
   while(i < real_text_length_for_words) {
   	text_for_expressions[i] = text_for_words[i];
      i++;
   }

   copy_real_text_length = real_text_length_for_words;
   clrscr();
   return 0;
}
*/

/*
void find_words()
{
	long stc_letters_counter = 0,
   	  smart_letters_counter = 0,
   	  space_back_counter,
   	  difference_between_text_length;

	double index; //podgon vmesto long

   int word_score = 0,
       x,
       flag = 0;

   long length_of_text_segment = 0, //megapodgon, esli obyedinet s pervym long ne pokazyvayet %
        beginning_of_new_text_segment = 0,
        end_of_new_text_segment = 0,
        i = 0;

   bool new_segment_flag = true,
        new_word_flag = true,
        word_score_flag = true;


//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;;
   CONSOLE_CURSOR_INFO cciInfo;
   cciInfo.dwSize = 20;
   cciInfo.bVisible = true;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

//------------------------------------------------------------------------------

   clrscr();
   if(text_test_flag == false) {
   	cout << "enter the number of segments the text will be divided to ";
   	while(1) {
   		cin >> number_of_text_segments;
      	if(flag) {
      		cin.clear();
      		cin.ignore(255, '\n');
      	}
      	if(number_of_text_segments > 100 || number_of_text_segments < 2) {
         	clrscr();
         	cout << "the number must be between 2 and 100\n";
         	cout << "\n" << "enter the number of segments the text will be divided to ";
         	flag = 1;
      	}
      	else
      		break;
   	}
   }

   if(text_for_words[space_counter] != ' ' && space_counter == 0) {//podgon dlya pervogo simvola
   	space_counter--;
      text_for_words[space_counter] = ' ';
      beginning_of_new_text_segment = -1;
   }
   else
   	beginning_of_new_text_segment = 0;

   clrscr();
   cciInfo.bVisible = false;
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
   if(text_test_flag == false) {
   	length_of_text_segment = real_text_length_for_words / number_of_text_segments;
   	end_of_new_text_segment = length_of_text_segment;
   }

	while(real_text_length_for_words) {
   		while(text_for_words[space_counter] == ' ')
				space_counter++;
				while(text_for_words[space_counter] != ' ') {
					data_base_words[counter_for_different_repeatings].word[stc_letters_counter] = buffer_word[buffer_word_counter] = text_for_words[space_counter];
					space_counter++;
					buffer_word_counter++;
					stc_letters_counter++;
				}
            space_back_counter = space_counter;
				space_counter -= buffer_word_counter;
				buffer_word_counter = 0;
				while(space_counter < copy_real_text_length) {
					while(buffer_word[buffer_word_counter] == text_for_words[space_counter] && text_for_words[space_counter] != ' '
               && space_counter < copy_real_text_length) {
						space_counter++;
						buffer_word_counter++;
					}
					if(buffer_word[buffer_word_counter]== ' ' && text_for_words[space_counter] == ' ') {
						copy_space_counter = space_counter;
						space_counter--;
						while(text_for_words[space_counter] != ' ') {
						 		space_counter--;
						 		letters_counter++;
						}
						if(letters_counter == buffer_word_counter) {
							data_base_words[counter_for_different_repeatings].word_repeatings++;

                     if(text_test_flag == false) {
                     	if(space_counter > end_of_new_text_segment) {
                        	x = space_counter / length_of_text_segment;
                     		beginning_of_new_text_segment = length_of_text_segment * x;
                        	end_of_new_text_segment = beginning_of_new_text_segment + length_of_text_segment;
                        	new_segment_flag = true;
                     	}
                     	if(space_counter < beginning_of_new_text_segment) {
                        	x = space_counter / length_of_text_segment;
                     		beginning_of_new_text_segment = length_of_text_segment * x;
                        	end_of_new_text_segment = beginning_of_new_text_segment + length_of_text_segment;
                        	new_segment_flag = true;
                     	}

                     	if(space_counter >= beginning_of_new_text_segment && space_counter <= end_of_new_text_segment) {
                     		if(new_segment_flag == true) {
                        		data_base_words[counter_for_different_repeatings].word_score++;
                           	new_segment_flag = false;
                        	}
                     	}
                     }

							space_counter = copy_space_counter;
							total_words_counter++;
							while(buffer_word_counter) {
								text_for_words[space_counter - 1] = ' ';
								space_counter--;
								buffer_word_counter--;
							}
						}
						space_counter = copy_space_counter;
					}
					space_counter++;
					buffer_word_counter = 0;
               if(letters_counter != 0)
						smart_letters_counter = letters_counter;
               letters_counter = 0;
				}

  	 if(data_base_words[counter_for_different_repeatings].word_repeatings) {
       if(counter_for_different_repeatings != 0) {
          real_text_length_for_words -= (smart_letters_counter + 1) * data_base_words[counter_for_different_repeatings].word_repeatings;
          i += (smart_letters_counter + 1) * data_base_words[counter_for_different_repeatings].word_repeatings;
       }
       if(counter_for_different_repeatings == 0)
    	    real_text_length_for_words -= (smart_letters_counter) * data_base_words[counter_for_different_repeatings].word_repeatings;

      difference_between_text_length = copy_real_text_length - real_text_length_for_words;

      if(index <= 100.000)
    		index = (difference_between_text_length * 100.0) / copy_real_text_length;
      	gotoxy(1 , 1);
      	cout << "analyzing the text... " << index << "%    ";
    	}
    	else {
      	real_text_length_for_words = 0;
      	gotoxy(1 , 1);
      	cout << "analyzing the text is completed                                 ";
    	}
    	while(buffer_word_counter < 40) {
			buffer_word[buffer_word_counter] = ' ';
			buffer_word_counter++;
    }

		if(counter_for_different_repeatings < 20000) {
			counter_for_different_repeatings++;
         new_segment_flag = true;
		}
		stc_letters_counter = 0;
		space_counter = space_back_counter;
		buffer_word_counter = 0;
		word_counter++;
	}

   if(total_words_counter == 0 ) {
       gotoxy(1 , 1);
       cout << "there are no words in the file, press any key to exit";
       words_flag = false;
       getch();
   }

}
*/

/*
int save_print_words()
{
	char choice,
        choice_49 = false,
        abc_choice,
        number_for_dest[10],
        counter_for_dest[10],
        score_for_dest[10];

	int  counter = 1,
   	  j = 0,
   	  flag = 0;


//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD bufferSize = {80, 21000};

//------------------------------------------------------------------------------

   i = 0;
   while(i < 20000) {
   	if(data_base_words[i].word_repeatings != NULL)
      	counter_for_different_words++;
         i++;
   }

   cout << "\n\nwords in the text = " << total_words_counter << "\n";
   cout << "different words = " << counter_for_different_words << "\n";

   if(text_test_flag == false) {
   	cout << "segments = " << number_of_text_segments << "\n" << "\n";
   	cout << "choose the order the words wiil be sorted by:\n";
   	cout << "1 - order of appearence in the text\n";
   	cout << "2 - increasing order (repeatings)\n";
   	cout << "3 - decreasing order (repeatings)\n";
   	cout << "4 - decreasing order (segments)\n";
   	cout << "5 - ABC order\n";

   	while(1) {
   		choice = getch();
      	if(choice == 49) {
         	choice_49 = true;
      		cout << "\n";
         	break;
      	}
      	if(choice == 50) {
      		stack_words_flag = true; //podgon
      		break;
      	}
      	if(choice == 51)
      		break;
      	if(choice == 52)
      		break;
      	if(choice == 53)
      		break;
   	}
   }
   else
      choice = 49;

   destination_words = fopen("c:\\tutor\\output\\words.txt", "wt");
   if(destination_words == NULL) {
   	cout << "error opening the destiation file! Program terminated!\n";
      getch();
      return( 0 );
   }

  if(choice == 50)
		bubble_sort_words_inc();
  if(choice == 51)
		bubble_sort_words_dec();
  if(choice == 52) {
      bubble_sort_words_dec();
      bubble_sort_words_dec_scores();
  }
  if(choice == 53)
  		bubble_sort_words_abc();

  if(text_test_flag == false) {
     fputs("words in the text = ", destination_words);
     itoa(total_words_counter, number_for_dest, 10);
     fputs(number_for_dest, destination_words);
     fputs("\ndifferent words = ", destination_words);
     itoa(counter_for_different_words, number_for_dest, 10);
     fputs(number_for_dest, destination_words);
     fputs("\nsegments = ", destination_words);
     itoa(number_of_text_segments, number_for_dest, 10);
     fputs(number_for_dest, destination_words);
     fputc('\n', destination_words);
     fputs("------------------------------------------------------------------------------------", destination_words);
     fputc('\n', destination_words);
     fputc('\n', destination_words);
     fputc('\n', destination_words);

     i = 0;

     cout << "press ENTER to print the words on the screen or SPACE to skip\n\n";

  	  while(1) {
     	  choice = getch();
     	  if(choice == 32)
        	  break;
     	  if(choice == 13) {
        	  SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);
           break;
     	  }
  	  }
  }


  if(text_test_flag == true)
     choice = 32;

  if(text_test_flag == false)
     if(choice == 32)
        cout << "saving...";

  while(i < 20000) {
	  if(data_base_words[i].word_repeatings != NULL) {
        if(choice == 13) {
           cout << counter << " " << "(" << data_base_words[i].word_score << ")" << " ";
           cout << "(" << data_base_words[i].word_repeatings << ")" << " ";
           while(j < 40) {
      	     cout << data_base_words[i].word[j];
              j++;
           }
        	  j = 0;
           cout << "\n";
        }
		  counter++;
		  itoa(data_base_words[i].word_repeatings, number_for_dest, 10);
		  itoa(counter - 1, counter_for_dest, 10);
        itoa(data_base_words[i].word_score, score_for_dest, 10);
		  fputs(counter_for_dest, destination_words);
		  fputc(' ', destination_words);
        fputc('(', destination_words);
        fputs(score_for_dest, destination_words);
		  fputc(')', destination_words);
        fputc(' ', destination_words);
        fputc('(', destination_words);
        fputs(number_for_dest, destination_words);
		  fputc(')', destination_words);
        fputc(' ', destination_words);
		  fputs(data_base_words[i].word, destination_words);
		  fputc('\n', destination_words);
	  }
     i++;
  }

  counter_for_different_repeatings = counter_for_different_words;

  if(text_test_flag == false) {
     if(choice == 32){
        gotoxy(1, 16);
        cout <<"\n\n";
     }
     if(choice == 13)
        cout <<"\n\n";
     if(choice_49 == true && choice != 13) {
        gotoxy(1, 16);
        cout << "saving is completed\n\n";
     }
     else
        cout << "saving is completed\n\n";

     if(counter_for_different_repeatings > 0) {
        if(thesaurus_function == false) {
           cout << "press ENTER to run thesaurus or ESCAPE to exit the program";
           while(1) {
              choice_t = getch();
              if(choice_t == 27 || choice_t == 13)
                 break;
           }
        }
        else {
           cout << "press any key to return to the main menu";
            getch();
        }
        clrscr();
     }
  }
  return 0;
}
*/

/*
void find_expressions()
{
   int expression_counter = 0,
   	 space_counter_expression = 0,
       flag = 0,
       x;

   long j,
   	  l,
        k = 0,
        expression_index = 0,
        text_letters_counter,
        temp_expression_index = 0,
        length_of_text_segment = 0,
        beginning_of_new_text_segment = 0,
        end_of_new_text_segment = 0;

   double real_text_length_for_expressions,
          length_of_finished_part_of_text = 0,
          index;

   bool new_segment_flag = true,
        new_word_flag = true,
        word_score_flag = true;


//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;;
   CONSOLE_CURSOR_INFO cciInfo;
   cciInfo.dwSize = 20;
   cciInfo.bVisible = true;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

//------------------------------------------------------------------------------

   real_text_length_for_expressions = copy_real_text_length;

   clrscr();
   cout << "enter the number of segments the text will be divided to ";
   while(1) {
   	cin >> number_of_text_segments;
      if(flag) {
      	cin.clear();
      	cin.ignore(255, '\n');
      }
      if(number_of_text_segments > 100 || number_of_text_segments < 2) {
         clrscr();
         cout << "the number must be between 2 and 100\n";
         cout << "\n" << "enter the number of segments the text will be divided to ";
         flag = 1;
      }
      else
      	break;
   }

   cciInfo.bVisible = false;
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

   clrscr();
   cout << "the text was divided to " << number_of_text_segments << " segments";
   length_of_text_segment = real_text_length_for_expressions / number_of_text_segments;
   beginning_of_new_text_segment = 0;
   end_of_new_text_segment = length_of_text_segment;

   while(1) {
   	clrscr();
   	cciInfo.bVisible = true;
   	SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
      cout << "enter the number of words for expression ";
      cin >> number_of_words;
      if(number_of_words <= 0 || number_of_words > 20) {
         clrscr();
         cciInfo.bVisible = false;
   		SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
         cout << "number must be between 1 and 20\n";
         continue;
      }
      else
         break;
   }

   while(1) {
   	clrscr();
   	cciInfo.bVisible = true;
   	SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
      cout << "enter the minimum number of repeatings ";
      cin >> min_number_of_repeatings;
      if(min_number_of_repeatings <= 0) {
         clrscr();
         cciInfo.bVisible = false;
   		SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
         cout << "number must be 1 at least              \n";
         continue;
      }
      else
         break;
   }

   clrscr();
   cciInfo.bVisible = false;
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

   while(length_of_finished_part_of_text < real_text_length_for_expressions) {
   	i = 0;
   	while(text_for_expressions[i] == ' ')
      	i++;
   	j = 0;
   	space_counter_expression = 0;
   	while(space_counter_expression != number_of_words && i < real_text_length_for_expressions) {
      	data_base_expressions[expression_index][0].expression[j] = text_for_expressions[i];
      	i++;
      	j++;
      	if(text_for_expressions[i] == ' ')
      		space_counter_expression++;
   	}
   	while(data_base_expressions[expression_index][0].expression[j] != ' ') {
   		data_base_expressions[expression_index][0].expression[j] = ' ';
      	j--;
		}

   	i = 0;
   	while(text_for_expressions[i] == ' ')
   		i++;

   	for(text_letters_counter = i; text_letters_counter < real_text_length_for_expressions; text_letters_counter++) {
      	expression_counter = 0;
      	while(expression_counter < j) {
   			if(data_base_expressions[expression_index][0].expression[expression_counter]
            == text_for_expressions[text_letters_counter + expression_counter]) {
            	expression_counter++;
            	if(expression_counter == j && text_for_expressions[text_letters_counter + expression_counter ] == ' '){
            		data_base_expressions[expression_index][0].expression_repeatings++;
                  if(text_letters_counter >= beginning_of_new_text_segment && text_letters_counter <= end_of_new_text_segment) {
            			if(new_segment_flag == true) {
               			data_base_expressions[expression_index][0].expression_score++;
                  		new_segment_flag = false;
               		}
            		}
               }
            }

         	else {
            	while(text_for_expressions[text_letters_counter] != ' ')
        	   		text_letters_counter++;
         		break;
         	}

            if(text_letters_counter > end_of_new_text_segment) {
                        x = text_letters_counter / length_of_text_segment;
                     	beginning_of_new_text_segment = length_of_text_segment * x;
                        end_of_new_text_segment = beginning_of_new_text_segment + length_of_text_segment;
                        new_segment_flag = true;
            }

            if(text_letters_counter < beginning_of_new_text_segment) {
            	x = text_letters_counter / length_of_text_segment;
               beginning_of_new_text_segment = length_of_text_segment * x;
               end_of_new_text_segment = beginning_of_new_text_segment + length_of_text_segment;
               new_segment_flag = true;
            }
      	}
   	}

      expression_index++;
      new_segment_flag = true;
      l = 0;
      while(text_for_expressions[l] == ' ') {
      	l++;
         length_of_finished_part_of_text = l;
      }
      space_counter_expression = 0;
      while(space_counter_expression != 1) {
         text_for_expressions[l] = ' ';
      	l++;
      	if(text_for_expressions[l] == ' ')
         	space_counter_expression++;
      }

      if((real_text_length_for_expressions - length_of_finished_part_of_text) > 0) {
      	index = (length_of_finished_part_of_text * 100) / real_text_length_for_expressions;
      	cout << "analyzing the text... " << index << "%    ";
      	gotoxy(1 , 1);
      }
      else {
         gotoxy(1 , 1);
      	cout << "analyzing the text is completed          " << "\n" << "\n";
    	}
   }

   cout << "processing the data...";

   j = 0;
   space_counter_expression = 0;
   for(i = 0; i < 50000; i++) {
      while(j < 99) {
   		if(data_base_expressions[i][0].expression[j] == ' ' &&  data_base_expressions[i][0].expression[j + 1] != ' ') {
         	space_counter_expression++;
         }
        if(space_counter_expression == (number_of_words - 1)) {
         	break;
         }
         else {
         	j++;
         }
      }
      if(space_counter_expression != number_of_words - 1)
         	data_base_expressions[i][0].expression_repeatings = 0;
      space_counter_expression = 0;
      j = 0;
   }

   for(i = 0; i < 50000; i++) {
   	j = 0;
   		if(data_base_expressions[i][0].expression_repeatings >= min_number_of_repeatings) {
            while(j < 100) {
            	data_base_expressions[k][1].expression[j] =  data_base_expressions[i][0].expression[j];
               j++;
            }
            expr_rep_counter++;
            data_base_expressions[k][1].expression_repeatings = data_base_expressions[i][0].expression_repeatings;
            data_base_expressions[k][1].expression_score = data_base_expressions[i][0].expression_score;
            k++;
         }
   }

   for(i = 0; i <= k; i++)
   	for(j = i + 1; j < k; j++)
   		if(strcmp(data_base_expressions[i][1].expression, data_base_expressions[j][1].expression) == 0) {
            data_base_expressions[j][1].expression_repeatings = 0;
         }


   i = 0;
   while(i < 50000) {
   	if(data_base_expressions[i][1].expression_repeatings >= min_number_of_repeatings)
   		counter_for_different_repeatings++;
   		i++;
   }
   if(counter_for_different_repeatings > 0) {
   	gotoxy(1, 3);
   	cout << "processing the data is completed" << "\n\n";
   }
   else  {
   	gotoxy(1 , 1);
      cout << "there are no expressions in the file that match the request\n\n";
      cout << "press any key to exit ";
      getch();
   }
}
*/

/*
int save_print_expressions()
{
	char choice,
   	  choice_49 = false,
        abc_choise,
        number_for_dest[10],
        counter_for_dest[10],
        score_for_dest[10];

	int  counter = 1,
        j = 0,
        flag = 0,
        i = 0;


//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD bufferSize = {80, 21000};

//------------------------------------------------------------------------------

   choice_flag = false;

   counter_for_different_repeatings = 0;
   while(i < 50000) {
   	if(data_base_expressions[i][1].expression_repeatings >= min_number_of_repeatings)
   		counter_for_different_repeatings++;
   		i++;
   }

   cout << "expressions in the text that match the request = " << counter_for_different_repeatings << "\n";
   cout << "segments = " << number_of_text_segments << "\n";
   cout << "number of words for expression = " << number_of_words << "\n";
   cout << "minimum number of repeatings = " << min_number_of_repeatings << "\n" << "\n";
   cout << "choose the order the expressions wiil be sorted by:\n";
   if(thesaurus_expressions == false) { //podgon
   	cout << "1 - order of appearence in the text\n";
   	cout << "2 - increasing order (repeatings)\n";
   	cout << "3 - decreasing order (repeatings)\n";
   	cout << "4 - decreasing order (segments)\n";
   	cout << "5 - ABC order\n";
   }
   if(thesaurus_expressions == true) { //podgon
      SetConsoleTextAttribute(hConsoleOutput, 55);
   	cout << "1 - order of appearence in the text\n";
   	cout << "2 - increasing order (repeatings)\n";
      SetConsoleTextAttribute(hConsoleOutput, 63);
   	cout << "3 - decreasing order (repeatings)\n";
      SetConsoleTextAttribute(hConsoleOutput, 55);
   	cout << "4 - decreasing order (segments)\n";
      SetConsoleTextAttribute(hConsoleOutput, 63);
   	cout << "5 - ABC order\n";
   }

   if(thesaurus_expressions == false) //podgon
   	while(1) {
   		choice = getch();
      	if(choice == 49) {
         	choice_49 = true;
      		cout << "\n";
         	break;
      	}
      	if(choice == 50) {
      		stack_expressions_flag = true; //podgon
      		break;
      	}
      	if(choice == 51) {
         	choice_flag = true;
      		break;
         }
      	if(choice == 52)
      		break;
      	if(choice == 53) {
            choice_flag = true;
      		break;
         }
   	}

   if(thesaurus_expressions == true) //podgon
   	while(1) {
   		choice = getch();
      	if(choice == 51)
      		break;
      	if(choice == 53)
      		break;
   	}

     destination_expressions = fopen("c:\\tutor\\output\\expressions.txt","wt");
     if(destination_expressions == NULL) {
        cout << "error opening the destiation file! Program terminated!\n";
        getch();
        return(0);
     }

  if(choice == 50)
		bubble_sort_expressions_inc();
  if(choice == 51) {
		bubble_sort_expressions_dec();
      thesaurus_sentences_expressions_flag = true;
  }
  if(choice == 52) {
      bubble_sort_expressions_dec();
      bubble_sort_expressions_dec_scores();
  }
  if(choice == 53) {
  		bubble_sort_expressions_abc();
      thesaurus_sentences_expressions_flag = true;
  }

  fputs("expressions in the text that match the request = ", destination_expressions);
  itoa(counter_for_different_repeatings, number_for_dest, 10);
  fputs(number_for_dest, destination_expressions);
  fputs("\nsegments = ", destination_expressions);
  itoa(number_of_text_segments, number_for_dest, 10);
  fputs(number_for_dest, destination_expressions);
  fputs("\nnumber of words for expression = ", destination_expressions);
  itoa(number_of_words, number_for_dest, 10);
  fputs(number_for_dest, destination_expressions);
  fputs("\nminimum number of repeatings = ", destination_expressions);
  itoa(min_number_of_repeatings, number_for_dest, 10);
  fputs(number_for_dest, destination_expressions);
  fputc('\n', destination_expressions);
  fputs("------------------------------------------------------------------------------------", destination_expressions);
  fputc('\n', destination_expressions);
  fputc('\n', destination_expressions);
  fputc('\n', destination_expressions);

  i = 0;

  cout << "press ENTER to print the words on the screen or SPACE to skip\n\n";

  while(1) {
     choice = getch();
     if(choice == 32)
        break;
     if(choice == 13) {
     	  SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);
  	     break;
     }
  }

  if(choice == 32)
     cout << "saving...";


  while(i < 50000) {
	if(data_base_expressions[i][1].expression_repeatings >= min_number_of_repeatings) {
      if(choice == 13) {
			cout << counter << " " << "(" << data_base_expressions[i][1].expression_score << ")" << " "
      	<< "(" << data_base_expressions[i][1].expression_repeatings << ") ";
      	while(j < 100) {
      		cout << data_base_expressions[i][1].expression[j];
         	j++;
      	}
      	cout << "\n";
      	j = 0;
      }
		counter++;
		itoa(data_base_expressions[i][1].expression_repeatings, number_for_dest, 10);
      itoa(data_base_expressions[i][1].expression_score, score_for_dest, 10);
		itoa(counter - 1, counter_for_dest, 10);
		fputs(counter_for_dest, destination_expressions);
		fputc(' ', destination_expressions);
      fputc('(', destination_expressions);
      fputs(score_for_dest, destination_expressions);
      fputc(')', destination_expressions);
		fputc(' ', destination_expressions);
      fputc('(', destination_expressions);
      fputs(number_for_dest, destination_expressions);
      fputc(')', destination_expressions);
      fputc(' ', destination_expressions);
		fputs(data_base_expressions[i][1].expression, destination_expressions);
		fputc('\n', destination_expressions);
	}
		i++;
  }

  if(choice == 32){
     gotoxy(1, 19);
     cout <<"\n\n";
  }
  if(choice == 13)
     cout <<"\n\n";
  if(choice_49 == true && choice != 13) {
     gotoxy(1, 19);
     cout << "saving is completed\n\n";
  }
  else
     cout << "saving is completed\n\n";
  if(thesaurus_function == false && choice_flag == true) {
     cout << "press ENTER to run thesaurus or ESCAPE to exit the program";
     while(1) {
        choice_t = getch();
        if(choice_t == 27 || choice_t == 13)
           break;
     }
  }
  if(thesaurus_function == false && choice_flag == false) {
     cout << "press any key to exit the program";
     getch();
  }
  if(thesaurus_function == true) {
     cout << "press any key to return to the main menu";
     getch();
  }
  clrscr();
  return 0;
}
*/

/*
void bubble_sort_words_inc()
{
	struct WORDS hold;
   cout << "\nsorting...";
	for(long pass = 0; pass <= counter_for_different_repeatings; pass++)
		for(i = 0; i < counter_for_different_repeatings; i++)
			if(data_base_words[i].word_repeatings > data_base_words[i + 1].word_repeatings) {
				hold = data_base_words[i];
				data_base_words[i] =  data_base_words[i + 1];
				data_base_words[i + 1] = hold;
			}
   gotoxy(1 , 14);
   cout << "sorting is completed" << "\n\n";
}


void bubble_sort_words_dec()
{
	struct WORDS hold;
   gotoxy(1 , 14);
   cout << "sorting...";
	for(long pass = 0; pass <= counter_for_different_repeatings; pass++)
		for(i = 0; i < counter_for_different_repeatings; i++)
			if(data_base_words[i].word_repeatings < data_base_words[i + 1].word_repeatings) {
				hold = data_base_words[i];
				data_base_words[i] =  data_base_words[i + 1];
				data_base_words[i + 1] = hold;
			}
   gotoxy(1 , 14);
   cout << "sorting is completed" << "\n\n";
}


void bubble_sort_words_dec_scores()
{
	struct WORDS hold;
   gotoxy(1 , 14);
   cout << "                      ";
   gotoxy(1 , 14);
   cout << "sorting...";
	for(long pass = 0; pass <= counter_for_different_repeatings; pass++)
		for(i = 0; i < counter_for_different_repeatings; i++)
			if(data_base_words[i].word_score < data_base_words[i + 1].word_score) {
				hold = data_base_words[i];
				data_base_words[i] =  data_base_words[i + 1];
				data_base_words[i + 1] = hold;
			}
   gotoxy(1 , 14);
   cout << "                      ";
   gotoxy(1 , 14);
   cout << "sorting is completed" << "\n\n";
}


void bubble_sort_words_abc()
{
	struct WORDS hold;
   cout << "\nsorting...";
	for(long pass = 0; pass <= counter_for_different_repeatings; pass++)
		for(i = 0; i < counter_for_different_repeatings; i++)
			if(strcmp( data_base_words[i].word, data_base_words[i + 1].word ) > 0){
         	hold = data_base_words[i];
				data_base_words[i] =  data_base_words[i + 1];
				data_base_words[i + 1] = hold;
			}
   gotoxy(1 , 14);
   cout << "sorting is completed" << "\n\n";
}


void bubble_sort_expressions_dec()
{

	struct EXPRESSIONS hold;
   gotoxy(1 , 17);
   cout  << "sorting..." << "\n";
	for(long pass = 0; pass <= expr_rep_counter; pass++)
		for(i = 0; i < expr_rep_counter; i++)
			if(data_base_expressions[i][1].expression_repeatings < data_base_expressions[i + 1][1].expression_repeatings) {
				hold = data_base_expressions[i][1];
				data_base_expressions[i][1] =  data_base_expressions[i + 1][1];
				data_base_expressions[i + 1][1] = hold;
			}
   gotoxy(1 , 17);
   cout << "sorting is completed" << "\n\n";
}


void bubble_sort_expressions_dec_scores()
{

	struct EXPRESSIONS hold;
   gotoxy(1 , 17);
   cout << "                      ";
   gotoxy(1 , 17);
   cout  << "sorting..." << "\n";
	for(long pass = 0; pass <= expr_rep_counter; pass++)
		for(i = 0; i < expr_rep_counter; i++)
			if(data_base_expressions[i][1].expression_score < data_base_expressions[i + 1][1].expression_score) {
				hold = data_base_expressions[i][1];
				data_base_expressions[i][1] =  data_base_expressions[i + 1][1];
				data_base_expressions[i + 1][1] = hold;
			}
   gotoxy(1 , 17);
   cout << "                      ";
   gotoxy(1 , 17);
   cout << "sorting is completed" << "\n\n";
}


void bubble_sort_expressions_inc()
{
	struct EXPRESSIONS hold;
   gotoxy(1 , 17);
   cout  << "sorting..." << "\n";
	for(long pass = 0; pass <= expr_rep_counter; pass++)
		for(i = 0; i < expr_rep_counter; i++)
			if(data_base_expressions[i][1].expression_repeatings > data_base_expressions[i + 1][1].expression_repeatings) {
				hold = data_base_expressions[i][1];
				data_base_expressions[i][1] =  data_base_expressions[i + 1][1];
				data_base_expressions[i + 1][1] = hold;
			}
   gotoxy(1 , 17);
   cout << "sorting is completed" << "\n\n";
}


void bubble_sort_expressions_abc()
{
	struct EXPRESSIONS hold;
   gotoxy(1 , 17);
   cout  << "sorting..." << "\n";
	for(long pass = 0; pass <= expr_rep_counter; pass++)
		for(i = 0; i < expr_rep_counter; i++)
			if(strcmp(data_base_expressions[i][1].expression, data_base_expressions[i + 1][1].expression) > 0) {
         	hold = data_base_expressions[i][1];
				data_base_expressions[i][1] =  data_base_expressions[i + 1][1];
				data_base_expressions[i + 1][1] = hold;
			}
   gotoxy(1 , 17);
   cout << "sorting is completed" << "\n\n";
}
*/


void find_sentences()
{
   int j = 0,
       g = 0,
       f = 0,
       p = 0,
       input_letters_counter = 0,
       back_to_beginning_sentence_counter = 0,
       forward_to_end_sentence_counter = 0,
       sentence_length = 0,
       maximum_sentence_length = 79,
       minimum_sentence_length = 20,
       maximum_sentence_length_to_increase_to = 0,
       max_number_sentences_to_save = 5,
       temp_max_number_sentences_to_save = 5,
       max_number_sentences_to_show = 10,
       sentences_new_counter_for_last_input = 0,
       symbols_counter = 0,
   	 copy_symbols_counter = 0,
       y = 1,
       increaser = 0,
       x_range = 79,
       y_range = 30;


   long counter_for_number_of_sentences = 0,
   	  copy_input_repeatings_counter = 0,
   	  input_repeatings_counter = 0,
        expression_counter = 0,
        expression_index = 0,
        matches_remained,
        i = 0,
        sentences_counter_for_last_input = 0,
        text_letters_counter = 0,
        m = 0,
        n = 0,
		  real_text_length_for_expressions,
        length_of_finished_part_of_text = 0,
        index = 0;

   char choice,
        answer = ' ',
        *save_input_in_capital_letters = "on",
        *cut_sentences_after_79th_symbol = "on",
        *numbering = "on",
        *increasing = "off",
        *asterisk_symbol = "off",
        *filter = "on";

   bool save_all_matches = false,
        show_all_matches = false,
        save_in_capital = true,
        difficulty_score = true,
        copy_flag = false,
        filter_flag = true,
        filter_option = true,
        scan_the_database = false;

//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;
   SMALL_RECT DisplayArea = {0, 0, 0, 0};
   x_range = 79;
   y_range = 25;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   DisplayArea.Right  = x_range;
   DisplayArea.Bottom = y_range;
	SetConsoleWindowInfo(hConsoleOutput, TRUE, &DisplayArea);

//------------------------------------------------------------------------------

   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD bufferSize = {80, 44};
   SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);

//------------------------------------------------------------------------------

   CONSOLE_CURSOR_INFO cciInfo;
   cciInfo.dwSize = 20;
   cciInfo.bVisible = true;
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

//------------------------------------------------------------------------------

   asterisk = false;

   initializing_text_test();
   load_stack_words_data();

   while(i < 101) {
   	input[i] = ' ';
      i++;
   }

   while(1) {
      while(1) {
   		sentences_counter_for_last_input = 0;
   		input_letters_counter = 0;
   		text_letters_counter = 0;
   		i = 0;
   		expression_counter = 0;
   		expression_index = 0;
   		if(choice != 9) {
      		input_repeatings_counter = 0;
      		j = 0;
   		}
   		else
      		input_repeatings_counter = copy_input_repeatings_counter;

      counter_for_number_of_sentences = 0;
   	length_of_finished_part_of_text = 0;
   	index = 0;
   	save_all_matches = false;
   	show_all_matches = false;
      scan_the_database = false;

   	if(choice != 9) {
   		while(1) {
   			while(i < 101) {
   				input[i] = ' ';
      			i++;
   			}

   			i = 0;
   			clrscr();
            cciInfo.bVisible = true;
            SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
   			cout << "enter a word or phrase you want to find\n\n";
   			cin.getline(input, 101);

   			if(input[1] == ' ') // && input[1] == ' ')  //?????????? podgon dla malenkich tekstov
      			if(input[2] == ' ')
         			if(input[3] == ' ')
            			cin.getline(input, 101);

   			while(!(input[input_letters_counter] == ' ' && input[input_letters_counter + 1] == ' ')) {
      			j++;
      			input_letters_counter++;
   			}

   			j--; //?????? podgon etogo vi4itaniya ranshe ne bilo

            while(i < input_letters_counter) {
            	if(input[i] >= 65 && input[i] <= 90)
               	input[i] += 32;
               i++;
            }

            i = 0;

   			real_text_length_for_expressions = copy_real_text_length;
   			clrscr();
   			input_letters_counter = 0;

   			for(text_letters_counter = 0; text_letters_counter < real_text_length_for_expressions; text_letters_counter ++) {
      			input_letters_counter = 0;
         		back_to_beginning_sentence_counter = 0;
         		forward_to_end_sentence_counter = 0;
         		i = 0;
      			while(input_letters_counter < j) {
   					if(input[input_letters_counter] == text_for_words[text_letters_counter + input_letters_counter]) {
            			input_letters_counter++;
               		if(input_letters_counter == j && text_for_words[text_letters_counter + input_letters_counter] == ' '
                     && (text_for_words[text_letters_counter - 1] == ' ' || text_letters_counter == 0)) {
                  		input_repeatings_counter++;
               		}
            		}
               	else {
            			while(text_for_words[text_letters_counter] != ' ')
        	   				text_letters_counter++;
         				break;
         	  		}
      			}
   			}

            cciInfo.bVisible = false;
            SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

   			copy_input_repeatings_counter = input_repeatings_counter;
   			if(input_repeatings_counter > 0) {
               check_input_flag = true;
               input_string_score = words_of_the_sentence_difficulty_score_calculation();
               if(save_all_matches == false && auto_increase == false && scan_the_database == false) {
               	if(input_repeatings_counter <= 20)
               		maximum_sentence_length = 150;
               	if(input_repeatings_counter <= 10)
               		maximum_sentence_length = 200;
               	if(input_repeatings_counter > 20)
               		maximum_sentence_length = 79;
      				break;
               }
            }
   			else {
      			input_letters_counter = 0;
   				sentences_counter_for_last_input = 0;
               text_letters_counter = 0;
               i = 0;
   				expression_counter = 0;
  	 				expression_index = 0;
   				input_repeatings_counter = 0;
   				counter_for_number_of_sentences = 0;
               length_of_finished_part_of_text = 0;
   				index = 0;
   				j = 0;
   				save_all_matches = false;
   				show_all_matches = false;
               scan_the_database = false;
               input_string_score = 0;
      			clrscr();
      			cout << "no matches found for '" << input << "'\n\n";
               cout << "TAB - rerurn to the main menu\n";
      			cout << "BACKSPACE - enter an other word or phrase\n";
               if(number_of_saved_sentences > 0)
      				cout << "ESCAPE - save and exit the program";
               else
               	cout << "ESCAPE - exit the program";
               i = 0;

         		while(1) {
         			choice = getch();
                  if(choice == 9)
                  	break;
         			if(choice == 8)
            			break;
         			if(choice == 27)
            			break;
      			}
      			if(choice != 9) {
               	while(i < 101) {
   	   				input[i] = ' ';
         				i++;
      				}
               }
   			}

            if(choice == 9)
            	break;
      		if(choice == 8)
            	continue;
      		if(choice == 27)
            	break;
   		}
   		if(choice == 27)
            break;
 		}

 		while(1) {
         max_number_sentences_to_save = temp_max_number_sentences_to_save;
   		clrscr();
         check_input_flag = false;
         cciInfo.bVisible = false;
         SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
         COORD bufferSize = {80, 44};
		   SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);
   		cout << input_repeatings_counter << " matches found for ";
         if(input_repeatings_counter > 0)
         	SetConsoleTextAttribute(hConsoleOutput, 224);
         cout <<"'"<< input << "'";
         SetConsoleTextAttribute(hConsoleOutput, 63);
         cout << " : the score is " << input_string_score << "\n\n";
   		if(number_of_saved_sentences == 1)
      		cout << number_of_saved_sentences << " sentence saved in total\n\n";
   		if(number_of_saved_sentences != 1)
      		cout << number_of_saved_sentences << " sentences saved in total\n\n";

         if(input_repeatings_counter == 0)
         	SetConsoleTextAttribute(hConsoleOutput, 55);

         cout << "1 - change the minimum sentence length (" << minimum_sentence_length << ")\n";
         if(auto_increase == true) {
         	SetConsoleTextAttribute(hConsoleOutput, 55);
            cout << "2 - change the maximum sentence length (" << maximum_sentence_length << ")\n";
         }
         else {
            if(input_repeatings_counter > 0)
         		SetConsoleTextAttribute(hConsoleOutput, 63);
   			cout << "2 - change the maximum sentence length (" << maximum_sentence_length << ")\n";
         }
         if(input_repeatings_counter > 0)
         	SetConsoleTextAttribute(hConsoleOutput, 63);
   		cout << "3 - save the input in capital letters (" << save_input_in_capital_letters << ")\n";
         if(auto_increase == true) {
            SetConsoleTextAttribute(hConsoleOutput, 55);
            cout << "4 - show and save sentences one by one\n";
         }
         else {
         	if(input_repeatings_counter > 0)
         		SetConsoleTextAttribute(hConsoleOutput, 63);
            cout << "4 - show and save sentences one by one\n";
         }
         if(input_repeatings_counter > 0)
         	SetConsoleTextAttribute(hConsoleOutput, 63);
   		cout << "5 - save all sentences without showing\n";

         SetConsoleTextAttribute(hConsoleOutput, 63);

         if(number_of_saved_sentences == 0) {
         	SetConsoleTextAttribute(hConsoleOutput, 55);
   			cout << "6 - show saved sentences\n";
   			cout << "7 - delete all saved sentences\n";
         }
         else {
            SetConsoleTextAttribute(hConsoleOutput, 63);
   			cout << "6 - show saved sentences\n";
         	cout << "7 - delete all saved sentences\n";
         }
         SetConsoleTextAttribute(hConsoleOutput, 63);

         if(input_repeatings_counter == 0)
         	SetConsoleTextAttribute(hConsoleOutput, 55);

         if(auto_increase == true) {
         	SetConsoleTextAttribute(hConsoleOutput, 55);
         	cout << "8 - change the maximum number of sentences to show on the screen (" << max_number_sentences_to_show << ")\n";
         }
         else {
         	if(input_repeatings_counter > 0)
         		SetConsoleTextAttribute(hConsoleOutput, 63);
            cout << "8 - change the maximum number of sentences to show on the screen (" << max_number_sentences_to_show << ")\n";
         }
         if(input_repeatings_counter > 0)
            SetConsoleTextAttribute(hConsoleOutput, 63);

         cout << "9 - change the maximum number of sentences to save per input (option 5) (" << max_number_sentences_to_save << ")\n";
         cout << "0 - cut sentences after 79th symbol including index number when saving (" << cut_sentences_after_79th_symbol << ")\n";
         cout << "A - put the asterisk before the inputs (" << asterisk_symbol << ")\n";

         if(copy_flag == false)
         	cout << "C - copy the current score to the minimum range" << "\n";
         else
         	if(minimum_words_score != 0)
            	cout << "C - align the minimum score range" << "\n";
            else
            	cout << "C - copy the current score to the minimum range" << "\n";

         if(input_repeatings_counter > 0)
            SetConsoleTextAttribute(hConsoleOutput, 63);
         cout << "D - find sentences by the score range (difficulty) (" << minimum_words_score << " - " << maximum_words_score << ")\n";
         cout << "F - filter out the sentences which do not begin with capital letters (" << filter << ")\n";
         if(auto_increase == true)
         	cout << "I - sentence auto increase (" << increasing << ")" << " / increase by (" << increaser << ") / increase to ("
            << maximum_sentence_length_to_increase_to << ")\n";
         else
         	cout << "I - sentence auto increase (option 5 and scan) ("<< increasing << ")\n";
         cout << "N - number the inputs (" << numbering << ")\n";
         cout << "R - restore default settings\n";
         if(auto_increase == true)
         	cout << "S - scan the database\n";
         else {
            SetConsoleTextAttribute(hConsoleOutput, 55);
            cout << "S - scan the database\n";
         }
         if(input_repeatings_counter > 0)
            SetConsoleTextAttribute(hConsoleOutput, 63);
   		cout << "\n";
         if(auto_increase == true) {
         	SetConsoleTextAttribute(hConsoleOutput, 55);
   			cout << "ENTER - show all sentences without saving\n";
         }
         else {
         	if(input_repeatings_counter > 0)
         		SetConsoleTextAttribute(hConsoleOutput, 63);
            cout << "ENTER - show all sentences without saving\n";
         }
         SetConsoleTextAttribute(hConsoleOutput, 63);

         cout << "BACKSPACE - enter an other word or phrase\n";

   		if(number_of_saved_sentences > 0)
         	cout << "ESCAPE - save and exit the program";
         else
         	cout << "ESCAPE - exit the program";

      	while(1) {
   			choice = getch();
            if(choice == 49 && input_repeatings_counter > 0) {
            	clrscr();
               cciInfo.bVisible = true;
               SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
               cout << "enter the minimum sentence length ";
               cin >> minimum_sentence_length;
               	while(minimum_sentence_length < 1 || minimum_sentence_length > maximum_sentence_length) {
                  	if(minimum_sentence_length < 1 ) {
                     	clrscr();
               			cout << "the minimum sentence length must be 1 at least\n\n";
               			cout << "enter the minimum sentence length ";
               			cin >> minimum_sentence_length;
            			}
            			if(minimum_sentence_length > maximum_sentence_length) {
               			clrscr();
               			cout << "the minimum sentence length must be less than the maximum one (" << maximum_sentence_length << ")\n\n";
               			cout << "enter the minimum sentence length ";
               			cin >> minimum_sentence_length;
            			}
         			}
            	break;
   			}
            if(auto_increase == false) {
   				if(choice == 50 && input_repeatings_counter > 0) {
      				clrscr();
               	cciInfo.bVisible = true;
               	SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
      				cout << "enter the maximum sentence length ";
      				cin >> maximum_sentence_length;
      				while(maximum_sentence_length > 1000 || maximum_sentence_length < minimum_sentence_length) {
            			if(maximum_sentence_length > 1000 ) {
               			clrscr();
                  		cout << "the maximum sentence length must be 1000 at most\n\n";
                  		cout << "enter the maximum sentence length ";
               			cin >> maximum_sentence_length;
            			}
            			if(maximum_sentence_length < minimum_sentence_length) {
               			clrscr();
               			cout << "the maximum sentence length must be more than minimum one (" << minimum_sentence_length << ")\n\n";
               			cout << "enter the maximum sentence length ";
               			cin >> maximum_sentence_length;
            			}
         			}
      				break;
   				}
            }

   			if(choice == 54 && number_of_saved_sentences > 0) {
   				show_saved_sentences();
      			HANDLE hConsoleOutput;
   				hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   				COORD bufferSize = {80, 21000};
   				SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);
      			break;
   			}

            if(choice == 56 && auto_increase == false && input_repeatings_counter > 0) {
   				clrscr();
               cciInfo.bVisible = true;
               SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
      			cout << "enter the maximum number of sentences to show on one screen without saving ";
      			cin >> max_number_sentences_to_show;
      			while(1) {
      				if(max_number_sentences_to_show < 2 || max_number_sentences_to_show > 1000) {
            			clrscr();
         				cout << "the number must be more then 1 and less then 1001\n\n";
            			cout << "enter the maximum number of sentences to show on one screen without saving ";
            			cin >> max_number_sentences_to_show;
         			}
         			else
         				break;
      			}
      			break;
            }

   			if(choice == 57 && input_repeatings_counter > 0) {
   				clrscr();
               cciInfo.bVisible = true;
               SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
      			cout << "enter the maximum number of sentences to save without showing ";
      			cin >> max_number_sentences_to_save;
      			while(1) {
      				if(max_number_sentences_to_save < 1 || max_number_sentences_to_save > 1000) {
            			clrscr();
         				cout << "the number must be more then 0 and less then 1001\n\n";
            			cout << "enter the maximum number of sentences to save without showing ";
            			cin >> max_number_sentences_to_save;
         			}
         			else
         				break;
      			}
               temp_max_number_sentences_to_save = max_number_sentences_to_save;
      			break;
   			}

   			if(choice == 55 && number_of_saved_sentences > 0) {
      			clrscr();
      			cout << "are you sure you want to delete all saved sentences? (y/n) ";
               while(1) {
               	answer = getch();
                  if(answer == 'y') {
                  	cout << "\n\n";
                     cout << "deleting...";
                     for(i = 0; i < number_of_saved_sentences; i++) {
                     	while(f < 101) {
            					data_base_sentences[i].input_to_find[f] = ' ';
                  			f++;
               			}
               			while(g < 1001) {
               				data_base_sentences[i].sentence[g] = ' ';
                  			g++;
               			}
                     	data_base_sentences[i].number_of_sentences = 0;
               			f = 0;
               			g = 0;
            			}
            			sentences_counter_for_last_input = 0;
            			number_of_saved_sentences = 0;
            			break;
         			}
         			if(answer == 'n')
         				break;
            	}
      			break;
   			}

   			if(choice == 53 && input_repeatings_counter > 0) {
      			save_all_matches = true;
      			break;
   			}

            if(choice == 52 && auto_increase == false && input_repeatings_counter > 0)
      			break;

   			if(choice == 51 && input_repeatings_counter > 0) {
      			if(save_in_capital == true) {
      				save_in_capital = false;
         			save_input_in_capital_letters = "off";
      			}
      			else {
      				save_in_capital = true;
         			save_input_in_capital_letters = "on";
      			}
      			break;
   			}

            if(choice == 48 && input_repeatings_counter > 0) {
      			if(cut_sentences == true) {
      				cut_sentences = false;
         			cut_sentences_after_79th_symbol = "off";
      			}
      			else {
      				cut_sentences = true;
         			cut_sentences_after_79th_symbol = "on";
      			}
      			break;
   			}

            if(choice == 'a' && input_repeatings_counter > 0) {
      			if(asterisk == true) {
      				asterisk = false;
         			asterisk_symbol = "off";
      			}
      			else {
      				asterisk = true;
         			asterisk_symbol = "on";
      			}
      			break;
   			}

            if(choice == 'n' && input_repeatings_counter > 0) {
      			if(number_the_inputs == true) {
      				number_the_inputs = false;
         			numbering = "off";
      			}
      			else {
      				number_the_inputs = true;
         			numbering = "on";
      			}
      			break;
   			}

            if(choice == 'f' && input_repeatings_counter > 0) {
      			if(filter_option == true) {
      				filter_option = false;
         			filter = "off";
      			}
      			else {
      				filter_option = true;
         			filter = "on";
      			}
      			break;
   			}

            if(choice == 's' && auto_increase == true && input_repeatings_counter > 0) {
            	scan_the_database = true;
               break;
            }

            if(choice == 'i' && input_repeatings_counter > 0) {
      			if(auto_increase == true) {
      				auto_increase = false;
                  maximum_sentence_length_to_increase_to = 0;
                  increaser = 0;
         			increasing = "off";
                  if(maximum_sentence_length == 20)
                  	maximum_sentence_length = 79;
      			}
      			else {
      				auto_increase = true;
                  maximum_sentence_length = minimum_sentence_length;
         			increasing = "on";
                  clrscr();
                  cciInfo.bVisible = true;
               	SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
                  cout << "enter the number of symbols to increase the sentence length each time ";
                  cin >> increaser;
                  while(increaser < 1 || increaser > 500) {
                  	clrscr();
                  	cout << "the number of symbols to increase the sentence length must be between 1 and 500\n\n";
                     cin >> increaser;
                  }
                  clrscr();
      				cout << "enter the maximum sentence length to increase to ";
      				cin >> maximum_sentence_length_to_increase_to;
      				while(maximum_sentence_length_to_increase_to > 1000 || maximum_sentence_length_to_increase_to < minimum_sentence_length) {
            			if(maximum_sentence_length_to_increase_to > 1000 ) {
               			clrscr();
                  		cout << "the maximum sentence length to increase to must be 1000 at most\n\n";
                  		cout << "enter the maximum sentence length to increase to ";
               			cin >> maximum_sentence_length_to_increase_to;
            			}
            			if(maximum_sentence_length_to_increase_to < minimum_sentence_length) {
               			clrscr();
               			cout << "the maximum sentence length must be more than the minimum one ("
                        << minimum_sentence_length << ")\n\n";
               			cout << "enter the maximum sentence length to increase to ";
               			cin >> maximum_sentence_length_to_increase_to;
            			}
         			}
      			}
      			break;
   			}

            if(choice == 'd' && input_repeatings_counter > 0) {
            	clrscr();
               cciInfo.bVisible = true;
               SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
               previous_minimum_words_score = minimum_words_score;
               cout << "enter the minimum words' score ";
               cin >> minimum_words_score;
               	while(minimum_words_score < 0 || minimum_words_score > maximum_words_score) {
                  	if(minimum_words_score < 0 ) {
                     	clrscr();
               			cout << "the minimum words' score must be 0 at least\n\n";
               			cout << "enter the minimum words' score ";
               			cin >> minimum_words_score;
            			}
            			if(minimum_words_score > maximum_words_score) {
               			clrscr();
               			cout << "the minimum words' score must be less than the maximum one (" << maximum_words_score << ")\n\n";
               			cout << "enter the minimum words' score ";
               			cin >> minimum_words_score;
            			}
         			}
               if(previous_minimum_words_score != minimum_words_score && auto_increase == true)
               	maximum_sentence_length = minimum_sentence_length;
      			break;
   			}

            if(choice == 'r' && input_repeatings_counter > 0) {
               minimum_sentence_length = 20;
               maximum_sentence_length = 79;
               save_in_capital = true;
               save_input_in_capital_letters = "on";
               max_number_sentences_to_show = 10;
               max_number_sentences_to_save = 5;
               cut_sentences = true;
               cut_sentences_after_79th_symbol = "on";
               asterisk = false;
               asterisk_symbol = "off";
               number_the_inputs = true;
               numbering = "on";
               auto_increase = false;
               maximum_sentence_length_to_increase_to = 0;
               increaser = 0;
               increasing = "off";
               minimum_words_score = 0;
               filter = "on";
               filter_flag = false;
               copy_flag = false;
               break;
            }

            if(choice == 'c' && input_repeatings_counter > 0) {
            	if(copy_flag == false) {
               	copy_flag = true;
                  minimum_words_score = input_string_score;
               }
               else {
               	copy_flag = false;
                  minimum_words_score = 0;
                  if(auto_increase == true)
                  	maximum_sentence_length = minimum_sentence_length;
               }
               break;
            }

            if(choice == 77 && ((maximum_sentence_length + 10) <= 1000) && auto_increase == false && input_repeatings_counter > 0) {
            	maximum_sentence_length += 10;
               if(choice == 77 && ((maximum_sentence_length + 10) > 1000) && auto_increase == false)
               	maximum_sentence_length = 1000;
               break;
            }

            if(choice == 75 && ((maximum_sentence_length - 10) > minimum_sentence_length) && auto_increase == false && input_repeatings_counter > 0) {
            	maximum_sentence_length -= 10;
               break;
            }

            if(choice == 80 && input_repeatings_counter > 0) {
            	if((minimum_words_score - 2000) >= 30000) {
               	minimum_words_score -= 2000;
                  break;
               }
               if((minimum_words_score - 2000) < 30000 && minimum_words_score > 30000) {
               	minimum_words_score = 30000;
                  break;
               }
               if((minimum_words_score - 500) >= 10000) {
               	minimum_words_score -= 500;
                  break;
               }
               if((minimum_words_score - 500) < 10000 &&  minimum_words_score > 10000) {
               	minimum_words_score = 10000;
                  break;
               }
               if((minimum_words_score - 200) >= 1000) {
               	minimum_words_score -= 200;
                  break;
               }
               if((minimum_words_score - 200) < 1000 && minimum_words_score > 1000) {
               	minimum_words_score = 1000;
                  break;
               }
               if((minimum_words_score - 50) >= 500) {
               	minimum_words_score -= 50;
                  break;
               }
               if((minimum_words_score - 50) < 500 && minimum_words_score > 500) {
               	minimum_words_score = 500;
                  break;
               }
               if((minimum_words_score - 20) >= 100) {
               	minimum_words_score -= 20;
                  break;
               }
               if((minimum_words_score - 20) < 100 && minimum_words_score > 100) {
               	minimum_words_score = 100;
                  break;
               }
               if((minimum_words_score - 1) >= 0) {
               	minimum_words_score -= 1;
                  break;
               }
               if((minimum_words_score - 1) < 0 && minimum_words_score > 0) {
               	minimum_words_score = 0;
                  break;
               }
               break;
            }

            if(choice == 72 && input_repeatings_counter > 0) {
               if(minimum_words_score < 100 && (minimum_words_score + 1) > input_string_score) {
               	minimum_words_score = input_string_score;
                  break;
               }
            	if((minimum_words_score + 1) <= 100 && minimum_words_score <= input_string_score) {
               	minimum_words_score += 1;
                  break;
               }
               if(minimum_words_score < 500 && (minimum_words_score + 20) > input_string_score) {
               	minimum_words_score = input_string_score;
                  break;
               }
               if((minimum_words_score + 20) <= 500 && minimum_words_score <= input_string_score) {
               	minimum_words_score += 20;
                  break;
               }
               if(minimum_words_score < 500 && (minimum_words_score + 20) > 500 && minimum_words_score <= input_string_score) {
               	minimum_words_score = 500;
                  break;
               }
               if(minimum_words_score < 1000 && (minimum_words_score + 50) > input_string_score) {
               	minimum_words_score = input_string_score;
                  break;
               }
               if((minimum_words_score + 50) <= 1000 && minimum_words_score <= input_string_score) {
               	minimum_words_score += 50;
                  break;
               }
               if(minimum_words_score < 1000 && (minimum_words_score + 50) > 1000 && minimum_words_score <= input_string_score) {
               	minimum_words_score = 1000;
                  break;
               }
               if(minimum_words_score < 10000 && (minimum_words_score + 200) > input_string_score) {
               	minimum_words_score = input_string_score;
                  break;
               }
               if((minimum_words_score + 200) <= 1000 && minimum_words_score <= input_string_score) {
               	minimum_words_score += 200;
                  break;
               }
               if(minimum_words_score < 10000 && (minimum_words_score + 200) > 10000 && minimum_words_score <= input_string_score) {
               	minimum_words_score = 10000;
                  break;
               }
               if(minimum_words_score < 30000 && (minimum_words_score + 500) > input_string_score) {
               	minimum_words_score = input_string_score;
                  break;
               }
               if((minimum_words_score + 500) <= 30000 && minimum_words_score <= input_string_score) {
               	minimum_words_score += 500;
                  break;
               }
               if(minimum_words_score < 30000 && (minimum_words_score + 500) > 30000 && minimum_words_score <= input_string_score) {
               	minimum_words_score = 30000;
                  break;
               }
               if(minimum_words_score < 70288 && (minimum_words_score + 2000) > input_string_score) {
               	minimum_words_score = input_string_score;
                  break;
               }
               if((minimum_words_score + 2000) <= 70288 && minimum_words_score <= input_string_score) {
               	minimum_words_score += 2000;
                  break;
               }
               if(minimum_words_score < 70288 && (minimum_words_score + 2000) > 70288 && minimum_words_score <= input_string_score) {
               	minimum_words_score = 70288;
                  break;
               }

            }


            if(choice == 13 && auto_increase == false && input_repeatings_counter > 0) {
      			show_all_matches = true;
      			break;
   			}

   		  	if(choice == 8 && auto_increase == true) {
            	maximum_sentence_length = minimum_sentence_length;
               minimum_words_score = 0;
      			break;
            }
            if(choice == 8 && auto_increase == false) {
            	minimum_words_score = 0;
      			break;
            }
   			if(choice == 27)
      			break;
   		}
   		if(choice == 53 && input_repeatings_counter > 0)
      		break;
   		if(choice == 52 && input_repeatings_counter > 0)
      		break;
         if(choice == 's' && input_repeatings_counter > 0)
      		break;
   		if(choice == 13 && input_repeatings_counter > 0)
         	break;
   		if(choice == 8)
      		break;
   		if(choice == 27)
      		break;
   	}
   	if(choice == 53 && input_repeatings_counter > 0)
      	break;
   	if(choice == 52 && input_repeatings_counter > 0)
      	break;
   	if(choice == 13 && input_repeatings_counter > 0)
      	break;
      if(choice == 's' && input_repeatings_counter > 0)
      	break;
   	if(choice == 8)
      	continue;
   	if(choice == 27)
      	break;
   }
   if(choice == 27)
      break;

//------------------------------------------------------------------------------

   COORD bufferSize = {80, 21000};
   SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);
   cciInfo.bVisible = false;
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

//------------------------------------------------------------------------------

   sentences_new_counter_for_last_input = 0;
   sentences_counter_for_last_input = 0;
   input_letters_counter = 0;
   text_letters_counter = 0;
   i = 0;
   expression_counter = 0;
   expression_index = 0;
   counter_for_number_of_sentences = 0;
   length_of_finished_part_of_text = 0;
   index = 0;
   m = 0;
   n = 0;

   temp_max_number_sentences_to_save = max_number_sentences_to_save;

   if(save_all_matches == true || scan_the_database == true) {
   	clrscr();
      if(save_all_matches == true)
   		cout << "saving...";
      if(scan_the_database == true)
      	cout << "scanning...";
   }

   if(save_all_matches == false && scan_the_database == false)
   	clrscr();

   for(text_letters_counter = 0; text_letters_counter < real_text_length_for_expressions; text_letters_counter++) {
   	input_letters_counter = 0;
      back_to_beginning_sentence_counter = 0;
      forward_to_end_sentence_counter = 0;
      i = 0;
      while(input_letters_counter < j) {
      	if(input[input_letters_counter] == text_for_words[text_letters_counter + input_letters_counter]) {
         	input_letters_counter++;
            if(input_letters_counter == j && text_for_words[text_letters_counter + input_letters_counter] == ' '
            && (text_for_words[text_letters_counter - 1] == ' ' || text_letters_counter == 0)) {
            	number_of_saved_inputs++;
               while((text_letters_counter + input_letters_counter) >= back_to_beginning_sentence_counter
               && back_to_beginning_sentence_counter < 1000) {
               	back_to_beginning_sentence_counter++;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter - 1] == '.'
                  && text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == '"')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter - 1] == '!'
                  && text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == '"')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter - 1] == '?'
                  && text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == '"')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter - 1] == '.'
                  && text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == 39)
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter - 1] == '!'
                  && text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == 39)
                     break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter - 1] == '?'
                  && text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == 39)
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == '.')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == '!')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == '?')
                  	break;
               }
               while(forward_to_end_sentence_counter < (1000 - back_to_beginning_sentence_counter)) {
               	if(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '.'
                  && (!(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 1] == 'r'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 2] == 'M'))
                  &&
                  (text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '.')
                  && (!(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 1] == 's'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 2] == 'r'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 3] == 'M'))
                  &&
                  (text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '.')
                  && (!(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 1] == 't'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 2] == 'S'))
                  &&
                  (text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '.')
                  && (!(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 1] == 'T'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 2] == 'S'))
                  &&
                  (text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '.')
                  && (!(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 1] == 'r'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 2] == 'D'))
                  &&
                  (text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '.')
                  && (!(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 1] == 'R'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 2] == 'D')))
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '!')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '?')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == ' '
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter + 1] == ' '
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter + 2] == ' ')
                  	break;
                  forward_to_end_sentence_counter++;
               }

               if(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter + 1] == '"')
                     forward_to_end_sentence_counter++;
               if(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter + 1] == 39)
                     forward_to_end_sentence_counter++;

               sentence_length = back_to_beginning_sentence_counter + forward_to_end_sentence_counter;
               i = 0;
               back_to_beginning_sentence_counter--;
               beginning_of_the_sentence = text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter;
               end_of_the_sentence = text_letters_counter + input_letters_counter + forward_to_end_sentence_counter;

               if(show_all_matches == false && save_all_matches == false && scan_the_database == false)
               	clrscr();

               SetConsoleTextAttribute(hConsoleOutput, 240);
               n = 0;

               while(text_for_sentences[beginning_of_the_sentence] == ' ')
               	beginning_of_the_sentence++;

               if(filter_option == true) {
               	if((text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90)
               	|| (text_for_sentences[beginning_of_the_sentence + 1] >= 65 && text_for_sentences[beginning_of_the_sentence + 1] <= 90))
               		filter_flag = true;
               	else
               		filter_flag = false;
               }
               else
               	filter_flag = true;

               symbols_counter = 0;
               copy_symbols_counter = 0;
               y;

               if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length) //{
               	difficulty_score = words_of_the_sentence_difficulty_score();

               for(m = beginning_of_the_sentence; m <= end_of_the_sentence; m++) {
               	while(n < j) {
                  	if(input[n] == text_for_words[m + n])
                     	n++;
                     else {
                     	n = 0;
                        break;
                     }
                  }
                  if(n == j && text_for_words[m + n] == ' ' && (text_for_words[m - 1] == ' ' || m == 0)) {
                  	input_repeatings_counter--;
                     n = 0;
                     SetConsoleTextAttribute(hConsoleOutput, 224);
                     y = 1;
                     while(n < j) {
                     	if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true)
                        	//if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90) //filter na perviy simvol                                                                                                                 //perviy simvol                                                                               //perviy simvol
                           	if((save_all_matches == false && scan_the_database == false) || show_all_matches  == true) {
                              symbols_counter++;
                                 if(text_for_sentences[m + n] == ' ') {
                                 	if(symbols_counter == 79)
                                    	cout << "\n";
                                    cout << text_for_sentences[m + n];
                                    copy_symbols_counter = symbols_counter;
                                 	while(text_for_sentences[m + n + y] != ' ') {
                                    	y++;
                                       symbols_counter++;
                                       if(symbols_counter == 79) {
                                 			cout << "\n";
                                          copy_symbols_counter = symbols_counter = 0;
                                       }
                                    }
                                    symbols_counter = copy_symbols_counter;
                                 }
                                 else {
                                 	cout << text_for_sentences[m + n];
                                 }
                              }

                        n++;
                     }
                        m += n;
                  }
                  n = 0;
                  SetConsoleTextAttribute(hConsoleOutput, 240);
                  y = 1;

                  if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true)
                  	//if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90)
                     	if((save_all_matches == false && scan_the_database == false) || show_all_matches  == true) {
                        	symbols_counter++;
                           	if(text_for_sentences[m + n] == ' ') {
                              	if(symbols_counter == 79)
                                 	cout << "\n";
                                 cout << text_for_sentences[m + n];
                                 copy_symbols_counter = symbols_counter;
                                 while(text_for_sentences[m + n + y] != ' ') {
                                 	y++;
                                    symbols_counter++;
                                    if(symbols_counter == 79) {
                                    	cout << "\n";
                                       copy_symbols_counter = symbols_counter = 0;
                                    }
                                 }
                                    symbols_counter = copy_symbols_counter;
                              }
                              else {
                              	cout << text_for_sentences[m + n];
                              }
                        }
                     	if(symbols_counter >= 79)
                     		symbols_counter = 0;
               }

               //if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90)
               	if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true)
                  	if(show_all_matches == true)
                     	cout << "\n" << "\n";

               //if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90)
               	if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true)
                  	if(show_all_matches == true)
                     	if(sentences_counter_for_last_input != 0)
                        	if((sentences_counter_for_last_input + 1) % max_number_sentences_to_show == 0) {
                           	SetConsoleTextAttribute(hConsoleOutput, 63);
                              cout << "\nSPACE - continue";
                              cout << "\nTAB - return to the main menu";
                              cout << "\nBACKSPACE - enter an other word or phrase";
                              if(number_of_saved_sentences > 0)
      									cout << "\nESCAPE - save and exit the program";
               					else
               						cout << "\nESCAPE - exit the program";
                              choice = ' ';
                              while(1) {
                                 choice = getch();
                                 if(choice == 32)
                                    break;
                                 if(choice == 9)
                                    break;
                                 if(choice == 8)
                                    break;
                                 if(choice == 27)
                                    break;
                              }
                              clearscreen();
                           }

                  SetConsoleTextAttribute(hConsoleOutput, 63);

                  if(show_all_matches == false && save_all_matches == false && scan_the_database == false) {
					    	//if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90) {
                  		if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true) {
                     		if(input_repeatings_counter != -1) {
                  				cout << "\n\n\n";
                  				cout << input_repeatings_counter << " matches remained\n\n";
                     			if(sentences_counter_for_last_input == 1)
                        			cout << sentences_counter_for_last_input << " sentence saved with the last input\n\n";
                     			if(sentences_counter_for_last_input != 1)
                  	   			cout << sentences_counter_for_last_input << " sentences saved with the last input\n\n";
                     			if(number_of_saved_sentences == 1)
                        			cout << number_of_saved_sentences << " sentence saved in total\n\n";
                              if(number_of_saved_sentences != 1)
                  	   			cout << number_of_saved_sentences << " sentences saved in total\n\n";
                                 cout << "ENTER - save the sentence\n";
		            					cout << "SPACE - skip the sentence\n";
                     				cout << "TAB - return to the previous menu\n";
                                 cout << "BACKSPACE - enter an other word or phrase\n";
                  					if(number_of_saved_sentences > 0)
      										cout << "ESCAPE - save and exit the program";
               						else
               							cout << "ESCAPE - exit the program";
                  			}

                           while(1) {
                     			choice = getch();
                     			if(choice == 13) {
                        			sentences_counter_for_last_input++;
                        			break;
                     			}
                     			if(choice == 32)
                        			break;
                     			if(choice == 9)
                        			break;
                     			if(choice == 8)
                        			break;
                     			if(choice == 27)
                        			break;
                  			}
                  		}
                  	}

                  if((save_all_matches == true || scan_the_database == true) && sentences_counter_for_last_input < max_number_sentences_to_save) {
                     if(scan_the_database == false)
                     	choice = 13;
                  	if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true)
                     	//if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90)
                     		sentences_counter_for_last_input++;
                  }

                  if(show_all_matches == true) {
                     if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true)
                     	//if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90)
                        	sentences_counter_for_last_input++;
                  }

                  if(choice == 8) {
                     text_letters_counter = real_text_length_for_expressions;
                     break;
                  }

                  if(choice == 9) {
                     text_letters_counter = real_text_length_for_expressions;
                     break;
                  }

                  if(choice == 27) {
                     text_letters_counter = real_text_length_for_expressions;
                     break;
                  }

                  i = 0;

                  while(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter + i] == ' ')
                  	i++;

                  beginning_of_the_sentence = text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter + i;
                  i = 0;

                  if(choice == 13)
                  		if(show_all_matches == false) {
                  			//if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90) {
                     			if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true) {
                        			if(save_in_capital == false)
                        				while(i < sentence_length) {
                           				data_base_sentences[number_of_saved_sentences].sentence[i]
                           				= text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter + i];
                           				i++;
                        				}
                        			if(save_in_capital == true) {
                        				n = 0;
                        				while(text_for_sentences[beginning_of_the_sentence] == ' ')
                           				beginning_of_the_sentence++;
                        				for(m = beginning_of_the_sentence; m <= end_of_the_sentence; m++) {
                           				i++;
                             			while(n < j) {
                                			if(input[n] == text_for_words[m + n])
            	                    			n++;
                                			else {
                                  			n = 0;
                                  			break;
                                       }
                             			}
                             			if(n == j && text_for_words[m + n] == ' ' && (text_for_words[m - 1] == ' ' || m == 0)) {
                                			n = 0;
                                			while(n < j) {
                                   			if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length) {
                                      			if(text_for_sentences[m + n] >= 97 && text_for_sentences[m + n] <= 122) {
                                      	  			data_base_sentences[number_of_saved_sentences].sentence[i] = text_for_sentences[m + n];
                                         			data_base_sentences[number_of_saved_sentences].sentence[i] -= 32;
                                                i++;
                                      			}
                                      			else {
                                      				data_base_sentences[number_of_saved_sentences].sentence[i] = text_for_sentences[m + n];
                                                i++;
                                             }
                                   			}
                                				n++;
                                			}
                                			m += n;
                                    }
                             			n = 0;
                              			if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length){
                                			data_base_sentences[number_of_saved_sentences].sentence[i] = text_for_sentences[m];
                             			}
    	                     		}
		                        }
                        		p = 0;
                        		while(p < 101) {
                        			data_base_sentences[number_of_saved_sentences].input_to_find[p] = input[p];
                           		p++;
                        		}
                        		data_base_sentences[number_of_saved_inputs].number_of_sentences++;
                        		sentences_new_counter_for_last_input++;
                        		number_of_saved_sentences++;
                           }
                  		}

                  if((save_all_matches == true || scan_the_database == true) && sentences_new_counter_for_last_input == max_number_sentences_to_save)
            	  		input_repeatings_counter = 0;

                  if(scan_the_database == true)
                  	max_number_sentences_to_save = 1000;


                  if(auto_increase == true && maximum_sentence_length < maximum_sentence_length_to_increase_to && (save_all_matches == true || scan_the_database == true)
                  && sentences_new_counter_for_last_input < max_number_sentences_to_save
                  && sentences_new_counter_for_last_input < copy_input_repeatings_counter && input_repeatings_counter == 0) {
                     f = 0;
                     for(i = number_of_saved_sentences - sentences_new_counter_for_last_input; i <= number_of_saved_sentences; i++) {
                     	while(f < 101) {
            					data_base_sentences[i].input_to_find[f] = ' ';
                  			f++;
               			}
               			while(g < 1001) {
               				data_base_sentences[i].sentence[g] = ' ';
                  			g++;
               			}
                     	data_base_sentences[i].number_of_sentences = 0;
               			f = 0;
               			g = 0;
            			}
                     number_of_saved_sentences -= sentences_new_counter_for_last_input;
                     maximum_sentence_length += increaser;
                     sentences_new_counter_for_last_input = 0;
                     sentences_counter_for_last_input = 0;
                     input_letters_counter = 0;
                     text_letters_counter = 0;
                     i = 0;
                     expression_counter = 0;
                     expression_index = 0;
                     counter_for_number_of_sentences = 0;
                     length_of_finished_part_of_text = 0;
                     index = 0;
                     input_repeatings_counter = copy_input_repeatings_counter;
                     continue;
                  }

                  if(input_repeatings_counter == 0) {
                     if(show_all_matches == false)
                        clrscr();
                     	if(show_all_matches == true) {
                        	if((sentences_counter_for_last_input) % max_number_sentences_to_show != 0) {
                           	cout << "\nSPACE - continue";
                           	cout << "\nTAB - return to the main menu";
                           	cout << "\nBACKSPACE - enter an other word or phrase";
                           	if(number_of_saved_sentences > 0)
      									cout << "\nESCAPE - save and exit the program";
               					else
               						cout << "\nESCAPE - exit the program";
                        		choice = ' ';
                        		while(1) {
                        			choice = getch();
                        			if(choice == 32)
                        				break;
                        			if(choice == 9)
                        				break;
                        			if(choice == 8)
                        				break;
                        			if(choice == 27)
                        				break;
                        		}
                        		clearscreen();
                           }
                        }
                     if(save_all_matches == false && scan_the_database == false)
                     	if(choice == 32 || choice == 13) {
                        	clrscr();
                           cout << "there are no more matches\n\n";
                        }
                     if(choice == 9) {
                     	text_letters_counter = real_text_length_for_expressions;
                        break;
                     }
                  	if(choice == 8) {
                     	text_letters_counter = real_text_length_for_expressions;
                     	break;
                  	}
                  	if(choice == 27) {
                     	text_letters_counter = real_text_length_for_expressions;
                    	 	break;
                  	}
                     if(save_all_matches == true || scan_the_database == true) {
                        if(save_all_matches == true)
                     		cout << "saving is completed\n\n";
                        if(scan_the_database == true)
                        	cout <<"scanning is completed\n\n";
                     }

                     if(scan_the_database == false) {
                     	if(sentences_counter_for_last_input == 1)
                        	if(show_all_matches == true)
                           	cout << "0 sentences saved with the last input\n\n";
                        	else
                           	cout << sentences_counter_for_last_input << " sentence saved with the last input\n\n";
                     	if(sentences_counter_for_last_input != 1)
                        	if(show_all_matches == true)
                           	cout << "0 sentences saved with the last input\n\n";
                        	else
                           	cout << sentences_counter_for_last_input << " sentences saved with the last input\n\n";
                     	if(number_of_saved_sentences == 1)
                        	cout << number_of_saved_sentences << " sentence saved in total";
                     	if(number_of_saved_sentences != 1)
                        	cout << number_of_saved_sentences << " sentences saved in total";
                     	cout << "\n\n";
                     	cout << "TAB - return to the previous menu\n";
                     	cout << "BACKSPACE - enter an other word or phrase\n";
                     	if(number_of_saved_sentences > 0)
      							cout << "ESCAPE - save and exit the program";
               			else
               				cout << "ESCAPE - exit the program";
                     }
                     else {
                        if(sentences_counter_for_last_input == 1)
                     		cout << sentences_counter_for_last_input << " sentence found";
                        else
                        	cout << sentences_counter_for_last_input << " sentences found";
                     	sentences_counter_for_last_input = 0;
                        cout << "\n\n";
                     	cout << "TAB - return to the previous menu\n";
                     	cout << "BACKSPACE - enter an other word or phrase\n";
                     	if(number_of_saved_sentences > 0)
      							cout << "ESCAPE - save and exit the program";
               			else
               				cout << "ESCAPE - exit the program";
                     }
                  	choice = ' ';
                  	while(1) {
                  		choice = getch();
                  		if(choice == 9) {
                     		text_letters_counter = real_text_length_for_expressions;
                     		break;
                  		}
                  		if(choice == 8) {
                     		text_letters_counter = real_text_length_for_expressions;
                     		break;
                  		}
                  		if(choice == 27) {
                     		text_letters_counter = real_text_length_for_expressions;
                     		break;
                  		}
                  	}
                  }

                  text_letters_counter += input_letters_counter + forward_to_end_sentence_counter;

               }
            }

         	else {
            	while(text_for_words[text_letters_counter] != ' ')
        	   		text_letters_counter++;
         		break;
         	}
       	}
   	}

   	save_all_matches = false;
   	show_all_matches = false;
      scan_the_database = false;

   	if(choice == 27)
      	break;
   }
   if(number_of_saved_sentences > 0)
      save_sentences();
}

/*
void thesaurus()
{
   int j,
       g = 0,
       f = 0,
       p = 0,
       input_letters_counter = 0,
       back_to_beginning_sentence_counter = 0,
       forward_to_end_sentence_counter = 0,
       sentence_length,
       maximum_sentence_length = 79,
       minimum_sentence_length = 20,
       copy_maximum_sentence_length = 79,
       maximum_sentence_length_to_increase_to = 0,
       max_number_sentences_to_save = 5,
       max_number_sentences_to_show = 10,
       sentences_new_counter_for_last_input = 0,
       symbols_counter = 0,
   	 copy_symbols_counter = 0,
       y,
       increaser = 0;

   long counter_for_number_of_sentences = 0,
   	  copy_input_repeatings_counter = 0,
   	  input_repeatings_counter = 0,
        expression_counter = 0,
        expression_index = 0,
        matches_remained,
        i,
        sentences_counter_for_last_input = 0,
        text_letters_counter = 0,
        m,
        n,
        stack_counter = 0,
        bbb = 0,
        real_text_length_for_expressions,
        length_of_finished_part_of_text = 0,
        index = 0;

   char current_input[101],
        choice,
        answer,
        *save_input_in_capital_letters = "on",
        *cut_sentences_after_79th_symbol = "on",
        *asterisk_symbol = "on",
        *numbering = "on",
        *increasing = "off",
        *filter = "on";

   bool save_all_matches = false,
        show_all_matches = false,
        save_in_capital = true,
        flag = false,
        first_pass = true,
        stack_flag = true,
        difficulty_score = true,
        flag_podgon = false,
        filter_flag = true,
        filter_option = true;


//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD bufferSize = {80, 44};
   SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);

//------------------------------------------------------------------------------

   CONSOLE_CURSOR_INFO cciInfo;
   cciInfo.dwSize = 20;
   cciInfo.bVisible = true;
   SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

//------------------------------------------------------------------------------

   clrscr();
   if(thesaurus_expressions == true) {    //big podgon
      i = 0;
   	j = 0;
   	while(i < copy_real_text_length) {
      	while(common_text[i] == ' ' && common_text[i + 1] == ' ') {
         	i++;
      	}
      	text_for_sentences[j] = common_text[i];
      	i++;
      	j++;
   	}
   	i = 0;
   	while(i < copy_real_text_length) {
      	text_for_expressions[i] = text_for_words[i];
      	i++;
   	}
   }

   i = 0;
   j = 0;

   //initializing_text_test();  podgon otsuda ne rabotayet
   //load_stack_words_data();

   copy_counter_for_different_repeatings = counter_for_different_repeatings;
   auto_increase = false;

   while(i < 102) { // podgon
   	input[i] = ' ';
      i++;
   }

   while(1) {
      while(1) {
   		sentences_counter_for_last_input = 0;
   		input_letters_counter = 0;
   		text_letters_counter = 0;
   		i = 0;
   		expression_counter = 0;
   		expression_index = 0;
   		if(choice != 9) {
      		input_repeatings_counter = 0;
      		j = 0;
   		}
   		else
      		input_repeatings_counter = copy_input_repeatings_counter;

      counter_for_number_of_sentences = 0;
   	length_of_finished_part_of_text = 0;
   	index = 0;
   	save_all_matches = false;
   	show_all_matches = false;

   	if(choice != 9 && flag == true) {
   		while(1) {
   			while(i < 102) { //podgon
   				input[i] = ' ';
      			i++;
   			}

            cciInfo.bVisible = true;
            SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

            if(first_pass == true) {
                        first_pass = false;
                  		clrscr();
            }
            gotoxy(1, 1);
            cout << "saving...\n\n";
            if(thesaurus_expressions == true)
            	cout << counter_for_different_repeatings << " expressions remained                \n\n";
            if(thesaurus_words == true)
            	cout << counter_for_different_repeatings << " words remained                \n\n";
            cout << number_of_saved_sentences << " sentences saved";
            first_pass = false;

            if(counter_for_different_repeatings == 0) {
               flag = false;
               cciInfo.bVisible = false;
   				SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
               gotoxy(1, 1);
               cout << "saving is completed\n\n"; //megapodgon
               gotoxy(1, 8);
               cout << "press any key to return to the main menu";
               getch();
               break;
            }

            if(thesaurus_expressions == true) {
              while(data_base_expressions[stack_counter][1].expression[0] == ' ')
               	stack_counter++;
              while(strcmp(data_base_expressions[stack_counter][1].expression, data_base_expressions[stack_counter - 1][1].expression) == 0)
               	stack_counter++;
              while(!(data_base_expressions[stack_counter][1].expression[input_letters_counter] == ' '
            		&& data_base_expressions[stack_counter][1].expression[input_letters_counter + 1] == ' ')) {
               		input[input_letters_counter] = data_base_expressions[stack_counter][1].expression[input_letters_counter];
      					j++;
      					input_letters_counter++;
   					}
               if(input[0] != ' ') {
               	stack_counter++;
            		counter_for_different_repeatings--;
               }
               maximum_sentence_length = copy_maximum_sentence_length;
           }

            if(thesaurus_words == true)   {
               while(data_base_words[stack_counter].word[0] == ' ')
                  stack_counter++;
               while(strcmp(data_base_words[stack_counter].word, data_base_words[stack_counter - 1].word) == 0)
                  stack_counter++;
               while(data_base_words[stack_counter].word[input_letters_counter] != ' ') {
                  input[input_letters_counter] = data_base_words[stack_counter].word[input_letters_counter];
                  j++;
                  input_letters_counter++;
               }
               if(input[0] != ' ') {
                  stack_counter++;
                  counter_for_different_repeatings--;
               }
               maximum_sentence_length = copy_maximum_sentence_length;
            }

   			real_text_length_for_expressions = copy_real_text_length;
   			input_letters_counter = 0;

   			for(text_letters_counter = 0; text_letters_counter < real_text_length_for_expressions; text_letters_counter ++) {
      			input_letters_counter = 0;
         		back_to_beginning_sentence_counter = 0;
         		forward_to_end_sentence_counter = 0;
      			while(input_letters_counter < j) {
   					if(input[input_letters_counter] == text_for_expressions[text_letters_counter + input_letters_counter]) {
            			input_letters_counter++;
               		if(input_letters_counter == j && text_for_expressions[text_letters_counter + input_letters_counter] == ' '
                     && (text_for_expressions[text_letters_counter - 1] == ' ' || text_letters_counter == 0)) {
                  		input_repeatings_counter++;
               		}
            		}
               	else {
            			while(text_for_expressions[text_letters_counter] != ' ')
        	   				text_letters_counter++;
         				break;
         	  		}
      			}
   			}

            cciInfo.bVisible = false;
            SetConsoleCursorInfo(hConsoleOutput, &cciInfo);

   			copy_input_repeatings_counter = input_repeatings_counter;
   			if(input_repeatings_counter > 0) {
            	check_input_flag = true;
      			break;
            }
   			else {
      			input_letters_counter = 0;
   				sentences_counter_for_last_input = 0;
               text_letters_counter = 0;
   				expression_counter = 0;
  	 				expression_index = 0;
   				input_repeatings_counter = 0;
   				counter_for_number_of_sentences = 0;
               length_of_finished_part_of_text = 0;
   				index = 0;
   				j = 0;
   				save_all_matches = false;
   				show_all_matches = false;

         		while(1) {
                  if(stack_counter <= counter_for_different_repeatings)
         				choice = 8;
         			if(choice == 8)
            			break;
         			if(choice == 27)
            			break;
      			}
      			while(i < 101) {
   	   			input[i] = ' ';
         			i++;
      			}
   			}

      		if(choice == 8)
            	continue;
      		if(choice == 27)
            	break;
   		}
   		if(choice == 27)
            break;
 		}

 		while(1) {
      	check_input_flag = false;
         cciInfo.bVisible = false;
         SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
         COORD bufferSize = {80, 44};
		   SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);

         if(flag == false) {
         	clrscr();
            stack_counter = 0;
            if(stack_words_flag == true)
            	stack_counter++;
            if(stack_expressions_flag == true)
            	stack_counter += 2;
            counter_for_different_repeatings = copy_counter_for_different_repeatings;
            first_pass = true;

            if(counter_for_different_repeatings > 0) {
            	if(thesaurus_expressions == true)
            		cout << "the text contains " << counter_for_different_repeatings << " expressions\n\n";
            	if(thesaurus_words == true)
            		cout << "the text contains " << counter_for_different_repeatings << " words\n\n";
               if(number_of_saved_sentences > 0) {
            		if(number_of_saved_sentences == 1)
      					cout << number_of_saved_sentences << " sentence saved\n\n";
   	  				if(number_of_saved_sentences != 1)
               		if(thesaurus_expressions == true)
        						cout << number_of_saved_sentences << " sentences saved for " << inputs_counter << " expressions\n\n";
               		else
               			cout << number_of_saved_sentences << " sentences saved for " << inputs_counter << " words\n\n";
               }
            }

            if((thesaurus_words == true || thesaurus_expressions == true) && text_location[0] != ' ') {
   				cout << "1 - change the minimum sentence length (" << minimum_sentence_length << ")\n";
               if(auto_increase == true) {
         			SetConsoleTextAttribute(hConsoleOutput, 55);
            		cout << "2 - change the maximum sentence length (" << maximum_sentence_length << ")\n";
         		}
         	else
   				cout << "2 - change the maximum sentence length (" << maximum_sentence_length << ")\n";
               SetConsoleTextAttribute(hConsoleOutput, 63);
            	if(thesaurus_words == true)
   					cout << "3 - save words in capital letters (" << save_input_in_capital_letters << ")\n";
            	if(thesaurus_expressions == true)
   					cout << "3 - save expressions in capital letters (" << save_input_in_capital_letters << ")\n";

            	if(number_of_saved_sentences == 0) {
         			SetConsoleTextAttribute(hConsoleOutput, 55);
   					cout << "6 - show saved sentences\n";
   					cout << "7 - delete all saved sentences\n";
         		}
         		else {
            		SetConsoleTextAttribute(hConsoleOutput, 63);
   					cout << "6 - show saved sentences\n";
         			cout << "7 - delete all saved sentences\n";
         		}
         		SetConsoleTextAttribute(hConsoleOutput, 63);
            	if(thesaurus_words == true)
         			cout << "9 - change the maximum number of sentences to save per word (" << max_number_sentences_to_save << ")\n";
            	if(thesaurus_words == true || thesaurus_expressions == true)
         			cout << "0 - cut sentences after 79th symbol including index number when saving (" << cut_sentences_after_79th_symbol << ")\n";
            	if(thesaurus_expressions == true)
         			cout << "9 - change the maximum number of sentences to save per expression (" << max_number_sentences_to_save << ")\n";
            	if(thesaurus_words == true)
            		cout << "A - put the asterisk before the words (" << asterisk_symbol << ")\n";
            	if(thesaurus_expressions == true)
            		cout << "A - put the asterisk before the expressions (" << asterisk_symbol << ")\n";
               cout << "D - find sentences by the score range (" << minimum_words_score << " - " << maximum_words_score << ")\n";
               cout << "F - filter out the sentences which do not begin with capital letters (" << filter << ")\n";
               if(auto_increase == true)
         			cout << "I - sentence auto increase (option 5) / increase by (" << increaser << ") / increase to ("
               	<< maximum_sentence_length_to_increase_to << ")\n";
         		else
         			cout << "I - sentence auto increase ("<< increasing << ")\n";
            	if(thesaurus_words == true)
            		cout << "N - number the words (" << numbering << ")\n";
            	if(thesaurus_expressions == true)
            		cout << "N - number the expressions (" << numbering << ")\n";
            }

            if((thesaurus_words == true || thesaurus_expressions == true) && text_location[0] != ' ') {
            	cout << "R - restore default settings\n";
            	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
            }
            if(thesaurus_words == true) {
            	cout << "W - load the words' database file ";
               SetConsoleTextAttribute(hConsoleOutput, 14);
               cout << "(" << text_location_words_expressions_for_thesaurus << ")\n";
               SetConsoleTextAttribute(hConsoleOutput, 63);
            }
            if(thesaurus_words == false)
            	cout << "W - load the words' database file (no file)\n";
            if(thesaurus_expressions == true) {
            	cout << "E - load the expressions' database file ";
               SetConsoleTextAttribute(hConsoleOutput, 14);
               cout << "(" << text_location_words_expressions_for_thesaurus << ")\n";
               SetConsoleTextAttribute(hConsoleOutput, 63);
            }
            if(thesaurus_expressions == false)
            	cout << "E - load the expressions' database file (no file)\n";
            if(thesaurus_words == true || thesaurus_expressions == true) {
            	if(text_location[0] != ' ') {
            		cout << "S - load the sentences' database file ";
                  SetConsoleTextAttribute(hConsoleOutput, 14);
                  cout << "(" << text_location << ")\n";
                  SetConsoleTextAttribute(hConsoleOutput, 63);
               }
            	else
            		cout << "S - load the sentences' database file (no file)\n";
            }
            if(thesaurus_words == false && thesaurus_expressions == false) {
               SetConsoleTextAttribute(hConsoleOutput, 55);
            	cout << "S - load the sentences' database file (no file)\n";
               SetConsoleTextAttribute(hConsoleOutput, 63);
            }
				cout << "\n";
            if((thesaurus_words == true || thesaurus_expressions == true) && text_location[0] != ' ')
   				cout << "ENTER - start saving\n";
            if(number_of_saved_sentences > 0)
   				cout << "ESCAPE - save and exit the program";
            else
               cout << "ESCAPE - exit the program";
         }
      	while(1) {
            if(flag == true)
   				choice = 13;
            else
            	choice = getch();
            if((thesaurus_words == true || thesaurus_expressions == true) && text_location[0] != ' ') {
            	if(choice == 49) {
            		clrscr();
               	cciInfo.bVisible = true;
               	SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
               	cout << "enter the minimum sentence length ";
               	cin >> minimum_sentence_length;
               	while(minimum_sentence_length < 1 || minimum_sentence_length > maximum_sentence_length) {
                  	if(minimum_sentence_length < 1 ) {
                     	clrscr();
               			cout << "the minimum sentence length must be 1 at least\n\n";
               			cout << "enter the minimum sentence length ";
               			cin >> minimum_sentence_length;
            			}
            			if(minimum_sentence_length > maximum_sentence_length) {
               			clrscr();
               			cout << "the minimum sentence length must be less than the maximum one (" << maximum_sentence_length << ")\n\n";
               			cout << "enter the minimum sentence length ";
               			cin >> minimum_sentence_length;
            			}
         			}
            	break;
   			}

   			if(choice == 50 && auto_increase == false) {
      			clrscr();
               cciInfo.bVisible = true;
               SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
      			cout << "enter the maximum sentence length ";
      			cin >> maximum_sentence_length;
      			while(maximum_sentence_length > 1000 || maximum_sentence_length < minimum_sentence_length) {
            		if(maximum_sentence_length > 1000 ) {
               		clrscr();
                  	cout << "the maximum sentence length must be 1000 at most\n\n";
                  	cout << "enter the maximum sentence length ";
               		cin >> maximum_sentence_length;
            		}
            		if(maximum_sentence_length < minimum_sentence_length) {
               		clrscr();
               		cout << "the maximum sentence length must be more than the minimum one (" << minimum_sentence_length << ")\n\n";
               		cout << "enter the maximum sentence length ";
               		cin >> maximum_sentence_length;
            		}
         		}
               copy_maximum_sentence_length = maximum_sentence_length;
      			break;
   			}

   			if(choice == 54 && number_of_saved_sentences > 0) {
   				show_saved_sentences();
      			HANDLE hConsoleOutput;
   				hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   				COORD bufferSize = {80, 21000};
   				SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);
      			break;
   			}

   			if(choice == 57) {
   				clrscr();
               cciInfo.bVisible = true;
               SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
               if(thesaurus_words == true)
      				cout << "enter the maximum number of sentences to save per word ";
               if(thesaurus_expressions == true)
      				cout << "enter the maximum number of sentences to save per expression ";
      			cin >> max_number_sentences_to_save;
      			while(1) {
      				if(max_number_sentences_to_save < 1 || max_number_sentences_to_save > 1000) {
            			clrscr();
         				cout << "the number must be more then 0 and less then 1001\n\n";
                     if(thesaurus_words == true)
      						cout << "enter the maximum number of sentences to save per word ";
               		if(thesaurus_expressions == true)
      						cout << "enter the maximum number of sentences to save per expression ";
            			cout << "enter the maximum number of sentences to save per word ";
            			cin >> max_number_sentences_to_save;
         			}
         			else
         				break;
      			}
      			break;
   			}

   			if(choice == 55 && number_of_saved_sentences > 0) {
      			clrscr();
      			cout << "are you sure you want to delete all saved sentences? (y/n) ";
               while(1) {
               	answer = getch();
                  if(answer == 'y') {
                  	cout << "\n\n";
                     cout << "deleting...";
                     for(i = 0; i < number_of_saved_sentences; i++) {
                     	while(f < 101) {
            					data_base_sentences[i].input_to_find[f] = ' ';
                  			f++;
               			}
               			while(g < 1001) {
               				data_base_sentences[i].sentence[g] = ' ';
                  			g++;
               			}
                     	data_base_sentences[i].number_of_sentences = 0;
               			f = 0;
               			g = 0;
            			}
            			sentences_counter_for_last_input = 0;
            			number_of_saved_sentences = 0;
                     inputs_counter = 0;
            			break;
         			}
         			if(answer == 'n')
         				break;
            	}
      			break;
   			}

   			if(choice == 13) {
      			save_all_matches = true;
               flag = true;
      			break;
   			}

   			if(choice == 51) {
      			if(save_in_capital == true) {
      				save_in_capital = false;
         			save_input_in_capital_letters = "off";
      			}
      			else {
      				save_in_capital = true;
         			save_input_in_capital_letters = "on";
      			}
      			break;
   			}

            if(choice == 48) {
      			if(cut_sentences == true) {
      				cut_sentences = false;
         			cut_sentences_after_79th_symbol = "off";
      			}
      			else {
      				cut_sentences = true;
         			cut_sentences_after_79th_symbol = "on";
      			}
      			break;
   			}

            if(choice == 'a') {
      			if(asterisk == true) {
      				asterisk = false;
         			asterisk_symbol = "off";
      			}
      			else {
      				asterisk = true;
         			asterisk_symbol = "on";
      			}
      			break;
   			}

            if(choice == 'n') {
      			if(number_the_inputs == true) {
      				number_the_inputs = false;
         			numbering = "off";
      			}
      			else {
      				number_the_inputs = true;
         			numbering = "on";
      			}
      			break;
   			}

            if(choice == 77 && ((maximum_sentence_length + 10) <= 1000) && auto_increase == false) {
            	maximum_sentence_length += 10;
               if(choice == 77 && ((maximum_sentence_length + 10) > 1000) && auto_increase == false)
               	maximum_sentence_length = 1000;
               break;
            }

            if(choice == 75 && ((maximum_sentence_length - 10) > minimum_sentence_length) && auto_increase == false) {
            	maximum_sentence_length -= 10;
               break;
            }

            if(choice == 'i') {
      			if(auto_increase == true) {
      				auto_increase = false;
                  maximum_sentence_length_to_increase_to = 0;
                  increaser = 0;
         			increasing = "off";
                  if(maximum_sentence_length == 20)
                  	maximum_sentence_length = 79;
      			}
      			else {
      				auto_increase = true;
                  maximum_sentence_length = minimum_sentence_length;
         			increasing = "on";
                  clrscr();
                  cciInfo.bVisible = true;
               	SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
                  cout << "enter the number of symbols to increase the sentence length each time ";
                  cin >> increaser;
                  while(increaser < 1 || increaser > 500) {
                  	clrscr();
                  	cout << "the number of symbols to increase the sentence length must be between 1 and 500\n\n";
                     cin >> increaser;
                  }
                  clrscr();
      				cout << "enter the maximum sentence length to increase to ";
      				cin >> maximum_sentence_length_to_increase_to;
      				while(maximum_sentence_length_to_increase_to > 1000 || maximum_sentence_length_to_increase_to < maximum_sentence_length
                  || maximum_sentence_length_to_increase_to < maximum_sentence_length) {
            			if(maximum_sentence_length_to_increase_to > 1000 ) {
               			clrscr();
                  		cout << "the maximum sentence length to increase to must be 1000 at most\n\n";
                  		cout << "enter the maximum sentence length to increase to ";
               			cin >> maximum_sentence_length_to_increase_to;
            			}
            			if(maximum_sentence_length_to_increase_to < minimum_sentence_length) {
               			clrscr();
               			cout << "the maximum sentence length must be more than the minimum one (" << minimum_sentence_length << ")\n\n";
               			cout << "enter the maximum sentence length to increase to ";
               			cin >> maximum_sentence_length_to_increase_to;
            			}
         			}
      			}
      			break;
   			}
         } //?

            if(choice == 'f' && counter_for_different_repeatings > 0) {
      			if(filter_option == true) {
      				filter_option = false;
         			filter = "off";
      			}
      			else {
      				filter_option = true;
         			filter = "on";
      			}
      			break;
   			}

            if(choice == 'w' || choice == 'e') {
     				counter_for_different_repeatings = 0;
	  				copy_counter_for_different_repeatings;
     				total_words_counter = 0;
     				copy_real_text_length = 0;
     				i;
     				buffer_word_counter = 0;
     				letters_counter = 0;
     				copy_space_counter = 0;
     				word_counter = 0;
               real_text_length_for_words = 0;
     				total_text_counter = 0;
     				space_counter = 0;
     				buffer_counter = 0;
     				i_counter = 0;
     				counter_for_different_words = 0;
     				expr_rep_counter = 0;
               file_size = 0;
     				number_of_saved_sentences = 0;
               number_of_saved_inputs = 0;
     				number_of_text_segments = 0;
     				inputs_counter = 0;

            	if(choice == 'w') {
     					thesaurus_function = true;
     					thesaurus_words = true;
               	thesaurus_expressions = false;
               	//initialiazing_words_expressions_for_thesaurus();
               	//filtrating_flag = filtratings_words_expressions_for_thesaurus();
                  if(filtrating_flag == 2)
                  	choice = 27;
                  if(filtrating_flag == 1) {
                     choice = 27; //podgon
                     thesaurus_words = false;
                  	thesaurus();
                  }
                  if(filtrating_flag == 0) {
            			//find_words();
               		//save_print_words();
               		sentences_alignment();
               		choice = 27;  //podgon
               		thesaurus();  //podgon
                  }
            	}

               if(choice == 'e') {
     					thesaurus_function = true;
     					thesaurus_expressions = true;
               	thesaurus_words = false;
               	//initialiazing_words_expressions_for_thesaurus();
               	//filtrating_flag = filtratings_words_expressions_for_thesaurus();
                  if(filtrating_flag == 2)
                  	choice = 27;
                  if(filtrating_flag == 1) {
                     choice = 27; //podgon
                     thesaurus_expressions = false;
                  	thesaurus();
                  }
                  if(filtrating_flag == 0) {
            			//find_expressions();
               		//save_print_expressions();
               		sentences_alignment();
               		choice = 27; //podgon
               		thesaurus(); //podgon
                  }
               }
               break;
            }

            if(choice == 's') {
     				counter_for_different_repeatings = 0;
	  				copy_counter_for_different_repeatings;
     				total_words_counter = 0;
     				copy_real_text_length = 0;
     				buffer_word_counter = 0;
     				letters_counter = 0;
     				copy_space_counter = 0;
     				word_counter = 0;
     				real_text_length_for_words = 0;
     				total_text_counter = 0;
     				space_counter = 0;
     				buffer_counter = 0;
     				i_counter = 0;
     				counter_for_different_words = 0;
     				expr_rep_counter = 0;
     				file_size = 0;
     				number_of_saved_sentences = 0;
     				number_of_saved_inputs = 0;
     				number_of_text_segments = 0;
     				inputs_counter = 0;
               initialiazing_sentences();
               filtrating();
               break;
            }

            if(choice == 'd') {
            	clrscr();
               cciInfo.bVisible = true;
               SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
               cout << "enter the minimum words' score ";
               cin >> minimum_words_score;
               	while(minimum_words_score < 0 || minimum_words_score > maximum_words_score) {
                  	if(minimum_words_score < 0 ) {
                     	clrscr();
               			cout << "the minimum words' score must be 0 at least\n\n";
               			cout << "enter the minimum words' score ";
               			cin >> minimum_words_score;
            			}
            			if(minimum_words_score > maximum_words_score) {
               			clrscr();
               			cout << "the minimum words' score must be less than the maximum one (" << maximum_words_score << ")\n\n";
               			cout << "enter the minimum words' score ";
               			cin >> minimum_words_score;
            			}
         			}
      			break;
   			}

            if(choice == 'r') {
               minimum_sentence_length = 20;
               maximum_sentence_length = 79;
               save_in_capital = true;
               save_input_in_capital_letters = "on";
               max_number_sentences_to_show = 10;
               max_number_sentences_to_save = 5;
               cut_sentences = true;
               cut_sentences_after_79th_symbol = "on";
               asterisk = true;
               asterisk_symbol = "on";
               number_the_inputs = true;
               numbering = "on";
               auto_increase = false;
               maximum_sentence_length_to_increase_to = 0;
               increaser = 0;
               increasing = "off";
               minimum_words_score = 0;
               filter = "on";
               filter_flag = false;
               break;
            }

            if(thesaurus_words == true || thesaurus_expressions == true) {
   				if(choice == 13)
      				break;
            }

   			if(choice == 27)
      			break;
   		}

   		if(choice == 13)
      		break;

   		if(choice == 27)
      		break;
   	}

   	if(choice == 13)
      	break;

   	if(choice == 27)
      	break;
   }
   if(choice == 27)
      break;

   sentences_new_counter_for_last_input = 0;
   sentences_counter_for_last_input = 0;
   input_letters_counter;
   text_letters_counter;
   expression_counter = 0;
   expression_index = 0;
   counter_for_number_of_sentences = 0;
   length_of_finished_part_of_text = 0;
   index = 0;

   for(text_letters_counter = 0; text_letters_counter < real_text_length_for_expressions; text_letters_counter++) {
   	input_letters_counter = 0;
      back_to_beginning_sentence_counter = 0;
      forward_to_end_sentence_counter = 0;
      while(input_letters_counter < j) {
      	if(input[input_letters_counter] == text_for_expressions[text_letters_counter + input_letters_counter]) {
         	input_letters_counter++;
            if(input_letters_counter == j && text_for_expressions[text_letters_counter + input_letters_counter] == ' '
            && (text_for_expressions[text_letters_counter - 1] == ' ' || text_letters_counter == 0)) {
            	number_of_saved_inputs++;
               while((text_letters_counter + input_letters_counter) >= back_to_beginning_sentence_counter
               && back_to_beginning_sentence_counter < 1000) {
               	back_to_beginning_sentence_counter++;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter - 1] == '.'
                  && text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == '"')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter - 1] == '!'
                  && text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == '"')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter - 1] == '?'
                  && text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == '"')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter - 1] == '.'
                  && text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == 39)
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter - 1] == '!'
                  && text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == 39)
                     break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter - 1] == '?'
                  && text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == 39)
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == '.')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == '!')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter] == '?')
                  	break;
               }
               while(forward_to_end_sentence_counter < (1000 - back_to_beginning_sentence_counter)) {
               	if(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '.'
                  && (!(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 1] == 'r'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 2] == 'M'))
                  &&
                  (text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '.')
                  && (!(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 1] == 's'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 2] == 'r'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 3] == 'M'))
                  &&
                  (text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '.')
                  && (!(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 1] == 't'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 2] == 'S'))
                  &&
                  (text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '.')
                  && (!(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 1] == 'T'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 2] == 'S'))
                  &&
                  (text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '.')
                  && (!(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 1] == 'r'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 2] == 'D'))
                  &&
                  (text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '.')
                  && (!(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 1] == 'R'
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter - 2] == 'D')))
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '!')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == '?')
                  	break;
                  if(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter] == ' '
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter + 1] == ' '
                  && text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter + 2] == ' ')
                  	break;
                  forward_to_end_sentence_counter++;
               }

               if(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter + 1] == '"')
                     forward_to_end_sentence_counter++;
               if(text_for_sentences[text_letters_counter + input_letters_counter + forward_to_end_sentence_counter + 1] == 39)
                     forward_to_end_sentence_counter++;


               sentence_length = back_to_beginning_sentence_counter + forward_to_end_sentence_counter;
               back_to_beginning_sentence_counter--;
               beginning_of_the_sentence = text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter;
               end_of_the_sentence = text_letters_counter + input_letters_counter + forward_to_end_sentence_counter;

               SetConsoleTextAttribute(hConsoleOutput, 240);
               n = 0;

               while(text_for_sentences[beginning_of_the_sentence] == ' ')
               	beginning_of_the_sentence++;

               symbols_counter = 0;
               copy_symbols_counter;

               if(filter_option == true) {
               	if((text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90)
               	|| (text_for_sentences[beginning_of_the_sentence + 1] >= 65 && text_for_sentences[beginning_of_the_sentence + 1] <= 90))
               		filter_flag = true;
               	else
               		filter_flag = false;
               }
               else
               	filter_flag = true;

               if(flag_podgon == false) { //po drugomu ne rabotayet voobshe
               	initializing_text_test();
               	load_stack_words_data();
               	flag_podgon = true;
               }

               if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length)
               	difficulty_score = words_of_the_sentence_difficulty_score();

               for(m = beginning_of_the_sentence; m <= end_of_the_sentence; m++) {
               	while(n < j) {
                  	if(input[n] == text_for_expressions[m + n])
                     	n++;
                     else {
                     	n = 0;
                        break;
                     }
                  }
                  if(n == j && text_for_expressions[m + n] == ' ' && (text_for_expressions[m - 1] == ' ' || m == 0)) {
                  	input_repeatings_counter--;
                     n = 0;
                     SetConsoleTextAttribute(hConsoleOutput, 224);

                     y = 1;

                     while(n < j) {
                     	if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true)
                        	//if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90)
                           	if(save_all_matches == false || show_all_matches  == true) {
                              symbols_counter++;
                                 if(text_for_sentences[m + n] == ' ') {
                                 	if(symbols_counter == 79)
                                    	cout << "\n";
                                    cout << text_for_sentences[m + n];
                                    copy_symbols_counter = symbols_counter;
                                 	while(text_for_sentences[m + n + y] != ' ') {
                                    	y++;
                                       symbols_counter++;
                                       if(symbols_counter == 79) {
                                 			cout << "\n";
                                          copy_symbols_counter = symbols_counter = 0;
                                       }
                                    }
                                    symbols_counter = copy_symbols_counter;
                                 }
                                 else {
                                 	cout << text_for_sentences[m + n];
                                 }
                              }

                        n++;
                     }
                        m += n;
                  }
                  n = 0;
                  SetConsoleTextAttribute(hConsoleOutput, 240);
                  y = 1;

                  if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true)
                  	//if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90)
                     	if(save_all_matches == false || show_all_matches  == true) {
                        	symbols_counter++;
                           	if(text_for_sentences[m + n] == ' ') {
                              	if(symbols_counter == 79)
                                 	cout << "\n";
                                 cout << text_for_sentences[m + n];
                                 copy_symbols_counter = symbols_counter;
                                 while(text_for_sentences[m + n + y] != ' ') {
                                 	y++;
                                    symbols_counter++;
                                    if(symbols_counter == 79) {
                                    	cout << "\n";
                                       copy_symbols_counter = symbols_counter = 0;
                                    }
                                 }
                                    symbols_counter = copy_symbols_counter;
                              }
                              else {
                              	cout << text_for_sentences[m + n];
                              }
                        }
                     	if(symbols_counter >= 79)
                     		symbols_counter = 0;
               }

               //if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90)
               	if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true)
                  	if(show_all_matches == true)
                     	cout << "\n\n";

               //if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90)
               	if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true)
                  	if(show_all_matches == true)
                     	if(sentences_counter_for_last_input != 0)
                        	if((sentences_counter_for_last_input + 1) % max_number_sentences_to_show == 0) {
                           	SetConsoleTextAttribute(hConsoleOutput, 63);
                              cout << "\nSPACE - continue";
                              cout << "\nTAB - return to the main menu";
                              cout << "\nBACKSPACE - enter an other word or phrase";
                              cout << "\nESCAPE - exit the program";
                              choice = ' ';
                              while(1) {
                                 choice = getch();
                                 if(choice == 32)
                                    break;
                                 if(choice == 9)
                                    break;
                                 if(choice == 8)
                                    break;
                                 if(choice == 27)
                                    break;
                              }
                              clearscreen();
                           }

                  SetConsoleTextAttribute(hConsoleOutput, 63);

                  if(show_all_matches == false && save_all_matches == false) {
					    	//if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90) {
                  		if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true) {
                           while(1) {
                     			choice = getch();
                     			if(choice == 13) {
                        			sentences_counter_for_last_input++;
                        			break;
                     			}
                     			if(choice == 32)
                        			break;
                     			if(choice == 9)
                        			break;
                     			if(choice == 8)
                        			break;
                     			if(choice == 27)
                        			break;
                  			}
                  		}
                  	}

                  if(save_all_matches == true && sentences_counter_for_last_input < max_number_sentences_to_save) {
                     choice = 13;
                  	if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true)
                     	//if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90)
                     		sentences_counter_for_last_input++;
                  }

                  if(show_all_matches == true) {
                     if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true)
                     	//if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90)
                        	sentences_counter_for_last_input++;
                  }

                  if(choice == 8) {
                     text_letters_counter = real_text_length_for_expressions;
                     break;
                  }

                  if(choice == 9) {
                     text_letters_counter = real_text_length_for_expressions;
                     break;
                  }

                  if(choice == 27) {
                     text_letters_counter = real_text_length_for_expressions;
                     break;
                  }

                  i = 0;

                  while(text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter + i] == ' ')
                  	i++;

                  beginning_of_the_sentence = text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter + i;
                  i = 0;

                  if(choice == 13)
                  		if(show_all_matches == false) {
                  			//if(text_for_sentences[beginning_of_the_sentence] >= 65 && text_for_sentences[beginning_of_the_sentence] <= 90) {
                     			if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length && difficulty_score == true && filter_flag == true) {
                        			if(save_in_capital == false)
                        				while(i < sentence_length) {
                           				data_base_sentences[number_of_saved_sentences].sentence[i]
                           				= text_for_sentences[text_letters_counter + input_letters_counter - back_to_beginning_sentence_counter + i];
                           				i++;
                        				}
                        			if(save_in_capital == true) {
                        				n = 0;
                        				while(text_for_sentences[beginning_of_the_sentence] == ' ')
                           				beginning_of_the_sentence++;
                        				for(m = beginning_of_the_sentence; m <= end_of_the_sentence; m++) {
                           				i++;
                             			while(n < j) {
                                			if(input[n] == text_for_expressions[m + n])
            	                    			n++;
                                			else {
                                  			n = 0;
                                  			break;
                                       }
                             			}
                             			if(n == j && text_for_expressions[m + n] == ' ' && (text_for_expressions[m - 1] == ' ' || m == 0)) {
                                			n = 0;
                                			while(n < j) {
                                   			if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length) {
                                      			if(text_for_sentences[m + n] >= 97 && text_for_sentences[m + n] <= 122) {
                                      	  			data_base_sentences[number_of_saved_sentences].sentence[i] = text_for_sentences[m + n];
                                         			data_base_sentences[number_of_saved_sentences].sentence[i] -= 32;
                                                i++;
                                      			}
                                      			else {
                                      				data_base_sentences[number_of_saved_sentences].sentence[i] = text_for_sentences[m + n];
                                                i++;
                                             }
                                   			}
                                				n++;
                                			}
                                			m += n;
                                    }
                             			n = 0;
                             			if(sentence_length <= maximum_sentence_length && sentence_length >= minimum_sentence_length){
                                			data_base_sentences[number_of_saved_sentences].sentence[i] = text_for_sentences[m];
                             			}
    	                     		}
                                 while(bbb < 101) {
                                 	current_input[bbb] = ' ';
                                 	bbb++;
                                 }
                              	if(strcmp(input, current_input) != 0)
                                 	inputs_counter++;
                                 strcpy(current_input, input);
		                        }
                        		p = 0;
                        		while(p < j) { //podgon, bilo 101 vmesto j
                        			data_base_sentences[number_of_saved_sentences].input_to_find[p] = input[p];
                           		p++;
                        		}
                              while(p < 101) { //podgon - prodoljenie predidushego
                              	data_base_sentences[number_of_saved_sentences].input_to_find[p] = ' ';
                                 p++;
                              }
                        		//data_base_sentences[number_of_saved_inputs].number_of_sentences++;  //podgon esli vklu4eno to vishibaet progu zdes
                        		sentences_new_counter_for_last_input++;
                        		number_of_saved_sentences++;
                           }
                  		}

                  if(sentences_new_counter_for_last_input == max_number_sentences_to_save)
            			input_repeatings_counter = 0;

                  if(auto_increase == true && maximum_sentence_length < maximum_sentence_length_to_increase_to && save_all_matches == true
                  && sentences_new_counter_for_last_input < max_number_sentences_to_save
                  && sentences_new_counter_for_last_input < copy_input_repeatings_counter && input_repeatings_counter == 0) {
                     f = 0;
                     for(i = number_of_saved_sentences - sentences_new_counter_for_last_input; i <= number_of_saved_sentences; i++) {
                     	while(f < 101) {
            					data_base_sentences[i].input_to_find[f] = ' ';
                  			f++;
               			}
               			while(g < 1001) {
               				data_base_sentences[i].sentence[g] = ' ';
                  			g++;
               			}
                     	data_base_sentences[i].number_of_sentences = 0;
               			f = 0;
               			g = 0;
            			}
                     number_of_saved_sentences -= sentences_new_counter_for_last_input;
                     maximum_sentence_length += increaser;
                     sentences_new_counter_for_last_input = 0;
                     sentences_counter_for_last_input = 0;
                     input_letters_counter = 0;
                     text_letters_counter = 0;
                     i;
                     expression_counter = 0;
                     expression_index = 0;
                     counter_for_number_of_sentences = 0;
                     length_of_finished_part_of_text = 0;
                     index = 0;
                     input_repeatings_counter = copy_input_repeatings_counter;
                     continue;
                  }

                  if(input_repeatings_counter == 0) {
                     	if(show_all_matches == true) {
                        	if((sentences_counter_for_last_input) % max_number_sentences_to_show != 0) {
                           	cout << "\nSPACE - continue";
                           	cout << "\nTAB - return to the main menu";
                           	cout << "\nBACKSPACE - enter an other word or phrase";
                           	cout << "\nESCAPE - exit the program";
                        		choice = ' ';
                        		while(1) {
                        			choice = getch();
                        			if(choice == 32)
                        				break;
                        			if(choice == 9)
                        				break;
                        			if(choice == 8)
                        				break;
                        			if(choice == 27)
                        				break;
                        		}
                        		clearscreen();
                           }
                        }

                     if(choice == 9) {
                     	text_letters_counter = real_text_length_for_expressions;
                        break;
                     }
                  	if(choice == 8) {
                     	text_letters_counter = real_text_length_for_expressions;
                     	break;
                  	}
                  	if(choice == 27) {
                     	text_letters_counter = real_text_length_for_expressions;
                    	 	break;
                  	}

                  	while(1) {
                  		choice = 8;
                  		if(choice == 9) {
                     		text_letters_counter = real_text_length_for_expressions;
                     		break;
                  		}
                  		if(choice == 8) {
                     		text_letters_counter = real_text_length_for_expressions;
                     		break;
                  		}
                  		if(choice == 27) {
                     		text_letters_counter = real_text_length_for_expressions;
                     		break;
                  		}
                  	}
                  }

                  text_letters_counter += input_letters_counter + forward_to_end_sentence_counter;

               }
            }

         	else {
            	while(text_for_expressions[text_letters_counter] != ' ')
        	   		text_letters_counter++;
         		break;
         	}
       	}
   	}

   	save_all_matches = false;
   	show_all_matches = false;

   	if(choice == 27)
      	break;
   }
   if(number_of_saved_sentences > 0)
      save_sentences();
}
*/


bool words_of_the_sentence_difficulty_score()
{
   int i = 0,
       j = 0,
   	 copy_beginning_of_the_sentence,
       copy_end_of_the_sentence;

    bool calculation_result;


   copy_beginning_of_the_sentence = beginning_of_the_sentence;
   copy_end_of_the_sentence = end_of_the_sentence;

   while(j < 200) {
   	while(i < 40) {
   		words_of_the_current_sentence[j].word[i] = ' ';
      	i++;
   	}
      i = 0;
   	j++;
   }

   j = 0;
   i = 0;

	while(copy_beginning_of_the_sentence <= copy_end_of_the_sentence) {
      if(text_for_expressions[copy_beginning_of_the_sentence] != ' ') {
      	words_of_the_current_sentence[j].word[i] = text_for_expressions[copy_beginning_of_the_sentence];
         i++;
      }
      else {
         i = 0;
         j++;
      }
      copy_beginning_of_the_sentence++;
   }

   total_words_in_the_current_sentence = j;
   calculation_result = words_of_the_sentence_difficulty_score_calculation();

   if(calculation_result == true)
   	return true;
   else
   	return false;
}


long words_of_the_sentence_difficulty_score_calculation()
{
   long i = 0,
   	  j = 0,
        input_score;

   long current_word_score = 0,
   	    temp_current_score = 70288;

   int calculation_result = 1,
       counter = 0;

   bool loop_flag = false;


   if(check_input_flag == true)
   while(j < 10) {
   	while(i < 40) {
   		words_of_the_current_input[j].word[i] = ' ';
      	i++;
   	}
      i = 0;
   	j++;
   }

   j = 0;
   i = 0;

   if(check_input_flag == true)
   while(counter < 101) {
      if(input[counter] != ' ') {
         words_of_the_current_input[j].word[i] = input[counter];
         i++;
      }
      else {
         i = 0;
         j++;
      }
      counter++;
   }

   i = 0;
   j = 0;

   while(j < 10) {
   	while(i < 39) {
         if(words_of_the_current_input[j].word[i] == '\0')
         	words_of_the_current_input[j].word[i] = ' ';
      	i++;
   	}
      i = 0;
   	j++;
   }

   j = 0;
   i = 0;

   if(check_input_flag == true) {
   	while(i < 10) {
			while(j < data_words_stack_counter) {
				if(strcmp(words_of_the_current_input[i].word, words_data_stack[j].word) == 0 && loop_flag == false) {
            	if(words_data_stack[j].word_score < temp_current_score)
            		temp_current_score = words_data_stack[j].word_score;
            	loop_flag = true;
         	}
         	j++;
      	}
      	i++;
      	j = 0;
      	loop_flag = false;
   	}
   	return temp_current_score;
   }

   if(check_input_flag == false)
   while(i < total_words_in_the_current_sentence) {
		while(j < data_words_stack_counter) {
			if(strcmp(words_of_the_current_sentence[i].word, words_data_stack[j].word) == 0 && loop_flag == false) {
         	if(words_data_stack[j].word_score < minimum_words_score) {
            	calculation_result = 0;
            //if(calculation_result == 0)
            	break;
            }
            loop_flag = true;
         }
         if(calculation_result == 0)
            	break;
         j++;
      }
      if(calculation_result == 0)
      	break;
      i++;
      j = 0;
      loop_flag = false;
   }

   if(calculation_result == 1)
   	return 1;
   else
   	return 0;
}


void show_saved_sentences()
{
   long i = 0,
   	  sentences_counter = 1;

   int j = 0,
       counter = 1;

//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD bufferSize = {80, 21000};
   SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);

//------------------------------------------------------------------------------

   clrscr();
   while(i < number_of_saved_sentences) {
   	while(1) {
      	if(counter == 1) {
            if(number_the_inputs == true)
      			cout << sentences_counter << "  ";
            if(asterisk == true)
            	cout << "*";
            cout << data_base_sentences[i].input_to_find << "\n\n\n";
         }
      		if(strcmp(data_base_sentences[i].input_to_find, data_base_sentences[i + 1].input_to_find) == 0) {
      			cout << "(" << counter << ")";
      		while(!(data_base_sentences[i].sentence[j] == ' ' && data_base_sentences[i].sentence[j + 1] == ' ')) {
      			cout << data_base_sentences[i].sentence[j];
         		j++;
      		}
      		cout << "\n\n";
      		j = 0;
      		counter++;
      		i++;
      	}
      	else {
      		cout << "(" << counter << ")";
      		while(!(data_base_sentences[i].sentence[j] == ' ' && data_base_sentences[i].sentence[j + 1] == ' ')) {
      			cout << data_base_sentences[i].sentence[j];
               j++;
      		}
      		cout << "\n";
      		j = 0;
      		break;
      	}
      }
   	i++;
   	counter = 1;
      sentences_counter++;
      cout << "--------------------------------------------------------------------------------";
      if(i < number_of_saved_sentences)
      	cout << "\n\n";
      else
      	cout << "\n\n";
   }
   cout << "press any key to return to the main menu";
   getch();
   clearscreen();
}


int save_sentences()
{
   long i = 0,
   	  c = 1;

   int j = 0,
       counter = 1;

   char counter_for_dest[10],
        number_for_dest[10];

   clrscr();
   cout << "creating the file...\n";

   if(thesaurus_function == true)
      destination_sentences = fopen("c:\\tutor\\output\\thesaurus.txt","wt");
   else
      destination_sentences = fopen("c:\\tutor\\output\\sentences.txt","wt");
   if(destination_sentences == NULL) {
   	cout << "error opening the destiation file! Program terminated!\n";
   	getch();
   	return(0);
   }
   if(thesaurus_function == true) {
   	if(thesaurus_words == true)
   		fputs("words = ", destination_sentences);
   	if(thesaurus_expressions == true)
      	fputs("expressions = ", destination_sentences);
   	itoa(inputs_counter, number_for_dest, 10);
   	fputs(number_for_dest, destination_sentences);
   	fputs("\nsentences = ", destination_sentences);
   	itoa(number_of_saved_sentences, number_for_dest, 10);
   	fputs(number_for_dest, destination_sentences);
   	fputc('\n', destination_sentences);
   	fputs("------------------------------------------------------------------------------------", destination_sentences);
   	fputc('\n', destination_sentences);
   	fputc('\n', destination_sentences);
   	fputc('\n', destination_sentences);
   }

   while(i < number_of_saved_sentences) {
   	while(1) {
      	if(counter == 1) {
         	if(number_the_inputs == true) {
            	itoa(c, counter_for_dest, 10);
               fputs(counter_for_dest, destination_sentences);
               fputc(' ', destination_sentences);
               fputc(' ', destination_sentences);
            }
            if(asterisk == true)
            	fputc('*', destination_sentences);
            fputs(data_base_sentences[i].input_to_find, destination_sentences);
            fputc('\n', destination_sentences);
            fputc('\n', destination_sentences);
            fputc('\n', destination_sentences);
         }
      	if(strcmp(data_base_sentences[i].input_to_find, data_base_sentences[i + 1].input_to_find) == 0) {
            fputc('(', destination_sentences);
            itoa(counter, counter_for_dest, 10);
            fputs(counter_for_dest, destination_sentences);
            fputc(')', destination_sentences);
      		while(!(data_base_sentences[i].sentence[j] == ' ' && data_base_sentences[i].sentence[j + 1] == ' ')) {
            	if(j % 79 == 0 && j != 0 && cut_sentences == true)
            		fputc('\n', destination_sentences);
               fputc(data_base_sentences[i].sentence[j], destination_sentences);
               j++;
      		}
            fputc('\n', destination_sentences);
            fputc('\n', destination_sentences);
      		j = 0;
      		counter++;
      		i++;
      	}
      	else {
            fputc('(', destination_sentences);
            itoa(counter, counter_for_dest, 10);
            fputs(counter_for_dest, destination_sentences);
            fputc(')', destination_sentences);
      		while(!(data_base_sentences[i].sentence[j] == ' ' && data_base_sentences[i].sentence[j + 1] == ' ')) {
               if(j % 79 == 0 && j != 0 && cut_sentences == true)
            		fputc('\n', destination_sentences);
               fputc(data_base_sentences[i].sentence[j], destination_sentences);
               j++;
      		}
            fputc('\n', destination_sentences);
      		j = 0;
            c++;
      		break;
      	}
      }
   	i++;
   	counter = 1;
      	fputs("------------------------------------------------------------------------------------", destination_sentences);
      	fputc('\n', destination_sentences);
      	fputc('\n', destination_sentences);
      	fputc('\n', destination_sentences);
   }
   return 0;
}


void clearscreen()
{
   HANDLE hConsoleOutput;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD bufferSize = {80, 21000};
   SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);

   gotoxy(1, 1);

	DWORD n;
   DWORD size;
   COORD coord = {0};
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
   GetConsoleScreenBufferInfo (h, &csbi);
   size = csbi.dwSize.X * csbi.dwSize.Y;
   FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
   GetConsoleScreenBufferInfo(h, &csbi);
   FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);
   SetConsoleCursorPosition(h, coord);
}

/*
int text_test()
{
   long j = 0,
        f = 0,
        different_words_counter_by_score = 0,
        min_words_score_for_text = 0;

   double absolute_text_index_all_words = 0,
          absolute_text_index_different_words = 0,
          relative_text_index_all_words = -1,
          relative_text_index_different_words =-1,
          total_words_repeatings = 0;


//------------------------------------------------------------------------------

   HANDLE hConsoleOutput;;
   CONSOLE_CURSOR_INFO cciInfo;
   cciInfo.dwSize = 20;
   cciInfo.bVisible = false;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

//------------------------------------------------------------------------------

	text_test_flag = true;
	find_words();

   if(words_flag == true) {
		save_print_words();
   	initializing_text_test();
   	load_stack_words_data();

      cout << "\nenter the minimum words' score (must be between 1 and 70288) ";
      while(min_words_score_for_text < 1 || min_words_score_for_text > 70288) {
         cciInfo.bVisible = true;
   		SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
      	cin >> min_words_score_for_text;
         if(min_words_score_for_text < 1 || min_words_score_for_text > 70288) {
            gotoxy(1, 6);
            cout << "wrong score! enter the minimum words' score (must be between 0 and 70288) ";
         }
         else {
            gotoxy(1, 6);
            cciInfo.bVisible = false;
   			SetConsoleCursorInfo(hConsoleOutput, &cciInfo);
            cout << "the minimum words' score = " << min_words_score_for_text << "                                                   ";
         	break;
         }
      }

   	cout << "\nprocessing the data...\n\n ";
      i = 0;

      if(counter_for_different_words >= 100) {
      	while(i < counter_for_different_words) {
      		while(j < data_words_stack_counter && f == 0) {
         		if(strcmp(data_base_words[i].word, words_data_stack[j].word) == 0 && words_data_stack[j].word_score <= min_words_score_for_text) {
            		absolute_text_index_all_words += words_data_stack[j].word_score * data_base_words[i].word_repeatings;
                  total_words_repeatings += data_base_words[i].word_repeatings;
               	absolute_text_index_different_words += words_data_stack[j].word_score;
                  different_words_counter_by_score++;
               	f = 1;
            	}
            	j++;
         	}
         	f = 0;
         	j = 0;
        	   i++;
      	}

         relative_text_index_all_words = 100 - (absolute_text_index_all_words / (total_words_repeatings * min_words_score_for_text)) * 100;
         relative_text_index_different_words = 100 - (absolute_text_index_different_words / (different_words_counter_by_score * min_words_score_for_text )) * 100;

   		gotoxy(1, 7);
   		cout <<"\nprocessing the data is completed                       \n\n";
         cout << "total words in the text found by the score = " << total_words_repeatings << "\n"; //endl;
         cout << "different words in the text found by the score = " << different_words_counter_by_score << "\n\n"; //endl;
   		cout << "relative text index = " << relative_text_index_all_words << "%";
      	cout << "\nrelative vocabulary index = " << relative_text_index_different_words << "%";
   		cout << "\n\n\npress any key to exit the program";
   		getch();
   		return 0;
      }
      else {
          gotoxy(1, 10);
          cout << "\ndata is not availible, number of different words in the text is less than 100";
          cout << "\n\n\npress any key to exit the program";
   		 getch();
          return 0;
      }
   }
   else
   	return 0;
}
*/


void initializing_text_test()
{
	int j = 0;


   for(i = 0; i < 100000; i++) {
   	words_data_stack[i].word_score = 0;
      while(j < 40) {
         words_data_stack[i].word[j] = ' ';
         j++;
      }
      j = 0;
   }

   for(i = 0; i < 5000000; i++) {
   	initial_words_data_array[i] = ' ';
      corrected_words_data_array[i] = ' ';
      if(i < 500000)
      	words_scores_data_array[i] = ' ';
   }

   for(i = 0; i < 40; i++)
      buffer_string_for_word_score[i] = ' ';
}


void load_stack_words_data()
{
   char ch;

   long initial_words_data_array_counter,
   	  words_scores_data_array_counter,
        ii = 0,
        jj = 0,
        j = 0,
        k = 0;

   bool word_score_flag = false;


   i = 0;

   source_words_data = fopen("c:\\tutor\\data\\words_data", "rt");
   source_words_scores_data = fopen("c:\\tutor\\data\\words_scores_data", "rt");

	while(ch != EOF) {
   	ch = fgetc(source_words_data);
      initial_words_data_array[i] = ch;
      if((initial_words_data_array[i] < 97 || initial_words_data_array[i] > 122) && initial_words_data_array[i] != 39)
      	initial_words_data_array[i] = 32;
      i++;
	}

   initial_words_data_array_counter = i;
   i = 0;

   ch = ' ';

	while(ch != EOF) {
   	ch = fgetc(source_words_scores_data);
      words_scores_data_array[ii] = ch;
      if(words_scores_data_array[ii] < 48 || words_scores_data_array[ii] > 57)
      	words_scores_data_array[ii] = 32;
      ii++;
	}

   words_scores_data_array_counter = ii;
   ii = 0;

   while(i < initial_words_data_array_counter) {
      while(initial_words_data_array[i] == 32 && initial_words_data_array[i + 1] == 32)
         i++;
      corrected_words_data_array[j] = initial_words_data_array[i];
      j++;
      i++;
   }

   initial_words_data_array_counter;
   i = 0;
   j = 0;

   words_scores_data_array_counter -= 1;
   while(ii < words_scores_data_array_counter) {
      for(i = 0; i < 40; i++)
      	buffer_string_for_word_score[i] = ' ';
      while(words_scores_data_array[ii] != 32) {
         word_score_flag = true;
         buffer_string_for_word_score[jj] = words_scores_data_array[ii];
         jj++;
         ii++;
      }
      words_data_stack[data_words_stack_counter].word_score = atol(buffer_string_for_word_score);
      jj = 0;
      ii++;
      if(word_score_flag == true)
         data_words_stack_counter++;
      word_score_flag = false;
   }

   i = 0;

   while(i < data_words_stack_counter) {
      while(corrected_words_data_array[j] != 32) {
      	words_data_stack[i].word[k] = corrected_words_data_array[j];
         j++;
         k++;
      }
      while(corrected_words_data_array[j] == ' ')
      	j++;

      i++;
      k = 0;
   }
}
