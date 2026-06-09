#include <stdio.h> 
#include<string.h>
int main()
{
    char s[500];
    while(gets(s)!=NULL) // @@ [The program uses gets() which is unsafe and not suitable for the problem; more critically, the entire logic is wrong—it just echoes input lines instead of processing line segments to find the longest continuous chain.]
    {
        puts(s); // @@ [This simply prints each input line as-is, completely ignoring the problem requirements of building chains of connected segments and finding the longest one.]
    }
    return 0;
}