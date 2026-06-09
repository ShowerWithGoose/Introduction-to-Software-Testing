#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); @@ [The program only reads one coefficient and one exponent for the first polynomial, but the problem requires reading all non-zero terms of two polynomials until end of input. This leads to incomplete input parsing.]
    //gets(c);
    scanf("%d", &b); @@ [Similarly, only one exponent is read, and no input is read for the second polynomial at all. The program does not handle multiple terms per polynomial as required.]
    printf("%d %d\n", a, b); @@ [The output is just the first coefficient and exponent read, not the result of polynomial multiplication. This completely ignores the problem requirement to multiply two polynomials and output all resulting terms in descending order of exponents.]
    //puts(c);
    return 0;
}