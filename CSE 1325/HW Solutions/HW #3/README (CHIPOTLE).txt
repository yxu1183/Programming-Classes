README
**************
File included: chipotle.cpp
**************
->This program is a delivery service from chipotle which allows the user to chose between "Burrito" and "Bowl".
->It also allows customers to pick stuffings 3 times(with each pick having at least two items to select).
->Exceptional handling while picking the stuffings has not been done. 
->It is assumed that the user enters the stuffs that is displayed to them, if they don't want any stuffs then they enter "None".
->A delivery charge of $3.49 is collected from the customer for each order. 

The program extracts the name of the delivery drivers from the file "deliveries.txt" which
is hardcoded on the program.

The format of the text file is:
--------------
Serj Takian
Daron Malakian
Shavo Odadjian
John Dolmayan
--------------

->The program produces a textfle "new_delivery.txt" which will have the name of the new person
who applied to be a delivery driver.
->The program also produces a textfile "total.txt" which will have the total amount of delivery money
collected from the total deliveries.

Input format is similar to that of the sample run.

**************
Compilation instructions:->
This is built in a Lubuntu virtual machine->
In terminal:
	g++ -o chipotle chipotle.cpp
	./chipotle
