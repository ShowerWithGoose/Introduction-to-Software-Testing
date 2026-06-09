#include <stdio.h> 
#include<string.h>
int main()
{
    char s[500];
    while(gets(s)!=NULL) // @@ gets() is deprecated and removed in C11 standard, causing compilation error. Use fgets() instead.
    {
        puts(s);
    }
    return 0;
}