#include<stdio.h>
#include<string.h>
char s[100];
int main()
{
    gets(s); // @@ The program simply reads the input and prints it back, instead of parsing and evaluating the arithmetic expression as required.
    printf("%s",s); // @@ The output should be the calculated integer result of the expression, not the original input string.
    return 0;
}