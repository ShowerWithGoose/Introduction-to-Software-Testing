#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
    gets(s);
    puts(s); // @@ [The program prints the input string instead of evaluating the arithmetic expression. It does not implement the required calculation logic, resulting in wrong output.]
    return 0;
}