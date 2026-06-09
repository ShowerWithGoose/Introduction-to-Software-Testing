#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); @@ [The program reads only one coefficient and one exponent for each polynomial, but the problem requires reading multiple terms (pairs of coefficient and exponent) until end of input. This causes incorrect parsing of polynomial input.]
    //gets(c);
    scanf("%d", &b); @@ [Same issue: only one term is read from each polynomial, but polynomials can have multiple non-zero terms. The program does not loop to read all input pairs.]
    printf("%d %d\n", a, b); @@ [The output is just the first term of each polynomial printed as-is, not the result of polynomial multiplication. Also, the format includes a newline which may not match expected output format (space-separated terms without mandatory newline).]
    //puts(c);
    return 0;
}