//Yunika Upadhayaya
//1001631183
//October 20 2018

import java.util.Scanner;//Required for users to input

public class Movie {

    public static String [] enterMovies(int numOfMovies)//Method to enter the movies information
    {
        String [] inputMovies= new String[numOfMovies];
        Scanner in =new Scanner(System.in);//Allows user to input
        for(int i=0;i<inputMovies.length;i++)
        {
            System.out.printf("***Enter a movie that starts with m:");//Output to screen
            inputMovies[i]=in.nextLine();//Asks user for entering movies
            String caseSensitive=inputMovies[i].toLowerCase();//Converts the movie entered into lowercase
             
            while(caseSensitive.charAt(0)!='m')//The loop runs if the first letter in the movie is m
            {
              System.out.println("-That movies does not start with m.");//Output to screen
              System.out.printf("***Enter a movie that starts with m:");//Output to screen
              inputMovies[i]=in.nextLine();//Aks user for entering movies
              caseSensitive = inputMovies[i].toLowerCase();
            }
         }
        return inputMovies;   
    }
    
    public static void movieLength(String [] s, int n)
    {
        int p=0;
        System.out.printf("\nMovies titles with an even length less than %d:\n",n);//Output to screen
    
        for(int j=0;j<s.length;j++)
        {
          if((s[j].length()<n)&&(s[j].length()%2==0))//True or false statement-if the length of the entered movie is less than n and is even length less than 5?
          {
             System.out.println(s[j]);//Output to screen
             p+=1;
          }
        }
        if(p==0)
        {
            System.out.printf("No any movies titles with an even length less than %d.\n",n);//Output to screen
        }
    }    
    
    public static void main(String[] args) 
    {
        String [] input= enterMovies(3);//We are passing 3 movies
        int a=5;//Variable Declaration and assingment
        movieLength(input,a);//Gives output of movie title with an even length less than 5
    }   

}
            
        