//implements methods from: Database and Person_info class
//as well as functions from display cpp file
#include "database_head.h"
#include <iostream>
using namespace std;

Menu::Menu(){
  new_database.get_data();
}

//gathers input for a new person and adds it to the database
void Menu::adding(){
  //Ask user to enter new information in the terminal
  person.new_person();  
  new_database.add_data(person);  
  // new_database.print_all();
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//searches the database using user's choice of field
//user can also decided to delete the searched information
/////////////////////////////////////////////////////////////////////////////////////////////////
void Menu::searching(char user_input){
  //user_input keeps track of whether the user pressed (s)earching or (d)eleting
  

  char search_input; //which field the user is searching by (name or city or yob etc) 
  string searchForStr = ""; //which string to search for
  string searchForSubstr = "";
  long long searchForInt = 0; //which in to search for 
  char method; // which method to be used when searching for strings (exact or substr) 
 
  search_input = search_display(user_input);

  if(search_input == 'r'){ //returning to main menu display
    cout<< "Returning...\n";
    //pauses program (so user can see messages printed to terminal before returning to main menu)
    chrono::seconds dura(2);
    this_thread::sleep_for(dura);
    //return search_input; 
  }

  //user chose to search based on vaccination status information
  if(search_input == 'v'){
    endwin();
    cout << "Which vaccination status would you like to search for? (y/n): ";
    string vacStatus;
    cin >> vacStatus;
    while(vacStatus != "y" && vacStatus != "n"){
      cout << "That is not a valid input, please re-enter (y/n): ";
      cin >> vacStatus; 
    }
    new_database.search_status(vacStatus);
  }

  //user chose to search a string field 
  if(search_input == 'n' || search_input == 'c'){

    if(search_input == 'r'){ //returning to main menu display
      cout<< "Returning...\n";
      chrono::seconds dura(2);
      this_thread::sleep_for(dura);
    }

    //determining which method should be used to search the name
    method = search_str_display(); 

    if(method == 'e'){  // if wants to search using exact occurence
      endwin();
      searchForStr = search_get_input();
      //search_name() will look for exact same input
      // if found; will cout out the record, if not found; will cout it's not found
      if(search_input == 'n') new_database.search_name(searchForStr);
      // if(search_input == 'v') new_database.search_status(searchForStr);
      if(search_input == 'c') {
        //checks if it's a city in Lower Mainland 
        while(!person.valid_city(searchForStr)){
          cout << "That is not a city in the Lower Mainland, please re-enter: \n";
          searchForStr = search_get_input();
        }
        new_database.search_city(searchForStr);
      }
    } else if(method == 'o'){ // if wants to search using substring 
      endwin();
      searchForSubstr = search_get_input();

      //looking using substring 
      if(search_input == 'n') new_database.search_substr_name(searchForSubstr);
      if(search_input == 'c') new_database.search_substr_city(searchForSubstr);
    }
  } 
  //user chose to search by yob or phone number 
  //phone number and yob searches by exact match
  //only yob searches using an interval (e.g. people born in 1990 - 2001)
  else if (search_input == 'd' || search_input == 'p'){
      
    if(search_input == 'r'){ //returning to main menu display
      cout<< "Returning...\n";
      chrono::seconds dura(2);
      this_thread::sleep_for(dura);
      //return search_input; 
    }

    method = search_int_display();
    if(method == 'e'){
    	endwin();
      // Look for exact number
      if(search_input == 'd') {
        searchForStr = search_get_input();
        new_database.search_yob(searchForStr);
      } else if (search_input == 'p'){
        searchForInt = search_num_input();
        new_database.search_phone(searchForInt);
      }

    } else if (method == 'i'){
    	endwin();
      // Search for yob in range from year A to year B
      int lowerYear;
      int upperYear;
      cout << "Please enter the lower year limit: ";
      cin >> lowerYear;

      //makes sure the lower year input is a valid year 
      while(lowerYear > 2003 || lowerYear < 1940){
        cout << "That is not a valid year, it must be after 1940 and before 2005.\n";
        cout << "Please re-enter: ";
        cin >> lowerYear; 
      }
      cout << "\n";
      cout << "Please enter the upper year limit: ";
      cin >> upperYear;

      //makes sure the upper year input is a valid year
      while(upperYear > 2003 || upperYear < 1940){
        cout << "That is not a valid year, it must be after 1940 and before 2005.\n";
        cout << "Please re-enter: ";
        cin >> upperYear;
      }

      //makes sure the lower year is less than the upper year input
      while (lowerYear > upperYear){
        cout << "Please enter the first year smaller than the second year!\n";
        cout << "Please re-enter the lower year limit: ";
        cin >> lowerYear;
        cout << "\n";
        cout << "Please re-enter the upper year limit: ";
        cin >> upperYear;
      }
      new_database.search_range_yob(lowerYear, upperYear);
    }
  }
  //if the user wants to delete the record(s) they searched for
  if(user_input == 'd'){
    cout << "Do you want to delete these records (y/n)?";
    string confirmDelete;
    cin >> confirmDelete;
    while(confirmDelete != "y" || confirmDelete != "n"){
      cout << "Please enter a valid answer: ";
      cin >> confirmDelete; 
    }
    if (confirmDelete == "y"){
      if (search_input == 'n') new_database.delete_name(searchForStr);
      if (search_input == 'v') new_database.delete_status(vacStatus);
      if (search_input == 'c') new_database.delete_city(searchForStr);      
      if (search_input == 'p') new_database.delete_phone(searchForInt);
      if (search_input == 'd') new_database.delete_yob(searchForStr);
      cout << "Record has been deleted.\nReturning to main menu...";
    }
     else if(confirmDelete == "n"){
      cout << "Record was not deleted.\nReturning to main menu...";
     }
  }
    //return user_input; //user_input should either be 's' or 'd' 
}


// //user can update selected record 
// void Menu::update(){
  
// }

//list records.
char Menu::list(){
  char search_input;
  char method;
  string returnResp;

  search_input = list_display();
  if (search_input == 'r') {
    cout << "Returning...\n";
    chrono::seconds dura(2);
    this_thread::sleep_for(dura);
    return search_input;
  }
  if(search_input == 'n' || search_input == 'c' || search_input == 'v'){
    method = list_str_display();
    endwin();
    if(method == 'a'){
      if(search_input == 'n') new_database.list_name_alpha();
    } else if (method == 'e'){
      if(search_input == 'n') new_database.list_name_reverse();
    }
  } else if (search_input == 'd' || search_input == 'p'){
    method = list_int_display();
    endwin();
    if (method == 'a'){
      if (search_input == 'd') new_database.list_yob_ascend();
      if (search_input == 'p') new_database.list_phone_ascend();
    } else if (method == 'd'){
      if (search_input == 'd') new_database.list_yob_descend();
      if (search_input == 'p') new_database.list_phone_descend();
    }
  }
  cout << "Enter (r) if you would like to return.\n";
  cin >> returnResp;
  while(returnResp != "r"){
    cout << "Invalid response\n";
    cin >> returnResp;
  }
  search_input = 'r';
  cout << "Returning...\n";
  chrono::seconds dura(3);
  this_thread::sleep_for(dura);
  return search_input;
}

//quitting program and creating new txt of the database 
void Menu::quit(){
  new_database.quitting_save();

  cout<<"Successfully quit\n";
}

string Menu::search_get_input(){ 
  cout<<"Please enter what you like to search: ";
  string search_for;
  getline(cin, search_for); 
  return search_for;
}

long long Menu::search_num_input(){
  cout << "Please enter number you like to search: ";
  long long num;
  cin >> num;
  return num;
}

////////////NOTE///////////////////
//Fix Person_info::new_person() with cout
// char Menu::add_display(){}

