#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char str[100000];
int main(void){
    int i,k = 0,num = 0;
    gets(str);
    for(i = 0;i < strlen(str);i++)
    {
        if(str[i] != '.')
            num++;
        else if(str[i] == '.')
            break;
    }    
    if(num == 1)
    {
        if(str[0] == '0')
        {
            num = 0;
            for(i = 0;i < strlen(str);i++)
            {
                if(str[i] == '0'&&k>0) // @@ Logic incorrectly counts zeros after the first non‑zero digit, not before it; exponent calculation becomes wrong.
                {
                    num--; // @@ Decrement logic does not correctly compute the negative exponent; should be counting zeros after decimal before first non‑zero.
                }
                else if(str[i] != '.')
                {
                    printf("%c",str[i]); // @@ Prints the leading '0', which should be omitted in scientific notation; the base must start with the first non‑zero digit.
                    k++;
                    if(k == 1&&i!=strlen(str)-1) // @@ Inserts a decimal point after the first printed digit, but that digit is the leading zero; the decimal point should appear after the first non‑zero digit (or not at all if only one significant digit).
                    {
                        printf(".");
                    }
                } 
            }
            printf("e%d",num); // @@ Exponent is always 0 because num was reset and never correctly set; should be negative (e.g., -1 for "0.9").
        }
        else
        {
            printf("%se0",str);
        }
    }
    else
    {
        for(i = 0;i < strlen(str);i++)
        {
            if(i == 1)
            {
                printf(".%c",str[i]);
            }
            else if(i != num)
            {
                printf("%c",str[i]);
            } 
        } 
        printf("e%d",num-1);
    }
    return 0;
}