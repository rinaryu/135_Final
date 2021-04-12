//This contains the class "Database" 
/////////////////////////////////////////////////////////////////////////////
//This class:
// - gets and stores the data from database.txt 
// - sorts the data from alphabetical order to reverse alphabetical order 
// - includes a searching feature to find specific data 

#include "database_head.h"
#include <iostream>
using namespace std;


Database::Database(){
    size = 0;
    capacity = 5;
    new_data = new Person_info[5];
}

int Database::get_size() const {return size;}
int Database::get_cap() const {return capacity;}

// Resize array
void Database::resize(){
    Person_info* temp_arr = new Person_info[capacity * 2];
    int i;
    for(i = 0; i < size; i++){
        temp_arr[i] = new_data[i];
    }

    delete[] new_data;
    new_data = temp_arr;
    capacity *= 2;
}

//gets data from database.txt
void Database::get_data(){
    vector<string> data;
    ifstream fin("database.txt");
    if(fin.fail()) cmpt::error("Problem with opening database.txt\n");

    while(true){
        string info;
        if(fin.fail()) break;
        getline(fin, info);
        data.push_back(info);
    }
    fin.close();
    //splitting database information into their respective fields
        //i.e. name, date of birth, city, phone number, and vaccination status 
    for(int i = 0; i < data.size()-1; i++){
        string temp = data.at(i);
        size_t spaceIdx = data.at(i).find_last_of(' ');

        // Resize the array if needed
        if(size >= capacity) resize();

        //setting vaccination status (Y or N)
        string temp_status = (temp.substr(spaceIdx + 1, temp.size()-1));
        new_data[i].set_status(temp_status);
        temp = temp.substr(0, temp.size() - temp_status.size() - 1); 
        spaceIdx = temp.find_last_of(' ');

        //setting phone number
        string temp_phone = temp.substr(spaceIdx + 1, temp.size()-1);
        new_data[i].set_phone(stoll(temp_phone));
        temp = temp.substr(0, temp.size() - temp_phone.size() - 1);
        spaceIdx = temp.find_last_of(' ');

        //setting their city
        string temp_city = (temp.substr(spaceIdx + 1, temp.size()-1));
        new_data[i].set_city(temp_city);
        temp = temp.substr(0, temp.size() - temp_city.size() - 1);
        spaceIdx = temp.find_last_of(' ');

        //setting their date of birth
        string temp_yob = (temp.substr(spaceIdx + 1, temp.size()-1)); 
        new_data[i].set_yob(temp_yob);
        temp = temp.substr(0, temp.size() - temp_yob.size() - 1);

        //setting their name 
        new_data[i].set_name(temp);
        size++;
    }
}

//////////////////////////////////////Adding a Record////////////////////////////////////////////
void Database::add_data(const Person_info& person){
    if(size >= capacity){
        resize();
    }
    new_data[size] = person;
    size++;
}

//////////////////////////////////////Finding a Record////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////
// 1st Method: type-in string EXACTLY matched the appropriate field
//////////////////////////////////////////////////////////////////////////////////////////////////
void Database::print_all(){
	for (int i = 0; i < size; i++){
		cout << new_data[i].get_name() << ' ';
		cout << new_data[i].get_yob() << ' ';
		cout << new_data[i].get_city() << ' ';
		cout << new_data[i].get_phone() << ' ';
		cout << new_data[i].get_status() << endl;
	}
}

string Database::print_record(int i){
    per_record = "";
    per_record += (new_data[i].get_name() + ", ");
    per_record += (new_data[i].get_yob() + ", ");
    per_record += (new_data[i].get_city() + ", ");
    per_record += (to_string(new_data[i].get_phone()) + ", ");
    per_record += (new_data[i].get_status());
	
    return per_record;
}

void Database::search_name (string name){
    int count_match = 0;
    for (int i = 0; i < size; i++){
        if (new_data[i].get_name() == name){
            cout << "Matching record found: \n" ;
            cout << print_record(i) << "\n";
            count_match++;
        }
    }
    if (count_match == 0){
        cout << "No matching person's name found!\n";
    }
}

void Database::search_yob (string yob){
    int count_match = 0;
    // NOTE: check for the right format search of yob
    for (int i = 0; i < size; i++){
        if (new_data[i].get_yob() == yob){
            cout << "Matching record found: \n" << print_record(i) << "\n";
            count_match++;
        }
    }
    if (count_match == 0){
        cout << "No matching person's date of birth found!\n";
    }
}

void Database::search_city (string city){
    int count_match = 0;
    city.at(0) = toupper(city.at(0)); //changing first letter to uppercase
    for (int i = 0; i < size; i++){
        if (new_data[i].get_city() == city){
            cout << "Matching record found: \n" << print_record(i) << "\n";
            count_match++;
        }
    }
    if (count_match == 0){
        cout << "No matching city found!\n";
    }
}
void Database::search_phone (long long phone){
    int count_match = 0;
    for (int i = 0; i < size; i++){
        if (new_data[i].get_phone() == phone){
            cout << "Matching record found: \n" << print_record(i) << "\n";
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


//string Database::save_record(int i);

//////////////////////////////////////////////////////////////////////////////////////////////////
// 2nd Method: type-in string as SUBstring in appropriate field.
//////////////////////////////////////////////////////////////////////////////////////////////////

void Database::search_substr_name(string findData){
    int count_match  = 0;
    for (int i = 0; i < size; i++){
        string name = new_data[i].get_name();
        
        if (name.find(findData) != std::string::npos){
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

void Database::search_substr_phone(long long num){
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

void Database::search_range_yob(int low, int high){
    int count_match = 0;
    for (int i = 0; i < size; i++){
        int year = stoi(new_data[i].get_yob());
        if (low <= year && year <= high){
            cout << "Year in the range found: " << print_record(i) << "\n";
            count_match++;
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
bool compare_yob_asc(Person_info a, Person_info b){
    return stoi(a.get_yob()) <= stoi(b.get_yob());

}

void Database::list_yob_ascend(){
    sort(new_data, new_data + size, compare_yob_asc);
         for(int i = 0; i < size; i++){
         cout << print_record(i) << "\n";
     }
}

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
bool compare_yob_des(Person_info a, Person_info b){
    return stoi(a.get_yob()) >= stoi(b.get_yob());

}

void Database::list_yob_descend(){
    sort(new_data, new_data + size, compare_yob_des);
         for(int i = 0; i < size; i++){
         cout << print_record(i) << "\n";
     }
}

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
void Database::delete_name(string name){
    for (int i = 0; i < size; i++){
        if (new_data[i].get_name() == name){
            new_data[i] = new_data[size - 1];
            size--; //Truncate
        }
    }
}
void Database::delete_yob(string yob){
    for (int i = 0; i < size; i++){
        if (new_data[i].get_yob() == yob){
            new_data[i] = new_data[size - 1];
            size--; //Truncate
        }
    }
}

void Database::delete_city(string city){
    for (int i = 0; i < size; i++){
        if (new_data[i].get_city() == city){
            new_data[i] = new_data[size - 1];
            size--; //Truncate
        }
    }
}

void Database::delete_phone(long long phone){
    for (int i = 0; i < size; i++){
        if (new_data[i].get_phone() == phone){
            new_data[i] = new_data[size - 1];
            size--; //Truncate
        }
    }
}

void Database::delete_status(string status){
    for(int i = 0; i < size; i++){
        if(new_data[i].get_status() == status){
            new_data[i] = new_data[size - 1];
            size--; 
        }
    }
}

//////////////////////////////////////Deleting Records/////////////////////////////////////////////
void Database::quitting_save(){
	ifstream fin("database.txt");
	fin.close();
	
	ofstream fout("temp.txt");
	
	
	for(int i = 0; i < size; i++){ //i stg if this seg faults IM GOING TO CRY ;-; 
		fout << new_data[i].get_name() << " " << new_data[i].get_yob() << " " << new_data[i].get_city() 
         << " " << new_data[i].get_phone() << " " << new_data[i].get_status() << "\n";
 
	}
	fout.close();
	remove("database.txt");
	rename("temp.txt", "database.txt");
	
}

Database::~Database(){
    delete[] new_data; 
}

