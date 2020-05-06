//Name:Yunika Upadhayaya   StudentID:1001631183

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "ListLib.h"
#include "BSTLib.h"
#include "QueueLib.h"
#include "StackLib.h"

#define MAX_ROW 26
#define MAX_COLUMN 20

void get_commandline_parameters(char* argv[], char ParamName[] , char argv_Value[])
{
    int i=0;

    while(argv[++i]!=NULL)
    {
        if(!strncmp(argv[i], ParamName, strlen(ParamName)))
        {
            strcpy(argv_Value, strchr(argv[i], '=')+1);
        }
    }
}

void zipFileRead(FILE *movieFile_zip,BNODE **root)
{
    char name_hall[50]= {};
    char zip_hall[7]= {};
    char size_hall[7]= {};
    char file_hall[150]= {};
    char read_zip[350]= {};

    while(fgets(read_zip,sizeof(read_zip),movieFile_zip))
    {
        strcpy(name_hall,strtok(read_zip,"|"));
        strcpy(zip_hall,strtok(NULL,"|"));
        strcpy(file_hall,strtok(NULL,"|"));
        strcpy(size_hall,strtok(NULL,"\n"));
        AddBSTNode(root, name_hall, zip_hall, file_hall,size_hall);
    }
}

void PrintHallMap(char MovieHall[][MAX_COLUMN], int size_row , int size_column)
{
    int a =0;
    int b =0;

    printf("\n");
    printf("\t");

    for(a=0; a<size_column; a++)
    {
        printf("Seat%d\t",a+1);
    }

    printf("\n");

    for(a=0; a<size_row; a++)
    {
        printf("\nRow %c",(a+65));
        for(b=0; b<size_column; b++)
        {
            printf("\t%c",MovieHall[a][b]);

        }
        printf("\n");
    }

    printf("\n");
    printf("\n");
}

int sold_status(char *MovieHall)
{
    int status;

    if(*MovieHall=='O')
    {
        status = 1;
    }

    else
    {
        status = 0;
    }

    return status;
}

int main(int argc, char* argv[])
{
    if(argc < 4)
    {
        printf("\nRun command is:\n\n %s RECEIPTNUMBER=file1 QUEUE=file2 ZIPFILE=file3 \n\n", argv[0]);
        exit(0);
    }

    char Parameters[4][25] = {"RECEIPTNUMBER=","QUEUE=","ZIPFILE="};

    int args_Check;
    int param_check=0;
    int occurence=0;
    int newArgs=0;

    for(args_Check=1; args_Check<=argc; args_Check++)
    {
        if(strncmp(argv[++newArgs], Parameters[param_check], strlen(Parameters[param_check])) == 0)
        {
            param_check++;
            occurence++;
            args_Check = 1;
            if(occurence == 3)
            {
                args_Check=argc+1;
            }
            newArgs = 0;
        }
    }

    if(occurence!=3)
    {
        printf("\nRun command is:\n\n %s RECEIPTNUMBER=file1 QUEUE=file2 ZIPFILE=file3 \n\n", argv[0]);
        exit(0);
    }

    char argv_Value[150];
    char ReceiptNumber_File[150];
    char Queue_File[150];
    char Zip_File[150];

    get_commandline_parameters(argv,Parameters[0],argv_Value);
    strcpy(ReceiptNumber_File,argv_Value);
    int receipt_num = atoi(ReceiptNumber_File);

    get_commandline_parameters(argv,Parameters[1],argv_Value);
    strcpy(Queue_File,argv_Value);

    get_commandline_parameters(argv,Parameters[2],argv_Value);
    strcpy(Zip_File,argv_Value);

    char MovieHall[MAX_ROW][MAX_COLUMN];

    LNODE *LinkedListHead=NULL;

    FILE *movieFile_zip = fopen(Zip_File,"r");

    if(movieFile_zip == NULL)
    {
        perror("Zip File did not open");
        exit(0);
    }

    BNODE *root = NULL;

    zipFileRead(movieFile_zip,&root);
    fclose(movieFile_zip);

    FILE *file_Queue = fopen(Queue_File,"r");

    if(file_Queue == NULL)
    {
        perror("Queue File did not open");
        exit(0);
    }

    QNODE *Head_Queue = NULL;
    QNODE *Tail_Queue = NULL;
    SNODE *stack_Top = NULL;

    char CustomerNames[40]= {};
    while(fgets(CustomerNames,sizeof(CustomerNames)+1,file_Queue))
    {
        enQueue(CustomerNames,&Head_Queue,&Tail_Queue);
    }
    fclose(file_Queue);

    while(Head_Queue!=NULL)
    {
        printf("\n\n");
        printf("1. Sell tickets to next customer\n");
        printf("\n2. See who's in line\n");
        printf("\n3. See the seat map for a given theater\n");
        printf("\n4. Print today's receipts\n");

        int choice_user =5;

        while(choice_user<1 || choice_user>4)
        {
            printf("\nChoice: ");
            scanf("%d",&choice_user);

            if(choice_user<1 || choice_user>4)
            {
                printf("\nChoice is unavailable. Please enter again:\n");
            }
        }

        if(choice_user==1)
        {
            int search;
            char name_customer[30];
            strcpy(name_customer, Head_Queue->Name);
            printf("\n\nHello %s\n",name_customer);
            deQueue(&Head_Queue);
            printf("Pick a theater by entering the zipcode:\n\n");
            InOrder(root);

            char zip_user[6]= {};
            BNODE *chosen_theatre=NULL;

            do
            {
                search=0;
                strcpy(zip_user,"571359");
                while(strlen(zip_user)<0 || strlen(zip_user)>5)
                {
                    printf("\n\nEnter Zip: ");
                    scanf("%s",zip_user);

                    if(strlen(zip_user)<0 || strlen(zip_user)>5)
                    {
                        printf("\nInvalid Zip %s. Try again\n",zip_user);
                    }
                }

                chosen_theatre=root;
                chosen_theatre = SearchForBNODE(chosen_theatre, zip_user);

                if(chosen_theatre == NULL)
                {
                    printf("\nThat ZIP code %s is not available.\n",zip_user);
                    search=-1;
                }

                else
                {
                    FILE *chosen_theatre_file = fopen(chosen_theatre->FileName,"r");

                    if(chosen_theatre_file==NULL)
                    {
                        perror("Error in selected movie theatre file");
                        search = -1;
                    }
                    else
                    {
                        char size_theatre[6];

                        strcpy(size_theatre, chosen_theatre->Dimensions);
                        int size_row;
                        int size_column;

                        sscanf(size_theatre, "%dx%d", &size_row , &size_column);

                        char getSeats[MAX_ROW*MAX_COLUMN];

                        fgets(getSeats,sizeof(getSeats),chosen_theatre_file);
                        fclose(chosen_theatre_file);

                        int x = 0;
                        int y = 0;
                        int check=0;

                        if(strlen(getSeats)!=size_row*size_column)
                        {
                            printf("%s has invalid size map. Choose another theatre ",chosen_theatre->MovieTheaterName);
                            search = -1;
                        }
                        else
                        {
                            for(x=0; x<size_row; x++)
                            {
                                for(y=0; y<size_column; y++)
                                {
                                    MovieHall[x][y]= getSeats[check];
                                    check++;
                                }
                            }
                        }

                        if(search!=-1)
                        {
                            PrintHallMap(MovieHall, size_row, size_column);
                            printf("\n\n How many movie tickets do you want to buy? ");

                            int ticket_movie,b,row,column,status;

                            scanf("%d",&ticket_movie);

                            char info_Seat[5];
                            char new_column[5];
                            status = 0;

                            for(b=0; b<ticket_movie; b++)
                            {
                                do
                                {
                                    printf("\n\nPick a Seat (row Seat): ");
                                    scanf("%s", info_Seat);
                                    printf("\n");

                                    info_Seat[0] = toupper(info_Seat[0]);
                                    row = info_Seat[0];
                                    strcpy(new_column,info_Seat+1);
                                    column = atoi(new_column);

                                    if((row - 65 >= size_row || row < 65 || row > 90) || (column > size_column|| column <1 ))
                                    {
                                        printf("This is not a valid seat. Please choose again\n");
                                        PrintHallMap(MovieHall, size_row, size_column);
                                    }
                                    else
                                    {
                                        status = sold_status(&MovieHall[row-65][column-1]);

                                        if(status ==1)
                                        {
                                            MovieHall[row-65][column-1] = 'X';
                                            PrintHallMap(MovieHall, size_row, size_column);
                                            InsertNode(&LinkedListHead,info_Seat);
                                        }
                                        else
                                        {
                                            printf("\nThat seat is not available!\n");
                                        }
                                    }
                                }
                                while((row-65 >= size_row || row < 65 || row > 90) || (column > size_column|| column <1 ) || status ==0);
                            }

                            FILE *writeFile;
                            writeFile = fopen(chosen_theatre->FileName,"w");

                            if(writeFile==NULL)
                            {
                                perror("Error in saving seats to movie theatre file");
                                search=-1;
                            }
                            else
                            {
								int x;
								int y;
								for(x=0; x<size_row; x++)
								{
									for(y=0; y<size_column; y++)
									{
										fprintf(writeFile,"%c",MovieHall[x][y]);
									}
								}
								fclose(writeFile);
                                printf("\n\nThank you. %s - Enjoy your movie! \n\n",name_customer);
                                push(&stack_Top,LinkedListHead,receipt_num,chosen_theatre->MovieTheaterName);
                                LinkedListHead = NULL;
                                receipt_num++;
                            }
                        }
                    }
                }
            }
            while(search==-1);
        }
        if(choice_user==2)
        {
            printf("\n\nCustomer Queue:\n\n");
            DisplayQueue(Head_Queue);
        }
        if(choice_user==3)
        {
            int newChoice;
            printf("\n\nPick a theater by entering the zipcode:\n\n");
            InOrder(root);
            char newZip_user[6]= {};
            BNODE *newChoosenTheatre=NULL;

            do
            {
                newChoice=0;
                strcpy(newZip_user,"571359");

                while(strlen(newZip_user)<0 || strlen(newZip_user)>5)
                {
                    printf("\n\nEnter Zip: ");
                    scanf("%s",newZip_user);

                    if(strlen(newZip_user)<0 || strlen(newZip_user)>5)
                    {
                        printf("\nInvalid Zip %s. Please Try again\n",newZip_user);
                    }
                }

                newChoosenTheatre=root;
                newChoosenTheatre = SearchForBNODE(newChoosenTheatre, newZip_user);

                if(newChoosenTheatre == NULL)
                {
                    printf("\nThat ZIP code %s is not available.\n",newZip_user);
                    newChoice=-1;
                }

                else
                {
                    FILE *NewChoosenTheatreFile = fopen(newChoosenTheatre->FileName,"r");

                    if(NewChoosenTheatreFile==NULL)
                    {
                        perror("There is an error in selected movie theatre file");
                        newChoice = -1;
                    }

                    else
                    {
                        char newTheatreSize[6];

                        strcpy(newTheatreSize, newChoosenTheatre->Dimensions);
                        int newRowSize;
                        int newColumnSize;

                        sscanf(newTheatreSize, "%dx%d", &newRowSize , &newColumnSize);

                        char newGetSeats[MAX_ROW*MAX_COLUMN];

                        fgets(newGetSeats,sizeof(newGetSeats), NewChoosenTheatreFile);
                        fclose(NewChoosenTheatreFile);

                        int m = 0;
                        int n =0;
                        int newCount=0;

                        if(strlen(newGetSeats)!=newRowSize*newColumnSize)
                        {
                            printf("%s has invalid size map. Choose another theatre.",newChoosenTheatre->MovieTheaterName);
                            newChoice = -1;
                        }
                        else
                        {
                            for(m=0; m<newRowSize; m++)
                            {
                                for(n=0; n<newColumnSize; n++)
                                {
                                    MovieHall[m][n]= newGetSeats[newCount];
                                    newCount++;
                                }
                            }
                        }

                        if(newChoice!=-1)
                        {
                            PrintHallMap(MovieHall, newRowSize, newColumnSize);
                        }
                    }
                }
            }
            while(newChoice==-1);
        }
        if(choice_user==4)
        {
            if(stack_Top==NULL)
            {
                printf("\nPop is not executed - stack is empty\n\n");
            }

            char seat_node[3];

            while(stack_Top!=NULL)
            {
                printf("\n\nReceipt #%d\n\n",stack_Top->ReceiptNumber);
                printf("\t%s\n\n",stack_Top->MovieTheaterName);

                while(stack_Top->TicketList!=NULL)
                {
                    ReturnAndFreeLinkedListNode(&stack_Top->TicketList,seat_node);
                    printf("%s\t",seat_node);
                }
                printf("\n");
                printf("\n");

                pop(&stack_Top);
            }
        }
    }

    printf("\n\nGood job - you sold tickets to all of the customers in line.\n\n");

    return 0;
}

