//Header file
////////////////////////////////////////////////
//contents:
// - all #include's 
// - declares methods from Person_info, Database and Menu classes 

#ifndef DATABASE_H
#define DATABASE_H

#include "cmpt_error.h"
#include <cassert>
#include <iomanip>
#include <ncurses.h>
#include <fstream>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

//Person_info class
class Person_info{
private:
	string new_name;
	string dob; 
	string new_city;
	int phone_num; 
	string vaccinated; 
    
public:
	void new_person(); 
	string get_name() const;
	string get_dob() const;
	string get_city() const;
	int get_phone() const;
	string get_status() const;

	void Person_info::set_name(string name);
	void Person_info::set_dob(string data);
	void Person_info::set_city(string city);
	void Person_info::set_phone(int phone);
	void Person_info::set_status(string status);

	bool valid_name (string user_input);
	bool check_date (int month, int day, int year);
	bool valid_date (string user_input);
	bool valid_city (string city_name);
	bool valid_phone (int num);
	~Person_info();
};


//Database class 
class Database{
private:
	string* per_person;
	int size;
	int capacity;
	Person_info* new_data;

public:
	Database(int sz, int cap);
	int get_size() const;
	int get_cap() const;
	void get_data();
	void resize();
	void search_name (string name);
	void search_dob (string dob);
	void search_city (string city);
	void search_phone (int phone);
	void search_substr(string findData);
	string print_record (int i);

	void list_name_alpha();
	void list_name_reverse();
	void list_dob_ascend();
	void list_phone_ascend();
	void list_dob_descend();
	void list_phone_descend();
	~Database();
};

//Menu class 
class Menu;
void feature_display();

#endif
