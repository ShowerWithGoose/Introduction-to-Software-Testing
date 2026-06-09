#include<stdio.h>
#include<string.h>
char s[100];
int main()
{
    gets(s); // @@ The program simply reads the input and prints it back, instead of parsing and evaluating the arithmetic expression as required.
    printf("%s",s); // @@ The output is the raw input string, not the calculated integer result.
    return 0;
}