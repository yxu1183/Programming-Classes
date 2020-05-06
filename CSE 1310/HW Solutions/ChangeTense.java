// Yunika Upadhayaya
// 1001631183
// October 6 2018
import java.util.Scanner;//Required for users to input


public class ChangeTense 
{

    public static void main(String[] args)
    {
        String []pastTense ={"ate","flew","spoke","shook","left","danced","baked"};// Array declaring and assinging with past tense verbs
        String []presentTense = {"eat","flies","speak","shakes","leaves","dances","bake"};// Array declaring and assinging with present tense verbs
                
        Scanner in = new Scanner(System.in);//Allows users to input
        boolean exit = true;// Directly gives true value
        
        while(exit)// While loop executes when exit is true
        {
            System.out.println("Please enter a sentence or q to quit:");// Output to Screen
            String input = in.nextLine();// Asks user to input
            
            if(input.equals("q"))//True or false- if user inputted value is 'q'
            {
                System.out.println("BYE!");// Output to screen
                exit=false;// Ends the loop
            }
            
            else
            {
                input = input.substring(0,input.length()-1);//Removes the period at the end of the sentence
                String []words = input.split(" ");// Splits the sentence 
                String replace = null;// If there are no above assigned verbs
                String presentPast = words[2];
                
                if (presentPast.equals ("today"))//True or false - if the user inputted present tense sentence
                {
                    for (int i=0;i<presentTense.length;i++)
                    {
                        if(presentTense[i].equals(words[1]))
                        {
                            replace = pastTense[i];
                            break;// Exit from the loop
                        }
                    }
                    
                    if (replace == null)// True or false - if other than above assinged verbs
                    {
                        System.out.println("Past tense is: "+words[0]+" "+ words[1]+"e"+"d"+" "+"yesterday"+".");// Output to screen
                    }
                    
                    else
                    {
                        System.out.println("Past tense is: "+words[0]+" "+replace+" "+"yesterday"+".");// Output to screen
                    }
                }
                
                if(presentPast.equals("yesterday"))// True or false - If the user inputted sentence is in past tense
                {
                    for(int i = 0; i<pastTense.length; i++)
                    {
                        if(pastTense[i].equals(words[1]))
                        {
                            replace = presentTense[i];
                            break;//Ends the loop
                        }        
                    }                    
                   
                    if (replace == null)// True or false - if other than above assigned verbs
                    {
                        System.out.println("Present tense is: "+words[0]+" "+words[1].substring(0,words[1].length()-2)+" "+"today"+".");//Output to screen
                    }
                    
                    else
                    {
                        
                        System.out.println("Presnt tense is: "+words[0]+" "+replace+" "+"today"+".");// Output to screen
                    }
                }
                
            }
            
        }
        
       
    }
}
