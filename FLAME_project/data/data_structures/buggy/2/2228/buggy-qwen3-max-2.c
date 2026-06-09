#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
    gets(s); // @@ [The program only reads the input and prints it back without performing any arithmetic calculation, which is required by the problem.]
    puts(s); // @@ [Instead of outputting the result of evaluating the arithmetic expression, it just echoes the input string.]
    return 0;
}