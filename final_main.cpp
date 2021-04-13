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
			
			string returnResp;
				cout << "Enter (r) if you would like to return.\n";
			cin >> returnResp;
			while(returnResp != "r"){
				cout << "Invalid response\n";
				cin >> returnResp;
			}
			returnResp = 'r';
			
			cout << "Returning to main menu...\n\n";
			chrono::seconds dura(3);
			this_thread::sleep_for(dura);
			done = false;
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
	cout << "Close program.\n";
}
int main(){
   	test();
}