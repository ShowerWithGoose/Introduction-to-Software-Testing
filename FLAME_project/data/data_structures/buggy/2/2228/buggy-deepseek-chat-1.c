#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
    gets(s); // @@ [Error: The program only reads and prints the input without performing any arithmetic calculation. It does not implement the required expression evaluation logic.]
    puts(s); // @@ [Error: This line outputs the raw input string instead of the computed result. The problem requires calculating the expression and outputting the integer result.]
    return 0;
}