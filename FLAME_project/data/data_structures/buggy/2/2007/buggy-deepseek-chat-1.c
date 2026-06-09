#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char a[10000];
int main()
{
    gets(a); // @@ This line reads the entire expression including spaces, but the program only outputs the input without evaluating the arithmetic expression. The problem requires calculating the result of the expression, not just printing it.
    puts(a); // @@ This line outputs the input string as-is, which does not compute the arithmetic result. The expected output is the calculated integer value (e.g., 602), not the original expression.
    return 0;
}