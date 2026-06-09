#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main()
{
    char a[500];
    int i=0, j=0, len;
    
    gets(a); // @@ gets() is removed in C11 standard and causes compilation errors in modern environments; use fgets() or scanf() instead.
    len = strlen(a);
    
    if(a[i] == '0')//零点几 
    {
        i=2;
        
        while(a[i] == '0')
        {
            i++;
        }
        j=i-2;
        
        printf("%c.", a[i]); // @@ Unconditionally prints a decimal point, leading to invalid format like "1.e-1" when no fractional digits remain. Should conditionally print "." only if more digits follow.
        
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
        printf("%c.", a[i]); // @@ Same logical error: unconditionally prints a decimal point, which may produce invalid output if no digits follow the first significant digit.
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