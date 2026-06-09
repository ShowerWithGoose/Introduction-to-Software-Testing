#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char c[100];
    gets(c);   printf("%s",c); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; it can cause buffer overflow. Use 'fgets' instead. Additionally, the problem requires parsing and evaluating an arithmetic expression, but this code only reads and prints the input without any calculation logic.]
    return 0;
}