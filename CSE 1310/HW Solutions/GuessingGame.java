//Yunika Upadhayaya
//1001631183
//November 13 2018

import java.util.Random;
import java.util.Scanner;

public class GuessingGame 
{
    
    public static int numGenerate(int number) //method that takes a int value and returns the randomly generated number less than the entered int value(within the bound)
    {
         while(number<=0) //We can't randomize the number if it it is 0 or less than 0
        {   Scanner in=new Scanner(System.in);
            System.out.println("It can't be randomized! Enter the largest number possible to guess (remember, if you want 5 to be the largest, enter one larger: 6)");
            number=in.nextInt();       
        }
        Random input=new Random();
        int n;
        if(number==1) //True or false - if the bound number is equal to 1?
        {
         n=0;
        }
        else //if the bound number is other than 1
        {
        n=input.nextInt(number-1); 
        }
        return n;
    }
    
    public static int getUserInput(String message) //method to get a user inputted value and return the same
    {
        System.out.println(message);
        Scanner in=new Scanner(System.in); //required for users to input
        int digits=in.nextInt(); //Asks user to input
        return digits;
    }
    
    public static boolean CompareGuess(int a, int b )//Method that takes user's number guess and the other the number user is trying to guess and returns the boolean value
    {
        boolean exit =true;
        if(a==b) //If the user's guess and the user trying to guess number is same
        {
            exit=false;
        }
        return exit; 
    }
    
    public static void finalMessage(boolean done, int c)//Method that prints out whether the user won or lost the game
    {
        if(!done) 
        {
            System.out.println("Yes, the number is "+c+". You win!"); //Output to screen
        }
        if(done) 
        {
            System.out.println("No, the number is "+c+". You lose!");//Outout to screen
        }
       
    }

    public static void main(String[] args) 
    {
        System.out.println("Welcome to the guessing game!");
        System.out.println("You have 3 guesses!");
        int n=getUserInput("Enter the largest number possible to guess (remember, if you want 5 to be the largest, enter one larger: 6)");
        
        int numToGuess=numGenerate(n);
        int i=0;
        
        boolean choice=true;
        
        while(i<3 && choice)
        {
            int userNumber=getUserInput("Enter your guess:");
            choice=CompareGuess(userNumber,numToGuess);
            i++;
        }
        finalMessage(choice,numToGuess);
    }
}
