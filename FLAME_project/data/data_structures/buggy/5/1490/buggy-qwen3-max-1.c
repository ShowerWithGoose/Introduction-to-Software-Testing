#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a);
    //gets(c);
    scanf("%d", &b);
    printf("%d %d\n", a, b); // @@ [The program only reads and prints two integers as if multiplying coefficients directly, but it completely ignores polynomial structure, exponents, multiple terms, combination of like terms, and sorting. It fails to implement polynomial multiplication logic.]
    //puts(c);
    return 0;
}