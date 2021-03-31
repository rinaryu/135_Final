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

// Definition
class Database {
    private:
        //vector<string> data;
        int size;
        int capacity;
        Person_info* new_data;

    public:
        Database(int sz, int cap)
        : size(sz), capacity(cap), new_data(new Person_info[cap])
        {}

        // Resize array
        void resize(){
            if (size >= capacity){
                Person_info* temp_arr = new Person_info[capacity * 2];
                int i;
                for(i = 0; i < size; i++){
                    temp_arr[i] = new_data[i];
                }

                delete[] new_data;
                new_data = temp_arr;
                capacity *= 5;
                size = i;
            }
        }

        //gets data from database.txt
        //???? Break down information of a single person
        void get_data(){
            ifstream fin("database.txt");
            while(true){
                if(fin.fail()) cmpt::error ("There was a problem opening database file");
                string info;
                getline(fin, info);
                if(fin.fail()) break;
                data.push_back(info);
            }
            fin.close();
        }

        // Finding a Record
            // 1st Method: type-in string EAXCTLY matched the appropriate field
        void search_name (string name){
            int count_macth = 0;
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

        void search_dob (string dob){
            int count_macth = 0;
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

        void search_city (string city){
            int count_macth = 0;
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
        void search_phone (int phone){
            int count_macth = 0;
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

        string print_record(int i){
            string per_record = "";
            per_record += (new_data[i].get_name() + ", ");
            per_record += (new_data[i].get_dob() + ", ");
            per_record += (new_data[i].get_city() + ", ");
            per_record += (new_data[i].get_phone() + ", ");
            per_record += (new_data[i].get_status() + ", ");
        }

            // 2nd Method: type-in string as SUBstring in appropriate field.
            //ADD: searching method -- takes in string and uses .find() to search through each entry in database 
        void search_substr(string findData){
            
        }

        // Listing record
            // String field: alphabetical order
        void list_name_alpha(){}

            // String field: reverse alphabetical order
        void list_name_reverse(){}
            // Number field: ascending order

            // Number field: descending order

        //ADD??: getter method for data vector

        ~Database();
};


