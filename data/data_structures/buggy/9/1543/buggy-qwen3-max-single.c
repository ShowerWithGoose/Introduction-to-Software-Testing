#include <stdio.h> 
#include<string.h>
int main()
{
    char s[500];
    while(gets(s)!=NULL) // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. Additionally, the problem requires parsing integer coordinates and processing line segments, but this code just echoes input lines without any logic to solve the problem.]
    {
        puts(s); // @@ [This merely prints the input line as-is, which does not implement the required logic to find the longest continuous line segment. The program completely ignores the problem specification.]
    }
    return 0;
}