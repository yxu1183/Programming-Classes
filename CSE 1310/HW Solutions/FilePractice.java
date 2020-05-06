//Yunika Upadhayaya
//1001631183
//November 30 2018

import java.io.File;//File class for our file object in the readFile()
import java.util.ArrayList;
import java.util.Scanner;

public class FilePractice 
{
    public static String [][]genFile() //The method allows us to type the file name and will return a 2D array of information
    {
        ArrayList<String>allLines= null;
        Scanner in = new Scanner(System.in);
        
        while (allLines == null) //Loop will continually run if we entered wrong file name
        {
            System.out.println("Enter	file	name:");
            String fileName = in.nextLine();
            allLines = readFile(fileName); //If file can't be opened, readFile() will return null
        }
        
        String [][]result = new String[(allLines.size())][]; //Making a 2D array the size of our ArrayList
        int i=0;
        while(i<allLines.size())
        {
            result[i] = allLines.get(i).split(",");
            i++;
        }
        return result;
    }
    
    public static ArrayList<String> readFile(String filename) //This method takes in the file name and returns the array list of string
    {
       File temp = new File(filename); //Ceated the file name called temp
       Scanner iFile; //Created a sacnner object
       try
       {
           iFile = new Scanner(temp);
       }
       catch (Exception e)
       {
           System.out.printf("Failed to open file: %s\n\n", filename);
           return null;
       }
       
       ArrayList<String>result = new ArrayList();
       
       while(iFile.hasNextLine())
       {
           String line = iFile.nextLine(); //Extracting a line from the file
           result.add(line); //Adding that line to our Arraylist
       }
       iFile.close(); //Closing the connection to the file
       return result;
    }
  
    public static void main(String[] args)
    {
        String [][]g=genFile();
        System.out.println("\nSecond row:"); //Output to screen
        for(int j=0;j<g[0].length;j++)
        {
           System.out.printf("%s ",g[2][j]); //Printing the second row
        }
        
        System.out.printf("\n\nDate: %s\n",g[9][0]);
    }
}
