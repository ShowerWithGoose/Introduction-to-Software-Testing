#include<stdio.h>
#include<string.h>
int main()
{
    char s[500];
    while (gets(s)) // @@ The program logic is completely incorrect for the problem description. It simply echoes input lines instead of processing line segments to find the longest continuous chain.
    {
        puts(s); // @@ This outputs the input line instead of calculating and printing the maximum number of segments and the starting coordinates.
    }
    return 0;
}