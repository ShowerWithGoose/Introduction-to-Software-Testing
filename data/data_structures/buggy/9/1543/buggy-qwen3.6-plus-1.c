#include <stdio.h> 
#include<string.h>
int main()
{
    char s[500];
    while(gets(s)!=NULL) // @@ gets() has been removed from the C standard library since C11, causing a compilation error in modern compilers; additionally, the program merely echoes input instead of implementing the required logic to find continuous line segments.
    {
        puts(s);
    }
    return 0;
}