//////////////////////////////////////////////////////

// person_info.cpp

#include "final_project.h"
#include "cmpt_error.h"
#include <iostream>

// Definition
class Person_info {
private:
    string new_name;
    string dob; 
    string new_city;
    int phone_num; 
    bool vaccinated; 

public:
    Person_info (const string& user_choice): user_input(user_choice){

    }
    //Method used to get user input to enter new person into the database.
    string new_person (){
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
        cout<<"Please enter their date of birth.\n The data must be in the following format of, MM/DD/YYYY (eg. 04/07/1999): \n";

        //Third: Getting the city that the new person resides in. 
        cout<<"Please enter the city in the Lower Mainland that they reside in: \n";
        getline(cin, new_city);
        if(!valid_city(new_city)){
            while(true){
                cout<<"That is not a valid city, please enter a city in the Lower Mainland: \n";
                getline(cin, new_city);
                if(valid_city(new_city)) break; 
            }
        }
        //Fourth: Getting phone number of new person. 
        cout<<"Please enter their phone number: \n";
        getline(cin, phone_num);
        if(!valid_phoneNum(phone_num)){
            while(true){
                cout<<"This is not a valid phone number, please re-enter: \n";
                getline(cin, phone_num);
                if(valid_phoneNum(phone_num)) break;
            }
        }
    }
    //method checks if new person's name input is valid (string with only alpha chars) 
    bool valid_name (string user_input){
        for (int i = 0; i < user_input.size(); i++){
            if (!isalpha(user_input.at(i))){
                return 0;
            } 
        }
        return 1;
    }
    // Method checks if new person's DOB is valid
    bool check_data (int month, int day, int year){
        if (month == 2){
            if (year % 4 == 0){
                if (day > 29 || day < 0) return 0;
            } else {
                if (day > 28 || day < 0) return 0;
            } 
        } else if (month == 1 || month == 3 || month == 5
                    month == 7 || month == 8 || month == )

        } 
    }
    bool valid_date (string user_input){
        
    }
    //checks if user entered city is valid
    bool valid_city(string city_name){
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
    
    bool valid_phone (int num){
        string temp_num = to_string(num);
        if(temp_num.size() != 7) return 0;
        //ADD: check if the input is all numbers 
    }
    
    
    ~Person_info(){};
};

#endif

