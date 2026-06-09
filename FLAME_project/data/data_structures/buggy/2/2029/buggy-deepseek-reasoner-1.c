#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char c[100];
    gets(c);   printf("%s",c); // @@ The program only prints the input, but it should evaluate the arithmetic expression and output the integer result.
    return 0;
}