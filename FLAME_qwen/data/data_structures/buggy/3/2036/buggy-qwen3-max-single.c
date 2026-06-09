#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define eps 1e-8

int main() {
    char s[1000],sum0=1,p[1000],k=0;
    int i=0;
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers.]
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
            printf("%c",p[0]); // @@ [If all digits after the decimal point are zero (which shouldn't happen per problem constraints, but code doesn't guarantee non-empty p), p[0] may be uninitialized, leading to undefined behavior. Also, 'sum0' counts leading zeros incorrectly—it should count positions, not just zeros.]
            for(i=1;i<strlen(p);i++) // @@ [strlen(p) is incorrect because 'p' is not null-terminated; this leads to undefined behavior.]
            {
                if(i==1)
                printf(".%c",p[i]);
                else
                printf("%c",p[i]);
            }
            printf("e-%d",sum0); // @@ ['sum0' was initialized to 1 and incremented for each leading zero, but exponent should be (position of first non-zero digit after decimal) which is (number of leading zeros + 1), so logic is off by one.]
        }    
        else
        {
            sum0=0;
            for(i=1;i<strlen(s);i++)
            {
                if(s[i]=='.')
                {
                    for(i;i<strlen(s)-1;i++) // @@ [Modifying string in-place while iterating causes issues: after shifting, the loop condition uses updated 'i' and strlen(s) changes, leading to incorrect processing or missed characters. Also, 'sum0' is intended to count digits before decimal but is misused.]
                    {
                        s[i]=s[i+1];
                    }
                    s[i]='\0';
                }
                else
                sum0++; // @@ ['sum0' is counting non-decimal digits after the first, but includes digits after the decimal point if '.' hasn't been encountered yet—logic is flawed.]
            }
            printf("%c.",s[0]);
            for(i=1;i<strlen(s);i++)
            {
                printf("%c",s[i]);
            }
                printf("e%d",sum0); // @@ [Exponent should be (original position of decimal point - 1). 'sum0' does not correctly represent this value due to flawed counting and string modification.]
            
        }
    } 
    return 0;
}