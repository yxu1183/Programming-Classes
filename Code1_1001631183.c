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
    for(k=0; k<8; k++)
    {
        printf("%d",Array2[k]);
    }

}
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

    return 0;
}













