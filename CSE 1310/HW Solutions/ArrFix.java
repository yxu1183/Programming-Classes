//Yunika Upadhayaya
//1001631183
//November 11 2018

import java.util.ArrayList;
import java.util.ListIterator;
import java.util.Scanner;

public class ArrFix 
{
    public static int getUserInput()//Method to return integer entered by the user
    {
        Scanner in = new Scanner(System.in);//Required for user to input
        System.out. println("Enter a number or -1 to quit.");
        boolean done = true;
        int n = 0;
        while(done)
        {
            try
            {
                n = in.nextInt();
                done = false;
            }
            catch(Exception e)
            {
                System.out.println("That is not a number. Please enter a number.");//Output to screen if user enters variables other than numbers
                in.nextLine();
            }
        }
        return n;//returns number
    }
    public static void printOutList(ArrayList<Integer>num)//Method that takes arraylist of integers and prints out all of its elements
    {
        System.out.println("Currently in the list:");//Output to the screen
        ListIterator<Integer>num2=num.listIterator();
        for(int i =1; num2.hasNext();i++)
        {
            System.out.print(num2.next()+" ");//Output to the screen- prints out each element in the array
        }
        System.out.println("\n");
    }
    public static void main(String[] args) 
    {
        ArrayList<Integer>numbers = new ArrayList();
        
        int n = 0;
        do
        {
            n = getUserInput();
            if(n==-1)//if user enters -1, the program ends
            {
                System.out.println("Bye!");//output to screen
                return;
            }
            else if(numbers.contains(n))//if user enter the same number
            {
                System.out.println("Already have this number.");
            }
            else 
            {
                numbers.add(n);
            }
            printOutList(numbers);
        }
        while(n!=-1);
    }
        
}
   
