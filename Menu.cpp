//////////////////////////////////////////////////////

// menu.cpp

#include "database_head.h"
#include "cmpt_error.h"
#include <iostream>

Menu::Menu(){
  new_database.get_data();
}

void Menu::temp_name(){
  char user_input = feature_display();
  
  char search_input = ''; //which field the user is searching by (name or city or dob etc) 
  string searchForStr = ""; //which string to search for
  int searchForInt = 0; //which in to search for 
  char method = ''; // which method to be used when searching for strings (exact or substr) 
  //***************************************************************************************
  if(user_input == 'a'){
    //Ask user to enter new information in the terminal
    person.new_person();  
    new_database.add_data(person);  
  }
  //***************************************************************************************
  //when deleting -- delete only one record or all records the appear when searched?
  if(user_input == 's' || user_input == 'd'){
    search_input = search_display(user_input);
    //user chose to search a string field 
    if(search_input == 'n' || search_input == 'v' || search_input == 'c'){
      //determining which method should be used to search the name
      method = search_str_display(); 
      if(method == 'e'){  // if wants to search using exact occurence
        searchForStr = search_get_input();

        //search_name() will look for exact same input
        // if found; will cout out the record, if not found; will cout it's not found
        if(search_input == 'n') new_database.search_name(searchForStr);
        if(search_input == 'v') new_database.search_status(searchForStr);
        if(search_input == 'c') new_database.search_city(searchForStr);

      } else if(method == 'o'){ // if wants to search using substring 
        searchForStr = search_get_input();

        //looking using substring 
        if(search_input == 'n') new_database.search_substr_name(searchForStr);
        if(search_input == 'c') new_database.search_substr_city(searchForStr);
      }
    } 
    //user chose to search by dob or phone number 
    //phone number and dob searches by exact match
    //only dob searches using an interval (e.g. people born in 1990 - 2001)
    else if (search_input == 'd' || search_input == 'p'){
      method = search_int_display();
      if(method == 'e'){
        // Look for exact number
        if(search_input == 'd') {
          searchForStr = search_get_input();
          new_database.search_dob(searchForStr);
        } else if (search_input = 'p'){
          searchForInt = search_int_input();
          new_database.search_phone(searchForInt);
        }

      } else if (method == 'i'){
        // Search for DOB in range from year A to year B
        int lowerYear;
        int upperYear;
        cout << "Please enter the lower year limit: ";
        cin >> lowerYear;
        cout << "\n";
        cout << "Please enter the upper year limit: ";
        cin >> upperYear;
        while (lowerYear > upperYear){
          cout << "Please enter the first year smaller than the second year!\n";
          cout << "Please re-enter the lower year limit: ";
          cin >> lowerYear;
          cout << "\n";
          cout << "Please re-enter the upper year limit: ";
          cin >> upperYear;
        }
        new_database.search_range_dob(lowerYear, upperYear);
      }
    }
    if(user_input == 'd' || user_input == 'p')
    //if the user wants to delete the record(s) they searched for
    if(user_input == 'd'){
      cout << "Do you want to delete these records (y/n)?"
      string confirmDelete;
      cin >> confirmDelete;
      while(confirmDelete != "y" || confirmDelete != "n"){
        cout << "Please enter a valid answer: ";
        cin >> confirmDelete; 
      }
      if (confirmDelete == "y"){
        if (search_input == 'n') new_database.delete_name(searchForStr);
        //if (search_input == 'v') ;-; 
        //if (search_input == 'c')
        if (search_input == 'p') new_database.delete_phone(searchForInt);
        if (search_input == 'd') new_database.delete_dob(searchForStr);
      }
    }
    //search_menu(search_input);
  }
//***************************************************************************************
  if(user_input == 'u'){
    //update
  }
//***************************************************************************************
  if(user_input == 'l'){
    //list records.

  }
  //***************************************************************************************
  if(user_input == 'q'){
    //export the current database array into textfile
    //exit the program
  }
  //***************************************************************************************
}

string Menu::search_get_input(){ 
  cout<<"Please enter what you like to search: ";
  string search_for;
  cin >> search_for; 
  return search_for;
}

int Menu::search_num_input(){
  cout << "Please enter number you like to search: ";
  int num;
  cin >> num;
  return num;
}
////////////NOTE///////////////////
//Fix Person_info::new_person() with cout
// char Menu::add_display(){}



