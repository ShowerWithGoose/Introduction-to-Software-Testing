#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); // @@ [Only reads the first coefficient of the first polynomial; should read both polynomials completely]
    //gets(c);
    scanf("%d", &b); // @@ [Reads the exponent of the first polynomial but then the program stops; missing reading of second polynomial and multiplication]
    printf("%d %d\n", a, b); // @@ [Prints the first polynomial term instead of the product of the two polynomials]
    //puts(c);
    return 0;
}