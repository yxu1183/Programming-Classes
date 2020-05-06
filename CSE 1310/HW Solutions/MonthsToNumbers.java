//Yunika Upadhayaya
//1001631183
//September 15 2018

import java.util.Scanner;// Required for users to input

public class MonthsToNumbers
{
    public static void main(String args[] )
    {
        String month;//Declaring variable string
       
        Scanner in = new Scanner(System.in);//Allows user to input
        
        System.out.printf("Please enter the name of the month:");//Output to screen
        month = in.nextLine();//Asks user for entering month
       
        String a="January";//Lines 18 to 29 are used for declaring variable String-Month's name
        String b="February";
        String c="March";
        String d="April";
        String e="May";
        String f="June";
        String g="July";
        String h="August";
        String i="September";
        String j="October";
        String k="November";
        String l="December";
        
        if (month.equalsIgnoreCase (a))//True or false - is the entered month equal to January?
        {
            System.out.println("January is the first month.");//Output to screen
        }
        else if (month.equalsIgnoreCase(b))//True or false - is the eneterd month equal to February?
        {
            System.out.println("February is the second month.");//Output to screen
        }
        else if (month. equalsIgnoreCase (c))//True or false - is the entered month equal to March?
        {
            System.out.println("March is the third month.");//Output to screen
        }
        else if (month.equalsIgnoreCase (d))//True or false - is the entered month equal to April?
        {
            System.out.println("April is the fourth month.");//Output to screen
        }
        else if (month.equalsIgnoreCase (e))//True or false - is the entered month equal to May?
        {
            System.out.println("May is the fifth month.");//Output to screen
        }    
        else if (month.equalsIgnoreCase (f))//True or false - is the entered month equal to June?
        {
            System.out.println("June is the sixth month.");//Output to screen
        }    
        else if (month.equalsIgnoreCase (g))//True or false - is the entered month equal to July?
        {
            System.out.println("July is the seventh month.");//Output to screen
        }    
        else if (month.equalsIgnoreCase (h))//True or false - is the entered month equal to August?
        {
            System.out.println("August is the eighth month.");//Output to screen
        }    
        else if (month.equalsIgnoreCase (i))//True or false - is the entered month equal to September?
        {
            System.out.println("September is the ninth month.");//Output to screen
        }
        else if (month.equalsIgnoreCase (j))//True or false - is the entered month equal to October?
        {
            System.out.println("October is the tenth month.");//Output to screen
        }    
        else if (month.equalsIgnoreCase (k))//True or false - is the entered month equal to November?
        {
            System.out.println("November is the eleventh month.");//Output to screen
        }    
        else if (month.equalsIgnoreCase (l))//True or false - is the entered month equal to December?
        {
            System.out.println("December is the twelfth month.");//Output to Screen
        }    
        else
        {
            System.out.printf("Unknown month:%s\n",month);//Output to screen
        }    
        
    }   
       
}
            

