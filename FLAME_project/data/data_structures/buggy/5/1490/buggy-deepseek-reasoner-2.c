#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); // @@ [This only reads the first integer of the first polynomial, but the input contains two numbers on the first line and a whole second line. The program should read all terms of both polynomials.]
    //gets(c);
    scanf("%d", &b); // @@ [This reads the second integer (exponent of first polynomial's term), not the second polynomial. The program fails to read the entire second polynomial.]
    printf("%d %d\n", a, b); // @@ [This prints the two numbers instead of performing polynomial multiplication and outputting the result. The expected output is the product of two binomials, which requires combining like terms and sorting.]
    //puts(c);
    return 0;
}