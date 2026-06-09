#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define eps 1e-8

int main() {
    char s[1000],sum0=1,p[1000],k=0;
    int i=0;
    gets(s);
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
            printf("%c",p[0]);
            for(i=1;i<strlen(p);i++)
            {
                if(i==1)
                printf(".%c",p[i]);
                else
                printf("%c",p[i]);
            }
            printf("e-%d",sum0); // @@ [Error: The exponent calculation is incorrect. For input "0.00000009123456789012", sum0 counts the zeros after the decimal point (7 zeros) but the exponent should be -8 because the first non-zero digit '9' is at the 8th position after the decimal point. The code should count the total number of zeros including the first zero after the decimal point, not just the consecutive zeros before the first non-zero digit.]
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
                printf("e%d",sum0);
            
        }
    } 
    return 0;
}