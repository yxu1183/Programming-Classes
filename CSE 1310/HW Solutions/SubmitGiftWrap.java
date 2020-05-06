//Yunika Upadhayaya
//1001631183
//September 15 2018

import java.util.Scanner;//Required for users to input

public class SubmitGiftWrap
{
    public static void main (String[] args)
    {
      int num;//Lines 11 to 16 are used for decalring variable integer
      int length;
      int width;
      int height;
      int surfaceArea;
      int cost;
      
      Scanner in = new Scanner(System.in);//Allows user to input
      
      System.out.println("***Hello! Please pick from the following options:***");//Output to screen
      System.out.println("1)Buy standard wrapping paper-press 1");//Output to screen
      System.out.println("2)Buy holiday edition wrapping paper-press 2");//Output to screen
      num = in.nextInt();//Asks user for entering num
      
      
      if(num==1)//True or false - is num equal to 1?
      {
         System.out.println("You have selected standard wrapping paper.");//Output to screen
         System.out.println("Please enter the size of your gift(in inches):");//Output to screen
         
         System.out.printf("Length:");//Output to screen
         length=in.nextInt();//Asks user for entering length
         System.out.printf("Height:");//Output to Screen
         height=in.nextInt();//Asks user for entering height
         System.out.printf("Width:");//Output to screen
         width=in.nextInt();//Asks user for entering width
         
         surfaceArea = 2 * (width*length + height*length +height*width);//Gives surface area for rectangular prism
         cost = 1*surfaceArea;//Gives cost for standard wrapping paper
         
         System.out.printf("You will pay $%d at the counter. Thank you for shopping with us!\n",cost);//Output to screen
      }
     
      if(num==2)//True or false - is num equal to 2?
      {
         System.out.println("You have selected holiday edition wrapping paper.");//Output to screen
         System.out.println("Please enter the size of your gift(in inches):");//Output to screen
         
         System.out.printf("Length:");//Output to screen
         length=in.nextInt();//Asks user to enter length
         System.out.printf("Height:");//Output to screen
         height=in.nextInt();//Asks user to enter height
         System.out.printf("Width:");//Output to screen
         width=in.nextInt();//Asks user to enter width
         
         
         surfaceArea = 2 * (width*length + height*length +height*width);//Gives surface area for rectangular prism
         cost = 2*surfaceArea;//Gives cost for holiday edition wrapping paper
         
         System.out.printf("You will pay $%d at the counter.Thank you for shopping with us!\n",cost);//Output to screen
      }
      
    }  
}            
    
      
      
            
