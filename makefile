CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g

final: final_main.o Person_info.o Database.o Menu.o display.o
	g++ -o final final_main.o Person_info.o Database.o Menu.o display.o -lncurses

Person_info:
	g++ -c $(CPPFLAGS) Person_info.cpp

Database:
	g++ -c $(CPPFLAGS) Database.cpp

Menu:
	g++ -lncurses -c $(CPPFLAGS) Menu.cpp
	
display:
	g++ -lncurses -c $(CPPFLAGS) display.cpp

final_main:
	g++ -lncurses -c $(CPPFLAGS) final_main.cpp

clean:
	rm -f final final_main.o Person_info.o Database.o Menu.o display.o

