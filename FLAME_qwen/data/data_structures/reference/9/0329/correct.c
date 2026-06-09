#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10007

typedef long long LL;

int input() {
    int x = 0; bool f = 1; char ch = getchar();
    for (;!isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    return f? x: -x;
}

void print(int x) {
    if (x < 0) {putchar(45); x = -x;}
    if (x > 9) print(x / 10);
    putchar(x % 10 + 48);
}

typedef struct line {
    int x, y, xx, yy;
} line;

void sort(line *low, line *high) {
    if (high - low <= 1) return;
    line *mid = low + (high - low) / 2;
    sort(low, mid); sort(mid, high);
    line *i = low, *j = mid, tmp[N]; int k = 0;
    while (i < mid && j < high) tmp[k++] = i->x < j->x? *i++: *j++;
    while (i < mid) tmp[k++] = *i++;
    while (j < high) tmp[k++] = *j++;
    memcpy(low, tmp, sizeof(line) * k);
}

line a[107], t[107][107];

int n, cnt, c[107], f, ma = -1, ii;

int main() {
    n = input();
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].xx, &a[i].yy);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        f = 0;
        for (int j = 1; j <= cnt; j++)
            if (t[c[j]][j].xx == a[i].x && t[c[j]][j].yy == a[i].y) {
                t[++c[j]][j] = a[i];
                f = 1;
            }
        if (!f) {t[1][++cnt] = a[i]; c[cnt] = 1;}
    }
    for (int i = 1; i <= cnt; i++) if (c[i] > ma) {ma = c[i]; ii = i;}
    printf("%d %d %d", ma, t[1][ii].x, t[1][ii].y);
    return 0;
}

