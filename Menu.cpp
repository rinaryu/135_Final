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
	bool exist_data = new_database.check_data_exist(person);
	
	if (exist_data == true){
		new_database.add_data(person);
	}
	new_database.added_person(exist_data);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//Searches the database using user's choice of field
//User can also decided to delete the searched information
void Menu::searching(char user_input){
	//user_input keeps track of whether the user pressed (s)earching or (d)eleting

	char search_input; //which field the user is searching by (name or city or yob etc) 
	string searchForStr = ""; //which string to search for
	string searchForSubstr = "";
	long long searchForInt = 0; //which number to search for 
	char method; // which method to be used when searching(exact or substr) 
	int lowerYear, upperYear; // range for searching year of birth
	
	search_input = search_display(user_input);

	//returning to main menu display
	if(search_input == 'r') return;
	
	//user chose to search based on vaccination status information
	string vacStatus;
	if(search_input == 'v'){
		endwin();
		cout << "Which vaccination status would you like to search for? (y/n): ";
		cin >> vacStatus;
		
		while(vacStatus != "y" && vacStatus != "n"){
			cout << "That is not a valid input, please re-enter (y/n): ";
			cin >> vacStatus; 
		}
		new_database.search_status(vacStatus);
	}
	//user chose to search a string field (name or city)
	if(search_input == 'n' || search_input == 'c'){
		//determining which method should be used to search string
		method = search_str_display(); 

		if(method == 'r') return;

		if(method == 'e'){// if wants to search using exact occurence
			endwin();
			searchForStr = search_get_input(); //getting cin input
			
			//search_name() will look for exact same input
			// if found; display the record(s), if not found; message not found
			vector<int> track_index;
			if(search_input == 'n') new_database.search_name(searchForStr, track_index);
			if(search_input == 'c') {
				//checks if it's a city in Lower Mainland 
				while(!person.valid_city(searchForStr)){
					cout << "That is not a city in the Lower Mainland, please re-enter: \n";
					searchForStr = search_get_input();
				}
				new_database.search_city(searchForStr);
			}
		} else if(method == 'o'){// if wants to search using substring 
			endwin();
			searchForSubstr = search_get_input();
			//looking using substring 
			if(search_input == 'n') new_database.search_substr_name(searchForSubstr);
			if(search_input == 'c') new_database.search_substr_city(searchForSubstr);
		}
	} 
	else if(search_input == 'p'){//if user searching using phone numbers
		method = search_phone_display();

		if(method == 'r') return;

		if(method == 'e'){//search based on exact phone number 
			endwin();
			searchForInt = search_num_input();
			new_database.search_phone(searchForInt);
		} else if(method == 'a'){ //search based on area code 
			endwin();
			searchForInt = search_num_input();
			while(true){ //checking if input area code is valid
				if(cin.fail()){
					cout << "This is not a number, please re-enter: ";
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> searchForInt;
				}
				if(!person.valid_area(searchForInt)){
					cout << "Please enter a valid area code (must be 3 numbers): ";
					cin >> searchForInt;
				} else if(person.valid_area(searchForInt)) break;
			}
			new_database.search_area_code(searchForInt);
		}
	}
	//user chose to search by exact yob or searches using an interval
	else if (search_input == 'y'){
		method = search_yob_display();

		if(method == 'r') return;
		
		if(method == 'e'){
			endwin();
			// Look for exact year of birth num 
			searchForStr = search_get_input();
			new_database.search_yob(searchForStr);

		} else if (method == 'i'){
			endwin();
			// Search for yob in range from year A to year B
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
		cout << "Do you want to delete these records (y/n)? ";
		string confirmDelete;
		cin >> confirmDelete;
		while(confirmDelete != "y" && confirmDelete != "n"){
			cout << "Please enter a valid answer: ";
			cin >> confirmDelete; 
		}
		
		if (confirmDelete == "y"){
			if (search_input == 'n'){
				if(method == 'e') new_database.delete_name(searchForStr);
				if(method == 'o') new_database.delete_substr_name(searchForSubstr);
			} 
			if (search_input == 'v') new_database.delete_status(vacStatus);

			if (search_input == 'c'){
				if(method == 'e') new_database.delete_city(searchForStr);  
				if(method == 'o') new_database.delete_substr_city(searchForSubstr);
			}   
			if (search_input == 'p'){
				if(method == 'e') new_database.delete_phone(searchForInt);
				if(method == 'a') new_database.delete_phone_area(searchForInt);			
			}
			if (search_input == 'y'){
				if(method == 'e') new_database.delete_yob(searchForStr);
				if(method == 'i') new_database.delete_yob_range(lowerYear, upperYear);
			}
			cout << "Record has been deleted.\n\n";
		
		} else if(confirmDelete == "n"){
			cout << "Record was not deleted.\n\n";
		}
	}
	returning();
}

//user can update selected record 
void Menu::update(){
	char update_input;

	string name;
	cout << "Enter full name of the person whose information you want to update: ";
	if(cin.peek() == '\n') cin.ignore();
	getline(cin, name);
	while(!person.valid_name(name)){
		cout << "That is not a valid name, please provide a different name of alphabetical characters: ";
		getline(cin, name);
	}     
	while(!new_database.person_exists(name)){
		cout << "\nThis person is not in the database.\n";
		cout << "Press (r) to return or re-enter please: ";
		getline(cin, name);
		if(name == "r") return;
	}      
	cout << '\n';

	vector<int> matches_index;
	new_database.search_name(name, matches_index);

 	if (matches_index.size() > 0){
		int record_idx = matches_index.at(0);
		cout << "====================================================\n";
		if(matches_index.size() > 1){
			cout << "Enter the number of the record you want to update: ";
			int record_num;
			cin >> record_num;
			while(true){
				if (record_num < 1 && record_num > matches_index.size()){
					cout << "There are only " << matches_index.size() << " results found.\n";
					cout << "Please re-enter the correct number of the record: ";
					cin >> record_num;
				} else {
					break;
				}
			}
			record_idx = matches_index.at(record_num-1);		
		}
		update_input = update_display();
		endwin();
		
		new_database.update_option(update_input, record_idx);
	}
	
	returning();
}
///////////////////////////////////////Listing Records///////////////////////////////////////
char Menu::listing(){
	char search_input;
	char method;
	string returnResp;

	search_input = list_display();

	if (search_input == 'r') {
		// cout << "Returning...\n";
		// chrono::seconds dura(2);
		// this_thread::sleep_for(dura);
		return search_input;
	}
	
	if(search_input == 'n' || search_input == 'c' || search_input == 'v'){//string fields
		method = list_str_display();
		endwin();
		if(method == 'a'){
			if(search_input == 'n') new_database.list_name_alpha();
			if(search_input == 'c') new_database.list_city_alpha();
			if(search_input == 'v') new_database.list_status_alpha();
			returning();
		} else if (method == 'e'){
			if(search_input == 'n') new_database.list_name_reverse();
			if(search_input == 'c') new_database.list_city_reverse();
			if(search_input == 'v') new_database.list_status_reverse();
			returning();
		}
		
	} else if (search_input == 'y' || search_input == 'p'){//number fields
		method = list_int_display();
		endwin();
		if (method == 'a'){
			if (search_input == 'y') new_database.list_yob_ascend();
			if (search_input == 'p') new_database.list_phone_ascend();
			returning();
		} else if (method == 'd'){
			if (search_input == 'y') new_database.list_yob_descend();
			if (search_input == 'p') new_database.list_phone_descend();
			returning();
		}
	}
	return search_input;
}

//quitting program and creating new txt of the database 
void Menu::quitting(){
	new_database.quitting_save();
	cout << "Successfully quit\n";
}

string Menu::search_get_input(){ 
	cout<<"Please enter what you like to search: ";
	if(cin.peek() == '\n') cin.ignore();
	string search_for;
	getline(cin, search_for);
	return search_for;
}

long long Menu::search_num_input(){
	cout << "Please enter the number you like to search: ";
	long long num;
	cin >> num;
	return num;
}

string Menu::returning(){
	string returnResp;
	cout << "Enter (r) if you would like to return.\n";
	cin >> returnResp;
	while(returnResp != "r"){
		cout << "Invalid response\n";
		cin >> returnResp;
	}
	return returnResp;
}
