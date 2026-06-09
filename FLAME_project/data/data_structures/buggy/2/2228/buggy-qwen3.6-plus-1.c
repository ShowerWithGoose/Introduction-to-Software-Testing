#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
    gets(s); // @@ The program only reads the input and prints it back using puts(s), instead of parsing and evaluating the arithmetic expression as required. It fails to implement any logic for calculation.
    puts(s); // @@ This line outputs the raw input string instead of the calculated integer result.
    return 0;
}