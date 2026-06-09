#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define eps 1e-8

int main() {
    char s[1000],sum0=1,p[1000],k=0; // @@ sum0 and k should be int, not char. Using char for counters causes overflow and incorrect results.
    int i=0;
    gets(s); // @@ gets is dangerous and deprecated; may cause buffer overflow.
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
                sum0++; // @@ sum0 is char, incrementing may cause overflow; should be int.
                else
                {
                    p[k]=s[i]; // @@ p array entries set but no null terminator.
                    k++; // @@ k is char, may overflow.
                }
            }    
            printf("%c",p[0]);
            for(i=1;i<strlen(p);i++) // @@ p is not null-terminated, strlen(p) invokes undefined behavior.
            {
                if(i==1)
                printf(".%c",p[i]);
                else
                printf("%c",p[i]);
            }
            printf("e-%d",sum0); // @@ sum0 is char, but %d expects int; also exponent calculation is incorrect for numbers with zeros after first non-zero.
        }    
        else
        {
            sum0=0; // @@ sum0 is char, assignment to 0 is okay but limited.
            for(i=1;i<strlen(s);i++)
            {
                if(s[i]=='.')
                {
                    for(i;i<strlen(s)-1;i++) // @@ modifying loop variable i inside nested loop is confusing and fragile.
                    {
                        s[i]=s[i+1];
                    }
                    s[i]='\0';
                }
                else
                sum0++; // @@ sum0 counts digits after decimal point if removal fails; logic is error-prone.
            }
            printf("%c.",s[0]);
            for(i=1;i<strlen(s);i++)
            {
                printf("%c",s[i]);
            }
                printf("e%d",sum0); // @@ sum0 is char, printed as int; exponent may be correct for some cases but still uses char type.
            
        }
    } 
    return 0;
}