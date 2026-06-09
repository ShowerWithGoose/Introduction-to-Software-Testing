#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); @@ [The program reads only one coefficient and one exponent from the first polynomial, but the problem requires reading all non-zero terms of two polynomials until newline/end-of-input. This incomplete input handling causes incorrect parsing and multiplication logic.]
    //gets(c);
    scanf("%d", &b); @@ [Similarly, only one exponent is read for the first term, and no input is read for the second polynomial at all. The program does not handle multiple terms per polynomial as required.]
    printf("%d %d\n", a, b); @@ [The output simply prints the first coefficient and exponent read, which does not represent the product of two polynomials. The multiplication logic is entirely missing.]
    //puts(c);
    return 0;
}