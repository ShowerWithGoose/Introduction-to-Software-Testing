#include<stdio.h>
#include<string.h> // @@ This include is unnecessary and not used correctly.
int main()
{
    char s[500]; // @@ The problem requires reading integers and processing segments, not strings.
    while (gets(s)) // @@ gets() is unsafe and reading strings is not the correct approach; should read integer n and segment coordinates.
    {
        puts(s); // @@ This simply echoes input, which is not what the problem asks.
    }
    return 0;
}