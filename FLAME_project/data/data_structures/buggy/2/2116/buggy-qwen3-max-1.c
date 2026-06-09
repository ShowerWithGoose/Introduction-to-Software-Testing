#include<stdio.h>
#include<string.h>
char s[100];
int main()
{
    gets(s); // @@ [The program only reads the input and prints it back without performing any arithmetic evaluation, which is the core requirement of the problem. This is a completely incorrect implementation that ignores operator precedence, integer division, and expression parsing.]
    printf("%s",s); // @@ [Instead of outputting the computed result of the arithmetic expression, it just echoes the input string, leading to wrong answer.]
    return 0;
}