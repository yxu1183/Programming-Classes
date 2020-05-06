/* Name: Yunika Upadhayaya      Student ID: 1001631183 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BSTLib.h"

void AddBSTNode(BNODE **root, char name_hall[], char zip_hall[],char file_hall[], char hall_size[])
{
	if (*root == NULL)
    {
       *root = (BNODE *)malloc(sizeof(BNODE));
       (*root)->left = (*root)->right = NULL;
       strcpy((*root)->MovieTheaterName,name_hall);
	   strcpy((*root)->ZipCode,zip_hall);
	   strcpy((*root)->FileName,file_hall);
	   strcpy((*root)->Dimensions,hall_size);
	   
    }
	
    else
    {
       if (strcmp(zip_hall,(*root)->ZipCode)<0)
       {
		   AddBSTNode(&(*root)->left, name_hall, zip_hall ,file_hall, hall_size);
	   }
     
       else if(strcmp(zip_hall,(*root)->ZipCode)>0)
       {
		   AddBSTNode(&(*root)->right, name_hall, zip_hall ,file_hall, hall_size);
	   }

       else
       {
		   printf(" Duplicate Zip Code. Not Allowed.");
	   }
    }
}

void InOrder(BNODE *root)
{
	if(root!=NULL)
	{
      InOrder(root->left);
      printf("%-35s",root->MovieTheaterName);
	  printf("%s\n", root->ZipCode);
      InOrder(root->right);
    }
}

BNODE * SearchForBNODE(BNODE *chosen_theatre, char user_zip[])
{
	BNODE *TempPtr = chosen_theatre;
	
	if(TempPtr==NULL || strcmp(user_zip,TempPtr -> ZipCode)==0)
	{
		return TempPtr;
	}
	
    else if(strcmp(user_zip,TempPtr->ZipCode)>0)
	{
		SearchForBNODE(TempPtr->right, user_zip);
		
	}
		
	else
	{	
        SearchForBNODE(TempPtr->left, user_zip);
    }
	
}

