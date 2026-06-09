#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char c[100];
    gets(c);   printf("%s",c); // @@ [The program only reads and prints the input without parsing or evaluating the arithmetic expression. It completely ignores the problem requirements to compute the result of the expression with proper operator precedence and integer division.]
    return 0;
}