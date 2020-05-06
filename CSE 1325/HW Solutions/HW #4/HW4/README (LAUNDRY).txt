README
**************
File included: laundry.cpp
**************
The file reads in from the file and performs various functionalities for Lundromat.

All registered users was read in from a file (command line argument). The file 	
looked like:
Jon Doe,D160,3.75,5//name,id,balance,amount of detergent in oz
Jane Doe,D450,5.00,3

All the machines available was read in from a file(command line argument). The file 
looked like:
Fast,5
Slow,8
Very Slow,10

Input format:
Same as the sample run.

**************
Compilation instructions:
->This is built in a Lubuntu virtual machine
->In terminal:
	g++ -o laundry laundry.cpp
	./laundry

