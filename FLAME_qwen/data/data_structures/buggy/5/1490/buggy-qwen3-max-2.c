#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); @@ [The program only reads one coefficient and one exponent from the first polynomial, but the problem requires reading all non-zero terms of two polynomials until end of input. This incomplete input handling causes incorrect parsing of polynomial data.]
    //gets(c);
    scanf("%d", &b); @@ [Similarly, only one exponent is read for the first term, and no input is read for the second polynomial at all. The program does not handle multiple terms per polynomial as required by the problem.]
    printf("%d %d\n", a, b); @@ [The output simply prints the first coefficient and exponent read, instead of computing and printing the product of two polynomials in descending order of exponents. This completely ignores the multiplication logic and proper output format.]
    //puts(c);
    return 0;
}