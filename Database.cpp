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
void Database::get_data(){
    vector<string> data;
    ifstream fin("database.txt");
    if(fin.fail()) cmpt::error("Problem with opening database text file.");
    while(true){
        string info;
        if(fin.fail()) break;
        getline(fin, info);
        data.push_back(info);
    }
    fin.close();
    //splitting database information into their respective fields
        //i.e. name, date of birth, city, phone number, and vaccination status 
    for(int i = 0; i < data.size(); i++){
        string temp = data.at(i);
        size_t spaceIdx = data.at(i).find_last_of(' ');

        // Resize the array if needed
        resize();

        //setting vaccination status (Y or N)
        new_data[i].set_status(temp.substr(spaceIdx + 1, temp.size()-1));
        temp = temp.substr(0, temp.size() - new_data[i].get_status().size() - 1); 
        spaceIdx = temp.find_last_of(' ');

        //setting phone number
        string temp_phone_num = temp.substr(spaceIdx + 1, temp.size()-1);
        new_data[i].set_phone(stoi(temp_phone_num));
        temp = temp.substr(0, temp.size() - temp_phone_num.size() - 1);
        spaceIdx = temp.find_last_of(' ');
        
        //setting their city
        new_data[i].set_city(temp.substr(spaceIdx + 1, temp.size()-1));
        temp = temp.substr(0, temp.size() - new_data[i].get_city().size() - 1);
        spaceIdx = temp.find_last_of(' ');

        //setting their date of birth
        new_data[i].set_dob(temp.substr(spaceIdx + 1, temp.size()-1)); 
        temp = temp.substr(0, temp.size() - new_data[i].get_dob().size() - 1);

        //setting their name 
        new_data[i].set_name(temp);
    }
}


//////////////////////////////////////Finding a Record////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////
// 1st Method: type-in string EXACTLY matched the appropriate field
//////////////////////////////////////////////////////////////////////////////////////////////////
void Database::search_name (string name){
    int count_match = 0;
    for (int i = 0; i < size; i++){
        if (new_data[i].get_name() == name){
            cout << "Matching record found: " << print_record(i) << "\n";
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
            cout << "Matching record found: " << print_record(i) << "\n";
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
            cout << "Matching record found: " << print_record(i) << "\n";
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
            cout << "Matching record found: " << print_record(i) << "\n";
            count_match++;
        }
    }
    if (count_match == 0){
        cout << "No matching person's phone number found!\n";
    }
}

void Database::search_status(string status){
    int count_match = 0;
    for(int i = 0; i < size; i++){
        if(new_data[i].get_status() == status && status == "Y"){
            cout << "According to the database, people who have been vaccinated are: \n";
            cout << print_record(i) << "\n";
        } else if(new_data[i].get_status() == status && status == "N"){
            cout <<"According to the database, people who haven't been vaccinated are: ";
            cout <<print_record(i) <<"\n";
        }
    }
    if (count_match == 0){
        cout << "No matching results found!\n";
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

//////////////////////////////////////////////////////////////////////////////////////////////////
// 2nd Method: type-in string as SUBstring in appropriate field.
//////////////////////////////////////////////////////////////////////////////////////////////////

void Database::search_substr_name(string findData){
    int count_match  = 0;
    for (int i = 0; i < size; i++){
        size_t found = new_data[i].get_name().find(findData);
        if (found != string::npos){
            cout << "Similar name record found: " << print_record(i) << "\n";
            count_match++;
        }
    }
    if (count_match == 0){
        cout << "No similar name found!\n";
    }
}

void Database::search_substr_city(string findCity){
    int count_match = 0;
    for(int i = 0; i < size; i++){
        string tempCity = new_data[i].get_city();
        size_t city_found = tempCity.find(findCity);
        if(city_found != string::npos){
            cout << "Similar city record found: " << print_record(i) << "\n";
            count_match++;
        }
    }
    if(count_match == 0){
        cout << "No similar city found!\n";
    }
}

void Database::search_substr_phone(int num){
    int count_match = 0;
    for (int i = 0; i < size; i++){
        string num_str = to_string(new_data[i].get_phone());
        size_t found = num_str.find(to_string(num));
        if (found != string::npos){
            cout << "Similar name record found: " << print_record(i) << "\n";
            count_match++;
        }
    }
    if (count_match == 0){
        cout << "No similar digits found!\n";
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// 3rd Method: type-in number is in the range from low to high.
//////////////////////////////////////////////////////////////////////////////////////////////////
void Database::search_range_dob(int low, int high){
    int count_match = 0;
    for (int i = 0; i < size; i++){
        int year = stoi(new_data[i].get_dob().substr(6,4));
        if (low <= year && year <= high){
            cout << "Year in the range found: " << print_record(i) << "\n";
        }
    }
    if (count_match == 0){
        cout << "No such results found.\n";
    }
}

//////////////////////////////////////Listing Records//////////////////////////////////////////////
    // String field: alphabetical order
bool compare_name_alpha(Person_info a, Person_info b){
    return a.get_name() <= b.get_name();
}

void Database::list_name_alpha(){
    sort(new_data, new_data + size, compare_name_alpha);
    for(int i = 0; i < size; i++){
        cout << print_record(i) << "\n";
    }
}

    // String field: reverse alphabetical order
bool compare_name_rev(Person_info a, Person_info b){
    return a.get_name() >= b.get_name();
}

void Database::list_name_reverse(){
    sort(new_data, new_data + size, compare_name_rev);
    for(int i = 0; i < size; i++){
        cout << print_record(i) << "\n";
    }
}

    //Number field: ascending order
    //FINISH/////////////////////
// bool compare_dob_asc(Person_info a, Person_info b){
//     return 0;

// }

// void Database::list_dob_ascend(){
//     sort(new_data, new_data + size, compare_dob_asc);
//     for(int i = 0; i < size; i++){
//         cout << print_record(i) << "\n";
//     }
// }

bool compare_phone_asc(Person_info a, Person_info b){
    return a.get_phone() <= b.get_phone();
}

void Database::list_phone_ascend(){
    sort(new_data, new_data + size, compare_phone_asc);
    for(int i = 0; i < size; i++){
        cout << print_record(i) << "\n";
    }
}

    // Number field: descending order
//void Database::list_dob_descend(){}
bool compare_phone_desc(Person_info a, Person_info b){
    return a.get_phone() >= b.get_phone();
}
void Database::list_phone_descend(){
    sort(new_data, new_data + size, compare_phone_desc);
    for(int i = 0; i < size; i++){
        cout << print_record(i) << "\n";
    }
}


//////////////////////////////////////Deleting Records/////////////////////////////////////////////

Database::~Database(){
    delete[] new_data; 
}

