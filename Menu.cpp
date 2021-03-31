//////////////////////////////////////////////////////

// menu.cpp

#include "database.h"
#include "cmpt_error.h"
#include <iostream>

// Definition
class Menu {
private:
  
public:
  Menu();
  
  void feature_display(){
    //Initiaize the screen 
    initscr();
    echo();

    // Create a window
    // Get size of the user's window
    int height, width;
    getmaxyx(stdscr, height, width);

    WINDOW* win = newwin(height/2, width/2, height/4, width/4);
    box(win, 0, 0);

    mvwprintw(win, 0, 3, "Features");
    mvwprintw(win, 0, 13, "Appointment");

    mvwprintw(win, 4, 3, "Welcome to the Vaccination Database!");
    mvwprintw(win, 5, 3, "====================================");
    mvwprintw(win, 8, 3, "(A) Add new person's information.");
    mvwprintw(win, 9, 3, "(S) Search specific information.");
    mvwprintw(win, 10, 3, "(U) Update vaccination status,");
    mvwprintw(win, 11, 3, "(D) Delete data.");
    mvwprintw(win, 12, 3, "(Q) Quit.");

    mvwprintw(win, 15, 3, "Enter first letter of the feature: ");

    wgetch(win);

    // Deallocate memory and end ncurses
    endwin(); 
  }

  ~Menu();
};

