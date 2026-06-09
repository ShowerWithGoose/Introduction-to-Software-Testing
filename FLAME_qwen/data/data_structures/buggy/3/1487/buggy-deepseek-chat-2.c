#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main()
{
    char a[500];
    int i=0, j=0, len;
    
    gets(a);
    len = strlen(a);
    
    if(a[i] == '0')//零点几 
    {
        i=2; // @@ Error: Assumes input always has format "0.xxx", but input could be "0" alone or "0.0" without trailing zeros. Should handle general case by skipping leading zeros and the decimal point.
        
        while(a[i] == '0')
        {
            i++;
        }
        j=i-2; // @@ Error: j is used to calculate exponent but logic is incorrect. For input like "0.001", i starts at 2, then increments to 4 (for '1'), j=2, exponent should be -3, but j+1=3, which is wrong. Also fails for inputs like "0.0" (no non-zero digit).
        
        printf("%c.", a[i]); // @@ Error: If input is "0.0", a[i] will be '\0' (end of string), causing undefined behavior.
        
        i++;
        
        while(i<len)
        {
            printf("%c", a[i]);    
            i++;
        }
        
        printf("e-%d", j+1); // @@ Error: Exponent calculation is incorrect. For "0.001", should be e-3, but outputs e-3 by coincidence? Actually j=2, j+1=3, correct for this case, but fails for "0.01" (j=1, j+1=2, correct) and "0.1" (j=0, j+1=1, correct). However, for "0.0001", i starts at 2, while loop skips three zeros, i=5, j=3, j+1=4, correct. But the logic is fragile and fails for edge cases like "0.0" or "0".
    }
    else if(a[i] != '0')//几点几 
    {
        printf("%c.", a[i]); // @@ Error: Assumes first character is non-zero and there is a decimal point later. For integer input like "123", there is no decimal point, causing the while loop to go out of bounds.
        i=1;
         
        while(a[i] != '.')
        {
            printf("%c", a[i]);
            i++;
        }
        j=i-1; // @@ Error: j is the number of digits before decimal point minus 1, but for input like "12.34", j=1, exponent should be 1, correct. However, for "1.23", j=0, exponent should be 0, correct. But fails for inputs without decimal point.
        
        i++;
        
        while(i<len)
        {
            printf("%c", a[i]);    
            i++;
        }
        printf("e%d", j);
    }
    return 0;
}