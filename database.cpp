//////////////////////////////////////////////////////

// database.cpp

#include "database.h"
#include "cmpt_error.h"
#include <iostream>

// Definition
class database : public person_info {
    private:
        vector<string> data;

    public:
        database();
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
        };
        ~database();
};

