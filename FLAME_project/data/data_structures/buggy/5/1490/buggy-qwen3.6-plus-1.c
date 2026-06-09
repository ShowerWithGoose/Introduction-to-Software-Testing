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
    printf("%d %d\n", a, b); // @@ The program fails to implement polynomial multiplication. It simply reads two integers and prints them, ignoring the exponents and the multiplication logic required by the problem description. The expected output requires multiplying coefficients (8*15=120) and adding exponents (1000000000+1000000000=2000000000).
    //puts(c);
    return 0;
}