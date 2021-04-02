//////////////////////////////////////////////////////

// menu.cpp

#include "database_head.h"
#include "cmpt_error.h"
#include <iostream>

//creates the main menu display windows 
void Menu::feature_display(){
  
	//Initiaize the screen 
  initscr();  
  noecho(); //hides user input from window
  curs_set(0); //hides screen cursor

  // Create a window
  // Get size of the user's window
  int height, width;
  getmaxyx(stdscr, height, width);

  mainwin = newwin(height/2, width/2, height/4, width/4);
  
  box(mainwin, 0, 0);


  mvwprintw(mainwin, 0, 3, "Features");
  mvwprintw(mainwin, 0, 13, "Appointment");

  mvwprintw(mainwin, 4, 3, "Welcome to the Vaccination Database!");
  mvwprintw(mainwin, 5, 3, "====================================");
  mvwprintw(mainwin, 8, 3, "(a) Add new person's information.");
  mvwprintw(mainwin, 9, 3, "(s) Search specific information.");
  mvwprintw(mainwin, 10, 3, "(u) Update vaccination status,");
  mvwprintw(mainwin, 11, 3, "(d) Delete data.");
  mvwprintw(mainwin, 12, 3, "(q) Quit.");

  //detecting which option is being pressed by the user 
  char ch = ' ';
  while(ch == wgetch(mainwin)){
    switch(ch){
      case 'a':
        wattron(mainwin, A_STANDOUT);
        mvwprintw(mainwin, 8, 4, "a");
        wattroff(mainwin, A_STANDOUT);
        mvwprintw(mainwin, 9, 4, "s");
        mvwprintw(mainwin, 10, 4, "u");
        mvwprintw(mainwin, 11 ,4, "d");
        break;
      case 's':
        wattron(mainwin, A_STANDOUT);
        mvwprintw(mainwin, 9, 4, "s");
        wattroff(mainwin, A_STANDOUT);
        mvwprintw(mainwin, 8, 4, "a");
        mvwprintw(mainwin, 10, 4, "u");
        mvwprintw(mainwin, 11 ,4, "d");
        break;
      case 'u':
        wattron(mainwin, A_STANDOUT);
        mvwprintw(mainwin, 10, 4, "u");
        wattroff(mainwin, A_STANDOUT);
        mvwprintw(mainwin, 8, 4, "a");
        mvwprintw(mainwin, 9, 4, "s");
        mvwprintw(mainwin, 11 ,4, "d");
        break;
      case 'd':
        wattron(mainwin, A_STANDOUT);
        mvwprintw(mainwin, 11 ,4, "d");
        wattroff(mainwin, A_STANDOUT);
        mvwprintw(mainwin, 8, 4, "a");
        mvwprintw(mainwin, 9, 4, "s");
        mvwprintw(mainwin, 10, 4, "u");
        break;
      default:
        mvwprintw(mainwin, 8, 3, "(a) Add new person's information.");
        mvwprintw(mainwin, 9, 3, "(s) Search specific information.");
        mvwprintw(mainwin, 10, 3, "(u) Update vaccination status,");
        mvwprintw(mainwin, 11, 3, "(d) Delete data.");
        break;
    }
  }    
}

void Menu::deleteWin(WINDOW* win){
  delwin(win);
}

//creates a new window 
// void Menu::newWin(){
//   initscr();
//   noecho();
//   cur_set(0);



// }




    

