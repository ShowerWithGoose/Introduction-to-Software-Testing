#include <stdio.h> 
#include<string.h>
int main()
{
    char s[500];
    while(gets(s)!=NULL) // @@ This line is incorrect: the program should read an integer n first and then parse coordinates; echoing input does not solve the problem.
    {
        puts(s); // @@ This line is incorrect: outputting the input lines does not produce the required output (maximum number of segments and starting point).
    }
    return 0;
}