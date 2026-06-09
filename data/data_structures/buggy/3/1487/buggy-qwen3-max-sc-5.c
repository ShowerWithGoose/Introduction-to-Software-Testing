#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main()
{
    char a[500];
    int i=0, j=0, len;
    
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use 'fgets' instead.]
    
    len = strlen(a);
    
    if(a[i] == '0')//零点几 
    {
        i=2;
        
        while(a[i] == '0')
        {
            i++;
        }
        j=i-2;
        
        printf("%c.", a[i]);
        
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