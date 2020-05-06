/*Yunika Upadhayaya 1001631183*/

#include "MyLib.h"
#include <stdio.h>

void ConvertDecimalToBinary(int convert_decimal,int Array1[])
{    
    int j;
    int i=0;
    for(j=7; j>=0; j--)
    {
       Array1[i] = convert_decimal>>j;
       Array1[i] = Array1[i]&1;
       i++;
    }
}
void PrintBinary( int Array2[])
{
    int k;
    for(k=0;k<8;k++)
    {
       printf("%d",Array2[k]);
    }
}

