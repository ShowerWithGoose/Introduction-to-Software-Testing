#include<stdio.h>
#include<string.h>
int main()
{
    char s[500];
    while (gets(s)) // @@ [The program completely ignores the problem requirements and instead just echoes input lines. It does not read or process line segments, build connections, or compute the longest continuous line segment. The logic is entirely missing.]
    {
        puts(s); // @@ [This simply prints back each input line, which explains why the buggy output matches the input. There is no attempt to parse coordinates, link segments, or find the maximum chain.]
    }
    return 0;
}