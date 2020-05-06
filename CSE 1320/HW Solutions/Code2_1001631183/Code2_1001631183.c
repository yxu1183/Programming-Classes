/*Yunika Upadhayaya 1001631183*/

#include <stdio.h>
#include "MyLib.h"

int main (void)
{
    int decimal_number;
    int Array[8]= {};

    printf("Decimal to binary convertor\n");
    printf("Please enter a decimal number between 0 and 255 ");
    scanf("%d",&decimal_number);

    while(decimal_number<0||decimal_number>255)
    {
       printf("You entered a number not between 0 and 255\n");
       printf("Please enter a decimal number between 0 and 255 ");
       scanf("%d",&decimal_number);
    } 

    ConvertDecimalToBinary(decimal_number,Array);
    printf("Decimal %d converts to binary ",decimal_number);
    PrintBinary(Array);
    printf("\n");
    return 0;
}

