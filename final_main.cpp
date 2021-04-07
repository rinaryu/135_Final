#include "database_head.h"
using namespace std;

void test(){ //change to better function name later
	Menu menu;
    bool done = false;
	while(!done){
		char x = menu.feature_display();
		char res;
			if(x == 's' || x == 'd'){
				res = menu.searching(x);
			} else if (x == 'u'){
				res = menu.update();
			} else if (x == 'l'){
				res = menu.list();
			}
			
			if (res == 'r'){
				done = false;
			} else {
				done = true;
			}
	}
	endwin();
}

int main(){
    test();
}
