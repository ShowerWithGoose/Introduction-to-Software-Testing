#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define eps 1e-8

int main() {
    char s[1000],sum0=1,p[1000],k=0; // @@ [Variable 'sum0' is initialized to 1, but for numbers like 0.00...X, the exponent calculation logic below is flawed. Also 'p' is not null-terminated.]
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
            // @@ [Logic Error: The loop above skips ALL zeros after the decimal point until the first non-zero digit. 
            // However, scientific notation requires preserving ALL significant digits. 
            // For input 0.00000009123456789012:
            // The code finds the first non-zero '9'. It sets sum0 to count the zeros before it (7 zeros -> sum0 becomes 8? No, sum0 starts at 1. i=2 to 8 are '0'. sum0 increments 7 times. sum0 = 1+7=8).
            // Then it copies '9', '1', '2'... into p.
            // Wait, let's trace carefully.
            // Input: 0.00000009123456789012
            // i=2 ('0'): sum0++ (2)
            // i=3 ('0'): sum0++ (3)
            // ...
            // i=8 ('0'): sum0++ (8)
            // i=9 ('9'): else branch. p[0]='9', k=1.
            // i=10 ('1'): else branch. p[1]='1', k=2.
            // ...
            // The problem is that `sum0` is calculating the position of the first significant digit relative to the decimal point incorrectly for the exponent.
            // For 0.00000009..., the first sig digit is at 10^-8 position (9 * 10^-8). So exponent should be -8.
            // sum0 ends up being 8. So it prints e-8. This part seems correct for the exponent value.
            
            // HOWEVER, look at the output construction:
            // printf("%c",p[0]); -> prints '9'
            // for(i=1;i<strlen(p);i++) ...
            // `p` is NOT null-terminated. `strlen(p)` will read garbage memory or crash, or return incorrect length.
            // This leads to undefined behavior and likely wrong output content (trailing garbage or missing digits).
            
            // Let's look at the specific failure:
            // Buggy Output: 9.12345678912e-9
            // Expected: 9.123456789012e-8
            
            // The buggy output has exponent -9. My trace said sum0=8. Why -9?
            // Ah, `sum0` is initialized to 1.
            // Indices of '0' after decimal: s[2] to s[8]. That is 7 zeros.
            // Loop i=2 to 8: sum0 increments 7 times. 1 + 7 = 8.
            // So it should print e-8.
            // Why did it print e-9?
            // Maybe the input string handling or `strlen` issues.
            
            // But the bigger issue is `p` not being null terminated.
            // And the loop `for(i=1;i<strlen(p);i++)` relies on `p` being a valid string.
            
            // Let's look at the "Buggy Output" again: 9.12345678912e-9
            // It seems digits are truncated or changed. "9012" became "912"? And exponent is off.
            
            // Actually, there is a logical error in how `sum0` is calculated vs what is required.
            // If the number is 0.09, exponent is -1.
            // s[2] is '9'. Loop doesn't run for zeros. sum0=1. Prints e-1. Correct.
            // If number is 0.009, exponent is -2.
            // s[2]='0', sum0=2. s[3]='9'. Prints e-2. Correct.
            
            // So the exponent logic for `sum0` is actually correct IF `sum0` represents the number of places the decimal moved.
            // 0.0000000912...
            // Decimal moves 8 places right to get 9.12...
            // Exponent is -8.
            
            // Why does the buggy output say -9?
            // Perhaps `gets` or string length includes newline? No, `gets` removes newline.
            
            // Let's look at the `else` block (numbers >= 1).
            // The main error reported is Wrong Answer.
            
            // Critical Error 1: `p` is not null-terminated.
            p[k] = '\0'; // @@ [The array p is used as a string in strlen(p) and printf, but it is never null-terminated, causing undefined behavior and incorrect output length/content.]
            
            printf("%c",p[0]);
            for(i=1;i<strlen(p);i++)
            {
                if(i==1)
                printf(".%c",p[i]);
                else
                printf("%c",p[i]);
            }
            printf("e-%d",sum0);
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