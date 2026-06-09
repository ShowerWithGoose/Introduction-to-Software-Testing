#include <stdio.h> 
#include<string.h>
int main()
{
    char s[500];
    while(gets(s)!=NULL) // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. Additionally, the problem requires parsing structured numeric input, not echoing arbitrary lines.]
    {
        puts(s); // @@ [This simply echoes input lines without processing them as line segments, which contradicts the problem's requirement to compute the longest continuous line segment.]
    }
    return 0;
}