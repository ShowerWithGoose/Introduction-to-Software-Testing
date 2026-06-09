#include<stdio.h>
#include<string.h>
int main()
{
    char s[500];
    while (gets(s)) // @@ The program logic is completely incorrect. It simply echoes input lines instead of solving the line segment connectivity problem described. It fails to parse integers, build the graph/chain of segments, or calculate the longest continuous segment.
    {
        puts(s); // @@ This line outputs the raw input string, which does not match the required output format (count and starting coordinates).
    }
    return 0;
}