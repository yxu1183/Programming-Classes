/*Yunika Upadhayaya
ID-1001631183
2nd September 2018
*/


import java.util.Scanner; // Required for users to input

public class Info 
{
public static void main (String[] args)
{
    String name; //Declaring variable String
    int age; //Declaring variable integer
    String food; //Declaring variable String
    
    Scanner in= new Scanner(System.in); //Allows user to input
    
    System.out.println("Enter your name:"); // Output to screen
    name=in.next(); // Asks user for inputing name 
    
    System.out.printf("Enter your age:\n"); // Output appears in new line using printf 
    age=in.nextInt(); //Asks user for imputing age
    
    System.out.printf("Enter your favorite food:\n"); //Output appears in new line using printf
    food=in.next(); //Asks user for inputing favorite food 
   
    int futureAge = age+2; //Declaring variable integer
    
    System.out.printf("\nMy name is: "+name+" and my favorite food is "+food+"! \n"); //Concatenation operator + is used for getting output
    System.out.println("***"); //Aesthetic line
    System.out.println("I am "+age+" years old and in 2 years I will be "+futureAge+"!\n"); //Concatentation 0perator + is used for getting output
 }
        
}