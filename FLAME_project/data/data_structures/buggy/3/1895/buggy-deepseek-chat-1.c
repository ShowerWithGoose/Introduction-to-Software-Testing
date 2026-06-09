#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char num[105];
    scanf("%s",&num);
    int i,k,suma=0,sumb=0;
    if(num[0]=='0')
    {
        sumb=1;
    }
    for(i=1;i<strlen(num);i++)
    {
        if(num[0]=='0')
        {
            if(num[i]=='0' && sumb==i-1)
            {
                sumb++;
                
            }
        }
        else
        {
            if(num[i]=='.')
            {
                break;
            }
            else
            {
                suma++;
                
            }
        }
    }
    //printf("%d\n%d\n",sumb,strlen(num));
    if(sumb!=0)
    {
        printf("%c",num[sumb+1]); // @@ Error: When the input is "0.00000009123456789012", sumb is 8 (counting leading zeros after decimal), but num[sumb+1] = num[9] = '9', which is correct. However, the exponent calculation is wrong: sumb counts the number of leading zeros after the decimal point, but the exponent should be -(sumb+1) because the first non-zero digit is at position sumb+1 after the decimal. For example, for "0.00000009123456789012", sumb=8, but the exponent should be -8 (since 9.123456789012e-8), not -8 as printed. Actually the output shows e-8 which matches sumb=8, but the expected output is e-8 as well. Wait, the buggy output shows "9.123456789012 e-8" with an extra space before e-8? No, the buggy output shows "9.123456789012 e-8" with a space? Actually the buggy output is "9.123456789012 e-8" but the expected is "9.123456789012e-8". The issue is that the program prints an extra space character. Looking at the code, there is no explicit space printed, but the buggy output shows a space before 'e'. This could be due to printing a null character or an extra character from the string. The loop `for(k=sumb+2;k<=strlen(num);k++)` goes up to `<= strlen(num)`, which includes the null terminator at index strlen(num). This causes an extra null character to be printed, which may appear as a space or garbage. The correct condition should be `k < strlen(num)`.
        if((sumb+2)==strlen(num))
        {
            printf("e-%d",sumb);
        }
        else
        {
            printf(".");
            for(k=sumb+2;k<=strlen(num);k++) // @@ Error: The loop condition should be `k < strlen(num)` instead of `k <= strlen(num)`. Using `<=` causes the null terminator at index strlen(num) to be printed, which results in an extra character (often a space or garbage) in the output.
            {
                printf("%c",num[k]);
            }
            printf("e-%d",sumb);    
        }
    }
    else
    {
        printf("%c.",num[0]);
        for(k=1;k<strlen(num);k++)
        {
            if(num[k]!='.')
            {
                printf("%c",num[k]);
            }
        }
        printf("e%d",suma);
    }
    
}