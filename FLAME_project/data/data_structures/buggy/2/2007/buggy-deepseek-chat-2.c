#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char a[10000];
int main()
{
    gets(a); // @@ This line reads the entire expression including spaces, but the program only prints it without evaluating the arithmetic expression. The problem requires calculating the result of the expression, not just printing it.
    puts(a); // @@ This line prints the input string, but the expected output is the calculated integer result (e.g., 602), not the original expression.
    return 0;
}