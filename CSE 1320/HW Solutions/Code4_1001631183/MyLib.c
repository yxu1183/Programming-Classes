/*Yunika Upadhayaya 1001631183*/


#include <stdio.h>
#include "MyLib.h"

void ConvertDecimalToBinary(int convert_decimal)
{    
    int Binary_number[8];
	int i =0;
	int j;
	int k= 0;
	
	for(j=7; j>=0; j--)
    {
       Binary_number[i] = convert_decimal>>j;
       Binary_number[i] = Binary_number[i]&1;
	   i++;
    }
    for(k=0;k<8;k++)
    {
       printf("%d",Binary_number[k]);
    }
}

