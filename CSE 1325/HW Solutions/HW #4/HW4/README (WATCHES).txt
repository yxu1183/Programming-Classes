README
**************
File included: watches.cpp
**************
The above file finds the type of watch and calculates the total repair cost of the watch.
Watch with price above 800 is a designer watch and a watch above age of 50 is antique.
If the watch has both characteristics as above, then it is considered as both designer and antique.
Other wise, it is a non-desgner watch.

The repair price is set up same as mentioned in the question.
If both antinque and designer, then the repair price is (one forth of the original price - half of age)
If a non-desginer watch and falls under free repair list:"piaget","cartier","rolex","tag heuer","panerai","omega","chopard"
then the repair price is 0.

Input format:

~~Welcome to our Watch Repair Shop~~

-----------------------------------
Please choose the following options:
1. Repair Watch
2. Exit
Choice: 1

~~First, let's find the type of your watch.~~

Enter the original price of your watch:
$850
How old is your watch?
55

You have a very unique watch. It's both Desginer and Antique!

We have a special discount on repair cost for your watch!

~~~The repair cost for your watch is $240.00.~~~

-----------------------------------
Please choose the following options:
1. Repair Watch
2. Exit
Choice: 1

~~First, let's find the type of your watch.~~

Enter the original price of your watch:
$850
How old is your watch?
34

You have a Designer watch!

Please enter the material used in your watch (gold or silver):
gold

~~~The repair cost for your watch is $212.50.~~~

-----------------------------------
Please choose the following options:
1. Repair Watch
2. Exit
Choice: 1

~~First, let's find the type of your watch.~~

Enter the original price of your watch:
$500
How old is your watch?
62

You have an Antique watch!

~~~The repair cost for your watch is $31.00.~~~

-----------------------------------
Please choose the following options:
1. Repair Watch
2. Exit
Choice: 1

~~First, let's find the type of your watch.~~

Enter the original price of your watch:
$500
How old is your watch?
34

You have a Non-designer watch!

Please enter the name of the brand of your watch:
rolex

Your watch is in our special free repair list!!!

~~~The repair cost for your watch is $0.00.~~~

-----------------------------------
Please choose the following options:
1. Repair Watch
2. Exit
Choice: 2

Thank you for visiting us!
Exiting...Hope to see you soon:).


**************
Compilation instructions:
->This is built in a Lubuntu virtual machine
->In terminal:
	g++ -o watches watches.cpp
	./watches

