#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
int main()
{
    char s[105];
    int i,j,k;
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')
        {
            if(s[i-1]!='0')
            {
                printf("%c.",s[0]);
                for(j=1;j<i;j++)
                {
                    printf("%c",s[j]);
                }
                for(j=i+1;j<strlen(s);j++)
                {
                    printf("%c",s[j]);
                }
                printf("e%d",i-1);
            }
            else
            {
                for(j=2;j<strlen(s);j++)
                {
                    if(s[j]!='0')
                    {
                        k=j;
                        break;
                    }
                }
                for(j=k;j<strlen(s);j++)
                {
                    printf("%c",s[j]);
                }
                printf("e-%d",k-1); // @@ The exponent calculation is incorrect. For input "0.00000009123456789012", k is the index of the first non-zero digit after the decimal point (which is '9' at index 9), but the exponent should be -(k-1) = -8, which matches the expected output. However, the code prints all digits from k to end without inserting a decimal point after the first significant digit, and it does not handle trailing zeros. The expected output is "9.123456789012e-8", but the buggy output is "9123456789012e-8", missing the decimal point after the first digit.
            }
        }
    }
    return 0;
}