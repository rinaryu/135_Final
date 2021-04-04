//////////////////////////////////////////////////////

// menu.cpp

#include "database_head.h"
#include "cmpt_error.h"
#include <iostream>

//destroys a window
void Menu::destroy_win(WINDOW *deleteWin){
  wborder(deleteWin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  wrefresh(deleteWin);
  delwin(deleteWin);
}

//creates a new window
WINDOW* Menu::create_win(){
  int h, w;
  getmaxyx(stdscr, h, w);

  WINDOW* tempwin = newwin(h/2, w/2, h/4, w/4);
  box(tempwin, 0, 0);
  refresh();

  return tempwin; 
}

//creates main menu display of database 
char Menu::feature_display(){
  char returnChar = '0'; //gets returned -- used to keep detect which option was chosen by user when in the main menu 
  
	//Initiaize the screen 
  initscr();  
  noecho(); //hides user input from window
  curs_set(0); //hides screen cursor

  WINDOW* mainwin = create_win();

  mvwprintw(mainwin, 0, 3, "Features");
  mvwprintw(mainwin, 0, 13, "Appointment");

  mvwprintw(mainwin, 4, 3, "Welcome to the Vaccination Database!");
  mvwprintw(mainwin, 5, 3, "====================================");
  mvwprintw(mainwin, 8, 3, "(a) Add new person's information.");
  mvwprintw(mainwin, 9, 3, "(s) Search specific information.");
  mvwprintw(mainwin, 10, 3, "(u) Update vaccination status.");
  mvwprintw(mainwin, 11, 3, "(l) List all records.");
  mvwprintw(mainwin, 12, 3, "(d) Delete data.");
  mvwprintw(mainwin, 13, 3, "(q) Quit.");

  mvwprintw(mainwin, 15, 3, "Press a key to choose one feature!");

  //detecting which option is being pressed by the user 
  char ch;
  while(ch = wgetch(mainwin)){
    switch(ch){
      case 'a':
        wattron(mainwin, A_STANDOUT);
        mvwprintw(mainwin, 8, 4, "a");
        wattroff(mainwin, A_STANDOUT);
        mvwprintw(mainwin, 9, 4, "s");
        mvwprintw(mainwin, 10, 4, "u");
        mvwprintw(mainwin, 11, 4, "l");
        mvwprintw(mainwin, 12 ,4, "d");
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
        returnChar = 'd';
        break;
      default:
        mvwprintw(mainwin, 8, 3, "(a) Add new person's information.");
        mvwprintw(mainwin, 9, 3, "(s) Search specific information.");
        mvwprintw(mainwin, 10, 3, "(u) Update vaccination status.");
        mvwprintw(mainwin, 11, 3, "(l) List all records.");
        mvwprintw(mainwin, 12, 3, "(d) Delete data.");
        break;
    }
    if(ch == 10) break;
  }  
    destroy_win(mainwin);
    return returnChar;
}

////////////////////text based version of adding new person to database//////////////////
//probably delete later :P 
// void Menu::add_person(){
//   person.new_person();

//   string name = person.get_name();
//   string dob = person.get_dob();
//   string city = person.get_city();
//   int phone = person.get_phone();
//   string status = person.get_status();

//   string new_info = name + " " + dob + " " + city + " " + to_string(phone) + " " + status;
//   cout << "This is the information you have entered into the database.\nReturning to main menu...\n";

//   //add new info to database

// }
//////////////////////////////////////////////////////////////////////////////////////////////////////



/*
////////////NOTE///////////////////
//Fix Person_info::new_person() with cout
char Menu::add_display(){}

char Menu::search_display(){
  char returnChar = '0';
  newWin();

  // Create new window
  int height, width;
  getmaxyx(stdscr, height, width);

  mainwin = newwin(height/2, width/2, height/4, width/4);
  box(mainwin, 0, 0);

  mvwprintw(mainwin, 0, 3, "Features");
  mvwprintw(mainwin, 0, 13, "Appointment");

  mvwprintw(mainwin, 4, 3, "Search specific information!");
  mvwprintw(mainwin, 5, 3, "============================");
  mvwprintw(mainwin, 8, 3, "You can search by: ");
  mvwprintw(mainwin, 9, 3, "(n) Name of the person.");
  mvwprintw(mainwin, 10, 3, "(d) Date of birth.");
  mvprinttw(mainwin, 11, 3, "(c) City.")
  mvwprintw(mainwin, 12, 3, "(p) Phone number.");
  mvwprintw(mainwin, 13, 3, "(v) Vaccination status.");

  mvprinttw(mainwin, 15, 3, "(r) Return to main menu.");
  mvprintw(mainwin, 17, 3, "Press a key to choose one option!");
  //Detecting which option is pressed by the user.

  return returnChar;
}

char Menu::search_option(char enterChar){

}


char Menu::update_display(){
  newWin();

  // Create new window
  int height, width;
  getmaxyx(stdscr, height, width);

  mainwin = newwin(height/2, width/2, height/4, width/4);
  box(mainwin, 0, 0);

  mvwprintw(mainwin, 0, 3, "Features");
  mvwprintw(mainwin, 0, 13, "Appointment");

  mvwprintw(mainwin, 4, 3, "Update specific information!");
  mvwprintw(mainwin, 5, 3, "============================");
  mvwprintw(mainwin, 8, 3, "You can update by: ");
  mvwprintw(mainwin, 9, 3, "(n) Name of the person.");
  mvwprintw(mainwin, 10, 3, "(d) Date of birth.");
  mvprinttw(mainwin, 11, 3, "(c) City.")
  mvwprintw(mainwin, 12, 3, "(p) Phone number.");
  mvwprintw(mainwin, 13, 3, "(v) Vaccination status.");

  mvprinttw(mainwin, 15, 3, "(r) Return to main menu.");
  mvprinttw(mainwin, 17, 3, "Press a key to choose one option!")
  //Detecting which option is pressed by the user.
}

char Menu::list_display(){
  char returnChar;
  newWin();

  // Create new window
  int height, width;
  getmaxyx(stdscr, height, width);

  mainwin = newwin(height/2, width/2, height/4, width/4);
  box(mainwin, 0, 0);

  mvwprintw(mainwin, 0, 3, "Features");
  mvwprintw(mainwin, 0, 13, "Appointment");

  mvwprintw(mainwin, 4, 3, "List all record!");
  mvwprintw(mainwin, 5, 3, "============================");
  mvwprintw(mainwin, 8, 3, "You can list records in order of: ");
  mvwprintw(mainwin, 9, 3, "(n) Name of the person.");
  mvwprintw(mainwin, 10, 3, "(d) Date of birth.");
  mvprinttw(mainwin, 11, 3, "(c) City.")
  mvwprintw(mainwin, 12, 3, "(p) Phone number.");
  mvwprintw(mainwin, 13, 3, "(v) Vaccination status.");

  mvprinttw(mainwin, 15, 3, "(r) Return to main menu.");
  mvprinttw(mainwin, 17, 3, "Press a key to choose one option!")
  //Detecting which option is pressed by the user.

  return returnChar;
}

char Menu::order_option(char enterChar){
  char returnChar;
  newWin();

  //Create new window
  int height, width;
  getmaxyx(stdscr, height, width);

  mainwin = newwin(height/2, width/2, height/4, width/4);
  box(mainwin, 0, 0);

  mvwprintw(mainwin, 0, 3, "Features");
  mvwprintw(mainwin, 0, 13, "Appointment");

  mvwprintw(mainwin, 4, 3, "Choose order of listing!");
  mvwprintw(mainwin, 5, 3, "============================");
  mvwprintw(mainwin, 8, 3, "You can list records in: ");

  if(enterChar == 'n' || enterChar == 'c' || enterChar == 'v'){
    mvprintw(mainwin, 9, 3, "(a) Alphabetical order.");
    mvprintw(mainwin, 10, 3, "(r) Reverse alphbetical order.");
  } else if (enterChar == 'd' || enterChar == 'p'){
    mvprintw(mainwin, 9, 3, "(a) Ascending order.");  
    mvprintw(mainwin, 10, 3, "(d) Descending order.");  
  }
  
  mvprinttw(mainwin, 15, 3, "(b) Bac to main menu.");
  mvprinttw(mainwin, 17, 3, "Press a key to choose one option!")
  //Detecting which option is pressed by the user.

  return returnChar;
}
*/


