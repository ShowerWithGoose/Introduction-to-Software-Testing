#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
    gets(s);
    puts(s); // @@ This line only prints the input expression, but does not compute or output the result. The program should parse and evaluate the arithmetic expression, then output the integer result (e.g., 602 for the given test case).
    return 0;
}