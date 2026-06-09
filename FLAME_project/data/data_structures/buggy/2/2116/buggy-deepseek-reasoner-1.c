#include<stdio.h>
#include<string.h>
char s[100];
int main()
{
    gets(s); // @@ [Error: gets is unsafe and does not evaluate the expression; the program should parse and compute the arithmetic expression, not just read a string.]
    printf("%s",s); // @@ [Error: This only prints the input string, but the requirement is to calculate and output the result of the arithmetic expression.]
    return 0;
}