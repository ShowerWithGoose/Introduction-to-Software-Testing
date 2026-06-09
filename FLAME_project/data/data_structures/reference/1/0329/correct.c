#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100007

typedef long long LL;

int input() {
    int x = 0; int sign = 1; char chr = getchar();
    for (;!isdigit(chr); chr = getchar()) if (chr == '-') sign = 0;
    for (; isdigit(chr); chr = getchar()) x = x * 10 + chr - '0';
    return sign? x: -x;
}

void print(int x) {
    if (x < 0) {putchar('-'); x = -x;}
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int n, a[15], v[15];

void dfs(int d) {
    if (d > n) {
        for (int i = 1; i <= n; i++) {
            print(a[i]); putchar(' ');
        } putchar('\n');
    }
    for (int i = 1; i <= n; i++) {
        if (v[i]) continue;
        v[i] = 1;
        a[d] = i;
        dfs(d + 1);
        v[i] = 0;
    }
}

int main() {
    n = input();
    dfs(1);
    return 0;
}

