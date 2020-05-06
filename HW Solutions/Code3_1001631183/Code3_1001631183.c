/*Name: Yunika Upadhayaya    Student Id:1001631183 */

#include <stdio.h>
#define INT_MAX 20

void printArray(int num, char array[INT_MAX][INT_MAX])
{
    int row; 
    int column;
    for(row =0; row<num; row++)
    {	
        printf("\n");
        for(column = 0; column<num; column++)
        {
            printf(" %c", array[row][column]);
        }
    }
    printf("\n");
}

void ArrayConvert(char Arr[][INT_MAX], int row_2, int column_2, int cells_2, char draw_command_2, char symbol_2)
{
    int i=0;
    int j=0;
	
    if(draw_command_2 == 'v')
    {
        for (i=0; i<cells_2; i++)
        {
            Arr[row_2+i][column_2] = symbol_2;
        }
    }
	
    if(draw_command_2 == 'h')
    {
        for(j=0; j <cells_2; j++)
        {
            Arr[row_2][column_2+j] = symbol_2;
        }
    }
}

int main(void)
{
    char Array [INT_MAX][INT_MAX];
    int value;
    int row1; 
    int column1;
    int cells;
    char drawCommand;
    char symbol;
    char backGround, temp;
    char exit;
	
    printf("How big is the array? (Enter a value between 1 and 20) ");
    scanf("%d",&value);
    
    while(value > 20 || value < 1)
    {
        printf("That value is outside of the max bounds of the array. Please reenter\n");
        printf("\nHow big is the array? (Enter a value between 1 and 20) ");
        scanf("%d",&value);
    }
    
    printf("What is the background character? ");
    scanf(" %c",&backGround);
	
    for(row1 = 0;row1 <value;row1++)
    {
        for(column1 = 0; column1<value; column1++)
        {
            Array[row1][column1] = backGround;
        }
    }
	
    printf("\n\nDraw commands start with\n\n");
    printf("\tP for a single point\n\tH for a horizontal line\n\t");
    printf("V for a vertical line\n\nAfter the P/V/H,");
    printf(" enter a row,col coordinate and the number of spots to mark\n");
    printf("enclosed in () and separated by commas and then the character for the mark.");
    printf("\n'X' will be used if a mark is not entered. For example,");
    printf("\t\n\n\tP(2,3,1)*\tstart at point 2,3 in the array and mark one spot\n\t\t");
    printf("\twith an *. For P, the 3rd parameter is ignored.\n\n\tV(1,2,3)$");
    printf("\tstart at point 1,2 in the array and mark the next\n");
    printf("\t\t\t3 spots to the right with $\n\n\tH(4,6,7)#");
    printf("\tstart at point 4,6 in the array and mark the next\n\t\t");
    printf("\t7 spots down from the current position with #\n");
    printf("\nCoordinates out of range and lines drawn past the borders are not allowed.\n\n");	
    printf("Enter Q at the draw command prompt to quit\n\n");
    printf("Press <Enter> to continue");
	
    temp = getchar();
    getchar();
    printArray(value, Array);
    printf("\nEnter draw command(enter Q to quit) ");
    scanf(" %c(%d,%d,%d)%c", &drawCommand, &row1, &column1, &cells, &symbol);
    drawCommand = drawCommand | (1<<5);
	
    if (symbol=='\n')
    {
        symbol='X';
    }
	
    while (drawCommand!= 'q')
    {
        if(drawCommand=='v' || drawCommand=='h')
        {
            if(drawCommand=='v')
            {
                if(cells==0 ||  cells>value || row1+cells>value ||column1>value || row1>value)
                {
                    printf("\nThat draw command is out of range.\n");
                }
                else
                {
                    ArrayConvert(Array,row1,column1,cells,drawCommand,symbol);
                }
            }
            else if (drawCommand == 'h')
            {        
                if(cells==0 || cells>value || column1+cells>value || row1>value || column1>value)
                {
                    printf("\nThat draw command is out of range.\n");
                }
                else
                {
                    ArrayConvert(Array, row1, column1, cells, drawCommand, symbol);
                }
            }
        }
		
        else if (drawCommand == 'p')
        {
            if (column1>=value || row1>=value)
            {
                printf("\nThat draw command is out of range.\n");
            }
            else
            {
                Array[row1][column1] = symbol;
                printf("\n");
            }
        }

        else
        {
            printf("\nThat draw command is unknown.\n");
        }
		
       printArray(value, Array);
       printf("\nEnter draw command(enter Q to quit) ");
       scanf(" %c(%d,%d,%d)%c", &drawCommand, &row1, &column1, &cells, &symbol);
	
       if (symbol=='\n')
       {
           symbol='X';
       }
       
       drawCommand = drawCommand | (1<<5);
	
    }
    return 0;
}

