#include <stdio.h> 
#include<string.h>
int main()
{
    char s[500];
    while(gets(s)!=NULL) // @@ This loop reads and prints input lines instead of parsing the number of segments and their coordinates.
    {
        puts(s); // @@ This prints the input line instead of the required output (maximum number of segments and starting point coordinates).
    }
    return 0;
}