#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input() {
    int x = 0; bool f = 1; char c = getchar();
    for (;!isdigit(c); c = getchar()) if (c == '-') f = 0;
    for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
    return f? x: -x;
}

int n, m, a[107][107], k, v[107] = {1}, q[107], l = 0, r = -1;

void dfs(int u) {
    printf("%d ", u);
    for (int j = 0; j < n; j++)
        if (!v[j] && a[u][j]) v[j] = 1, dfs(j);
}

void bfs() {
    printf("\n0 ");
    memset(v, 0, sizeof v);
    v[0] = 1; q[++r] = 0;
    while (l <= r) {
        int u = q[l++];
        for (int j = 0; j < n; j++)
            if (!v[j] && a[u][j]) {
                printf("%d ", j);
                v[j] = 1; q[++r] = j;
            }
    }
}

int main() {
    n = input(); m = input();
    for (int i = 1; i <= m; i++) {
        int u = input(), v = input();
        a[u][v] = a[v][u] = 1;
    } k = input();
    dfs(0); bfs();
    for (int i = 0; i < n; i++) a[i][k] = a[k][i] = 0;
    memset(v, 0, sizeof v); v[0] = 1; putchar(10);
    dfs(0); bfs();
    return 0;
}

