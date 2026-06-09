#include<stdio.h>
#include<string.h>
int main()
{
    char s[500];
    while (gets(s)) // @@ [gets() is removed in the C11 standard, causing a compilation error; additionally, the program merely echoes input instead of parsing coordinates and implementing the algorithm to find the longest continuous line segment]
    {
        puts(s);
    }
    return 0;
}