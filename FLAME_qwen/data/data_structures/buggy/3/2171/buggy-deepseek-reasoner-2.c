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
                if(str[i] == '0'&&k>0) // @@ Condition incorrectly only counts zeros after first printed digit; should count all leading zeros including the one before decimal point.
                {
                    num--;
                }
                else if(str[i] != '.')
                {
                    printf("%c",str[i]); // @@ Prints the leading zero, which should be skipped; the base should start from the first non-zero digit.
                    k++;
                    if(k == 1&&i!=strlen(str)-1) // @@ Prints a decimal point after the leading zero; should print after the first non-zero digit instead.
                    {
                        printf(".");
                    }
                } 
            }
            printf("e%d",num); // @@ Exponent calculation is wrong; it underestimates the exponent because it didn't count all leading zeros and didn't adjust for the shifted decimal point.
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