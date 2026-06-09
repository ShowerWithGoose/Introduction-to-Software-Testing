#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main()
{
    char a[500];
    int i=0, j=0, len;
    
    gets(a); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the main logical error is elsewhere.]
    len = strlen(a);
    
    if(a[i] == '0')//零点几 
    {
        i=2;
        
        while(a[i] == '0')
        {
            i++;
        }
        j=i-2;
        
        printf("%c.", a[i]); // @@ [This always prints a decimal point even when there are no digits after, leading to output like "9." instead of "9". For input "0.9", it prints "9." which is incorrect per problem requirements.]
        
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
        printf("%c.", a[i]); // @@ [Similarly, this always prints a decimal point even if the number should be represented as an integer base (only one significant digit). According to the problem, if the base is an integer (i.e., only one digit), it should not have a decimal point. So for numbers like "5.0" (though not in test case), or more relevantly, after normalization, if only one digit remains, no decimal point should be printed. However, in this branch, it's used for numbers like "123.45", which becomes "1.2345e2", so decimal is needed. But the real issue is in the first branch.]
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