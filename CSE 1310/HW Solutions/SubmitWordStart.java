//Yunika Upadhayaya
//1001631183
//September 15 2018

import java.util.Scanner;//Required for user to input

public class SubmitWordStart
{
    public static void main(String []args)
    {
       Scanner in=new Scanner(System.in);//Allows user to input
       
       String word1;//Declaring variable String
       String word;//Declaring variable String
       
       System.out.printf("Please enter a word:");//Output to screen
       word1=in.next();//Asks user for inputing word
       word= word1.toLowerCase();//Converts the entered word to lowercase
       
       
       char a = 'a';//Lines 21 to 46 are used for declaring varible character
       char b = 'b';
       char c = 'c';
       char d = 'd';
       char e = 'e';
       char f = 'f';
       char g = 'g';
       char h = 'h';
       char i = 'i';
       char j = 'j';
       char k = 'k';
       char l = 'l';
       char m = 'm';
       char n = 'n';
       char o = 'o';
       char p = 'p';
       char q = 'q';
       char r = 'r';
       char s = 's';
       char t = 't';
       char u = 'u';
       char v = 'v';
       char w = 'w';
       char x = 'x';
       char y = 'y';
       char z = 'z';
       
       if (word.charAt(0)== a || word.charAt(0)== e || word.charAt(0)== i || word.charAt(0)== o || word.charAt(0) == u)//True or false - Does the word starts with a or e or i or o or u?
       {
         System.out.printf("%s starts with a vowel.\n",word1);// Output to screen
       }   
       else if(word.charAt(0)== b || word.charAt(0)== c || word.charAt(0)== d || word.charAt(0)== f || word.charAt(0) == g || word.charAt(0)== h || word.charAt(0)== j || word.charAt(0)== k || word.charAt(0)== l || word.charAt(0) == m || word.charAt(0)== n || word.charAt(0)== p || word.charAt(0)== q || word.charAt(0) == r || word.charAt(0) == s || word.charAt(0)== t || word.charAt(0)== v || word.charAt(0)== w || word.charAt(0)== x || word.charAt(0)==y || word.charAt(0)== z)//True or false - Does the word start with b or c or d or f or g or h or j or k or l or m or n or p or q or r or s or t or v or w or x or y or z? 
       {
         System.out.printf("%s starts with a consonant.\n",word1); //Output to screen
       }
       else 
       {
           System.out.printf("%s starts with neither a vowel nor a consonant.\n",word1);  //Output to screen    
       }
    }
}    
