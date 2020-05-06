//Yunika Upadhayaya  1001631183

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListLib.h"

#define MAX_LIMIT 20

void get_commandline_parameters(char* argv[], char Param_Name[] , char Param_Value[])
{
    int i=0;

    while(argv[++i]!=NULL)
    {
        if(!strncmp(argv[i], Param_Name, strlen(Param_Name)))
        {
            strcpy(Param_Value, strchr(argv[i], '=')+1);
        }
    }
}

void PrintArray(char Array[][MAX_LIMIT],int user_size)
{
    int i=0;
    int j =0;

    for(i=0; i<user_size; i++)
    {
        for(j=0; j<user_size; j++)
        {
            printf("%c  ",Array[i][j]);
        }
        printf("\n");
    }
}

void arrayConvert(char New_Array[][MAX_LIMIT], int num_row, int num_column, int num_spots, char symbol , char drawcommand)
{
    int x=0;
    int y=0;

    if(drawcommand=='v')
    {
        for(x=0; x<num_spots; x++)
        {
            New_Array[num_row+x][num_column]=symbol;
        }
    }

    if(drawcommand=='h')
    {
        for(y=0; y<num_spots; y++)
        {
            New_Array[num_row][num_column+y]=symbol;
        }
    }
}

void ConvertUpper(char stringarray[])
{
    int z = 0;
    for (z = 0; z < strlen(stringarray); z++)
    {
        stringarray[z] = toupper(stringarray[z]);
    }
}

void read_File_Data(struct node **LinkedListHead, FILE *file_input)
{

    char command_buffer[15];
    char *token;
    char Letter;
    char draw_command[MAX_LIMIT];

    while ((fgets(command_buffer, sizeof(command_buffer) ,file_input)) != NULL)
    {
        token = strtok(command_buffer, "|");
        Letter = *token;
        token = strtok(NULL, "|");
        strcpy(draw_command, token);
        InsertNewNode(Letter, draw_command, LinkedListHead);
    }

}

int main(int argc, char* argv[])
{
    struct node *LinkedListHead = NULL;
    char value_argv[100];
    char file_name[100];
    char Array_main[MAX_LIMIT][MAX_LIMIT];
    char input_char[4];
    char command_array[15];
    char background_character;
    char draw_command;
    int row =0;
    int column =0;
    int num_count =0;
    int user_draw;
    char symbol;
    int i,j,k =0;
    int move = 0;

    if (argc < 2)
    {
        printf("\nCommand Missing! Command should be: %s DCFILE=yourfile.txt\n", *argv);
        exit(0);
    }
    else if (strncmp(*(argv + 1), "DCFILE", strlen("DCFILE")) != 0)
    {
        printf("\nCommand Invalid! Command should be: %s DCFILE=yourfile.txt\n", *argv);
        exit(0);
    }

    get_commandline_parameters(argv, "DCFILE=", value_argv);
    strcpy(file_name, value_argv);

    FILE *Input_File;
    Input_File= fopen(file_name, "r");

    if(Input_File == NULL)
    {
        printf("The file does not exist.");
        exit(0);
    }

    read_File_Data(&LinkedListHead,Input_File);
    fclose(Input_File);

    printf("\nWhat is the background character? ");
    scanf(" %c",&background_character);

    for (i = 0; i < MAX_LIMIT; i++)
    {
        for (j = 0; j < MAX_LIMIT; j++)
        {
            Array_main[i][j] = background_character;
        }
    }
    printf("\nPlease enter 1-3 letters: ");
    scanf(" %s",input_char);

    while(strlen(input_char)< 1 || strlen(input_char)>3)
    {
        printf("Those characters are out of bounds.");
        printf("\nPlease re-enter 1-3 letters: ");
        scanf(" %s",input_char);
    }
	printf("\n\n");
    ConvertUpper(input_char);

    struct node *New_Bookmark = LinkedListHead;

    while(strlen(input_char)>num_count)
    {
        while(New_Bookmark!= NULL)
        {
            Find_LinkedList(&New_Bookmark, command_array, input_char[num_count]);

            if (strlen(command_array) != 0)
            {
                sscanf(command_array, "%c %*c %d %*c %d %*c %d %*c %c", &draw_command, &row, &column, &user_draw, &symbol);
                draw_command = tolower(draw_command);

                if(symbol=='\n')
                {
                    symbol='X';
                }

                draw_command = tolower(draw_command);

                if(draw_command=='p')
                {
                    if(row>=MAX_LIMIT || column>=MAX_LIMIT)
                    {
                        printf("Draw command %c is out of range.\n",draw_command);
                    }

                    else
                    {
                        Array_main[row][column+move]=symbol;
                    }
                }

                else if(draw_command=='v' || draw_command=='h')
                {
                    if(draw_command=='v')
                    {
                        if(row+user_draw>MAX_LIMIT || user_draw> MAX_LIMIT || column>=MAX_LIMIT || row>=MAX_LIMIT)
                        {
                            printf("Draw command %c is out of range.\n",draw_command);
                        }

                        else
                        {
                            arrayConvert(Array_main,row,column+move,user_draw,symbol,draw_command);
                        }
                    }

                    else if(draw_command=='h')
                    {
                        if(row>=MAX_LIMIT || user_draw>MAX_LIMIT || column+user_draw>MAX_LIMIT || column>=MAX_LIMIT)
                        {
                            printf("Draw command %c is out of range.\n",draw_command);
                        }

                        else
                        {
                            arrayConvert(Array_main,row,column+move,user_draw,symbol, draw_command);
                        }
                    }
                }
                else
                {
                    printf("Draw command %c is unknown.\n",draw_command);
                }
            }
        }
        if (strlen(command_array) != 0)
        {
            command_array[0] = '\0';
            move = move+7;
        }
        num_count++;
        New_Bookmark = LinkedListHead;
    }
    PrintArray(Array_main, MAX_LIMIT);
    return 0;
}

