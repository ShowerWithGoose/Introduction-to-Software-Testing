#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char c[100];
    gets(c);   printf("%s",c); // @@ [The program only reads and prints the input without parsing or evaluating the arithmetic expression, completely ignoring the problem requirements.]
    return 0;
}