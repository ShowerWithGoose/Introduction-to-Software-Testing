#include <stdio.h>
#include <string.h>
int main(void)
{
    char c;
    while ((c=getchar())!=EOF)
        printf("%c",c); // @@ [The program simply echoes input characters without performing polynomial multiplication. It completely ignores the problem requirements and does not parse coefficients/exponents, compute products, combine like terms, or output in descending exponent order.]
}