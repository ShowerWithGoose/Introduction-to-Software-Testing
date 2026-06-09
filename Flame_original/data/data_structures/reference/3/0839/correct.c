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

char s[200000];
int main() {
    scanf("%s", s);
    int l = strlen(s), e = 0;
    if (s[0]!='0') {
        int dot = 0;
        putchar(s[0]);
        putchar('.');
        FOR(i, 1, l - 1) if (s[i] != '.') {
            putchar(s[i]);
        } else {
            dot = i;
        }
        e = dot - 1;
    } else {
        int top = 0;
        FOR(i, 2, l - 1) if (s[i] != '0') {
            top = i;
            break;
        }
        putchar(s[top]);
        if (top < l - 1) {
            putchar('.');
            FOR(i, top + 1, l - 1)
                putchar(s[i]);
        }
        e = 1 - top;
    }
    printf("e%d", e);
    return 0;
}
