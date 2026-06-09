#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); @@ [The program only reads one coefficient and one exponent for the first polynomial, but the problem requires reading multiple terms until the end of input. This causes incomplete input parsing.]
    //gets(c);
    scanf("%d", &b); @@ [Similarly, this only reads one more integer, assuming exactly two integers total, which is insufficient for polynomials with more than one term.]
    printf("%d %d\n", a, b); @@ [The output logic simply prints the two read integers, which does not perform polynomial multiplication at all. It fails to process both polynomials, compute their product, or output terms in descending order of exponents.]
    //puts(c);
    return 0;
}