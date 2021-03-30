// final project

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

// Class that stores a single database record
class person_info {
    private:
        string new_name;
        string dob; 
        string new_city;
        int phone_num; 
        string vaccinated; 

    public: 
        person_info();

        void new_person(); 
        bool valid_name (string user_input);
        bool check_date (int month, int day, int year);
        bool valid_date (string user_input);
        bool valid_city (string city_name);
        bool valid_phone (int num);
        ~person_info();
};

// // Class that stores all record
// class database : public person_info{
//     public:
//     void store();
// };

// // Class that represent Menu
// class menu{

// };

#endif