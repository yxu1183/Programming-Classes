//Yunika Upadhayaya
//1001631183
//December 1 2018

package petinfo;

import catstuff.Cat;//Import the method made in Cat class

public class petInfo 
{
    public static void main(String[] args) 
    {
        Cat S1=new Cat();
        S1.giveAllinfo(); //Method to give all the information
        S1.addFavFood(); // Lines 15-17 are methods to add favourite food
        S1.addFavFood();
        S1.addFavFood();
        S1.printOutCatInfo();//Method to print all the cat information
    }
}
