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
    gets(s); // @@ gets() is removed in C11 standard and causes compilation errors in modern compilers; use fgets() or scanf() instead.
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')
        {
            if(s[i-1]!='0') // @@ Logical error: checks only the immediate preceding digit, failing for inputs like "10.5" where the number is >= 1. Also unsafe if i=0.
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
                for(j=k;j<strlen(s);j++) // @@ Variable 'k' may be used uninitialized if no non-zero digit is found, causing a compilation error. Also fails to insert a decimal point for mantissas with multiple digits.
                {
                    printf("%c",s[j]);
                }
                printf("e-%d",k-1); // @@ Exponent calculation logic is flawed and does not account for the missing decimal point in the mantissa.
            }
        }
    } // @@ Missing 'break;' statement after processing the decimal point causes the loop to continue unnecessarily.
    return 0;
}