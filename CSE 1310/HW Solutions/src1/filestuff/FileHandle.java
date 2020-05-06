//Yunika Upadhayaya
//1001631183
//December 1 2018

package filestuff;

import java.io.File;//File class for our file object in the readFile()
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class FileHandle {

    public static String[][] genFile() //The method allows us to type the file name and will return a 2D array of information
    {
        ArrayList<String> info = null;
        Scanner in = new Scanner(System.in);

        while (info == null) //Loop will continually run if we entered wrong file name
        {
            System.out.println("Enter file name:");
            String fileName = in.nextLine();
            info = readFile(fileName); //If file can't be opened, readFile() will return null
        }

        String[][] end = new String[(info.size())][]; //Making a 2D array the size of our ArrayList

        for (int i = 0; i < info.size(); i++) {
            String line = info.get(i); //Taking element form the array lsit
            end[i] = line.split(","); //Splitting by comma and putting the resulted array into result at index i
        }
        return end;
    }

    public static ArrayList<String> readFile(String filename) //This method takes in the file name and returns the array list of string
    {
        File tempo = new File(filename); //Ceated the file name called tempo
        Scanner inputFile; //Created a sacnner object
        try {
            inputFile = new Scanner(tempo);
        } catch (Exception e) {
            System.out.printf("Failed to open file: %s\n\n", filename);
            return null;
        }

        ArrayList<String> result = new ArrayList();

        while (inputFile.hasNextLine()) {
            String line = inputFile.nextLine(); //Extracting a line from the file
            result.add(line); //Adding that line to our Arraylist
        }
        inputFile.close(); //Closing the connection to the file
        return result;
    }

    public static void printinfo(String[][] a, String g)//Method that takes in file and persons name and returns all the info for that person 
    {
        boolean c = false;
        for (int i = 0; i < a.length; i++) {
            if (a[i][0].equals(g)) {
                System.out.println("Info for " + g + ":" + "\nClass number: " + a[i][1].trim() + "\nClass name:" + a[i][2].trim() + "\nGrade:" + a[i][3].trim());//Output to screen
                c = true;
            }
        }
        if (c == false) {
            System.out.println("No student named " + g + " found.");//Output to screen
        }
    }

    public static double average(String[][] m, String y)//Method that return the average for the class number or name entered
    {
        double getTotal = 0;
        double num = 0;
        for (int i = 0; i < m.length; i++) {
            if (m[i][1].trim().equals(y) || m[i][2].trim().equals(y)) {
                getTotal = getTotal + Integer.parseInt(m[i][3].trim());
                num++;
            }
        }
        double avg = getTotal / num;
        return avg;
    }

    public static ArrayList<String> convert2D(String[][] a, String delimiter) {
        ArrayList<String> I = new ArrayList();
        int rows = a.length;
        int columns = a[0].length;
        String s = "";

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                String s2 = a[i][j];
                s = s + " " + s2;
            }
            I.add(s.substring(1, s.length() - 1));
            s = "";
        }
        return I;
    }

    public static void fileOutputObj(ArrayList<String> toFile) {
        String filename = getUserInput("Enter filename to save to:");
        PrintWriter out = null;
        try {
            out = new PrintWriter(filename);
        } catch (Exception e) {
            System.out.printf("Error:failed to open file %s.\n", filename);
            System.exit(0);
        }

        for (int i = 0; i < toFile.size(); i++) {
            out.println(toFile.get(i));
        }
        out.close();

        System.out.printf("Done writing to file %s.\n", filename);
    }

    public static ArrayList<String> out(String[][] a, String b) {
        ArrayList<String> info = new ArrayList();

        for (int i = 0; i < a.length; i++) {
            if (a[i][2].trim().equals(b)) {
                String Str = a[i][0];
                info.add(Str);
            }
        }
        return info;
    }

    public static String getUserInput(String newMessage)//Methos that returns the userinpput
    {
        Scanner in = new Scanner(System.in);
        System.out.println(newMessage);
        return in.nextLine();
    }
}    

