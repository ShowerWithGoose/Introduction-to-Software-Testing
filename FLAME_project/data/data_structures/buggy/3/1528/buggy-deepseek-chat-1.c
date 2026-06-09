#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    char str[1000]={},copy[1000]={};
    int i,k=0,j=0;
    gets(str);
    if(str[0]!='0')
    {
        for(i=0;i<strlen(str);i++)
        {
            if(str[i]!='.')
            k++;
            else
            break;
        }
        if(strlen(str)>1)
        {
        printf("%c",str[0]);
        printf(".");
        for(i=1;i<strlen(str);i++)
        {
            if(str[i]!='.')
            printf("%c",str[i]);
        }
        printf("e");
        printf("%d",k-1);
        }
        else
        {
            printf("%c",str[0]);
            printf("e0");
        }
        
    }
    else
    {
        for(i=0;i<strlen(str);i++)
        {
            if(str[i]=='0'||str[i]=='.')
            k++;
            else
            break;
        }
        for(i=0;i<strlen(str);i++)
        {
             if(str[i]!='0'&&str[i]!='.')
             {
             copy[j++]=str[i];
             }
        }
        if(strlen(copy)==1)
        {
        printf("%c",copy[0]);
        printf("e-%d",k-1);
        }
        else
        {
            printf("%c",copy[0]);
            printf(".");
            for(i=1;i<strlen(copy);i++)
            {
                printf("%c",copy[i]);
            }
            printf("e-%d",k-1); // @@ The exponent calculation is incorrect. For input "0.00000009123456789012", k counts 9 zeros and the decimal point, so k=9, but the correct exponent should be -8 (since the first non-zero digit is at position 9 after the decimal point). The exponent should be -(k-1) = -8, but the code outputs e-8, which is correct for this case. However, the issue is that the copy array loses trailing zeros because it only copies non-zero digits. The input has "09123456789012" but the copy becomes "912345678912" (missing the trailing '0' after '1' because the loop copies all non-zero and non-dot characters, but the original string has '0' at the end which is significant). The copy array should preserve all digits after the first non-zero digit, including zeros. The error is in the second for loop where it skips '0' characters, causing loss of significant zeros.
        }

    }
}