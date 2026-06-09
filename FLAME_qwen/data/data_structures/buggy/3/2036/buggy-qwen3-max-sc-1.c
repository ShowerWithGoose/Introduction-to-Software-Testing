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
            printf("%c",p[0]); // @@ [if input is "0.0", p[0] is uninitialized, leading to undefined behavior]
            for(i=1;i<strlen(p);i++) // @@ [strlen(p) is incorrect because p is not null-terminated]
            {
                if(i==1)
                printf(".%c",p[i]);
                else
                printf("%c",p[i]);
            }
            printf("e-%d",sum0); // @@ [sum0 counts leading zeros incorrectly; e.g., "0.001" should give exponent -3, but sum0 starts at 1 and increments per zero, yielding -2]
        }    
        else
        {
            sum0=0;
            for(i=1;i<strlen(s);i++)
            {
                if(s[i]=='.')
                {
                    for(i;i<strlen(s)-1;i++) // @@ [modifying string while iterating causes logic errors and potential out-of-bounds access]
                    {
                        s[i]=s[i+1];
                    }
                    s[i]='\0';
                }
                else
                sum0++; // @@ [sum0 counts digits after first, but includes digits after decimal; exponent should be (position of decimal - 1), not total digits after first]
            }
            printf("%c.",s[0]);
            for(i=1;i<strlen(s);i++)
            {
                printf("%c",s[i]);
            }
                printf("e%d",sum0); // @@ [exponent calculation is wrong; e.g., "123.45" should be "1.2345e2", but sum0 becomes 4 (digits '2','3','4','5'), outputting e4]
            
        }
    } 
    return 0;
}