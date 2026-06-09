#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define eps 1e-8

int main() {
    char s[1000],sum0=1,p[1000],k=0; // @@ [Variable 'sum0' is initialized to 1, but for numbers like 0.00...x, the exponent calculation logic below is flawed. Also 'p' is not null-terminated.]
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
            for(i=2;i<strlen(s);i++) // @@ [This loop skips all zeros after the decimal point, including significant zeros that are part of the mantissa. It only keeps non-zero digits, which destroys the precision and changes the value. For input 0.00000009123456789012, it skips the first seven 0s, but then incorrectly processes the rest.]
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
            for(i=1;i<strlen(p);i++) // @@ [strlen(p) is undefined behavior because p is not null-terminated. It should be k.]
            {
                if(i==1)
                printf(".%c",p[i]);
                else
                printf("%c",p[i]);
            }
            printf("e-%d",sum0); // @@ [The exponent calculation is incorrect. For 0.0000000912..., the first non-zero digit is at index 9 (0-indexed). The exponent should be -(position of first non-zero digit - 1). The current logic counts zeros but fails to account for the position correctly relative to the decimal point and the first significant digit.]
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