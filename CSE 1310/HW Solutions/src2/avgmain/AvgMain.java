//Yunika Upadhayaya
//1001631183
//Decmber 3 2018

package avgmain;  //package of Main class

import fileIO.FileIO;  //importing methods from FileIO class 
import java.util.ArrayList;
import java.util.Scanner;

public class AvgMain 
{

    public static boolean check(String[][] s, String Str) //Method that checks if userinput is in the file heading or not.
    {
        boolean check = false;

        for (int i = 1; i < s[0].length; i++) 
        {
            if (s[0][i].trim().equals(Str)) 
            {
                check = true;
            }
        }
        if (check == false) 
        {
            if(s[0][0].trim().equals(Str))
            {
                System.out.println("This is the first column!(enter any other column except the first one)");
            }
            else
            {    
            System.out.println("Sorry, we didnt find it.\n"); //No any heading.
            }
        }
        return check;
    }

    public static ArrayList<Double> info(String[][] jingle, String bell, String christmas) //Method that takes two names of a heading and a 2D array and returns an average between those two headings
    {                                                                                           
        System.out.println("\n***Avg of: " + bell + " and " + christmas +":**\n"); //Output to screen
        double thankyou = 0;
        double next = 0;
        double grateful = 0;

        ArrayList<Double> thanksGiving = new ArrayList(); //Declaring Arraylists
        ArrayList<Double> ribbon = new ArrayList();
        ArrayList<Double> tree = new ArrayList();

        for (int i = 1; i < jingle[0].length; i++) 
        {
            if (jingle[0][i].trim().equals(bell)) //Runs when one of the heading is found
            {
                for (int j = 1; j < jingle.length; j++) 
                {
                    thankyou = Double.parseDouble(jingle[j][i].trim()); //Changes the value into double and adds into another arraylist
                    ribbon.add(thankyou);
                }
            }

            if (jingle[0][i].trim().equals(christmas)) 
            {
                for (int k = 1; k < jingle.length; k++) 
                {
                    next = Double.parseDouble(jingle[k][i].trim());
                    tree.add(next);
                }
            }
        }

        for (int l = 0; l < ribbon.size() && l < tree.size(); l++) 
        {
            grateful = (ribbon.get(l) + tree.get(l)) / 2; //Gets an average between those two headings
            thanksGiving.add(grateful); //Adds into another arraylist
        }
        return thanksGiving;
    }

    public static void preju(ArrayList<Double> koirala, String[][] susmita) //Method that takes an array of doubles and outputs the 2D array with its respective average
    {
        for (int i = 0; i < koirala.size(); i++) 
        {
            System.out.println(susmita[i + 1][0] + ": " + koirala.get(i));
        }
    }

    public static void main(String[] args) 
    {
        String[][] shrestha = FileIO.genFile(); //Read file
        Scanner in = new Scanner(System.in);
        
        String Monima = "";
        String yunika = "";
     
        boolean upadhayaya = false;
        boolean Anjana = false;

        while (upadhayaya != true) //For first heading
        {
            Monima = FileIO.getUserInput("\nEnter first column to find.");
            upadhayaya= check(shrestha, Monima);
        }

        System.out.println(" ");

        while (Anjana != true) //For second heading
        {
            yunika = FileIO.getUserInput("Enter second column to find.");
            if (yunika.equals(Monima)) 
            {
                System.out.println("Same as column 1! Enter another column.\n"); 
                yunika= FileIO.getUserInput("Enter second column to find");
            }

            Anjana = check(shrestha, yunika);
        }

        ArrayList<Double> luintel = info(shrestha, Monima, yunika);
        preju(luintel, shrestha);

        ArrayList<String> Senior = FileIO.convert2D(shrestha, ","); //Prints output
        FileIO.fileOutputObj(luintel, shrestha);
    }
}