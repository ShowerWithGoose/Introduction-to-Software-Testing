#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
    scanf("%s",&s);
    int i,j;
    if(s[1]=='.')
    {
        if(s[0]!='0')
        {
            for(i=0;i<strlen(s);i++)
            {
                printf("%c",s[i]);
            }
            printf("e0");    
        }
        else
        {
            for(i=2;i<strlen(s);i++)
            {
                if((s[i]!='0')&&(i!=strlen(s)-1))
                {
                    printf("%c.",s[i]);
                    for(j=i+1;j<strlen(s);j++)
                    {
                        printf("%c",s[j]);
                    }
                    printf("e%d",i-1); // @@ The exponent calculation is incorrect for numbers less than 1. For 0.00...0X, the exponent should be negative. Specifically, if the first non-zero digit is at index i, the exponent is -(i - 1). Here it prints a positive value. It should be printf("e-%d", i - 1); or similar logic to handle the negative sign correctly based on the position. Actually, for 0.0009, i=4 (index of 9). The value is 9 * 10^-4? No. 0.0009 = 9 * 10^-4. Wait. 0.000912. Index 0='0', 1='.', 2='0', 3='0', 4='0', 5='9'. i=5. Exponent should be -4? 9.12e-4. Formula: -(i - 2). Let's check. i=2 (first digit after dot). If s[2]!='0', e.g. 0.912. i=2. Output 9.12e-1? 0.912 = 9.12 * 10^-1. Correct. So exponent is -(i - 2) = 2 - i. The code prints i - 1. For i=2, prints 1. Wrong sign and value. For i=5 (0.0009), prints 4. Should be -4. So it should be printf("e%d", 2 - i);
                    break;
                }
                else if(i==strlen(s)-1)
                {
                    printf("%ce-%d",s[i],i-1); // @@ Similar error here. If the last digit is the first non-zero one (e.g. 0.00...09 at end), the exponent logic is flawed. It should also follow the 2 - i rule for the exponent value and ensure the sign is correct. However, the format string hardcodes '-', which might be correct for value, but the magnitude i-1 is likely wrong. It should be printf("%ce%d", s[i], 2 - i); because 2-i will be negative.
                }
            }
        }
    }
    else
    {
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='.')
            {
                printf("%c.",s[0]);
                for(j=1;j<=i-1;j++)
                {
                    printf("%c",s[j]);
                }
                for(j=i+1;j<strlen(s);j++)
                {
                    printf("%c",s[j]);
                }
                printf("e%d",i-1);
                break;
            }
        }
    }
    return 0;
 }