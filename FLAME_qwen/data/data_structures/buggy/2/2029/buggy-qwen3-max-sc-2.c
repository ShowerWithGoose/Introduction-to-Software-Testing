#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char c[100];
    gets(c);   printf("%s",c); // @@ [The function `gets` is unsafe and has been removed from the C standard library since C11. It can cause buffer overflow vulnerabilities. Additionally, the problem requires parsing an arithmetic expression ending with '=', but this code just reads a line and prints it without any calculation.]
    return 0;
}