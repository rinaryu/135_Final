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

Statement of Originality
------------------------
All the code and comments below are our own original work. For any non-
original work, we have provided citations in the comments with enough detail
so that someone can see the exact source and extent of the borrowed work.

In addition, we have not shared this work with anyone else, and we have not
seen solutions from other students, tutors, websites, books, etc.

References
----------
1. http://www.cs.ukzn.ac.za/~hughm/os/notes/ncurses.html#using
2. https://www.youtube.com/watch?v=lV-OPQhPvSM&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v
3. https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html
4. https://docs.oracle.com/cd/E88353_01/html/E37849/makehtml-id-5.html

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
Update feature
    - user can search for a person in the database based on their full name
    - if a record is found they can choose to update/change
        + name
        + year of birth
        + city
        + phone number
        + vaccination status