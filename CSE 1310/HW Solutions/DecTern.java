//Yunika Upadhayaya
//1001631183
//November 14 2018

import java.util.Scanner;

public class DecTern 
{
    public static String[] UserInput(String message) //Method to get a input by the user
    {   
        Scanner in=new Scanner(System.in); //Required for user to input
        System.out.println(message); //Output to screen
        String info=in.nextLine(); //Allows user to input
        String [] parts=info.split("\\W+"); //Splits the given info at all parts
        boolean exit=true;
        while(exit)//The loop continues until it is true
        {   
            if(parts.length!=2 && !info.equals("exit")) //If user enters the wrong format the if statement will execute
            {
             System.out.println("Wrong format. Enter again.\n");//Output to screen
             System.out.println(message);
             info=in.nextLine();
             parts=info.split("\\W+");
            }
            else
            {
                exit=false;
            }  
        }
        
        return parts;
    }
    
    public static String DecTOTernary(int num) //Method that takes int value in decimal system to convert to ternary
    {
        String ternary="";
        while(num!=0) //Keeps running until the remainder is 0
        {
            ternary=buildnum(num)+ternary; 
            num=num/3;  
        }
        return ternary;
    }
    
    public static String buildnum(int num2) //Supporting method for previous method
    {
        String me;
        switch(num2)
        {
        default:me=Integer.toString(num2%3);//Converts the int value to string value
        }
        return me;
    }
    
    public static int TernToDec(String word) //Method that takes int value in ternary system to convert to decimal system
    {
        int preju=word.length();
        int sush=0;
        for(int i=0;i<preju;i++)
        {
            char mons=word.charAt((preju-1)-i);
            sush=sush+alisha(mons,i);
        }
        return sush;
    }
    
    public static int alisha(char hrithik, int roshan ) //Supporting method for previous method
    {
        int abc=Character.getNumericValue(hrithik);
        double sonali=(double)roshan;
        double ruin=abc*Math.pow(3,sonali);
        return (int)ruin; //Returns double value as integer value
    }
    
    public static void main(String[] args) 
    {
        String[] dell=UserInput("Enter a value to convert followed by d or t (d=decimal, t=tertiary):");
    
        while(!dell.equals("exit")) 
        {
            if(dell[0].equals("exit")) //If user enters exit
            {
                System.out.println("Bye!");//Output to screen
                break;    
            }
            if(dell[1].equals ("t")) //If user wants to convert ternary into decimal
            {
                int yunika;
                yunika = TernToDec(dell[0]);
                System.out.println("Value in decimal: " +yunika+"\n");//Output to screen
            }
                
            if(dell[1].equals("d")) //If user wants to convert decimal to ternary
            {
               int upadhayaya =Integer.parseInt(dell[0]);
               String luintel = DecTOTernary(upadhayaya);
               System.out.println("Value in ternary: "+luintel+"\n");//Output to screen
            }
                
            dell=UserInput("Enter a value to convert followed by d or t (d=decimal, t=tertiary):"); //Keeps asking user until the user enters exit
        }
    }
}    
       
    
   
