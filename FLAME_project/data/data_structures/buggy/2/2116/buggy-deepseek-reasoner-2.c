#include<stdio.h>
#include<string.h>
char s[100];
int main()
{
    gets(s);
    printf("%s",s); // @@ This line prints the input string instead of the computed result. The program lacks any expression evaluation logic, so the output is incorrect.
    return 0;
}