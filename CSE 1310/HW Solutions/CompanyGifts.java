// Yunika Upadhayaya
// 1001631183
// October 7 2018
import java.util.Scanner;// Required for users to input


public class CompanyGifts 
{

   public static void main(String[] args) 
   {
       Scanner in = new Scanner (System.in);// Allows user to input
       String customers[] = new String[7];// Declaring Customer array with 7 spots
       int counter = 0;// Declares initial number of customers as 0
       
       boolean a=true;//Gives true value directly
       while(a)
       {
           System.out.println("***\nEnter the word customer if you are a customer or your ID if you are the manager.");// Output to screen
           String userInput = in.nextLine();// Asks user for input
           userInput = userInput.toLowerCase();// Converts user inputted value to lowercase
           
           if(userInput.equals("exit"))// True or false- is the user inputted value 'exit'?
           {
               System.out.println("Bye!");// Output to screen if users input exit
               a=false;
           }
          
           else if(userInput.equals("abc 132"))// True or false - is the user inputted value "abc 132"?
           {
               boolean b=true;// Gives true value directly
               while(b)
               {
                   System.out.println("***\nHello manager. What would you like to do?\nPrint to screen or exit?\n***");// Output to Screen
                   userInput=in.nextLine();// Asks user for input
                   userInput = userInput.toLowerCase();// Converts user inputed value to lowercase
                   
                   if(userInput.equals ("print to screen"))// True or false - is the user inputted value 'print to screen'?
                   {
                       if (customers[0]==null)// True or false - if no cutomer inputted value
                       {
                           System.out.println("***\nSorry,no customers have entered any information yet.\n***");// Output to screen
                       }
                       
                       else
                       {
                           System.out.println("***\nCUTOMERS\n");// Output to screen
                           
                           for(int i=0;i<customers.length;i++)
                           {
                               if (customers[i]!=null)//True or false - if customers entered some input
                               {
                                 String [] parts = customers[i].split(" ");
                                 System.out.println("BIRTHDAY:"+parts[2]+" "+" "+"NAME:"+parts[1]+","+parts[0]);//Output to the screen
                               }
                           }
                       }
                   }
                   
                   else if (userInput.equals("exit"))//Ture or false- if user inputted value is exit
                   {
                       b=false;//Exit from the loop
                   }
               }
           }
           
           else if (userInput.equals ("customer"))// True or false - did the user input customer?
           {
               if(customers.length<= counter)//True or false- check so that we do not enter more than the size of the array
               {
                   System.out.println("Sorry, no more customers.\n***");//Output to screen
               }
               
               else
               {
                 System.out.println("***\nHello customer. Please enter your name(first and last) followed by your birthday(MM/DD/YYYY:\n***");//Output to Screen
                 customers[counter] = in.nextLine();
                 String parts[]=customers[counter].split(" ");
                 System.out.println("Thank you"+" "+parts[0]+"!");//Output to Screen using concatenation operator
                 counter ++;//It increaes the counter to have new array index next time
                 continue;//To cause the loop to continue to the next iteration
               }
           }
       }   
                   
   }       
         
}       
       
       
       
       
    
    

