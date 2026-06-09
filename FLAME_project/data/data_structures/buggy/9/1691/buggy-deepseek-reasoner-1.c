#include<stdio.h>
#include<string.h>
int main()
{
    char s[500]; // @@ [Buffer size may be insufficient for large input, but main error is that the program does not implement the required algorithm]
    while (gets(s)) // @@ [Error: reads lines until EOF, does not process the first line as number of segments, and does not parse coordinates to build line segments. This does not solve the problem.]
    {
        puts(s); // @@ [Error: outputs the raw input line instead of computing the maximum number of continuous segments and the starting point coordinates. Should output "2 12 12" for the given test case.]
    }
    return 0;
}