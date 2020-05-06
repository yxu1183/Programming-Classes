README
**************
File included: 
choice.cpp 
makefile
choice.h 
choice_main.cpp

**************
->The above file compiles and runs on a Gtk window. 
->This program is a delivery service from chipotle which allows the user to chose between "Burrito" and "Bowl".
->It also allows customers to pick stuffings 3 times(with each pick having at least two items to select).

->The program extracts the name of the delivery drivers from the file "deliveries.txt" which
is hardcoded on the program.

The format of the text file is:
--------------
Serj Takian
Daron Malakian
Shavo Odadjian
John Dolmayan
--------------

->The program also produces a textfile "total.txt" which will have the total amount of delivery money
collected from the total deliveries.

Input format is similar to that of the sample run.

**************
Compilation instructions:
->This is built in a Lubuntu virtual machine
->In terminal:
	make
	./choice

