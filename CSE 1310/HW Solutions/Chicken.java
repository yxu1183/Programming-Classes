//Yunika Upadhayaya
//1001631183
//October 20 2018

import java.util.Scanner;

public class Chicken {

    public static String[] getInput(String message)//Method to get user input
    {
        Scanner in = new Scanner(System.in);//Allows user to input

        String[] s = new String[3];
        System.out.println(message);//Whatever we pass an input, we get the output
        
        System.out.printf("Day 1: ");//Output to screen
        s[0]= in.nextLine();//Allows user to input
        
        System.out.printf("Day 2: ");//Output to screen
        s[1]=in.nextLine();//Allows user to input
        
        System.out.printf("Day 3: ");//Output to screen
        s[2]=in.nextLine();//Allows user to input
        
        System.out.printf("\n");
        
        return s;
    }

    public static int totalEggs(String[] s) //Method to count total number of eggs
    {
        String []last = s[0].split("-"); //Lines 32-34 splits the string at - 
        String []last1 = s[1].split("-");
        String []last2 = s[2].split("-");
        int a1=Integer.parseInt(last[1]);//Lines 35-37 converts the string in the array into ineteger
        int a2=Integer.parseInt(last1[1]);
        int a3=Integer.parseInt(last2[1]);
        int eggs=a1+a2+a3;
        return eggs;
    }

    public static void main(String[] args)
    {
        String[] farmerOne = getInput("-Info for first farmer:");//We are passing the output message
        String[] farmerTwo = getInput("-Info for second farmer:");//We are passing different output

        int numOne = totalEggs(farmerOne);//Counts the total number of eggs with farmer one
        int numTwo = totalEggs(farmerTwo);//Counts the total number of eggs with farmer two

        if (numOne < numTwo)//True or false- is the total number of eggs with famer one is greater than total number of eggs with farmer 2?
        {
            System.out.println("Farmer 2 has more eggs.");//Output to screen
        } 
        else if (numTwo < numOne)//True or false-is the total number of eggs with farmer two is greater than total number of eggs with farmer 1?
        {
            System.out.println("Famer 1 has more eggs.");//Output to screen
        } 
        else
        {
            System.out.println("They have the same number of eggs.");//Output to screen
        }

    }

}
