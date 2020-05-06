README
**************
File included: chili.cpp
**************
The above file is a program for selling 4 different chili cup sizes.
Each batch is worth 4 cups, where
Venti = 2 batches
Grande = 2 batches
Tall = 1 batch and 
Short = 1 batch

Input format: Same as the sample run in homework.

When the number of chilies becomes less and is not enough to serve customers, the program says "Sorry,not enough chili. 
Would you like to make another batch or quit?" 
Entering "Yes" will make a new batch and serve the remaining customers, entering "Quit" would directly exit the program. 

"info.txt" file has been hardcoded on the program.
The file format is given below:

Natassa,Venti
Demy,Grande
Elena,Tall
Yunika,Short
Ashish,Grande
Preju,Tall

After all the customers are served, the program exits.

**************
Compilation instructions:->
This is built in a Lubuntu virtual machine->
In terminal:
	g++ -o chili chili.cpp
	./chili