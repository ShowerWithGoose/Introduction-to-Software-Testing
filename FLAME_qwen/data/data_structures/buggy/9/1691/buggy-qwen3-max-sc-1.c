#include<stdio.h>
#include<string.h>
int main()
{
    char s[500];
    while (gets(s)) // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. Additionally, the problem requires parsing structured input of line segments, but this code just echoes input lines without processing them according to the problem specification.]
    {
        puts(s);
    }
    return 0;
}