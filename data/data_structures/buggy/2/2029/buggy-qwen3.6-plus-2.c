#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char c[100];
    gets(c);   printf("%s",c); // @@ gets() is deprecated and removed in the C11 standard, which causes a compilation error in modern environments; use fgets() instead. Furthermore, the program merely echoes the input string and completely lacks the parsing and evaluation logic required to solve the arithmetic expression problem.
    return 0;
}