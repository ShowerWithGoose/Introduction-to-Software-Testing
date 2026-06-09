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
    printf("%d %d\n", a, b); // @@ The program fails to implement polynomial multiplication. It simply reads two integers and prints them, ignoring the exponents and the requirement to multiply terms. For the input "8 1000000000" and "15 1000000000", it should calculate (8*x^1000000000) * (15*x^1000000000) = 120*x^2000000000, but instead outputs the raw inputs.
    //puts(c);
    return 0;
}