#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); @@ [The program only reads one coefficient and one exponent from the first polynomial, but the problem requires reading all non-zero terms of two polynomials until end of input. This leads to incomplete input parsing.]
    //gets(c);
    scanf("%d", &b); @@ [Similarly, only one exponent is read, and no attempt is made to read the rest of the terms of the first polynomial or any terms of the second polynomial.]
    printf("%d %d\n", a, b); @@ [The output is just the first coefficient and exponent read, not the result of polynomial multiplication. The logic for polynomial multiplication is entirely missing.]
    //puts(c);
    return 0;
}