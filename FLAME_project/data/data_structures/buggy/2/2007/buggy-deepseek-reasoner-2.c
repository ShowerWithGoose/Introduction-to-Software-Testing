#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char a[10000];
int main()
{
    gets(a);
    puts(a); // @@ This line incorrectly outputs the raw input instead of the computed result. The program must parse and evaluate the arithmetic expression to produce the correct integer output.
    return 0;
}