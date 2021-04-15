//contains:
// -- functions that create the display for each necessary window
// -- function that deletes a window
// -- function that creates a new window 

#include "database_head.h"
#include <iostream>
using namespace std;

//destroys a window
void destroy_win(WINDOW *deleteWin){
	wborder(deleteWin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(deleteWin);
	delwin(deleteWin);
}

//creates a new window
WINDOW* create_win(){
	int h, w;
	getmaxyx(stdscr, h, w);
	WINDOW* tempwin = newwin(h/2, w/2, h/4, w/4);
	box(tempwin, 0, 0);
	refresh();
	return tempwin; 
}

//WINDOW 1: Display main menu
char feature_display(){
	char returnChar = '0'; //gets returned; keeps track of what option was chosen by user in main menu

	initscr();  //Initiaize the screen 
	noecho(); //hides user input from window
	curs_set(0); //hides screen cursor
	WINDOW* mainwin = create_win(); //creating window

	mvwprintw(mainwin, 0, 3, "Features");
	mvwprintw(mainwin, 0, 13, "Appointment");
	mvwprintw(mainwin, 4, 3, "Welcome to the Vaccination Database!");
	mvwprintw(mainwin, 5, 3, "====================================");
	mvwprintw(mainwin, 8, 3, "(a) Add new person's information.");
	mvwprintw(mainwin, 9, 3, "(s) Search specific information.");
	mvwprintw(mainwin, 10, 3, "(u) Update personal information.");
	mvwprintw(mainwin, 11, 3, "(l) List all records.");
	mvwprintw(mainwin, 12, 3, "(d) Delete data.");
	mvwprintw(mainwin, 13, 3, "(q) Quit.");
	mvwprintw(mainwin, 15, 3, "Enter the letter of your choice: ");

	//detecting which option is being pressed by the user 
	char ch;
	while((ch = wgetch(mainwin))){
		switch(ch){
			case 'a':
				wattron(mainwin, A_STANDOUT);
				mvwprintw(mainwin, 8, 4, "a");
				wattroff(mainwin, A_STANDOUT);
				mvwprintw(mainwin, 9, 4, "s");
				mvwprintw(mainwin, 10, 4, "u");
				mvwprintw(mainwin, 11, 4, "l");
				mvwprintw(mainwin, 12 ,4, "d");
				mvwprintw(mainwin, 13, 4, "q");
				returnChar = 'a';
				break;
			case 's':
				wattron(mainwin, A_STANDOUT);
				mvwprintw(mainwin, 9, 4, "s");
				wattroff(mainwin, A_STANDOUT);
				mvwprintw(mainwin, 8, 4, "a");
				mvwprintw(mainwin, 10, 4, "u");
				mvwprintw(mainwin, 11, 4, "l");
				mvwprintw(mainwin, 12 ,4, "d");
				mvwprintw(mainwin, 13, 4, "q");
				returnChar = 's';
				break;
			case 'u':
				wattron(mainwin, A_STANDOUT);
				mvwprintw(mainwin, 10, 4, "u");
				wattroff(mainwin, A_STANDOUT);
				mvwprintw(mainwin, 8, 4, "a");
				mvwprintw(mainwin, 9, 4, "s");
				mvwprintw(mainwin, 11, 4, "l");
				mvwprintw(mainwin, 12 ,4, "d");
				mvwprintw(mainwin, 13, 4, "q");
				returnChar = 'u';
				break;
			case 'l':
				wattron(mainwin, A_STANDOUT);
				mvwprintw(mainwin, 11, 4, "l");
				wattroff(mainwin, A_STANDOUT);
				mvwprintw(mainwin, 8, 4, "a");
				mvwprintw(mainwin, 9, 4, "s");
				mvwprintw(mainwin, 10, 4, "u");
				mvwprintw(mainwin, 12 ,4, "d");
				mvwprintw(mainwin, 13, 4, "q");
				returnChar = 'l';
				break;
			case 'd':
				wattron(mainwin, A_STANDOUT);
				mvwprintw(mainwin, 12 ,4, "d");
				wattroff(mainwin, A_STANDOUT);
				mvwprintw(mainwin, 8, 4, "a");
				mvwprintw(mainwin, 9, 4, "s");
				mvwprintw(mainwin, 10, 4, "u");
				mvwprintw(mainwin, 11, 4, "l");
				mvwprintw(mainwin, 13, 4, "q");
				returnChar = 'd';
				break;
			case 'q':
				wattron(mainwin, A_STANDOUT);
				mvwprintw(mainwin, 13, 4, "q");
				wattroff(mainwin, A_STANDOUT);
				mvwprintw(mainwin, 8, 4, "a");
				mvwprintw(mainwin, 9, 4, "s");
				mvwprintw(mainwin, 10, 4, "u");
				mvwprintw(mainwin, 11, 4, "l");
				mvwprintw(mainwin, 12 ,4, "d");
				returnChar = 'q';
				break;
			default:
			mvwprintw(mainwin, 8, 3, "(a) Add new person's information.");
			mvwprintw(mainwin, 9, 3, "(s) Search specific information.");
			mvwprintw(mainwin, 10, 3, "(u) Update personal information.");
			mvwprintw(mainwin, 11, 3, "(l) List all records.");
			mvwprintw(mainwin, 12, 3, "(d) Delete data.");
			mvwprintw(mainwin, 13, 3, "(q) Quit.");
			mvwprintw(mainwin, 15, 3, "Please enter valid letter of your choice: ");
			break;
		}
		if(ch == 10) break; //if user presses enter -- break while loop
	}  
	destroy_win(mainwin);
	return returnChar;
}

//WINDOW 2: Display search-for options
char search_display(char response){
	char returnChar; 

	initscr(); 
	noecho(); 
	curs_set(0); 
	WINDOW* searchwin = create_win();

	mvwprintw(searchwin, 0, 3, "Features");
	mvwprintw(searchwin, 0, 13, "Appointment");

	if (response == 's'){
		mvwprintw(searchwin, 4, 3, "Search specific information!");
		mvwprintw(searchwin, 5, 3, "============================");
		mvwprintw(searchwin, 8, 3, "You can search by: ");
	} else if (response == 'd'){
		mvwprintw(searchwin, 4, 3, "Delete personal information!");
		mvwprintw(searchwin, 5, 3, "============================");
		mvwprintw(searchwin, 8, 3, "You can search for: ");
	}
	mvwprintw(searchwin, 9, 3, "(n) Name of the person.");
	mvwprintw(searchwin, 10, 3, "(y) Year of birth.");
	mvwprintw(searchwin, 11, 3, "(c) City.");
	mvwprintw(searchwin, 12, 3, "(p) Phone number.");
	mvwprintw(searchwin, 13, 3, "(v) Vaccination status.");

	mvwprintw(searchwin, 15, 3, "(r) Return to main menu.");
	mvwprintw(searchwin, 17, 3, "Enter the letter of your choice: ");

	//detecting which option is being pressed by the user 
	char ch;
	while((ch = wgetch(searchwin))){
		switch(ch){
			case 'n':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "n");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 10, 4, "y");
				mvwprintw(searchwin, 11, 4, "c");
				mvwprintw(searchwin, 12, 4, "p");
				mvwprintw(searchwin, 13, 4, "v");
				mvwprintw(searchwin, 15, 4, "r");
				returnChar = 'n';
				break;
			case 'y':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 10, 4, "y");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "n");
				mvwprintw(searchwin, 11, 4, "c");
				mvwprintw(searchwin, 12, 4, "p");
				mvwprintw(searchwin, 13 ,4, "v");
				mvwprintw(searchwin, 15, 4, "r");
				returnChar = 'y';
				break;
			case 'c':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 11, 4, "c");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "n");
				mvwprintw(searchwin, 10, 4, "y");
				mvwprintw(searchwin, 12, 4, "p");
				mvwprintw(searchwin, 13 ,4, "v");
				mvwprintw(searchwin, 15, 4, "r");
				returnChar = 'c';
				break;
			case 'p':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 12, 4, "p");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "n");
				mvwprintw(searchwin, 10, 4, "y");
				mvwprintw(searchwin, 11, 4, "c");
				mvwprintw(searchwin, 13, 4, "v");
				mvwprintw(searchwin, 15, 4, "r");
				returnChar = 'p';
				break;
			case 'v':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 13 ,4, "v");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "n");
				mvwprintw(searchwin, 10, 4, "y");
				mvwprintw(searchwin, 11, 4, "c");
				mvwprintw(searchwin, 12, 4, "p");
				mvwprintw(searchwin, 15, 4, "r");
				returnChar = 'v';
				break;
			case 'r':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 15 ,4, "r");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "n");
				mvwprintw(searchwin, 10, 4, "y");
				mvwprintw(searchwin, 11, 4, "c");
				mvwprintw(searchwin, 12, 4, "p");
				mvwprintw(searchwin, 13, 4, "v");
				returnChar = 'r';
				break;
			default:
				mvwprintw(searchwin, 9, 3, "(n) Name of the person.");
				mvwprintw(searchwin, 10, 3, "(y) Year of birth.");
				mvwprintw(searchwin, 11, 3, "(c) City.");
				mvwprintw(searchwin, 12, 3, "(p) Phone number.");
				mvwprintw(searchwin, 13, 3, "(v) Vaccination status.");

				mvwprintw(searchwin, 15, 3, "(r) Return to main menu.");
				mvwprintw(searchwin, 17, 3, "Please enter valid letter of choice: ");
			break;
		}
		if(ch == 10) break;
	}  
	destroy_win(searchwin);
	return returnChar;
}

//WINDOW 3: Display search options for string type
char search_str_display(){
	char returnChar; 

	initscr(); 
	noecho(); 
	curs_set(0);
	WINDOW* searchwin = create_win();

	mvwprintw(searchwin, 0, 3, "Features");
	mvwprintw(searchwin, 0, 13, "Appointment");
	mvwprintw(searchwin, 4, 3, "Search specific information!");
	mvwprintw(searchwin, 5, 3, "============================");
	mvwprintw(searchwin, 8, 3, "You can search information that: ");
	mvwprintw(searchwin, 9, 3, "(e) Exactly matches.");
	mvwprintw(searchwin, 10, 3, "(o) Occurs as a substring.");
	mvwprintw(searchwin, 13, 3, "(r) Return to main menu.");
	mvwprintw(searchwin, 15, 3, "Enter the letter of your choice: ");

	//detecting which option is being pressed by the user 
	char ch;
	while((ch = wgetch(searchwin))){
		switch(ch){
			case 'e':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "e");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 10, 4, "o");
				mvwprintw(searchwin, 13, 4, "r");
				returnChar = 'e';
				break;
			case 'o':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 10, 4, "o");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "e");
				mvwprintw(searchwin, 13 ,4, "r");
				returnChar = 'o';
				break;
			case 'r':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 13, 4, "r");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "e");
				mvwprintw(searchwin, 10, 4, "o");
				returnChar = 'r';
				break;
			default:
				mvwprintw(searchwin, 9, 3, "(e) Exactly matches.");
				mvwprintw(searchwin, 10, 3, "(o) Occurs as a substring.");
				mvwprintw(searchwin, 13, 3, "(r) Return to main menu.");
				mvwprintw(searchwin, 15, 3, "Please enter valid letter of choice: ");
			break;
		}
		if(ch == 10) break;
	}  
	destroy_win(searchwin);
	return returnChar;
}

//WINDOW 4: Display search option for phone number
//can search by exact num or using area codes 
char search_phone_display(){
	char returnChar;

	initscr();
	noecho();
	curs_set(0);

	WINDOW* searchwin = create_win();

	mvwprintw(searchwin, 4, 3, "Search specific information!");
	mvwprintw(searchwin, 5, 3, "============================");
	mvwprintw(searchwin, 8, 3, "You can search number that: ");
	mvwprintw(searchwin, 9, 3, "(e) Exactly matches.");
	mvwprintw(searchwin, 10, 3, "(a) By area code.");

	mvwprintw(searchwin, 13, 3, "(r) Return to main menu.");
	mvwprintw(searchwin, 15, 3, "Enter the letter of your choice: ");

	char ch;
	while((ch = wgetch(searchwin))){
		switch(ch){
			case 'e':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "e");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 10, 4, "a");
				mvwprintw(searchwin, 13, 4, "r");
				returnChar = 'e';
				break;
			case 'a':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 10, 4, "a");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "e");
				mvwprintw(searchwin, 13, 4, "r");
				returnChar = 'a';
				break;
			case 'r':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 13, 4, "r");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "e");
				mvwprintw(searchwin, 10, 4, "a");
				returnChar = 'r';
				break;
			default:
				mvwprintw(searchwin, 9, 3, "(e) Exactly matches.");
				mvwprintw(searchwin, 10, 3, "(a) By area code.");
				mvwprintw(searchwin, 13, 3, "(r) Return to main menu.");
				mvwprintw(searchwin, 15, 3, "Please enter valid letter of choice: ");
		}
		if(ch == 10) break;
	}
	destroy_win(searchwin);
	return returnChar;
}
//WINDOW 5: Display search option for year of birth
char search_yob_display(){
	char returnChar;  

	initscr();  
	noecho(); 
	curs_set(0); 
	WINDOW* searchwin = create_win();

	mvwprintw(searchwin, 0, 3, "Features");
	mvwprintw(searchwin, 0, 13, "Appointment");
	mvwprintw(searchwin, 4, 3, "Search specific information!");
	mvwprintw(searchwin, 5, 3, "============================");
	mvwprintw(searchwin, 8, 3, "You can search number that: ");
	mvwprintw(searchwin, 9, 3, "(e) Exactly matches.");
	mvwprintw(searchwin, 10, 3, "(i) Is in the range, low to high.");
	mvwprintw(searchwin, 13, 3, "(r) Return to main menu.");
	mvwprintw(searchwin, 15, 3, "Enter the letter of your choice: ");

	//detecting which option is being pressed by the user 
	char ch;
	while((ch = wgetch(searchwin))){
		switch(ch){
			case 'e':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "e");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 10, 4, "i");
				mvwprintw(searchwin, 13, 4, "r");
				returnChar = 'e';
				break;
			case 'i':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 10, 4, "i");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "e");
				mvwprintw(searchwin, 13, 4, "r");
				returnChar = 'i';
				break;
			case 'r':
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 13, 4, "r");
				wattroff(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 9, 4, "e");
				mvwprintw(searchwin, 10, 4, "i");
				returnChar = 'r';
				break;
			default:
				mvwprintw(searchwin, 9, 3, "(e) Exactly matches.");
				mvwprintw(searchwin, 10, 3, "(i) Is in the range, low to high.");
				mvwprintw(searchwin, 13, 3, "(r) Return to main menu.");
				mvwprintw(searchwin, 15, 3, "Please enter valid letter of choice: ");
			break;
		}
		if(ch == 10) break;
	}  
	destroy_win(searchwin);
	return returnChar;
}

//WINDOW 6: Display questions to add information


//WINDOW 7: Display update options
char update_display(){
	char returnChar; 

	initscr(); 
	noecho(); 
	curs_set(0);
	WINDOW* updatewin = create_win();

	mvwprintw(updatewin, 0, 3, "Features");
	mvwprintw(updatewin, 0, 13, "Appointment");
	mvwprintw(updatewin, 4, 3, "Update personal information!");
	mvwprintw(updatewin, 5, 3, "============================");
	mvwprintw(updatewin, 8, 3, "Which field would you like to update? ");
	mvwprintw(updatewin, 9, 3, "(n) Name.");
	mvwprintw(updatewin, 10, 3, "(c) City.");
	mvwprintw(updatewin, 11, 3, "(p) Phone number.");
	mvwprintw(updatewin, 12, 3, "(v) Vaccination status.");
	mvwprintw(updatewin, 15, 3, "(r) Return to main menu.");
	mvwprintw(updatewin, 17, 3, "Enter the letter of your choice: ");

	//detecting which option is being pressed by the user 
	char ch;
	while((ch = wgetch(updatewin))){
		switch(ch){
			case 'n':
				wattron(updatewin, A_STANDOUT);
				mvwprintw(updatewin, 9, 4, "n");
				wattroff(updatewin, A_STANDOUT);
				mvwprintw(updatewin, 10, 4, "c");
				mvwprintw(updatewin, 11, 4, "p");
				mvwprintw(updatewin, 12, 4, "v");
				mvwprintw(updatewin, 15, 4, "r");
				returnChar = 'n';
				break;
			case 'c':
				wattron(updatewin, A_STANDOUT);
				mvwprintw(updatewin, 10, 4, "c");
				wattroff(updatewin, A_STANDOUT);
				mvwprintw(updatewin, 9, 4, "n");
				mvwprintw(updatewin, 11, 4, "p");
				mvwprintw(updatewin, 12, 4, "v");
				mvwprintw(updatewin, 15, 4, "r");
				returnChar = 'c';
				break;
			case 'p':
				wattron(updatewin, A_STANDOUT);
				mvwprintw(updatewin, 11, 4, "p");
				wattroff(updatewin, A_STANDOUT);
				mvwprintw(updatewin, 9, 4, "n");
				mvwprintw(updatewin, 10, 4, "c");
				mvwprintw(updatewin, 12, 4, "v");
				mvwprintw(updatewin, 15, 4, "r");
				returnChar = 'p';
				break;
			case 'v':
				wattron(updatewin, A_STANDOUT);
				mvwprintw(updatewin, 12, 4, "v");
				wattroff(updatewin, A_STANDOUT);
				mvwprintw(updatewin, 9, 4, "n");
				mvwprintw(updatewin, 10, 4, "c");
				mvwprintw(updatewin, 11, 4, "p");
				mvwprintw(updatewin, 15, 4, "r");
				returnChar = 'v';
				break;
			case 'r':
				wattron(updatewin, A_STANDOUT);
				mvwprintw(updatewin, 15, 4, "r");
				wattroff(updatewin, A_STANDOUT);
				mvwprintw(updatewin, 9, 4, "n");
				mvwprintw(updatewin, 10, 4, "c");
				mvwprintw(updatewin, 11, 4, "p");
				mvwprintw(updatewin, 12, 4, "v");
				returnChar = 'r';
				break;
			default:
				mvwprintw(updatewin, 9, 3, "(n) Name.");
				mvwprintw(updatewin, 10, 3, "(c) City.");
				mvwprintw(updatewin, 11, 3, "(p) Phone number.");
				mvwprintw(updatewin, 12, 3, "(v) Vaccination status.");
				mvwprintw(updatewin, 15, 3, "(r) Return to main menu.");
				mvwprintw(updatewin, 17, 3, "Please enter valid letter of choice: ");
			break;
		}
		if(ch == 10) break;
	}  
	destroy_win(updatewin);
	return returnChar;
}

// WINDOW 8: Display listing options
char list_display(){
	char returnChar; 

	initscr(); 
	noecho(); 
	curs_set(0);
	WINDOW* listwin = create_win();

	mvwprintw(listwin, 0, 3, "Features");
	mvwprintw(listwin, 0, 13, "Appointment");
	mvwprintw(listwin, 4, 3, "List all records!");
	mvwprintw(listwin, 5, 3, "============================");
	mvwprintw(listwin, 8, 3, "You can list by: ");
	mvwprintw(listwin, 9, 3, "(n) Name of the person.");
	mvwprintw(listwin, 10, 3, "(y) Year of birth.");
	mvwprintw(listwin, 11, 3, "(c) City.");
	mvwprintw(listwin, 12, 3, "(p) Phone number.");
	mvwprintw(listwin, 13, 3, "(v) Vaccination status.");
	mvwprintw(listwin, 15, 3, "(r) Return to main menu.");
	mvwprintw(listwin, 17, 3, "Enter the letter of your choice: ");

	//detecting which option is being pressed by the user 
	char ch;
	while((ch = wgetch(listwin))){
		switch(ch){
			case 'n':
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 9, 4, "n");
				wattroff(listwin, A_STANDOUT);
				mvwprintw(listwin, 10, 4, "y");
				mvwprintw(listwin, 11, 4, "c");
				mvwprintw(listwin, 12, 4, "p");
				mvwprintw(listwin, 13, 4, "v");
				mvwprintw(listwin, 15, 4, "r");
				returnChar = 'n';
				break;
			case 'y':
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 10, 4, "y");
				wattroff(listwin, A_STANDOUT);
				mvwprintw(listwin, 9, 4, "n");
				mvwprintw(listwin, 11, 4, "c");
				mvwprintw(listwin, 12, 4, "p");
				mvwprintw(listwin, 13 ,4, "v");
				mvwprintw(listwin, 15, 4, "r");
				returnChar = 'y';
				break;
			case 'c':
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 11, 4, "c");
				wattroff(listwin, A_STANDOUT);
				mvwprintw(listwin, 9, 4, "n");
				mvwprintw(listwin, 10, 4, "y");
				mvwprintw(listwin, 12, 4, "p");
				mvwprintw(listwin, 13 ,4, "v");
				mvwprintw(listwin, 15, 4, "r");
				returnChar = 'c';
				break;
			case 'p':
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 12, 4, "p");
				wattroff(listwin, A_STANDOUT);
				mvwprintw(listwin, 9, 4, "n");
				mvwprintw(listwin, 10, 4, "y");
				mvwprintw(listwin, 11, 4, "c");
				mvwprintw(listwin, 13, 4, "v");
				mvwprintw(listwin, 15, 4, "r");
				returnChar = 'p';
				break;
			case 'v':
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 13 ,4, "v");
				wattroff(listwin, A_STANDOUT);
				mvwprintw(listwin, 9, 4, "n");
				mvwprintw(listwin, 10, 4, "y");
				mvwprintw(listwin, 11, 4, "c");
				mvwprintw(listwin, 12, 4, "p");
				mvwprintw(listwin, 15, 4, "r");
				returnChar = 'v';
				break;
			case 'r':
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 15 ,4, "r");
				wattroff(listwin, A_STANDOUT);
				mvwprintw(listwin, 9, 4, "n");
				mvwprintw(listwin, 10, 4, "y");
				mvwprintw(listwin, 11, 4, "c");
				mvwprintw(listwin, 12, 4, "p");
				mvwprintw(listwin, 13, 4, "v");
				returnChar = 'r';
				break;
			default:
				mvwprintw(listwin, 9, 3, "(n) Name of the person.");
				mvwprintw(listwin, 10, 3, "(y) Year of birth.");
				mvwprintw(listwin, 11, 3, "(c) City.");
				mvwprintw(listwin, 12, 3, "(p) Phone number.");
				mvwprintw(listwin, 13, 3, "(v) Vaccination status.");
				mvwprintw(listwin, 15, 3, "(r) Return to main menu.");
				mvwprintw(listwin, 17, 3, "Please enter valid letter of choice: ");
				break;
		}
		if(ch == 10) break;
	}  
	destroy_win(listwin);
	return returnChar;
}

//WINDOW 9: Display list options for string type
char list_str_display(){
	char returnChar = '0'; 

	initscr(); 
	noecho(); 
	curs_set(0);
	WINDOW* listwin = create_win();

	mvwprintw(listwin, 0, 3, "Features");
	mvwprintw(listwin, 0, 13, "Appointment");
	mvwprintw(listwin, 4, 3, "List all records!");
	mvwprintw(listwin, 5, 3, "============================");
	mvwprintw(listwin, 8, 3, "You can choose the order of listing: ");
	mvwprintw(listwin, 9, 3, "(a) Aphebetical order.");
	mvwprintw(listwin, 10, 3, "(e) Reverse alphabetical order.");
	mvwprintw(listwin, 13, 3, "(r) Return to main menu.");
	mvwprintw(listwin, 15, 3, "Enter the letter of your choice: ");

	//detecting which option is being pressed by the user 
	char ch;
	while((ch = wgetch(listwin))){
		switch(ch){
			case 'a':
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 9, 4, "a");
				wattroff(listwin, A_STANDOUT);
				mvwprintw(listwin, 10, 4, "e");
				mvwprintw(listwin, 13, 4, "r");
				returnChar = 'a';
				break;
			case 'e':
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 10, 4, "e");
				wattroff(listwin, A_STANDOUT);
				mvwprintw(listwin, 9, 4, "a");
				mvwprintw(listwin, 13 ,4, "r");
				returnChar = 'e';
				break;
			case 'r':
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 13, 4, "r");
				wattroff(listwin, A_STANDOUT);
				mvwprintw(listwin, 9, 4, "a");
				mvwprintw(listwin, 10, 4, "e");
				returnChar = 'r';
				break;
			default:
				mvwprintw(listwin, 9, 3, "(a) Aphebetical order.");
				mvwprintw(listwin, 10, 3, "(e) Reverse alphabetical order.");
				mvwprintw(listwin, 13, 3, "(r) Return to main menu.");
				mvwprintw(listwin, 15, 3, "Please enter valid letter of choice: ");
				break;
		}
		if(ch == 10) break;
	}  
	destroy_win(listwin);
	return returnChar;
}

//WINDOW 10: Display search option for strings
char list_int_display(){
	char returnChar = '0'; 

	initscr();  
	noecho(); 
	curs_set(0); 
	WINDOW* listwin = create_win();

	mvwprintw(listwin, 0, 3, "Features");
	mvwprintw(listwin, 0, 13, "Appointment");
	mvwprintw(listwin, 4, 3, "List all records!");
	mvwprintw(listwin, 5, 3, "============================");
	mvwprintw(listwin, 8, 3, "You can choose the order of listing numbers: ");
	mvwprintw(listwin, 9, 3, "(a) Ascending order.");
	mvwprintw(listwin, 10, 3, "(d) Descending order.");
	mvwprintw(listwin, 13, 3, "(r) Return to main menu.");
	mvwprintw(listwin, 15, 3, "Enter the letter of your choice: ");

	//detecting which option is being pressed by the user 
	char ch;
	while((ch = wgetch(listwin))){
		switch(ch){
			case 'a':
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 9, 4, "a");
				wattroff(listwin, A_STANDOUT);
				mvwprintw(listwin, 10, 4, "d");
				mvwprintw(listwin, 13, 4, "r");
				returnChar = 'a';
				break;
			case 'd':
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 10, 4, "d");
				wattroff(listwin, A_STANDOUT);
				mvwprintw(listwin, 9, 4, "a");
				mvwprintw(listwin, 13 ,4, "r");
				returnChar = 'd';
				break;
			case 'r':
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 13, 4, "r");
				wattroff(listwin, A_STANDOUT);
				mvwprintw(listwin, 9, 4, "a");
				mvwprintw(listwin, 10, 4, "d");
				returnChar = 'r';
				break;
			default:
				mvwprintw(listwin, 9, 3, "(a) Ascending order.");
				mvwprintw(listwin, 10, 3, "(d) Descending order.");
				mvwprintw(listwin, 13, 3, "(r) Return to main menu.");
				mvwprintw(listwin, 15, 3, "Please enter valid letter of choice: ");
				break;
		}
		if(ch == 10) break;
	}  
	destroy_win(listwin);
	return returnChar;
}

void quit_display(){
	initscr(); //Initiaize the screen 
	noecho(); //hides user input from window
	curs_set(0); //hides screen cursor

	WINDOW* listwin = create_win();
	destroy_win(listwin);
}