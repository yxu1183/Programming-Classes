//Yunika Updhayaya
//1001631183
//October 23 2018

import java.util.Scanner;//Required for users to input

public class FinalGrade 
{
    public static int[] enterInput(String message,int size)//Overloaded Method
    {
        Scanner in=new Scanner(System.in);//Allows user to input
        int []array=new int[size];
        
        for(int i=0;i<array.length;i++)
        {
            System.out.println("Enter "+message+" "+(i+1)+":");//Output to screen
            array[i]=in.nextInt();//Each elemnet in the array is filled by user input
        }
        return array;
    }

    public static double getAvg(int[]a)//Method to get the average of grades
    {
        int total=0;
        
        for(int j=0; j<a.length;j++)
        {
            total=total+a[j];//To get the total value of all elements in the array
        }
        return (double)total/(double)a.length;//Using casting to get the number both left and right of the decimal
    }
    
    public static double getWeightedGrade(int percent, double avg)//Overloaded method
    {
        double percentDecimal=(double)percent/100;//USing casting to avoid 0
        return avg*percentDecimal;
    }
    
    public static void letterGrade(double g)
    {
        if((g<=100)&&(g>=90))//True or false statement
        {
            System.out.println("\nYou made an A!");
        }
        else if((g<90)&&(g>=80))//True or false statement
        {
            System.out.println("\nYou made a B!");
        }
        else if((g<80)&&(g>=70))//True or false statement
        {
            System.out.println("\nYou made a C!");
        }
        else if((g<70)&&(g>=60))//True or false statement
        {
            System.out.println("\nYou made a D!");
        }
        else
        {
            System.out.println("\nYou made a F!");
        }
    }
    
    public static void main(String []args)
    {
        System.out.println("***CSE 1310 grade calculator!***\n");
        
        System.out.println("Plese enter test grades:");
        int []examGrades = enterInput("grade",3);//Allows user to enter 3 grades
        
        System.out.println("\nPlease enter HW grades:");
        int []hwGrades = enterInput("grade",8);//Allows user to enter 8 grades
        
        System.out.println("\nPlease enter quiz grades:");
        int []quizGrades = enterInput("grade",5);//Allows user to enter 5 grades
        
        System.out.println("\nPlease enter final exam grade:");
        int []finalExamGrade = enterInput("grade",1);//Allows user ti enter 1 grade
        
        double avgHws = getAvg(hwGrades);//Gives average of hw grades
        double avgQuiz = getAvg(quizGrades);//Gives average of quiz grades
        
        double exam1 = getWeightedGrade(10,examGrades[0]);//Gives exam1 weight
        double exam2 = getWeightedGrade(12,examGrades[1]);//Gives exam2 weight
        double exam3 = getWeightedGrade(13,examGrades[2]);//Gives exam3 weight
        double HWGrades = getWeightedGrade(15,avgHws);//Gives HW weight
        double quizGrade = getWeightedGrade(20,avgQuiz);//Gives quiz weight
        double finalExam = getWeightedGrade(30,finalExamGrade[0]);//Gives final exam weight
        
        double totalGrade = exam1+exam2+exam3+HWGrades+quizGrade+finalExam;
        
        System.out.printf("\nTotal grade is:%.02f",totalGrade);//Using %.02f to get the grade only up to two decimal places
        letterGrade(totalGrade);//Method to get the grade
    }
}
