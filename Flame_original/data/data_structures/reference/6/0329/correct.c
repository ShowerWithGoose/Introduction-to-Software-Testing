#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input() {
    int x = 0; bool f = 1; char ch = getchar();
    for (;!isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    return f? x: -x;
}

int a[107], t, o, x;

int main() {
    while (1) {
        scanf("%d", &o);
        if (o == -1) break;
        if (o == 1) {
            scanf("%d", &x);
            if (t == 100) printf("error ");
            else a[++t] = x;
        }
        if (o == 0) {
            if (!t) printf("error ");
            else printf("%d ", a[t--]);
        }
    }
}

