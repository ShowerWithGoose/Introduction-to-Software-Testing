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
            num = 0; // @@ Resets num to 0, but should compute exponent based on zeros after decimal point; leads to incorrect exponent.
            for(i = 0;i < strlen(str);i++)
            {
                if(str[i] == '0'&&k>0) // @@ This condition only decrements num after printing has started; does not correctly skip leading zeros or compute proper exponent.
                {
                    num--;
                }
                else if(str[i] != '.')
                {
                    printf("%c",str[i]); // @@ Prints the leading '0' and any zeros after decimal before first non-zero; these should be omitted from the base.
                    k++;
                    if(k == 1&&i!=strlen(str)-1) // @@ Prints a decimal point after the first printed digit, but the first digit may be a leading zero; should print dot only after the first non-zero digit.
                    {
                        printf(".");
                    }
                } 
            }
            printf("e%d",num); // @@ Prints the exponent wrongly; for input "0.9", num remains 0, output "0.9e0" instead of "9e-1".
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