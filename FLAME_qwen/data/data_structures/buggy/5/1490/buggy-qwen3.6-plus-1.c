#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); // @@ [Logical Error] The input format requires reading multiple coefficient-exponent pairs for the first polynomial, but this only reads a single integer.
    //gets(c);
    scanf("%d", &b); // @@ [Logical Error] This only reads one more integer, completely ignoring the remaining terms of the first polynomial and the entire second polynomial input.
    printf("%d %d\n", a, b); // @@ [Logical Error] The program must compute the product of the two polynomials and output the resulting terms in descending order of exponents, not just print the first two input values.
    //puts(c);
    return 0;
}