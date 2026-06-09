#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); @@ [The program only reads one coefficient and one exponent for the first polynomial, but the problem requires reading all non-zero terms of two polynomials until newline. This incomplete input handling causes incorrect parsing of polynomial data.]
    //gets(c);
    scanf("%d", &b); @@ [Similarly, only one exponent is read, and no input is taken for the second polynomial at all. The program fails to read multiple term pairs for both polynomials as required by the input format.]
    printf("%d %d\n", a, b); @@ [The output is just the first coefficient and exponent read, not the result of polynomial multiplication. This does not implement polynomial multiplication logic and ignores all other terms and the second polynomial.]
    //puts(c);
    return 0;
}