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
            if(s[i-1]!='0') // @@ [Logical error: Checks the digit immediately before the decimal point instead of the first digit s[0]. This incorrectly classifies valid numbers like "10.5" as small numbers. Should be if(s[0] != '0').]
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
                for(j=k;j<strlen(s);j++) // @@ [Logical error: Prints all significant digits consecutively without inserting a decimal point after the first one. For inputs like "0.123", it outputs "123e-1" instead of the correct "1.23e-1".]
                {
                    printf("%c",s[j]);
                }
                printf("e-%d",k-1); // @@ [Logical error: While the exponent value is mathematically correct, the missing decimal point in the base formatting above violates the output specification. It also fails to handle the single-significant-digit case where the base should be an integer without a decimal point.]
            }
        }
    }
    return 0;
}