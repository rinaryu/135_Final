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
		}
		if(x == 's' || x == 'd'){
			endwin();	
			menu.searching(x);
			//string returnResp;
			  //  cout << "Enter (r) if you would like to return.\n";
			  //cin >> returnResp;
			  //while(returnResp != "r"){
			    ///cout << "Invalid response\n";
			    //cin >> returnResp;
			  //}
			  //returnResp = 'r';
			  cout << "Returning...\n";
			  chrono::seconds dura(3);
			  this_thread::sleep_for(dura);
			  done = false;
		}
		//else if (x == 'u'){
		// 	res = menu.update();
		// } 

		if (x == 'l'){
			endwin();
			menu.list();
		}	
		
		if(x == 'q') {
			//quit_display();
		 	endwin();
		 	menu.quit();
		 	done = true;
		}
	}
	endwin();
	cout<<"work?\n";

	//menu.quit();
}

int main(){
    test();
}
