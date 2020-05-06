//Yunika Upadhayaya
//1001631183
//October 17 2018

public class Fluffy
{
    public static void main(String[] args)
    {
        String s= "The big fluffy dog likes kibbles and bits";//String Declaring and Inititalizing
        
        String [] splitS=s.split(" ");//Turns the String S into an array of words
        
        boolean check = splitS[7].equals("bits");//Checks if the last word in spiltS is bits 
        
        int len = splitS.length;//Checks the length of splitS array
        
        System.out.printf("Length:%d\n",len);//Prints out variable len
        
        System.out.println(splitS[2]);//Outputs the third word in splitS array
        
        for(int i=0; i<len; i++)//Line 17 to 19 prints out the array splitS
        {
            System.out.println(splitS[i]);
        }
    }
}