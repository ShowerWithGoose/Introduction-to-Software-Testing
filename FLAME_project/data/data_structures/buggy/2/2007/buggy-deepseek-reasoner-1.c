#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char a[10000];
int main()
{
    gets(a);
    puts(a); // @@ [The program outputs the original expression instead of computing the result. It should evaluate the arithmetic expression and print the integer result.]
    return 0;
}