// Yunika Upadhayaya
// 1001631183
// 4 November 2018
import java.util.Scanner;

public class Dates 
{
    
    
    public static String DecToBinary(int userInput)// This method converts passed decimal number into binary number 
    {
        String binaryNumber = "";// We are having our binary number into the empty string
        int dividend = userInput;// Starting with the value of dividend
        
        while(dividend!=0)// Our loop will run until our dividend is not equal to 0
        {
            binaryNumber=buildNum(dividend)+binaryNumber;// BuildNum builds it back
            dividend =dividend/2;// We will be having new value of dividend
        }
        
        return binaryNumber;// It returns new binary value assingmed to it
    }
    
    public static int BinaryToDec(int userInput)// This method converts passed binary number into decimal number
    {
        String binNum = Integer.toString(userInput);// Converts given integer into string
        int numberOfDigits = binNum.length();//Count the total number of digit in the input
        int ans =0;//
        
        for(int i=0;i<numberOfDigits;i++)
        {
            char num1 = binNum.charAt((numberOfDigits-1)-i);// Taking the lsat digit and converting into char
            ans = ans+valueToAdd(num1,i);// Gives the current value of i
        }
        
        return ans;
    }
    
    public static String buildNum(int num)// Helper method to convert decimal into binary
    {
        if(num%2==0)
        {
            return "0";
        }
        else
        {
            return "1";
        }
    }
    
    public static int valueToAdd(char c,int exp)//Helper method to convert binary to decimal
    {
        int integer = Character.getNumericValue(c);
        double power = (double)exp;
        double value = integer*Math.pow(2,power);
        return (int)value;
    }

    
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);// Allows user to Input
        System.out.println("***Enter today's date, month followed by day:(b=binary d=decimal)");//Output to screen
        String gold = in.nextLine();// Asks user to input
        
        String []parts = gold.split("\\W+");//Splits gold input except in the place of numbers and names
        boolean angel=true;
        
        while(angel)//The loop will run until it is true
        {
           if(gold.equals("quit"))
           {
               System.out.println("Bye:)");
               angel = false;
           }
           if(parts.length!=3 && !gold.equals("quit"))
           {
               System.out.println("Wrong format. Enter again.\n");
               System.out.println("***Enter today's date, month followed by day:(b=binary d=decimal)");
               gold = in.nextLine();
               parts = gold.split("\\W+"); 
           }
           else
           {
               angel = false;
           }
        }
            
        if(!gold.equals("quit"))
        {
            if(parts[2].equals("d"))//True or false statement- whether parts[2] is d or not?
            {
                int month= Integer.parseInt(parts[0]);
                int day= Integer.parseInt(parts[1]);
          
                String answer1 = DecToBinary(month);
                String answer2 = DecToBinary(day);
          
                System.out.printf("Date in binary: %s/%s\n",answer1,answer2);//Output to screen
            }
        
            if(parts[2].equals ("b"))//True or false statement - whether parts[2] is b or not?           
            {
               int month1= Integer.parseInt(parts[0]);
               int day1= Integer.parseInt(parts[1]);
           
               int ans1 = BinaryToDec(month1);
               int ans2 = BinaryToDec(day1);
           
               System.out.printf("Date in decimal: %d/%d\n",ans1,ans2);//Output to screen           
            }
        }    
    }
}
        
        
        
        
    
     
        
        
    

    

