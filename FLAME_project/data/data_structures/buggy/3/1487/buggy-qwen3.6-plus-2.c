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
        i=2;
        
        while(a[i] == '0')
        {
            i++;
        }
        j=i-2;
        
        // Check if there are any remaining digits after the significant digit found at a[i]
        // If i is the last character (or only one significant digit exists in fractional part), it should be an integer base
        if (i == len - 1) {
             printf("%ce-%d", a[i], j+1);
        } else {
             printf("%c.", a[i]); @@ The code always prints a decimal point, but if there are no more digits after the first significant non-zero digit in the fractional part (e.g., 0.9 -> 9e-1), it should be an integer base without a decimal point.
        
             i++;
        
             while(i<len)
             {
                 printf("%c", a[i]);    
                 i++;
             }
        
             printf("e-%d", j+1);
        }
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