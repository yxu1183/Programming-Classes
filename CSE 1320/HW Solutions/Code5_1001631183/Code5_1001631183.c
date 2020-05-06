//Yunika Upadhayaya 1001631183

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SortLib.h"
#define MAX_ORDER 1000

void get_line_parameters(char* argv[], char Pname[] , char Pvalue[])
{
    int i=0;
	
    while(argv[++i]!=NULL)
    {
        if(!strncmp(argv[i], Pname, strlen(Pname)))
        {
            strcpy(Pvalue, strchr(argv[i], '=')+1);
        }
    }
}

int ReadLunchOrders(Combos LunchOrders[], FILE *Menu)
{
    int i = 0;
    char input[150];
    char *token;
	
    while(fgets(input,sizeof(input),Menu))
    {
        if(ferror(Menu))
        {
            perror("fgets() error");
            i = -1; 
        }
        
            token = strtok(input, "|");
            strcpy(LunchOrders[i].name, token);
		 
            token = strtok(NULL, "|");
            strcpy(LunchOrders[i].sandwich, token);
		 
            token = strtok(NULL, "|");
            LunchOrders[i].fry_size= *token;
		 
            token = strtok(NULL, "|");
            LunchOrders[i].drink_size = *token;
		 
            token = strtok(NULL, "\n");
            strcpy(LunchOrders[i].drink_type, token);
		 
            i++;
        
    }
    return i;
}
	
void PrintLunchOrders(Combos LunchOrders[] , int orders)
{
    int j;
	
    printf("\n\t\t\t\t\t\tFry\tDrink\tDrink\n");
    printf("\tName\t\tSandwich\t\tSize\tSize\tType\n\n");
	
    for(j = 0; j < orders; j++)
    {
        printf("%d.\t%-15s %-25s %c\t %c\t%s\n",j+1,LunchOrders[j].name,LunchOrders[j].sandwich,LunchOrders[j].fry_size,LunchOrders[j].drink_size,LunchOrders[j].drink_type);
    }
    printf("\n");
}

void WriteLunchOrders(Combos LunchOrders[], int orders, FILE *Menu)
{
    int j;
    for(j=0; j < orders; j++)
    {
        if(ferror(Menu))
        {
            perror("fprintf() error");
        }
		
        else
        {
            fprintf(Menu,"%s|%s|%c|%c|%s\n",LunchOrders[j].name,LunchOrders[j].sandwich,LunchOrders[j].fry_size,LunchOrders[j].drink_size,LunchOrders[j].drink_type);
        } 	
    }
    printf("Writing lunch orders to file .... Done.\n\n");
}

void SuperSizeIt (Combos *LunchOrders)
{
    LunchOrders->drink_size = 'L';
    LunchOrders->fry_size= 'L';
}

int main(int argc, char* argv[])
{
    Combos Eat_Orders[MAX_ORDER];
    char value[100]={};
    char Input_File_name[100] = {};
    char Output_File_name[100] ={};
    int	choice_num = 2;
    int store_num;
	
    int (*CompareFunctionPtrArray[]) (const void *, const void *) = {name_Compare,sandwich_Compare,frysize_Compare,drinksize_Compare,drinktype_Compare};
	
    get_line_parameters(argv, "INITIALORDERS=", value);
    strcpy(Input_File_name, value);
	
    get_line_parameters(argv, "FINALORDERS=", value);
    strcpy(Output_File_name, value);
	
    FILE *InputFILE = fopen(Input_File_name, "r");
	//store_num = ReadLunchOrders(Eat_Orders, InputFILE);
	
    if(InputFILE== NULL)
    {
        printf(" %s did not properly open...exiting\n", Input_File_name);
        exit(0);
    }

    FILE *OutputFILE = fopen(Output_File_name, "w");
	
    if(OutputFILE == NULL)
    {
        printf(" %s did not properly open...exiting\n", Output_File_name);
        exit(0);
    }
	
    store_num = ReadLunchOrders(Eat_Orders, InputFILE);
    fclose(InputFILE);
	
    while(choice_num!=0)
    {
        PrintLunchOrders(Eat_Orders,store_num);
        printf("\nEnter 0 to finalize orders and print orders to file\n");
        printf("\nSupersize which order? (1-%d) : ",store_num);
        scanf("%d",&choice_num);
		
        while(choice_num != 0 && (choice_num < 0 || choice_num > store_num))
        {
            printf("\nInvalid menu choice. Please re-Enter:\n\n");
            printf("Enter 0 to finalize orders and print orders to file\n\n");
            printf("Supersize which order? (1-%d) : ",store_num);
            scanf("%d",&choice_num);
        }
		
        SuperSizeIt(&Eat_Orders[choice_num-1]);	
    }
	
    printf("\n\nChoose a sort before writing out the file\n\n");
    printf("0. No sort - write out in current order\n");
    printf("1. Sort by Name\n");
    printf("2. Sort by Sandwich\n");
    printf("3. Sort by fry_size\n");
    printf("4. Sort by drink_size\n");
    printf("5. Sort by DrinkType");
    printf("\nEnter Choice: ");
    scanf("%d",&choice_num);
	
    while(choice_num < 0 || choice_num > 5)
    {
        printf("\nPlease choose from given options (0-5)...\nEnter Choice: ");
        scanf("%d",&choice_num);
    }
		
    if(choice_num!=0)
    {
        qsort(Eat_Orders,store_num, sizeof(Combos),(*CompareFunctionPtrArray[choice_num-1]));
    }
	
    WriteLunchOrders(Eat_Orders,store_num,OutputFILE);
    fclose(OutputFILE);
    return 0;
}

