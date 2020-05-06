/*Name: Yunika Upadhayaya    Student ID: 1001631183*/

#include <stdio.h>
#include <string.h>
#include "MyLib.h"
#define ARRAYCHAR_MAX 200

typedef struct 
{
    char *song_artist;
    char *song_title;
    char *song_lyrics;
}SONG;

int main(void)
{
    #include "songlist.txt"
	
	int song_choice;
	char letter_guess;
	char yes_no;
	int num_out = 3; 
	int length = 0;
	int i =0;
	int j =0;
	int copy3_length = 0;
	int num_strikes = 0;
	int k =0;
	int y =0;
	
	printf("\n\n\nWelcome to 00000011 ");
	printf(" STRIKES - YOU'RE OUT - the CSE version\n\n");
	printf("Pick a song\n\n");
	printf("0. Exit\n");
	printf("1. Song 1\n");
	printf("2. Song 2\n");
	printf("3. Song 3\n");
	printf("4. Song 4\n");
	printf("5. Song 5\n");
	printf("Song Choice ");
	scanf("%d", &song_choice);
	printf("\n\n");
    while(song_choice >= 6 || song_choice < 0) 
    {
		printf("The song is not available. Please choose again.\n");
        printf("Song Choice: ");
        scanf("%d", &song_choice);
	}
	
    SONG *songarray[] = {&song1, &song2, &song3, &song4, &song5};
	
	char copy_1[ARRAYCHAR_MAX]; 
	char copy_2[ARRAYCHAR_MAX];
	char copy_3[ARRAYCHAR_MAX];
	
	
    if(song_choice != 0)
    {
        printf("\nRound 1 - Here's the song lyric you need to guess\n\n");
		
        strcpy(copy_1, songarray[song_choice-1]->song_lyrics);
        length = strlen(copy_1);
		
        for(i =0; i<length; i++)
        {
            copy_1[i] = toupper(copy_1[i]);
        }
		
        strcpy(copy_2,copy_1);
        strcpy(copy_3,copy_2);
        copy3_length = strlen(copy_3);
		
        for(j = 0; j<copy3_length; j++)
        {
            if((copy_3[j] >= 'A' && copy_3[j] <='Z') || copy_3[j] >= 'a' && copy_3[j] <= 'z')
            {
                copy_3[j] = '-';
            }
        }
        printf("%s\n", copy_3);
		
        while(!(strcmp(copy_3, songarray[song_choice-1]->song_lyrics)==0) && num_strikes < 3)
        {
            int your_out = 0;
            printf("\n\nPlayer: Guess a letter: ");
            scanf(" %c", &letter_guess);
            letter_guess = toupper(letter_guess);
			
            for(k =0; k<strlen(copy_2);k++)
            {
                if(letter_guess == copy_2[k])
               {
                   copy_3[k] = songarray[song_choice-1]->song_lyrics[k];
                   copy_2[k] = '-';
                   your_out = 1;
                }
            }
			
            if(strcmp(copy_3, songarray[song_choice-1]->song_lyrics)==0)
            {
                printf("\n\nYou guessed correctly!!\n\n");
            }
            if(your_out==0)
            {
                num_strikes++;
                if(num_strikes<3)
                {
                    printf("\nStrike ");
                    ConvertDecimalToBinary(num_strikes);
                    printf("\n\n%s\n", copy_3);
                }
            
                else
                {
                    ConvertDecimalToBinary(num_strikes);
                    printf(" STRIKES - YOU'RE OUT!!\n\n\nGame over\n");
                }
            }
            else
            {
                printf("\n%s\n", copy_3);
			
            }
        }
        if(num_strikes<3)
        {	
            num_strikes = 0;
            printf("\n\nCongratulations! You guessed correctly - ready for Bonus Round 2?\n\n");
            printf("Do you want to play the next round? ");
            scanf(" %c", &yes_no);
			
            if(yes_no == 'Y' || yes_no == 'y')
            {
                num_strikes = 0; 
                printf("\n\nRound 2 Here's the title you need to guess - \n\n");
                strcpy(copy_1, songarray[song_choice-1]->song_title);
                length = strlen(copy_1);
		
                for(i =0; i<length; i++)
                {
                    copy_1[i] = toupper(copy_1[i]);
                }
		
                strcpy(copy_2,copy_1);
                strcpy(copy_3,copy_2);
                copy3_length = strlen(copy_3);
		
                for(j = 0; j<copy3_length; j++)
                {
                    if((copy_3[j] >= 'A' && copy_3[j] <='Z') || copy_3[j] >= 'a' && copy_3[j] <= 'z')
                    {
                       copy_3[j] = '-';
                    }
                }
                printf("%s\n", copy_3);
		
                while(!(strcmp(copy_3, songarray[song_choice-1]->song_title)==0) && num_strikes < 3)
                {
                   int your_out = 0;
                   printf("\n\nPlayer: Guess a letter: ");
                   scanf(" %c", &letter_guess);
                   letter_guess = toupper(letter_guess);
			
                   for(k =0; k<strlen(copy_2);k++)
                   {
                        if(letter_guess == copy_2[k])
                        {
                            copy_3[k] = songarray[song_choice-1]->song_title[k];
                            copy_2[k] = '-';
                            your_out = 1;
                        }
                    }
                    if(strcmp(copy_3, songarray[song_choice-1]->song_title)==0)
                    {
                        printf("\n\nYou guessed correctly!!\n\n");
                    }
                    if(your_out==0)
                    {
                        num_strikes++;
                        if(num_strikes<3)
                        {
                            printf("\nStrike.");
                            ConvertDecimalToBinary(num_strikes);
                            printf("\n\n%s\n", copy_3);
                        }
                    
                        else
                        {
                            ConvertDecimalToBinary(num_strikes);
                            printf(" STRIKES - YOU'RE OUT!!\n\n\nGame over\n");
                        }
						
                    }
                    else
                    {
                       printf("\n%s\n", copy_3);
			
                    }
                } 
			}
			else
			{
				num_strikes = 4;
			}
        }
    
        if(num_strikes<3)
        {
            printf("\n\nCongratulations! You guessed correctly - ready for Bonus Round 3?\n\n");
            printf("Do you want to play the next round? ");
            scanf(" %c", &yes_no);
			
            if(yes_no == 'Y' || yes_no == 'y')
            {
                num_strikes = 0; 
                printf("\n\nRound 3 Here's the artist you need to guess - \n\n");
                strcpy(copy_1, songarray[song_choice-1]->song_artist);
                length = strlen(copy_1);
		
                for(i =0; i<length; i++)
                {
                    copy_1[i] = toupper(copy_1[i]);
                }
		
                strcpy(copy_2,copy_1);
                strcpy(copy_3,copy_2);
                copy3_length = strlen(copy_3);
		
                for(j = 0; j<copy3_length; j++)
                {
                    if((copy_3[j] >= 'A' && copy_3[j] <='Z') || copy_3[j] >= 'a' && copy_3[j] <= 'z')
                    {
                       copy_3[j] = '-';
                    }
                }
                printf("%s\n", copy_3);
		
                while(!(strcmp(copy_3, songarray[song_choice-1]->song_artist)==0) && num_strikes < 3)
                {
                    int your_out = 0;
                    printf("\n\nPlayer: Guess a letter: ");
                    scanf(" %c", &letter_guess);
                    letter_guess = toupper(letter_guess);
			
                    for(k =0; k<strlen(copy_2);k++)
                    {
                        if(letter_guess == copy_2[k])
                        {
                            copy_3[k] = songarray[song_choice-1]->song_artist[k];
                            copy_2[k] = '-';
                            your_out = 1;
                        }
                    }
			
                    if(strcmp(copy_3, songarray[song_choice-1]->song_artist)==0)
                    {
                        printf("You guessed correctly!!\n\n");
				    }
                    if(your_out==0)
                    {
                        num_strikes++;
                        if(num_strikes<3)
                       {
                            printf("\nStrike.");
                            ConvertDecimalToBinary(num_strikes);
                            printf("\n\n%s\n", copy_3);
                        }
                    
                        else
                        {
                            ConvertDecimalToBinary(num_strikes);
                            printf(" STRIKES - YOU'RE OUT!!\n\n\nGame over\n");
                        }
						
                    }
                    else
                    {
	                    printf("\n%s\n", copy_3);
                    }
                }
            }
	        else
            {
               num_strikes = 4;
            }
        }
        if(num_strikes<3)
        {
            printf("\n\nCongratulations! You won all the three rounds.\n");
        }
    }
    return 0;
}

