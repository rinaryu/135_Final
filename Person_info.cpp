//Person_info.cpp
//Contains Person_info class 
//////////////////////////////////////////////////////////////////////////////////////////////////
//This class:
// - gets user input to add new information into the database
// - also makes sure that input is valid for all fields

#include "database_head.h"
#include <iostream>
using namespace std;

Person_info::Person_info(){} //nothing

//Getter methods
string Person_info::get_name() const {return new_name;}
string Person_info::get_yob() const {return yob;}
string Person_info::get_city() const {return new_city;}
long long Person_info::get_phone() const {return phone_num;}
string Person_info::get_status() const {return vaccinated;}

//Setter methods
void Person_info::set_name(string name) {new_name = name;}
void Person_info::set_yob(string year) {yob = year;}
void Person_info::set_city(string city) {new_city = city;}
void Person_info::set_phone(long long phone) {phone_num = phone;}
void Person_info::set_status(string status) {vaccinated = status;}

//Method used to ask user input to enter new person into the database.
void Person_info::new_person (){
	//First: Getting name of new person to be added. 
	cout << "ADDING NEW PERSON\n";
	cout << "=================\n";
	cout << "To enter a new person in the database, first provide their first and last name: ";
	if(cin.peek() == '\n') cin.ignore();
	getline(cin, new_name); 
	//Call valid_name to check if user input is valid (is a valid name) 
	if(!valid_name(new_name)){
		while(true){
			cout << "That is not a valid name, please provide a different name of alphabetical characters: ";
			if(cin.peek() == '\n') cin.ignore();
			getline(cin, new_name);
			if(valid_name(new_name)) break; 
		}              
	}
	cout << '\n';

	//Second: Getting birthday of new person. 
	cout << "Please enter their year of birth: ";
	if(cin.peek() == '\n') cin.ignore();
	getline(cin, yob);
	while(true){
		if(!valid_year(yob)){
			cout << "That is not a valid year of birth, please re-enter (from 1940 to 2003): ";
			if(cin.peek() == '\n') cin.ignore();
			getline(cin, yob);
		}
		if(valid_year(yob)) break;
	}
	cout << '\n';

	//Third: Getting the city that the new person resides in. 
	cout << "Please enter the city in the Lower Mainland that they reside in: ";
	if(cin.peek() == '\n') cin.ignore();
	getline(cin, new_city);
	//Changing the user input to all lowercase letters
	for(int i = 0; i < new_city.size(); i++) new_city.at(i) = towlower(new_city.at(i));

	if(!valid_city(new_city)){
		while(true){
			cout << "That is not a valid city, please enter a city in the Lower Mainland: ";
			if(cin.peek() == '\n') cin.ignore();
			getline(cin, new_city);
			//Changing the user input to all lowercase letters
			for(int i = 0; i < new_city.size(); i++) new_city.at(i) = towlower(new_city.at(i));

			if(valid_city(new_city)) break;
		}
	}
	new_city.at(0) = toupper(new_city.at(0));
	cout << '\n';

	//Fourth: Getting phone number of new person. 
	cout << "Please enter their phone number: ";
	if(cin.peek() == '\n') cin.ignore();
	cin >> phone_num;
	while(true){
		if(cin.fail() || !valid_phone(phone_num)){
			cout << "This is not a valid phone number in BC, please re-enter: ";
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> phone_num;
		} 
		if(valid_phone(phone_num)) break;
	}
	cout << '\n';

	//Fifth: Getting if new person is vaccinated or not. 
	cout << "Is the new person vaccinated? (y)es or (n)o: ";
	if(cin.peek() == '\n') cin.ignore();
	cin >> vaccinated;
	while(vaccinated != "y" && vaccinated != "n"){
		cout<<"That is not a valid answer, please enter y or n: ";
		cin >> vaccinated;
	}
	vaccinated = toupper(vaccinated.at(0));
	cout << '\n';
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//Helper methods that check validity of input for each field in the database

//First: Checks if new person's name input is valid (string with only alpha chars) 
bool Person_info::valid_name (string user_input){
	for (int i = 0; i < user_input.size(); i++){
		if (!isalpha(user_input[i]) && user_input.at(i) != ' '){
			// is not a char
			return 0;
		} 
	}
	return 1;
}

//Second: Checks if new person's DOB is valid
bool Person_info::check_year (int year){
	// Between range 18 to 80 years old.
	if (year < 1940 || year > 2003) return 0;
	return 1;
}

bool Person_info::valid_year(string user_input){
	for (int i = 0; i < user_input.size(); i++){
		if (!(user_input[i] >= '0' && user_input.at(i) <= '9')){
			return 0;
		} 
	}
	int year = stoi(user_input);
	return check_year(year);
}

//Third: Checks if user entered the city is valid
bool Person_info::valid_city(string city_name){
	//making input city lower case letters 
	for(int i = 0; i < city_name.size(); i++) city_name.at(i) = towlower(city_name.at(i));
	
	//importing list of all cities in Lower Mainland 
	vector<string> cities;
	ifstream fin("lowermainland_cities.txt");
	if(fin.fail()) cmpt::error("Importing city text file failed.\n");
	
	while(true){
		string city;
		getline(fin, city);
		if(fin.fail()) break;
		cities.push_back(city);
	}
	fin.close(); 
	
	//checking if valid with user input  
	for(string x : cities) if(x == city_name) return 1;
	return 0; 
}

//Fourth: Check if user entered valid phone number in BC
bool Person_info::valid_phone (long long num){
	vector<string> area_codes = {"604", "778", "236","672","250"};
	string temp_num = to_string(num);
	if(temp_num.size() == 10){
		for(string code : area_codes) if(temp_num.substr(0,3) == code) return 1;
	} 
	return 0;
}

bool Person_info::valid_area(int code){
	vector<string> area_codes = {"604", "778", "236","672","250"};
	string temp_code = to_string(code);
	if(temp_code.size() == 3){
		for(string x : area_codes) if(x == temp_code) return 1;
	}
	return 0;
}
Person_info::~Person_info(){}
