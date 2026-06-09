#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    //int n;
    int a, b;
    //char c[100];
    //scanf("%d", &n);
    //getchar();
    scanf("%d", &a); // @@ Incorrect input handling: the problem requires reading multiple coefficient-exponent pairs for the first polynomial until a newline, not a single integer.
    //gets(c);
    scanf("%d", &b); // @@ Incorrect input handling: similarly, the second polynomial's terms must be read as multiple pairs, not a single integer.
    printf("%d %d\n", a, b); // @@ Missing core logic: the program does not store polynomial terms, perform multiplication, or output the result in the required descending exponent format.
    //puts(c);
    return 0;
}