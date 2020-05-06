//Yunika Upadhayaya
//1001631183
//December 1 2018

package catstuff;

import java.util.ArrayList;
import java.util.Scanner;

public class Cat 
{
    private String name;
    private String breed;
    private String[] colors;
    private ArrayList<String> favFoods=new ArrayList();
    
    public void giveAllinfo()
    {
        Scanner in=new Scanner(System.in);
        
        System.out.println("Hello! You will be entering cat info.");
        
        System.out.println("Enter cat name:");
        name=in.nextLine();
        System.out.println("Enter cat breed:");
        breed=in.nextLine();
        giveColors();
    }
    
    private void giveColors()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("How many colors?");
        int n=in.nextInt();
        in.nextLine();
        colors=new String[n];
        
        for(int i=0;i<colors.length;i++)
        {
            System.out.println("Give color"+(i+1)+":");
            colors[i]=in.nextLine();
        }
    }
    	public void printOutCatInfo()
        {
	System.out.println("\nName:"+name);
	System.out.println("Breed:"+breed);
								
	for(int	i=0;i<colors.length;i++)
	{
        System.out.println("Color:"+colors[i]);
	}
        printOutFavFoods();
	}

    public void addFavFood()
    {
        System.out.println("Add a new favorite food:");
        Scanner in=new Scanner(System.in);
        String food=in.nextLine();
        favFoods.add(food);
    }
    
    private void printOutFavFoods()
    {
        System.out.println("Favorite foods are:");
        for(int i=0;i<favFoods.size();i++)
        {
            String fd=favFoods.get(i);
            System.out.println(fd);
        }
    }
} 


