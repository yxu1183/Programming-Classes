//Yunika Upadhayaya
//1001631183
//October 20 2018

import java.util.Scanner;

public class NumeroDeux 
{

    public static int getUserNum(String message)//Method to get user input 
    {
        Scanner in = new Scanner(System.in);//Allows User to input
        System.out.printf(message);//Whatever we pass as an input we get as output
        int userIn = in.nextInt();
        return userIn;
    }

    public static String getUserString(int n)// Method to get user input
    {
        Scanner in = new Scanner(System.in);//Allows user to input
        boolean choice = true;
        System.out.printf("Enter a word at of length %d:", n);//Output to screen
        String input = in.nextLine();
        while(choice)
        {
            if(input.length()!=n)
            {
              System.out.printf("Enter a word at of length %d:", n);
              input = in.nextLine();
            }       
            else
            {
              choice=false;    
            }
        }
        return input;
        
    }

      public static boolean checkNumLength(int a, int check1, int check2)//Method to check whether the entered number is less than check1 or greater than check2
    {
        if (a < check1 || a > check2)//True-false statement 
        {
            return true;
        }
        return false;
    }

    public static void main(String[] args)
    {
        boolean choice = true;
        int userIn = 0;//Variable integer declaration and intialization
        while (choice)//The loop runs until choice is true
        {
            userIn = getUserNum("Enter a number between 4-6:");//We are passing the output message
            choice = checkNumLength(userIn, 4, 6);//Checks whether the passed number is in between 4 and 6
        }

        String input = getUserString(userIn);//
        choice = true;
        int userIn2 = 0;//Variable integer declaration and intialization

        while (choice)//The loop runs until choice is true
        {
            userIn2 = getUserNum("Enter another number(for substring) between 1-3:");//We are passing the output message
            choice = checkNumLength(userIn2, 1, 3);//Checks wheter the passed number is in between 1 and 3
        }

        System.out.println(input.substring(0, userIn2));//Prints the entered number of letters in the word
    }
}
