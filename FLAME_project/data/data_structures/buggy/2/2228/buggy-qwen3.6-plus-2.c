#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
    gets(s); // @@ The program only reads the input and prints it back, failing to parse or evaluate the arithmetic expression as required.
    puts(s); // @@ This line outputs the raw input string instead of the calculated integer result.
    return 0;
}