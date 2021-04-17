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
	
	
	//Set background color
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_WHITE);
	wbkgd(stdscr, COLOR_PAIR(1));
	
	WINDOW* mainwin = create_win(); //creating window
	
	mvwprintw(mainwin, 0, 3, "Features");
	mvwprintw(mainwin, 0, 13, "Appointment");
	wattron(mainwin, COLOR_PAIR(1));
	wattron(mainwin, A_BOLD);
	mvwprintw(mainwin, 4, 3, "Welcome to the Vaccination Database!");
	wattroff(mainwin, A_BOLD);
	wattroff(mainwin, COLOR_PAIR(1));
	
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
				wattron(mainwin, COLOR_PAIR(2));
				mvwprintw(mainwin, 8, 4, "a");
				wattroff(mainwin, COLOR_PAIR(2));
				mvwprintw(mainwin, 9, 4, "s");
				mvwprintw(mainwin, 10, 4, "u");
				mvwprintw(mainwin, 11, 4, "l");
				mvwprintw(mainwin, 12 ,4, "d");
				mvwprintw(mainwin, 13, 4, "q");
				mvwprintw(mainwin, 15, 3, "Enter the letter of your choice, press ENTER: a");
				wclrtoeol(mainwin);
				returnChar = 'a';
				break;
			case 's':
				wattron(mainwin, COLOR_PAIR(2));
				mvwprintw(mainwin, 9, 4, "s");
				wattroff(mainwin, COLOR_PAIR(2));
				mvwprintw(mainwin, 8, 4, "a");
				mvwprintw(mainwin, 10, 4, "u");
				mvwprintw(mainwin, 11, 4, "l");
				mvwprintw(mainwin, 12 ,4, "d");
				mvwprintw(mainwin, 13, 4, "q");
				mvwprintw(mainwin, 15, 3, "Enter the letter of your choice, press ENTER: s");
				wclrtoeol(mainwin);
				returnChar = 's';
				break;
			case 'u':
				wattron(mainwin, COLOR_PAIR(2));
				mvwprintw(mainwin, 10, 4, "u");
				wattroff(mainwin, COLOR_PAIR(2));
				mvwprintw(mainwin, 8, 4, "a");
				mvwprintw(mainwin, 9, 4, "s");
				mvwprintw(mainwin, 11, 4, "l");
				mvwprintw(mainwin, 12 ,4, "d");
				mvwprintw(mainwin, 13, 4, "q");
				mvwprintw(mainwin, 15, 3, "Enter the letter of your choice, press ENTER: u");
				wclrtoeol(mainwin);
				returnChar = 'u';
				break;
			case 'l':
				wattron(mainwin, COLOR_PAIR(2));
				mvwprintw(mainwin, 11, 4, "l");
				wattroff(mainwin, COLOR_PAIR(2));
				mvwprintw(mainwin, 8, 4, "a");
				mvwprintw(mainwin, 9, 4, "s");
				mvwprintw(mainwin, 10, 4, "u");
				mvwprintw(mainwin, 12 ,4, "d");
				mvwprintw(mainwin, 13, 4, "q");
				mvwprintw(mainwin, 15, 3, "Enter the letter of your choice, press ENTER: l");
				wclrtoeol(mainwin);
				returnChar = 'l';
				break;
			case 'd':
				wattron(mainwin, COLOR_PAIR(2));
				mvwprintw(mainwin, 12 ,4, "d");
				wattroff(mainwin, COLOR_PAIR(2));
				mvwprintw(mainwin, 8, 4, "a");
				mvwprintw(mainwin, 9, 4, "s");
				mvwprintw(mainwin, 10, 4, "u");
				mvwprintw(mainwin, 11, 4, "l");
				mvwprintw(mainwin, 13, 4, "q");
				mvwprintw(mainwin, 15, 3, "Enter the letter of your choice, press ENTER: d");
				wclrtoeol(mainwin);
				returnChar = 'd';
				break;
			case 'q':
				wattron(mainwin, COLOR_PAIR(2));
				mvwprintw(mainwin, 13, 4, "q");
				wattroff(mainwin, COLOR_PAIR(2));
				mvwprintw(mainwin, 8, 4, "a");
				mvwprintw(mainwin, 9, 4, "s");
				mvwprintw(mainwin, 10, 4, "u");
				mvwprintw(mainwin, 11, 4, "l");
				mvwprintw(mainwin, 12 ,4, "d");
				mvwprintw(mainwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: q");
				wclrtoeol(mainwin);
				returnChar = 'q';
				break;
			default:
			mvwprintw(mainwin, 8, 3, "(a) Add new person's information.");
			mvwprintw(mainwin, 9, 3, "(s) Search specific information.");
			mvwprintw(mainwin, 10, 3, "(u) Update personal information.");
			mvwprintw(mainwin, 11, 3, "(l) List all records.");
			mvwprintw(mainwin, 12, 3, "(d) Delete data.");
			mvwprintw(mainwin, 13, 3, "(q) Quit.");
			wattron(mainwin, A_STANDOUT);
			mvwprintw(mainwin, 15, 3, "Please enter valid letter of your choice! ");
			wattroff(mainwin, A_STANDOUT);
			wclrtoeol(mainwin);
			
			break;
		}
		//if user presses enter -- break while loop
		if(ch == 10 && (returnChar == 'a'|| returnChar == 's'|| returnChar == 'u'|| 
						returnChar == 'd'|| returnChar == 'l'|| returnChar == 'q')) break;
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
	
	// Set colors to text
	start_color();
	init_pair(3, COLOR_GREEN, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_WHITE);
	wbkgd(stdscr, COLOR_PAIR(1));
	
	WINDOW* searchwin = create_win();

	mvwprintw(searchwin, 0, 3, "Features");
	mvwprintw(searchwin, 0, 13, "Appointment");

	if (response == 's'){
		wattron(searchwin, COLOR_PAIR(3));
		wattron(searchwin, A_BOLD);
		mvwprintw(searchwin, 4, 3, "Search specific information!");
		wattroff(searchwin, A_BOLD);
		wattroff(searchwin, COLOR_PAIR(3));
		
		mvwprintw(searchwin, 5, 3, "============================");
		mvwprintw(searchwin, 8, 3, "You can search by: ");
	} else if (response == 'd'){
		wattron(searchwin, COLOR_PAIR(3));
		wattron(searchwin, A_BOLD);
		mvwprintw(searchwin, 4, 3, "Delete personal information!");
		wattroff(searchwin, A_BOLD);
		wattroff(searchwin, COLOR_PAIR(3));
		
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
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "n");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 10, 4, "y");
				mvwprintw(searchwin, 11, 4, "c");
				mvwprintw(searchwin, 12, 4, "p");
				mvwprintw(searchwin, 13, 4, "v");
				mvwprintw(searchwin, 15, 4, "r");
				mvwprintw(searchwin, 17, 3, "Enter the letter of your choice, PRESS ENTER: n");
				wclrtoeol(searchwin);
				returnChar = 'n';
				break;
			case 'y':
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 10, 4, "y");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "n");
				mvwprintw(searchwin, 11, 4, "c");
				mvwprintw(searchwin, 12, 4, "p");
				mvwprintw(searchwin, 13 ,4, "v");
				mvwprintw(searchwin, 15, 4, "r");
				mvwprintw(searchwin, 17, 3, "Enter the letter of your choice, PRESS ENTER: y");
				wclrtoeol(searchwin);
				returnChar = 'y';
				break;
			case 'c':
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 11, 4, "c");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "n");
				mvwprintw(searchwin, 10, 4, "y");
				mvwprintw(searchwin, 12, 4, "p");
				mvwprintw(searchwin, 13 ,4, "v");
				mvwprintw(searchwin, 15, 4, "r");
				mvwprintw(searchwin, 17, 3, "Enter the letter of your choice, PRESS ENTER: c");
				wclrtoeol(searchwin);
				returnChar = 'c';
				break;
			case 'p':
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 12, 4, "p");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "n");
				mvwprintw(searchwin, 10, 4, "y");
				mvwprintw(searchwin, 11, 4, "c");
				mvwprintw(searchwin, 13, 4, "v");
				mvwprintw(searchwin, 15, 4, "r");
				mvwprintw(searchwin, 17, 3, "Enter the letter of your choice, PRESS ENTER: p");
				wclrtoeol(searchwin);
				returnChar = 'p';
				break;
			case 'v':
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 13 ,4, "v");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "n");
				mvwprintw(searchwin, 10, 4, "y");
				mvwprintw(searchwin, 11, 4, "c");
				mvwprintw(searchwin, 12, 4, "p");
				mvwprintw(searchwin, 15, 4, "r");
				mvwprintw(searchwin, 17, 3, "Enter the letter of your choice, PRESS ENTER: v");
				wclrtoeol(searchwin);
				returnChar = 'v';
				break;
			case 'r':
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 15 ,4, "r");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "n");
				mvwprintw(searchwin, 10, 4, "y");
				mvwprintw(searchwin, 11, 4, "c");
				mvwprintw(searchwin, 12, 4, "p");
				mvwprintw(searchwin, 13, 4, "v");
				mvwprintw(searchwin, 17, 3, "Enter the letter of your choice, PRESS ENTER: r");
				wclrtoeol(searchwin);
				returnChar = 'r';
				break;
			default:
				mvwprintw(searchwin, 9, 3, "(n) Name of the person.");
				mvwprintw(searchwin, 10, 3, "(y) Year of birth.");
				mvwprintw(searchwin, 11, 3, "(c) City.");
				mvwprintw(searchwin, 12, 3, "(p) Phone number.");
				mvwprintw(searchwin, 13, 3, "(v) Vaccination status.");

				mvwprintw(searchwin, 15, 3, "(r) Return to main menu.");
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 17, 3, "Please enter valid letter of your choice! ");
				wattroff(searchwin, A_STANDOUT);
				wclrtoeol(searchwin);
			break;
		}
		if(ch == 10 && (returnChar == 'n' || returnChar == 'y' || returnChar == 'c' ||
						returnChar == 'p' || returnChar == 'v' || returnChar == 'r')) break;
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
	
	// Set colors to text
	start_color();
	init_pair(3, COLOR_GREEN, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_WHITE);
	wbkgd(stdscr, COLOR_PAIR(1));
	
	WINDOW* searchwin = create_win();

	mvwprintw(searchwin, 0, 3, "Features");
	mvwprintw(searchwin, 0, 13, "Appointment");
	wattron(searchwin, COLOR_PAIR(3));
	wattron(searchwin, A_BOLD);
	mvwprintw(searchwin, 4, 3, "Search specific information!");
	wattroff(searchwin, A_BOLD);
	wattroff(searchwin, COLOR_PAIR(3));
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
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "e");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 10, 4, "o");
				mvwprintw(searchwin, 13, 4, "r");
				mvwprintw(searchwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: e");
				wclrtoeol(searchwin);
				returnChar = 'e';
				break;
			case 'o':
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 10, 4, "o");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "e");
				mvwprintw(searchwin, 13 ,4, "r");
				mvwprintw(searchwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: 0");
				wclrtoeol(searchwin);
				returnChar = 'o';
				break;
			case 'r':
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 13, 4, "r");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "e");
				mvwprintw(searchwin, 10, 4, "o");
				mvwprintw(searchwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: r");
				wclrtoeol(searchwin);
				returnChar = 'r';
				break;
			default:
				mvwprintw(searchwin, 9, 3, "(e) Exactly matches.");
				mvwprintw(searchwin, 10, 3, "(o) Occurs as a substring.");
				mvwprintw(searchwin, 13, 3, "(r) Return to main menu.");
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 15, 3, "Please enter valid letter of your choice! ");
				wattroff(searchwin, A_STANDOUT);
				wclrtoeol(searchwin);
			break;
		}
		if(ch == 10 && (returnChar == 'e' || returnChar == 'o' || returnChar == 'r')) break;
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
	
	// Set colors to text
	start_color();
	init_pair(3, COLOR_GREEN, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_WHITE);
	wbkgd(stdscr, COLOR_PAIR(1));

	WINDOW* searchwin = create_win();

	wattron(searchwin, COLOR_PAIR(3));
	wattron(searchwin, A_BOLD);
	mvwprintw(searchwin, 4, 3, "Search specific information!");
	wattroff(searchwin, A_BOLD);
	wattroff(searchwin, COLOR_PAIR(3));
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
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "e");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 10, 4, "a");
				mvwprintw(searchwin, 13, 4, "r");
				mvwprintw(searchwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: e");
				wclrtoeol(searchwin);
				returnChar = 'e';
				break;
			case 'a':
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 10, 4, "a");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "e");
				mvwprintw(searchwin, 13, 4, "r");
				mvwprintw(searchwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: a");
				wclrtoeol(searchwin);
				returnChar = 'a';
				break;
			case 'r':
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 13, 4, "r");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "e");
				mvwprintw(searchwin, 10, 4, "a");
				mvwprintw(searchwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: r");
				wclrtoeol(searchwin);
				returnChar = 'r';
				break;
			default:
				mvwprintw(searchwin, 9, 3, "(e) Exactly matches.");
				mvwprintw(searchwin, 10, 3, "(a) By area code.");
				mvwprintw(searchwin, 13, 3, "(r) Return to main menu.");
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 15, 3, "Please enter valid letter of your choice! ");
				wattroff(searchwin, A_STANDOUT);
				wclrtoeol(searchwin);
		}
		if(ch == 10 && (returnChar == 'e' || returnChar == 'a' || returnChar == 'r')) break;
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
	
	// Set colors to text
	start_color();
	init_pair(3, COLOR_GREEN, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_WHITE);
	wbkgd(stdscr, COLOR_PAIR(1));
	
	WINDOW* searchwin = create_win();

	mvwprintw(searchwin, 0, 3, "Features");
	mvwprintw(searchwin, 0, 13, "Appointment");
	wattron(searchwin, COLOR_PAIR(3));
	wattron(searchwin, A_BOLD);
	mvwprintw(searchwin, 4, 3, "Search specific information!");
	wattroff(searchwin, A_BOLD);
	wattroff(searchwin, COLOR_PAIR(3));
	
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
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "e");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 10, 4, "i");
				mvwprintw(searchwin, 13, 4, "r");
				mvwprintw(searchwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: e");
				wclrtoeol(searchwin);
				returnChar = 'e';
				break;
			case 'i':
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 10, 4, "i");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "e");
				mvwprintw(searchwin, 13, 4, "r");
				mvwprintw(searchwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: i");
				wclrtoeol(searchwin);
				returnChar = 'i';
				break;
			case 'r':
				wattron(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 13, 4, "r");
				wattroff(searchwin, COLOR_PAIR(2));
				mvwprintw(searchwin, 9, 4, "e");
				mvwprintw(searchwin, 10, 4, "i");
				mvwprintw(searchwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: r");
				wclrtoeol(searchwin);
				returnChar = 'r';
				break;
			default:
				mvwprintw(searchwin, 9, 3, "(e) Exactly matches.");
				mvwprintw(searchwin, 10, 3, "(i) Is in the range, low to high.");
				mvwprintw(searchwin, 13, 3, "(r) Return to main menu.");
				wattron(searchwin, A_STANDOUT);
				mvwprintw(searchwin, 15, 3, "Please enter valid letter of your choice! ");
				wattroff(searchwin, A_STANDOUT);
				wclrtoeol(searchwin);
			break;
		}
		if(ch == 10 && (returnChar == 'e' || returnChar == 'i' || returnChar == 'r')) break;
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
	
	// Set colors to text
	start_color();
	init_pair(3, COLOR_GREEN, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_WHITE);
	wbkgd(stdscr, COLOR_PAIR(1));

	mvwprintw(updatewin, 0, 3, "Features");
	mvwprintw(updatewin, 0, 13, "Appointment");
	
	wattron(updatewin, COLOR_PAIR(2));
	wattron(updatewin, A_BOLD);
	mvwprintw(updatewin, 4, 3, "Update personal information!");
	wattroff(updatewin, A_BOLD);
	wattroff(updatewin, COLOR_PAIR(2));
	
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
				wattron(updatewin, COLOR_PAIR(2));
				mvwprintw(updatewin, 9, 4, "n");
				wattroff(updatewin, COLOR_PAIR(2));
				mvwprintw(updatewin, 10, 4, "c");
				mvwprintw(updatewin, 11, 4, "p");
				mvwprintw(updatewin, 12, 4, "v");
				mvwprintw(updatewin, 15, 4, "r");
				mvwprintw(updatewin, 17, 3, "Enter the letter of your choice, PRESS ENTER: n");
				wclrtoeol(updatewin);
				returnChar = 'n';
				break;
			case 'c':
				wattron(updatewin, COLOR_PAIR(2));
				mvwprintw(updatewin, 10, 4, "c");
				wattroff(updatewin, COLOR_PAIR(2));
				mvwprintw(updatewin, 9, 4, "n");
				mvwprintw(updatewin, 11, 4, "p");
				mvwprintw(updatewin, 12, 4, "v");
				mvwprintw(updatewin, 15, 4, "r");
				mvwprintw(updatewin, 17, 3, "Enter the letter of your choice, PRESS ENTER: c");
				wclrtoeol(updatewin);
				returnChar = 'c';
				break;
			case 'p':
				wattron(updatewin, COLOR_PAIR(2));
				mvwprintw(updatewin, 11, 4, "p");
				wattroff(updatewin, COLOR_PAIR(2));
				mvwprintw(updatewin, 9, 4, "n");
				mvwprintw(updatewin, 10, 4, "c");
				mvwprintw(updatewin, 12, 4, "v");
				mvwprintw(updatewin, 15, 4, "r");
				mvwprintw(updatewin, 17, 3, "Enter the letter of your choice, PRESS ENTER: p");
				wclrtoeol(updatewin);
				returnChar = 'p';
				break;
			case 'v':
				wattron(updatewin, COLOR_PAIR(2));
				mvwprintw(updatewin, 12, 4, "v");
				wattroff(updatewin, COLOR_PAIR(2));
				mvwprintw(updatewin, 9, 4, "n");
				mvwprintw(updatewin, 10, 4, "c");
				mvwprintw(updatewin, 11, 4, "p");
				mvwprintw(updatewin, 15, 4, "r");
				mvwprintw(updatewin, 17, 3, "Enter the letter of your choice, PRESS ENTER: v");
				wclrtoeol(updatewin);
				returnChar = 'v';
				break;
			case 'r':
				wattron(updatewin, COLOR_PAIR(2));
				mvwprintw(updatewin, 15, 4, "r");
				wattroff(updatewin, COLOR_PAIR(2));
				mvwprintw(updatewin, 9, 4, "n");
				mvwprintw(updatewin, 10, 4, "c");
				mvwprintw(updatewin, 11, 4, "p");
				mvwprintw(updatewin, 12, 4, "v");
				mvwprintw(updatewin, 17, 3, "Enter the letter of your choice, PRESS ENTER: r");
				wclrtoeol(updatewin);
				returnChar = 'r';
				break;
			default:
				mvwprintw(updatewin, 9, 3, "(n) Name.");
				mvwprintw(updatewin, 10, 3, "(c) City.");
				mvwprintw(updatewin, 11, 3, "(p) Phone number.");
				mvwprintw(updatewin, 12, 3, "(v) Vaccination status.");
				mvwprintw(updatewin, 15, 3, "(r) Return to main menu.");
				wattron(updatewin, A_STANDOUT);
				mvwprintw(updatewin, 17, 3, "Please enter valid letter of your choice! ");
				wattroff(updatewin, A_STANDOUT);
				wclrtoeol(updatewin);
			break;
		}
		if(ch == 10 && (returnChar == 'n' || returnChar == 'c' || returnChar == 'p' || 
						returnChar == 'v' || returnChar == 'r')) break;
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
	
	// Set colors to text
	start_color();
	init_pair(3, COLOR_GREEN, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_WHITE);
	wbkgd(stdscr, COLOR_PAIR(1));

	WINDOW* listwin = create_win();

	mvwprintw(listwin, 0, 3, "Features");
	mvwprintw(listwin, 0, 13, "Appointment");
	wattron(listwin, COLOR_PAIR(3));
	wattron(listwin, A_BOLD);
	mvwprintw(listwin, 4, 3, "List all records!");
	wattroff(listwin, A_BOLD);
	wattroff(listwin, COLOR_PAIR(3));
	
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
				wattron(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 9, 4, "n");
				wattroff(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 10, 4, "y");
				mvwprintw(listwin, 11, 4, "c");
				mvwprintw(listwin, 12, 4, "p");
				mvwprintw(listwin, 13, 4, "v");
				mvwprintw(listwin, 15, 4, "r");
				mvwprintw(listwin, 17, 3, "Enter the letter of your choice, PRESS ENTER: n");
				wclrtoeol(listwin);
				returnChar = 'n';
				break;
			case 'y':
				wattron(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 10, 4, "y");
				wattroff(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 9, 4, "n");
				mvwprintw(listwin, 11, 4, "c");
				mvwprintw(listwin, 12, 4, "p");
				mvwprintw(listwin, 13 ,4, "v");
				mvwprintw(listwin, 15, 4, "r");
				mvwprintw(listwin, 17, 3, "Enter the letter of your choice, PRESS ENTER: y");
				wclrtoeol(listwin);
				returnChar = 'y';
				break;
			case 'c':
				wattron(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 11, 4, "c");
				wattroff(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 9, 4, "n");
				mvwprintw(listwin, 10, 4, "y");
				mvwprintw(listwin, 12, 4, "p");
				mvwprintw(listwin, 13 ,4, "v");
				mvwprintw(listwin, 15, 4, "r");
				mvwprintw(listwin, 17, 3, "Enter the letter of your choice, PRESS ENTER: c");
				wclrtoeol(listwin);
				returnChar = 'c';
				break;
			case 'p':
				wattron(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 12, 4, "p");
				wattroff(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 9, 4, "n");
				mvwprintw(listwin, 10, 4, "y");
				mvwprintw(listwin, 11, 4, "c");
				mvwprintw(listwin, 13, 4, "v");
				mvwprintw(listwin, 15, 4, "r");
				mvwprintw(listwin, 17, 3, "Enter the letter of your choice, PRESS ENTER: p");
				wclrtoeol(listwin);
				returnChar = 'p';
				break;
			case 'v':
				wattron(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 13 ,4, "v");
				wattroff(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 9, 4, "n");
				mvwprintw(listwin, 10, 4, "y");
				mvwprintw(listwin, 11, 4, "c");
				mvwprintw(listwin, 12, 4, "p");
				mvwprintw(listwin, 15, 4, "r");
				mvwprintw(listwin, 17, 3, "Enter the letter of your choice, PRESS ENTER: v");
				wclrtoeol(listwin);
				returnChar = 'v';
				break;
			case 'r':
				wattron(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 15 ,4, "r");
				wattroff(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 9, 4, "n");
				mvwprintw(listwin, 10, 4, "y");
				mvwprintw(listwin, 11, 4, "c");
				mvwprintw(listwin, 12, 4, "p");
				mvwprintw(listwin, 13, 4, "v");
				mvwprintw(listwin, 17, 3, "Enter the letter of your choice, PRESS ENTER: r");
				wclrtoeol(listwin);
				returnChar = 'r';
				break;
			default:
				mvwprintw(listwin, 9, 3, "(n) Name of the person.");
				mvwprintw(listwin, 10, 3, "(y) Year of birth.");
				mvwprintw(listwin, 11, 3, "(c) City.");
				mvwprintw(listwin, 12, 3, "(p) Phone number.");
				mvwprintw(listwin, 13, 3, "(v) Vaccination status.");
				mvwprintw(listwin, 15, 3, "(r) Return to main menu.");
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 17, 3, "Please enter valid letter of your choice! ");
				wattroff(listwin, A_STANDOUT);
				wclrtoeol(listwin);
				break;
		}
		if(ch == 10 && (returnChar == 'n' || returnChar == 'y' || returnChar == 'c' ||
						returnChar == 'p' || returnChar == 'v' || returnChar == 'r')) break;
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
	
	// Set colors to text
	start_color();
	init_pair(3, COLOR_GREEN, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_WHITE);
	wbkgd(stdscr, COLOR_PAIR(1));
	
	WINDOW* listwin = create_win();

	mvwprintw(listwin, 0, 3, "Features");
	mvwprintw(listwin, 0, 13, "Appointment");
	wattron(listwin, COLOR_PAIR(3));
	wattron(listwin, A_BOLD);
	mvwprintw(listwin, 4, 3, "List all records!");
	wattroff(listwin, A_BOLD);
	wattroff(listwin, COLOR_PAIR(3));
	
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
				wattron(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 9, 4, "a");
				wattroff(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 10, 4, "e");
				mvwprintw(listwin, 13, 4, "r");
				mvwprintw(listwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: a");
				wclrtoeol(listwin);
				returnChar = 'a';
				break;
			case 'e':
				wattron(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 10, 4, "e");
				wattroff(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 9, 4, "a");
				mvwprintw(listwin, 13 ,4, "r");
				mvwprintw(listwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: e");
				wclrtoeol(listwin);
				returnChar = 'e';
				break;
			case 'r':
				wattron(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 13, 4, "r");
				wattroff(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 9, 4, "a");
				mvwprintw(listwin, 10, 4, "e");
				mvwprintw(listwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: r");
				wclrtoeol(listwin);
				returnChar = 'r';
				break;
			default:
				mvwprintw(listwin, 9, 3, "(a) Aphebetical order.");
				mvwprintw(listwin, 10, 3, "(e) Reverse alphabetical order.");
				mvwprintw(listwin, 13, 3, "(r) Return to main menu.");
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 15, 3, "Please enter valid letter of your choice! ");
				wattroff(listwin, A_STANDOUT);
				wclrtoeol(listwin);
				break;
		}
		if(ch == 10 && (returnChar == 'a'|| returnChar == 'e'|| returnChar == 'r')) break;
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
	wattron(listwin, COLOR_PAIR(3));
	wattron(listwin, A_BOLD);
	mvwprintw(listwin, 4, 3, "List all records!");
	wattroff(listwin, A_BOLD);
	wattroff(listwin, COLOR_PAIR(3));
	
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
				wattron(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 9, 4, "a");
				wattroff(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 10, 4, "d");
				mvwprintw(listwin, 13, 4, "r");
				mvwprintw(listwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: a");
				wclrtoeol(listwin);
				returnChar = 'a';
				break;
			case 'd':
				wattron(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 10, 4, "d");
				wattroff(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 9, 4, "a");
				mvwprintw(listwin, 13 ,4, "r");
				mvwprintw(listwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: d");
				wclrtoeol(listwin);
				returnChar = 'd';
				break;
			case 'r':
				wattron(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 13, 4, "r");
				wattroff(listwin, COLOR_PAIR(2));
				mvwprintw(listwin, 9, 4, "a");
				mvwprintw(listwin, 10, 4, "d");
				mvwprintw(listwin, 15, 3, "Enter the letter of your choice, PRESS ENTER: r");
				wclrtoeol(listwin);
				returnChar = 'r';
				break;
			default:
				mvwprintw(listwin, 9, 3, "(a) Ascending order.");
				mvwprintw(listwin, 10, 3, "(d) Descending order.");
				mvwprintw(listwin, 13, 3, "(r) Return to main menu.");
				wattron(listwin, A_STANDOUT);
				mvwprintw(listwin, 15, 3, "Please enter valid letter of your choice! ");
				wattroff(listwin, A_STANDOUT);
				wclrtoeol(listwin);
				break;
		}
		if(ch == 10 && (returnChar == 'a'|| returnChar == 'd'|| returnChar == 'r')) break;
	}  
	destroy_win(listwin);
	return returnChar;
}

void quit_display(){
	initscr(); 
	noecho(); 
	curs_set(0); 

	WINDOW* listwin = create_win();
	destroy_win(listwin);
}
