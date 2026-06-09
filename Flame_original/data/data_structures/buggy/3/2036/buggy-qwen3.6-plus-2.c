#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define eps 1e-8

int main() {
    char s[1000],sum0=1,p[1000],k=0; // @@ sum0 and k should be int, not char; using char for counters and %d format specifier causes undefined behavior
    int i=0;
    gets(s); // @@ gets is unsafe and removed in C11 standard, causing compilation errors in modern environments; use fgets instead
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')
        break;
    }
    if(i==strlen(s))
    printf("%s",s);
    else
    {
        if(s[0]=='0')
        {
            for(i=2;i<strlen(s);i++)
            {
                if(s[i]=='0')
                sum0++; // @@ counts leading zeros but exponent should be -(sum0-1), not -sum0
                else
                {
                    p[k]=s[i];
                    k++;
                }
            }
            printf("%c",p[0]);
            for(i=1;i<strlen(p);i++) // @@ strlen(p) invokes undefined behavior because p is not null-terminated
            {
                if(i==1)
                printf(".%c",p[i]);
                else
                printf("%c",p[i]);
            }
            printf("e-%d",sum0); // @@ exponent calculation is off by one; should be sum0-1
        }
        else
        {
            sum0=0;
            for(i=1;i<strlen(s);i++)
            {
                if(s[i]=='.')
                {
                    for(i;i<strlen(s)-1;i++) // @@ modifying outer loop variable i breaks loop control flow and causes incorrect string shifting
                    {
                        s[i]=s[i+1];
                    }
                    s[i]='\0';
                }
                else
                sum0++;
            }
            printf("%c.",s[0]);
            for(i=1;i<strlen(s);i++)
            {
                printf("%c",s[i]);
            }
                printf("e%d",sum0); // @@ exponent relies on flawed shifting logic; should be sum0-1

        }
    }
    return 0;
}