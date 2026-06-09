#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); // @@ Error: The program reads a single integer, but the input format requires reading pairs of coefficient and exponent for two polynomials. This does not comply with the problem description.
    //gets(c);
    scanf("%d", &b); // @@ Error: Similarly, this reads a second integer, but the input contains many numbers; the program does not correctly process the polynomial inputs.
    printf("%d %d\n", a, b); // @@ Error: The program outputs only the two integers, but the expected output is the product polynomial in descending order of exponents.
    //puts(c);
    return 0;
}