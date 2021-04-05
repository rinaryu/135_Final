//Person_info.cpp
//Contains Person_info class 
//////////////////////////////////////////////////////////////////////////////////////
//This class:
// - gets user input to add new information into the database
// - also makes sure that input is valid for all fields

#include "database_head.h"
#include "cmpt_error.h"
#include <iostream>
using namespace std;

//getter methods
string Person_info::get_name() const {return new_name;}
string Person_info::get_dob() const {return dob;}
string Person_info::get_city() const {return new_city;}
int Person_info::get_phone() const {return phone_num;}
string Person_info::get_status() const {return vaccinated;}

//setter methods
void Person_info::set_name(string name) {new_name = name;}
void Person_info::set_dob(string date) {dob = date;}
void Person_info::set_city(string city) {new_city = city;}
void Person_info::set_phone(int phone) {phone_num = phone;}
void Person_info::set_status(string status) {vaccinated = status;}

//Method used to get user input to enter new person into the database.
void Person_info::new_person (){
	//First: Getting name of new person to be added. 
	cout << "To enter a new person in the database, first provide their first and last name: \n";
	getline(cin, new_name); 
	//call valid_name to check if user input is valid (is a valid name) 
	if(!valid_name(new_name)){
	    while(true){
			cout<<"That is not a valid name, please provide a different name of alphabetical characters: \n";
			getline(cin, new_name);
			if(valid_name(new_name)) break; 
	    }              
	}
	//Second: Getting birthday of new person. 
	cout << "Please enter their date of birth.\nThe data must be in the following format of, MM/DD/YYYY (eg. 04/07/1999): \n";
	getline(cin, dob);
	while(true){
	    if(!(dob.at(2) == '/') && !(dob.at(5) == '/')){
			cout<<"The date of birth is not in the correct format, please re-enter: \n";
			getline(cin, dob);
			continue;
	    }
	    if(!valid_date(dob)){
			cout<<"That is not a valid date of birth, please re-enter: \n";
			getline(cin, dob);
			if(valid_date(dob)) break;
	    }
	}
	//Third: Getting the city that the new person resides in. 
	cout<<"Please enter the city in the Lower Mainland that they reside in: \n";
	getline(cin, new_city);
	//changing the user input to all lowercase letters
	for(int i = 0; i < new_city.size(); i++){
	    new_city.at(i) = towlower(new_city.at(i));
	}
	cout<<"new_city: "<<new_city<<endl;
	if(!valid_city(new_city)){
	    while(true){
			cout<<"That is not a valid city, please enter a city in the Lower Mainland: \n";
			getline(cin, new_city);
			//changing the user input to all lowercase letters
			for(int i = 0; i < new_city.size(); i++){
				new_city.at(i) = towlower(new_city.at(i));
			}
			if(valid_city(new_city)) break;
	    }
	}
	//Fourth: Getting phone number of new person. 
	cout<<"Please enter their phone number: \n";
	cin >> phone_num;
	while(true){
		if(cin.fail()){
			cout<<"This is not a number, please re-enter: \n";
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> phone_num;
		}
		if(valid_phone(phone_num)) break; 
		else {
			cout<<"This is not a valid phone number, please re-enter: \n";
			cin >> phone_num;
		}
	}
	//Fifth: Getting if new person is vaccinated or not. 
	cout<<"Is the new person vaccinated? (y/n)";
	getline(cin, vaccinated);
	while(true){
	    if(vaccinated == "y" || vaccinated == "n") break;
	    else{
			cout<<"That is not a valid answer: please enter y or n.\n";
			getline(cin, vaccinated);
	    }
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//helper methods that check validity of input for each field in the database
//////////////////////////////////////////////////////////////////////////////////////////////////

//checks if new person's name input is valid (string with only alpha chars) 
bool Person_info::valid_name (string user_input){
    for (int i = 0; i < user_input.size(); i++){
	    if (!isalpha(user_input.at(i))){
			return 0;
	    } 
	}
	return 1;
}
//checks if new person's DOB is valid
bool Person_info::check_date (int month, int day, int year){
	if (month < 0 || month > 12) return 0;

	if (month == 2){
	    if (year % 4 == 0){
			if (day > 29 || day < 0) return 0;
	    } else {
			if (day > 28 || day < 0) return 0;
	    } 
	} 
	else if (month == 1 || month == 3 || month == 5 ||
		    month == 7 || month == 8 || month == 10 ||
		    month == 12){
	    if (day > 31 || day < 0) return 0;
	} else {
	    if (day > 30 || day < 0) return 0;
	}

	if (year < 1940 || year > 2005) return 0;

	return 1;
}
bool Person_info::valid_date (string user_input){
	// MM/DD/YYYY
	int month = stoi (user_input.substr(0, 2));
	int day = stoi (user_input.substr(3, 2));
	int year = stoi (user_input.substr(6, 4));

	return check_date(month, day, year);
}

//checks if user entered city is valid
bool Person_info::valid_city(string city_name){
	//importing list of all cities in Lower Mainland 
	vector<string> cities;
	ifstream fin("lowermainland_cities.txt");
	if(fin.fail()) cmpt::error("Importing city text file failed");
	while(true){
	    string city;
	    getline(fin, city);
	    if(fin.fail()) break;
	    cities.push_back(city);
	}
	fin.close(); 
	//checking if valid with user input  
	for(string x : cities){
	    if(x == city_name) return 1;
	}
	return 0; 
}
//check if user entered phone number is valid
bool Person_info::valid_phone (int num){
	vector<string> area_codes = {"604", "778", "236","672","250"};
	string temp_num = to_string(num);
	if(temp_num.size() == 7){
	    for(string code : area_codes){
			if(temp_num.substr(0,3) == code) return 1;
	    }
	} 
	return 0;
}

Person_info::~Person_info(){}