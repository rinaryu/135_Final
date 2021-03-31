// Database.cpp
//This contains the class "Database" 
/////////////////////////////////////////////////////////////////////////////
//This class:
// - gets and stores the data from database.txt 
// - sorts the data from alphabetical order to reverse alphabetical order 
// - includes a searching feature to find specific data 

#include "database_head.h"
#include "cmpt_error.h"
#include <iostream>


Database::Database(int sz, int cap)
: size(sz), capacity(cap), new_data(new Person_info[cap])
{}

int Database::get_size() const {return size;}
int Database::get_cap() const {return capacity;}
// Resize array
void Database::resize(){
    if (size >= capacity){
        Person_info* temp_arr = new Person_info[capacity * 2];
        int i;
        for(i = 0; i < size; i++){
            temp_arr[i] = new_data[i];
        }

        delete[] new_data;
        new_data = temp_arr;
        capacity *= 2;
        size = i;
    }
}

//gets data from database.txt
//ADD: substr each element in temp_data arry to be respective Person_info variable type 
/*void Database::get_data(){
    int count = 0;
    string temp_data[50] // data's size may change later if we add more to database.txt 
    ifstream fin("database.txt");
    while(count < 50){
        string info;
        getline(fin, info);
        data[count] = info;
        count++
    }
}*/



// Finding a Record
    // 1st Method: type-in string EXACTLY matched the appropriate field
void Database::search_name (string name){
    int count_match = 0;
    for (int i = 0; i < size; i++){
        if (new_data[i].get_name() == name){
            cout << print_record(i) << endl;
            count_match++;
        }
    }
    if (count_match == 0){
        cout << "No matching person's name found!\n";
    }
}

void Database::search_dob (string dob){
    int count_match = 0;
    // NOTE: check for the right format search of dob
    for (int i = 0; i < size; i++){
        if (new_data[i].get_dob() == dob){
            cout << print_record(i) << endl;
            count_match++;
        }
    }
    if (count_match == 0){
        cout << "No matching person's date of birth found!\n";
    }
}

void Database::search_city (string city){
    int count_match = 0;
    for (int i = 0; i < size; i++){
        if (new_data[i].get_city() == city){
            cout << print_record(i) << endl;
            count_match++;
        }
    }
    if (count_match == 0){
        cout << "No matching city found!\n";
    }
}
void Database::search_phone (int phone){
    int count_match = 0;
    for (int i = 0; i < size; i++){
        if (new_data[i].get_phone() == phone){
            cout << print_record(i) << endl;
            count_match++;
        }
    }
    if (count_match == 0){
        cout << "No matching person's phone number found!\n";
    }
}

string Database::print_record(int i){
    string per_record = "";
    per_record += (new_data[i].get_name() + ", ");
    per_record += (new_data[i].get_dob() + ", ");
    per_record += (new_data[i].get_city() + ", ");
    per_record += (new_data[i].get_phone() + ", ");
    per_record += (new_data[i].get_status() + ", ");

    return per_record;
}

    // 2nd Method: type-in string as SUBstring in appropriate field.
    //ADD: searching method -- takes in string and uses .find() to search through each entry in database 
//void Database::search_substr(string findData){
    
//}

// Listing record
    // String field: alphabetical order
//void Database::list_name_alpha(){}


    // String field: reverse alphabetical order
//void Database::list_name_reverse(){}

    // Number field: ascending order
//void Database::list_dob_ascend(){}
//void Database::list_phone_ascend(){}

    // Number field: descending order
//void Database::list_dob_descend(){}
//void Database::list_dob_descend(){}

