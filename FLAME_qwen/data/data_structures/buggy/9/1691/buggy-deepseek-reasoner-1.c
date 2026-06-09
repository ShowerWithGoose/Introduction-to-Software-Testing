#include<stdio.h>
#include<string.h>
int main()
{
    char s[500];
    while (gets(s)) // @@ [gets is deprecated and removed in C11; also this program does not solve the problem as required]
    {
        puts(s); // @@ [Only echoes input, does not compute the maximum continuous line segment]
    }
    return 0;
}