//Yunika Upadhayaya
//1001631183
//8 November 2018

import java.text.DecimalFormat;
import java.util.ArrayList;

public class directMethods
{
    public static int time(int sec)//Method for converting seconds into 24 hr format of clock and getting hours
    {
        while(sec>86400)//This loop will run if the entered second is greater than 86400
        {
            return -1;
        }
        
        int min = sec/60;
        sec= sec-(min*60);//For converting into mins
           
        int hour = min/60;
        min = min -(hour*60);//For converting into  hours
        
        DecimalFormat formatter = new DecimalFormat("00");//To get the time in double digit
        
        String first = formatter.format(hour);
        String second = formatter.format(min);
        String third = formatter.format(sec);
           
        System.out.printf("Current time is %s:%s:%s\n",first,second,third);//Output to screen
        return hour;
    }
    
    public static boolean prime(int number)//Method to check whether a number is prime or not
    {
        int value = 0;
        
        for(int i=2;i<=(number-1);i++)//The loop will run until up to 1 number less than the eneterd number
        {
            if(number%i==0)
            {
                value = value + 1;
            }
        }
        if(value>0)
        {
            return false;// False - Not a prime number
        }
        else
        {
            return true;// True - A prime number
        }
    }
    
    public static int allFactors(int num)//Method to count total number of factors
    {
        ArrayList<Integer>factors = new ArrayList<Integer>();
        for(int i=1;i<=num;i++)
        {
            if(num%i==0)
            {
                factors.add(i);
            }
        }
        System.out.println("Factors of "+num+":"+factors);
        int totalnum = factors.size();
        return totalnum; //Returns total number of factors of the number   
    }
   
    public static void main(String []args)
    {
        System.out.println(time(18000));
        System.out.println(prime(13));
        System.out.println(allFactors(100));
    }
}


