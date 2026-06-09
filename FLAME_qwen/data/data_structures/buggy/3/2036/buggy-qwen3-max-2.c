#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define eps 1e-8

int main() {
    char s[1000],sum0=1,p[1000],k=0;
    int i=0;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers]
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
            printf("%c",p[0]); // @@ [If all digits after decimal are zero, p[0] is uninitialized, leading to undefined behavior]
            for(i=1;i<strlen(p);i++) // @@ ['strlen(p)' is incorrect because 'p' is not null-terminated; this leads to undefined behavior]
            {
                if(i==1)
                printf(".%c",p[i]);
                else
                printf("%c",p[i]);
            }
            printf("e-%d",sum0); // @@ [Exponent calculation is wrong: 'sum0' counts leading zeros but should be (position of first non-zero digit - 1)]
        }    
        else
        {
            sum0=0;
            for(i=1;i<strlen(s);i++)
            {
                if(s[i]=='.')
                {
                    for(i;i<strlen(s)-1;i++) // @@ [Modifying string while iterating and using 'i' as loop variable inside nested loop causes logic errors and potential out-of-bounds access]
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
                printf("e%d",sum0); // @@ [Exponent is incorrectly calculated as count of digits after first, instead of (original decimal position - 1)]
            
        }
    } 
    return 0;
}