//Yunika Upadhayaya
//1001631183
//October 17 2018

import java.util.Scanner;//Required for users to input

public class EvenOdd 
{
   public static int getUserInput(String message)//Method to get the user input
   {
      Scanner in = new Scanner(System.in);//Allows user to input
      System.out.println(message);//Whatever we pass as an input, we get as an output
      int n= in.nextInt();
      return n;
   }
    public static boolean checkIfEven(int n)//Method to check whether inputted number is even or not
    {
        while((n%2)!=0)//This loop will continue until the remainder for n/2 is not equal to 0
        {
          System.out.println("That is not even. Enter an even number:");// Output to screen      
          Scanner in = new Scanner(System.in);
          n=in.nextInt();
        }
        return true;
    }
    
    public static void main(String[] args)
   {
     int num1=getUserInput("--Enter an even number:");//We are passing the output message
     boolean check = checkIfEven(num1);//Checks whether the passed number is even or not
     
       if(check==true)//True or false- is the passed number even? 
       {
          int num2 = getUserInput("\n--Ok thanks! Now enter an odd number:");//We are passing different output
        
            while (num2%2==0)//The loop will run until the remainder for num2/2 is not equal to 0
            {
             Scanner in = new Scanner(System.in);
             System.out.println("That is not odd. Enter an odd number:");//Output to screen
             num2 = in.nextInt();
            }
         
            System.out.println("\n**Thanks! Bye!**");//Output to screen
        }
    }
}   
    

    

