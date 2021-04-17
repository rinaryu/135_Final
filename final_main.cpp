#include "database_head.h"
using namespace std;

void final_test(){ //change to better function name later
	Menu menu;
	bool done = false;
	while(!done){
		char x = feature_display();
		//char res;#include "database_head.h"
using namespace std;

void final_test(){
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
		}
		
		else if (x == 'u'){
			endwin();
			menu.update();
		} 

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
   	final_test();
}
		
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
		
		else if (x == 'u'){
			endwin();
			menu.update();
		} 

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
   	final_test();
}
