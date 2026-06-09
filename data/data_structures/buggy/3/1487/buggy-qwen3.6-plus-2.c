#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main()
{
    char a[500];
    int i=0, j=0, len;
    
    gets(a); // @@ `gets` is removed in the C11 standard and causes compilation errors on modern compilers; use `fgets(a, sizeof(a), stdin)` instead.
    len = strlen(a);
    
    if(a[i] == '0')//零点几 
    {
        i=2;
        
        while(a[i] == '0')
        {
            i++;
        }
        j=i-2;
        
        printf("%c.", a[i]); // @@ Unconditionally prints a decimal point, but scientific notation requires an integer format (no decimal point) when there are no fractional digits after the first significant digit (e.g., 0.001 should output 1e-3, not 1.e-3).
        
        i++;
        
        while(i<len)
        {
            printf("%c", a[i]);    
            i++;
        }
        
        printf("e-%d", j+1);
    }
    else if(a[i] != '0')//几点几 
    {
        printf("%c.", a[i]);
        i=1;
         
        while(a[i] != '.')
        {
            printf("%c", a[i]);
            i++;
        }
        j=i-1;
        
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