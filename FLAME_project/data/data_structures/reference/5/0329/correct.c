#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10007

typedef struct num {
    int a, b;
} num;

num a[N], b[N], c[N], d[N];
char s[N], *ch;
int ta, tb, tc, td;

int input() {
    int x = 0; bool f = 1;
    for (;!isdigit(*ch); ch++) if (*ch == '-') f = 0;
    for (; isdigit(*ch); ch++) x = x * 10 + *ch - 48;
    return f? x: -x;
}

void sort(num *low, num *high) {
    if (high - low <= 1) return;
    num *mid = low + (high - low) / 2;
    sort(low, mid); sort(mid, high);
    num *i = low, *j = mid, tmp[N]; int k = 0;
    while (i < mid && j < high) tmp[k++] = i->b > j->b? *i++: *j++;
    while (i < mid) tmp[k++] = *i++;
    while (j < high) tmp[k++] = *j++;
    memcpy(low, tmp, sizeof(num) * k);
}

int main() {
    gets(s); ch = s;
    while (*ch) {
        a[++ta].a = input();
        a[ta].b = input();
    }
    gets(s); ch = s;
    while (*ch) {
        b[++tb].a = input();
        b[tb].b = input();
    }
    for (int i = 1; i <= ta; i++)
        for (int j = 1; j <= tb; j++) {
            c[++tc].a = a[i].a * b[j].a;
            c[tc].b = a[i].b + b[j].b;
        }
    sort(c + 1, c + tc + 1);
    for (int i = 1; i <= tc; i++)
        if (i > 1 && c[i].b == c[i-1].b) d[td].a += c[i].a;
        else d[++td] = c[i];
    for (int i = 1; i <= td; i++) printf("%d %d ", d[i].a, d[i].b);
    return 0;
}

