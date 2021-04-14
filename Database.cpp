//This contains the class "Database" 
//////////////////////////////////////////////////////////////////////////////////////////////////
//This class:
// - gets and stores the data from database.txt 
// - sorts the data from alphabetical order to reverse alphabetical order 
// - includes a searching feature to find specific data 

#include "database_head.h"
#include <iostream>
using namespace std;

//Constructor
Database::Database(){
	size = 0;
	capacity = 5;
	new_data = new Person_info[5];
}

//Getter methods
int Database::get_size() const {return size;}
int Database::get_cap() const {return capacity;}

//Resize array
void Database::resize(){
	Person_info* temp_arr = new Person_info[capacity * 2];
	for(int i = 0; i < size; i++){
		temp_arr[i] = new_data[i];
	}
	delete[] new_data;
	new_data = temp_arr;
	capacity *= 2;
}

//Read the records from database.txt
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
	
	//Splitting database information into their respective fields
	//i.e. name, year of birth, city, phone number, and vaccination status 
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
void Database::print_record(int i){
	cout << "Full name: " << new_data[i].get_name() << '\n';
	cout << "Year of birth: " << new_data[i].get_yob() << '\n';
	cout << "City that resides in: " << new_data[i].get_city() << '\n';
	cout << "Contact: " << new_data[i].get_phone() << '\n';
	cout << "Vaccination status: " << new_data[i].get_status() << '\n';
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// 1st Method: type-in STRING EXACTLY matched the appropriate field
void Database::search_name (string name){
	int count_match = 0;
	for (int i = 0; i < size; i++){
		if (new_data[i].get_name() == name){
			count_match++;
			if (count_match == 1) cout << "Matching record(s) found: \n\n" ;
			cout << "Record " << count_match << ": \n";
			print_record(i);
			cout << '\n';
		}
	}
	if (count_match == 0){
		cout << "No matching person's name found!\n";
	}
}
void Database::search_city (string city){
	int count_match = 0;
	city.at(0) = toupper(city.at(0)); //making first letter capital
	
	for (int i = 0; i < size; i++){
		if (new_data[i].get_city() == city){
			count_match++;
			if (count_match == 1) cout << "Matching record(s) found: \n\n" ;
			cout << "Record " << count_match << ": \n";
			print_record(i);
			cout << '\n';
		}
	}
	if (count_match == 0){
		cout << "No matching city found!\n";
	}
}
void Database::search_status(string status){
	int count_match = 0;
	status.at(0) = toupper(status.at(0));
	for(int i = 0; i < size; i++){
		if(new_data[i].get_status() == status && (status == "Y")){
			count_match++;
			if (count_match == 1) cout << "According to the database, people who have been vaccinated are: \n";

			cout << "Record " << count_match << ": \n";
			print_record(i);
			cout << '\n';
			
		} else if(new_data[i].get_status() == status && (status == "N")){
			count_match++;
			if (count_match == 1) cout << "According to the database, people who haven't been vaccinated are: \n";

			cout << "Record " << count_match << ": \n";
			print_record(i);
			cout << '\n';
		}
	}
	if (count_match == 0) cout << "No matching results found!\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// 2nd Method: type-in string as SUBSTRING in appropriate field.
void Database::search_substr_name(string findData){
	int count_match  = 0;
	for (int i = 0; i < size; i++){
		string name = new_data[i].get_name();
		if (name.find(findData) != std::string::npos){
			count_match++;
			if (count_match == 1) cout << "Matching record(s) found: \n\n" ;
			cout << "Record " << count_match << ": \n";
			print_record(i);
			cout << '\n';	
		}
	}
	if (count_match == 0) cout << "No similar name found!\n";
}
void Database::search_substr_city(string findCity){
	int count_match = 0;
	for(int i = 0; i < size; i++){
		string tempCity = new_data[i].get_city();
		size_t city_found = tempCity.find(findCity);
		if(city_found != string::npos){
			count_match++;
			if (count_match == 1) cout << "Matching record(s) found: \n\n" ;
			cout << "Record " << count_match << ": \n";
			print_record(i);
			cout << '\n';
		}
	}
	if(count_match == 0) cout << "No similar city found!\n";
}
void Database::search_substr_phone(long long num){
	int count_match = 0;
	for (int i = 0; i < size; i++){
		string num_str = to_string(new_data[i].get_phone());
		size_t found = num_str.find(to_string(num));
		if (found != string::npos){
			count_match++;
			if (count_match == 1) cout << "Matching record(s) found: \n\n" ;
			cout << "Record " << count_match << ": \n";
			print_record(i);
			cout << '\n';
		}
	}
	if (count_match == 0) cout << "No similar digits found!\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// 3rd Method: type-in NUMBER EXACTLY matches.
void Database::search_yob(string yob){
	int count_match = 0;
	// NOTE: check for the valid search
	while(true){
		bool done = true;
		for (int i = 0; i < yob.size(); i++){
			if (!(yob[i] >= '0' && yob[i] <= '9')){
				done = false;
				cout << "This is not a number, please re-enter: ";
				cin >> yob;
			} else done = true;
		}
		if(done == true) break; 
	}
	for (int i = 0; i < size; i++){
		if (new_data[i].get_yob() == yob){
			count_match++;
			if (count_match == 1) cout << "Matching record(s) found: \n\n";
			cout << "Record " << count_match << ": \n";
			print_record(i);
			cout << '\n';
		}
	}
	if (count_match == 0) cout << "No matching person's date of birth found!\n";
}
void Database::search_phone (long long phone){
	int count_match = 0;
	for (int i = 0; i < size; i++){
		if (new_data[i].get_phone() == phone){
			count_match++;
			if (count_match == 1) cout << "Matching record(s) found: \n\n" ;
			cout << "Record " << count_match << ": \n";
			print_record(i);
			cout << '\n';
		}
	}
	if (count_match == 0) cout << "No matching person's phone number found!\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// 4rd Method: type-in NUMBER is in the RANGE from low to high.
void Database::search_range_yob(int low, int high){
	int count_match = 0;
	for (int i = 0; i < size; i++){
		int year = stoi(new_data[i].get_yob());
		if (low <= year && year <= high){
			count_match++;
			if (count_match == 1) cout << "Matching record(s) found: \n\n" ;
			cout << "Record " << count_match << ": \n";
			print_record(i);
			cout << '\n';
		}
	}
	if (count_match == 0) cout << "No such results found!\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// 5th Method: search phone number based on given area code.
void Database::search_area_code(int code){
	int count_match = 0;
	string input_code = to_string(code);
	for(int i = 0; i < size; i++){
		string data_code = to_string(new_data[i].get_phone());
		if(data_code.substr(0,3) == input_code){
			count_match++; 
			if(count_match == 1) cout << "Matching record(s) found: \n\n";
			cout << "Record " << count_match << ": \n";
			print_record(i);
			cout << '\n';
		}
	}
	if(count_match == 0) cout << "No such results found!\n";
}

//////////////////////////////////////Listing Records//////////////////////////////////////////////
void Database::print_all(){
	for (int i = 0; i < size; i++){
		cout << left << setw(25) << new_data[i].get_name() ;
		cout << left << setw(7) << new_data[i].get_yob();
		cout << left << setw(20) << new_data[i].get_city();
		cout << left << setw(14) << new_data[i].get_phone();
		cout << left << setw(10) << new_data[i].get_status() << '\n';
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
// 1st and 2nd Method: type-in STRING
//////////////////////////////////////////////////////////////////////////////////////////////////
// STRING field: ALPHAbetical order
bool compare_name_alpha(Person_info a, Person_info b){
	return a.get_name() <= b.get_name();
}

void Database::list_name_alpha(){
	sort(new_data, new_data + size, compare_name_alpha);
	print_all();
}

bool compare_city_alpha(Person_info a, Person_info b){
	if (a.get_city() == b.get_city()) return a.get_name() <= b.get_name();

	else return a.get_city() < b.get_city();
}

void Database::list_city_alpha(){
	sort(new_data, new_data + size, compare_city_alpha);
	print_all();
}

bool compare_status_alpha(Person_info a, Person_info b){
	if (a.get_status() == b.get_status()) return a.get_name() <= b.get_name();

	else return a.get_status() < b.get_status();
}

void Database::list_status_alpha(){
	sort(new_data, new_data + size, compare_status_alpha);
	print_all();
}

// STRING field: REVERSE alphabetical order
bool compare_name_rev(Person_info a, Person_info b){
	return a.get_name() >= b.get_name();
}

void Database::list_name_reverse(){
	sort(new_data, new_data + size, compare_name_rev);
	print_all();
}

bool compare_city_rev(Person_info a, Person_info b){
	if (a.get_city() == b.get_city()) return a.get_name() <= b.get_name();

	else return a.get_city() > b.get_city();
}

void Database::list_city_reverse(){
	sort(new_data, new_data + size, compare_city_rev);
	print_all();
}

bool compare_status_rev(Person_info a, Person_info b){
	if (a.get_status() == b.get_status()) return a.get_name() <= b.get_name();

	 else return a.get_status() > b.get_status();
}

void Database::list_status_reverse(){
	sort(new_data, new_data + size, compare_status_rev);
	print_all();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// 3rd and 4th Method: type-in NUMBER
//NUMBER field: ASCENDING order
bool compare_yob_asc(Person_info a, Person_info b){
	return stoi(a.get_yob()) <= stoi(b.get_yob());
}

void Database::list_yob_ascend(){
	sort(new_data, new_data + size, compare_yob_asc);
	print_all();
}

bool compare_phone_asc(Person_info a, Person_info b){
	return a.get_phone() <= b.get_phone();
}

void Database::list_phone_ascend(){
	sort(new_data, new_data + size, compare_phone_asc);
	print_all();
}

//NUMBER field: DESCENDING order
bool compare_yob_des(Person_info a, Person_info b){
	return stoi(a.get_yob()) > stoi(b.get_yob());
}

void Database::list_yob_descend(){
	sort(new_data, new_data + size, compare_yob_des);
	print_all();
}

bool compare_phone_desc(Person_info a, Person_info b){
	return a.get_phone() >= b.get_phone();
}
void Database::list_phone_descend(){
	sort(new_data, new_data + size, compare_phone_desc);
	print_all();
}


//////////////////////////////////////Deleting Records/////////////////////////////////////////////
int Database::findIdx(string find){
	for(int i = 0; i < size; i++){
		if(new_data[i].get_name() == find) return i;
	}
	return 0;
}
//could be problem when deleting more than one element******
void Database::delete_name(string name){
	int n = findIdx(name);
	
	size--;
	for (int i = n; i < size; i++) new_data[i] = new_data[size - 1];
}

void Database::delete_name_substr(string nameSubstr){
	int i;
	for(i = 0; i < size; i++){
		string tempName = new_data[i].get_name();
		cout<<"break1\n";
		if(tempName.find(nameSubstr) != std::string::npos) break;
	}
	size--;
	for(int j = i; j < size; j++){
		cout<<"break2\n";
		new_data[j] = new_data[size - 1];
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

//////////////////////////////////////Saving Records/////////////////////////////////////////////
void Database::quitting_save(){
	ofstream fout("temp.txt");
		
	for(int i = 0; i < size; i++){ 
		fout << new_data[i].get_name() << " " 
			<< new_data[i].get_yob() << " " 
			<< new_data[i].get_city() << " " 
			<< new_data[i].get_phone() << " " 
			<< new_data[i].get_status() << '\n';
 	}
	fout.close();
	remove("database.txt");
	rename("temp.txt", "database.txt");
}

Database::~Database(){
    delete[] new_data; 
}