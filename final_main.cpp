#include "database_head.h"
using namespace std;

void test(){ //change to better function name later
	Menu menu;
	while(true){
		char x = feature_display();
		char res;
		if(x == 'a') menu.adding();
		if(x == 's' || x == 'd') res = menu.searching(x);
		 
		//else if (x == 'u'){
		// 	res = menu.update();
		// } 

		if (x == 'l') res = menu.list();
			
		if (res == 'r') continue; 
		// if(res == 'q') {
		// 	menu.quit();
		// 	wgetch();
		// 	endwin();
		// 	refresh();
		// 	break;
		// }
	}
	endwin();
	cout<<"work?\n";

	menu.quit();
}

int main(){
    test();
}
