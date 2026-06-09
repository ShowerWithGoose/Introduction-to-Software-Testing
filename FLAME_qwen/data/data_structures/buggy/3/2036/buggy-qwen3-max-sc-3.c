#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define eps 1e-8

int main() {
    char s[1000],sum0=1,p[1000],k=0;
    int i=0;
    gets(s); // @@ [Use of unsafe function 'gets' which is deprecated and removed in C11; causes compilation error with modern compilers]
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
                sum0++;    
                else
                {
                    p[k]=s[i];
                    k++;
                }
            }    
            printf("%c",p[0]); // @@ [Undefined behavior if input is "0.0" or similar where no non-zero digit exists after decimal, leading to reading uninitialized memory]
            for(i=1;i<strlen(p);i++) // @@ ['strlen(p)' is incorrect because 'p' is not null-terminated; this leads to undefined behavior]
            {
                if(i==1)
                printf(".%c",p[i]);
                else
                printf("%c",p[i]);
            }
            printf("e-%d",sum0); // @@ [Exponent calculation is incorrect; should be based on position of first non-zero digit, not count of leading zeros]
        }    
        else
        {
            sum0=0;
            for(i=1;i<strlen(s);i++)
            {
                if(s[i]=='.')
                {
                    for(i;i<strlen(s)-1;i++)
                    {
                        s[i]=s[i+1];
                    }
                    s[i]='\0';
                }
                else
                sum0++; // @@ [Incorrect exponent calculation: 'sum0' counts digits after the first, but doesn't account for removal of decimal point correctly]
            }
            printf("%c.",s[0]);
            for(i=1;i<strlen(s);i++)
            {
                printf("%c",s[i]);
            }
                printf("e%d",sum0); // @@ [Exponent should be (position of decimal point - 1), not count of remaining digits]
            
        }
    } 
    return 0;
}