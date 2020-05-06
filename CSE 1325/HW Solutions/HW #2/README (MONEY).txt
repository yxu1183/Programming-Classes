Name: Yunika Upadhayaya
Student ID: 1001631183

README
**************
File included: money.cpp
**************
In this program there are two currency exchange offices. One office services north and east and the other one services south and west. 
These offices convert the input currency into dollar amount.
Input currencies included in the program are:
- rupee
- yen
- peso
- euro
 
The output looks similar to the sample run:
Enter name of exchange office and manager: ABC Conversions Armin
Enter name of exchange office and manager: DEF Conversions Jep
********
Hello traveler! Where are you in the airport? North
********
Welcome	to ABC Conversions. Please contact the manager Armin if	you have any complaints.
What currency are you converting to dollars and	how much? 200 yen
Here you go: $1.86
********
Hello traveler! Where are you in the airport? West
********
Welcome	to DEF Conversions. Please contact the manager Jep if you have any complaints.
What currency are you converting to dollars and	how much? 300 dinar
We do not convert the dinar currency here. Sorry.
********
Hello traveler! Where are you in the airport? West 
********
Welcome	to DEF Conversions. Please contact the	manager	Jep if you have	any complaints.
What currency are you converting to dollars and	how much? 300 peso
Here you go: $15.30 
********
Hello traveler! Where are you in the airport? exit
********
$$$Total dollars given out: $17.16
Exiting…

**************
Compilation instructions:->
This is built in a Lubuntu virtual machine->
In terminal:
	g++ -o money money.cpp
	./money
