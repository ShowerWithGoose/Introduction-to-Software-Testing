#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
    gets(s);
    puts(s); // @@ This line outputs the input string instead of computing the expression result. The program lacks the evaluation logic required by the problem. Should compute and print the result.
    return 0;
}