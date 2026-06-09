#include <stdio.h>
#include <math.h> // @@ Unnecessary include; not used for polynomial multiplication.
#include <string.h> // @@ Unnecessary include; not used.
int main() {
    //int n;
    int a, b; // @@ Insufficient variables: need data structures to store multiple terms of two polynomials.
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); // @@ Only reads the first integer of the first polynomial; should read entire polynomial until newline.
    //gets(c);
    scanf("%d", &b); // @@ Reads only one more integer, not the rest of the polynomials. Entire multiplication logic missing.
    printf("%d %d\n", a, b); // @@ Output is just two numbers, but required output is product polynomial terms in descending order.
    //puts(c);
    return 0;
}