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
    bool valid_name (string user_input);
    bool check_date (int month, int day, int year);
    bool valid_date (string user_input);
    bool valid_city (string city_name);
    bool valid_phone (int num);
};

//Database class 
class Database;
void get_data();
void resize();
void search_name (string name);
void search_dob (string dob);
void search_city (string city);
void search_phone (string phone);
void search_substr(string findData);
string print_record (int i);

void list_name_alpha();
void list_name_reverse();
void list_dob_ascend();
void list_phone_ascend();
void list_dob_descend();
void list_phone_descend(){}


//Menu class 
class Menu;
void feature_display();

#endif