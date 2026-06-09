#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define eps 1e-8

int main() {
    char s[1000],sum0=1,p[1000],k=0; // @@ [sum0 should be int initialized to 0, not char 1. Also, p is not null-terminated.]
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
                sum0++; // @@ [This counts all zeros, not just leading zeros. Zeros after the first non‑zero digit should be copied to p, not counted.]
                else
                {
                    p[k]=s[i]; // @@ [Only executes for non‑zero digits. After the first non‑zero digit, all subsequent digits (including zeros) must be copied.]
                    k++;
                }
            }    
            printf("%c",p[0]);
            for(i=1;i<strlen(p);i++) // @@ [p is not null‑terminated; strlen(p) is undefined. Should use k instead.]
            {
                if(i==1)
                printf(".%c",p[i]);
                else
                printf("%c",p[i]);
            }
            printf("e-%d",sum0); // @@ [Exponent sum0 is overcounted because it includes non‑leading zeros and starts from 1. Should be based on leading zero count only.]
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