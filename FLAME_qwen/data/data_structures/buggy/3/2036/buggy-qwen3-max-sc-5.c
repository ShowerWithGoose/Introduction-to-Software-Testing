#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define eps 1e-8

int main() {
    char s[1000],sum0=1,p[1000],k=0; // @@ [sum0 is declared as char but used as integer counter; should be int]
    int i=0;
    gets(s); // @@ [gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
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
            printf("%c",p[0]); // @@ [if all digits after decimal are zero, p[0] is uninitialized → undefined behavior]
            for(i=1;i<strlen(p);i++) // @@ [strlen(p) is incorrect because p is not null-terminated]
            {
                if(i==1)
                printf(".%c",p[i]);
                else
                printf("%c",p[i]);
            }
            printf("e-%d",sum0); // @@ [sum0 counts leading zeros including the one before first non-zero, but exponent should be -(number of leading zeros + 1)]
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
                sum0++;
            }
            printf("%c.",s[0]);
            for(i=1;i<strlen(s);i++)
            {
                printf("%c",s[i]);
            }
                printf("e%d",sum0); // @@ [sum0 counts digits after first digit excluding decimal, but exponent should be (position of decimal - 1), not total digits after first]
            
        }
    } 
    return 0;
}