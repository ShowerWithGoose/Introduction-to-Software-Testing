#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cL while (getchar() != '\n')  // clear line
#define fi(x) for (i = 0; i < x; i++)
#define fj(x) for (j = 0; j < x; j++)
#define FOR(a, b, c) for (int(a) = (b); (b) < (c) ? (a) <= (c) : (a) >= (c); (b) < (c) ? (a)++ : (a)--)
#define LL long long
#define min(a, b) (a > b ? b : a)
#define max(a, b) (a < b ? b : a)
#define pf printf
#define sf scanf

char c[200000];
int main() {
    scanf("%s", c);
    int l = strlen(c), e = 0;
    if (c[0]!='0') {
        int b = 0;
        putchar(c[0]);
        putchar('.');
        FOR(i, 1, l - 1) if (c[i] != '.') {
            putchar(c[i]);
        } else {
            b = i;
        }
        e = b - 1;
    } else {
        int d = 0;
        FOR(i, 2, l - 1) if (c[i] != '0') {
            d = i;
            break;
        }
        putchar(c[d]);
        if (d < l - 1) {
            putchar('.');
            FOR(i, d + 1, l - 1)
                putchar(c[i]);
        }
        e = 1 - d;
    }
    printf("e%d", e);
    return 0;
}
