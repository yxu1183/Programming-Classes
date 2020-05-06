//Yunika Upadhayaya
//1001631183
//December 3 2018

package fileIO;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class FileIO {

    public static String[][] genFile() 
    {
        ArrayList<String> lines = null;
        Scanner in = new Scanner(System.in);

        while (lines == null) 
        {
            System.out.println("Enter file name:");
            String fileName = in.nextLine();
            lines = readFile(fileName);
        }
        String[][] result = new String[lines.size()][];

        for (int i = 0; i < lines.size(); i++) {

            String line = lines.get(i);
            result[i] = line.split(",");
        }
        return result;
    }

    public static ArrayList<String> readFile(String filename) 
    {
        File temp = new File(filename);
        Scanner input_file;
        try {
            input_file = new Scanner(temp);
        } catch (Exception e) {

            System.out.printf("Failed to open file %s\n\n ", filename);
            return null;
        }
        ArrayList<String> result = new ArrayList();
        while (input_file.hasNextLine()) {

            String line = input_file.nextLine();
            result.add(line);
        }
        input_file.close();
        return result;
    }

    public static ArrayList<String> convert2D(String[][] a, String delimiter) {

        ArrayList<String> I = new ArrayList();

        int rows = a.length;

        int columns = a[0].length;
        String s = "";

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < columns; j++) {
                String s2 = a[i][j];
                s = s + "" + s2;
                s = s + delimiter;
            }
            I.add(s.substring(1, s.length() - 1));
            s = "";
        }
        return I;

    }

    public static String getUserInput(String message) {

        System.out.println(message);
        Scanner in = new Scanner(System.in);
        return in.nextLine();

    }

    public static void fileOutputObj(ArrayList<Double>File, String[][] n) 
    {
        String filename = getUserInput("\n---Enter filename to save to:");
        PrintWriter out = null;

        try 
        {
            out = new PrintWriter(filename);
        } 
        catch (Exception e) 
        {
            System.out.printf("Error: failed to open file %s\n", filename);
            System.exit(0);
        }
        for (int i = 0; i < File.size(); i++) 
        {
            out.printf(n[i+1][0]);
            out.printf(": ");
            out.println(File.get(i));
        }  
        int row = n.length;
        
        out.close();
        System.out.printf("Done writing to file %s.\n", filename);
    }

}

