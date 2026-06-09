#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
    gets(s); // @@ [The program only reads the input and prints it back without parsing or evaluating the arithmetic expression. It completely lacks the logic to compute the result according to operator precedence and integer division requirements.]
    puts(s); // @@ [Instead of outputting the computed result of the arithmetic expression, it just echoes the input string, which is why the output matches the input rather than the expected numeric result like 602.]
    return 0;
}