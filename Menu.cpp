//////////////////////////////////////////////////////

// menu.cpp

#include "database_head.h"
#include "cmpt_error.h"
#include <iostream>

//destroys a window
/*void Menu::destroy_win(WINDOW *deleteWin){
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



////////////NOTE///////////////////
//Fix Person_info::new_person() with cout
char Menu::add_display(){}
*/


