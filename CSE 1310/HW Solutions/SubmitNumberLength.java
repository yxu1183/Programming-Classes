//Yunika Upadhayaya
//1001631183
//September 8 2018

import java.util.Scanner; //Required for users to input

public class SubmitNumberLength 
{
    public static void main(String [] args)
    {
      Scanner in= new Scanner(System.in);//Allows user to input
      
      int num; //Declaring variable integer
      
      System.out.printf("Please enter a number between 4 and 6:");//Output to screen
      num=in.nextInt();  // Asks user for inputing number
      
      if (num>6 || num<4) //True or false - is the entered number greater than 6 or less than 4?
      {
         System.out.println("Number out of range!");//output to screen
      }
      
      else
      {
          String word;// Declaring variable String
          System.out.printf("Enter a word with atleast "+num+" letters and atmost 10 letters:");//Output to screen
          word= in.next();//Asking user for inputing word
        
          if (word.length()>10)//True or false - is the length of the word greater than 10?
          {
             System.out.println("Too many letters!");//output to screen
          }
         
          else if (word.length()<num)//True or false - is the length of the word smaller than user entered value num?
          {
             System.out.println("Too few letters!");//output to screen
          }
             
          else
          {
             int num2;//Declaring variable integer
             System.out.printf("Please enter another number between 1 and 3:");//output to screen
             num2=in.nextInt();//Asks user for inputing number
             
             if (num2==1)//True or false - is the user entered value num2 equal to 1?
             {
                 System.out.printf("%c\n",word.charAt(0));//ouput to screen
             }
             
             if (num2==2)//True or false - is the user entered value num2 equal to 2?
             {    
                 System.out.printf("%c%c\n",word.charAt(0),word.charAt(1));//output to screen
             }
             
             if (num2==3)//True or false - is the user entered value num2 equal to 3?
             {
                 System.out.printf("%c%c%c\n",word.charAt(0),word.charAt(1),word.charAt(2));//Format specifier is used for getting output
             }
        
                 
          }   
             
      }  
            
    }        
         
}    
           