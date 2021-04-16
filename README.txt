CMPT 135 Assignment 5
=====================

Names of Team Members
---------------------

(include the full names, SFU email addresses, and SFU student numbers of all
team members)
Full Name: Rina Ryu
Student ID: 301427397
Email: rra51@sfu.ca

Full Name: Ngan Ngoc (Lynn) Nguyen
Student ID: 301420556
Email: nnn2@sfu.ca

Instructions for Compiling and Running
--------------------------------------
Step 1: Install the ncurses library by typing this at the terminal command line:
            sudo apt-get install libncurses5-dev libncursesw5-dev

Step 2: BEFORE typing anything in the terminal -- make sure your terminal window's size instructions 
is at least 1/2 of your screen, this will ensure that the entire database display will appear 
(115 x 48 is a good size for eg).

Step 3: in the terminal
    - first enter "make"
    - then enter "./final"
The terminal should then begin the program and the user should be able to view/interact 
with the menu displayed on the terminal. 

Limitations
-----------
none

Known Bugs
----------
none (that we know of >.>)


Extra Features
--------------
1. Update feature
    - user can search for a person in the database based on their full name
    - if a record is found they can choose to update/change
        + name
        + year of birth
        + city
        + phone number
        + vaccination status