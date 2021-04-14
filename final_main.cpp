#include "database_head.h"
using namespace std;

void test(){ //change to better function name later
	Menu menu;
	bool done = false;
	while(!done){
		char x = feature_display();
		//char res;
		
		if(x == 'a'){
			endwin();
			menu.adding();
			done = false;
		}
		
		if(x == 's' || x == 'd'){
			endwin();	
			menu.searching(x);

			// cout << "Returning...\n\n";
			// chrono::seconds dura(2);
			// this_thread::sleep_for(dura);
		}
		
		//else if (x == 'u'){
		// 	res = menu.update();
		//} 

		if (x == 'l'){
			endwin();
			menu.listing();
		}	
		
		if(x == 'q') {
			endwin();
		 	menu.quitting();
		 	done = true;
		}
	}
	endwin();
}
int main(){
   	test();
}