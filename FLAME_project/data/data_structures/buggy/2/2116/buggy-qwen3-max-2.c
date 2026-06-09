#include<stdio.h>
#include<string.h>
char s[100];
int main()
{
    gets(s); // @@ [Using `gets` is unsafe and deprecated; more critically, the program merely prints the input instead of evaluating the arithmetic expression as required. The entire logic for parsing and computing the expression is missing.]
    printf("%s",s); // @@ [This outputs the raw input string instead of the computed result of the arithmetic expression. According to the problem, it should output the integer result (e.g., 602 for the given test case), not the expression itself.]
    return 0;
}