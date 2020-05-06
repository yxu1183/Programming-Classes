//Yunika Upadhayaya
//1001631183
//December 1 2018

package studentstuff;

import filestuff.FileHandle;//Import the methods made in Filehandle class
import java.util.ArrayList;

public class StudentStuff 
{

    public static void main(String[] args) 
    {
        String[][] newfile = FileHandle.genFile();//Reads the file
        String getInput = "";
        while (!getInput.equals("quit")) 
        {
            getInput = FileHandle.getUserInput("******\nEnter any one:\n1)print info\n2)output file\n3)average grade\n4)quit");//Output to screen
            if (getInput.equals("print info")) //If user enters print info
            {
                String getName = FileHandle.getUserInput("Enter student name:");//get students name-output to screen
                FileHandle.printinfo(newfile, getName);
            } 
            else if(getInput.equals("output file"))//If user inputs output file
            {
                String clas=FileHandle.getUserInput("Enter class name: ");
                ArrayList<String> a=FileHandle.out(newfile, clas);
                FileHandle.fileOutputObj(a);
            }
            else if (getInput.equals("average grade")) //If user enters output grade
            {
                String classNumber = FileHandle.getUserInput("Enter class name or class number: ");//get students class or class number - output to screen
                double avg = FileHandle.average(newfile, classNumber);
                System.out.println("Class average is " + avg + ".");//Out to screen
            } 
            else if (getInput.equals("quit")) //If user enters quit
            {
                System.out.println("Bye!");//Output to screen
                System.exit(0);
            }
        }
    }
}
