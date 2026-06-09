#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); @@ [The program only reads one coefficient and one exponent for the first polynomial, but the problem requires reading multiple terms until end of input. This causes incomplete parsing of input polynomials.]
    //gets(c);
    scanf("%d", &b); @@ [Similarly, only one exponent is read, which is insufficient for handling full polynomial input as specified. The program does not loop to read all terms of both polynomials.]
    printf("%d %d\n", a, b); @@ [The output format is incorrect—it just prints the first two integers read, rather than computing and printing the product of two polynomials in descending exponent order.]
    //puts(c);
    return 0;
}