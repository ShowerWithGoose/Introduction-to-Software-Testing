#include <stdio.h>
int read();
int n;
int xa[1003], ya[1003], xb[1003], yb[1003], h[1003];

int dfs(int u) {
    h[u] = 1;
    int i;
    for (i = 1; i <= n; ++i) {
        if (xb[u] == xa[i] && yb[u] == ya[i]) {
            dfs(i), h[u] = h[i] + 1;
            break;
        }
    }
}

int main() {
    n = read();
    int i, j;
    for (i = 1; i <= n; ++i)
        xa[i] = read(), ya[i] = read(), xb[i] = read(), yb[i] = read();

    int ans = 0;
    for (i = 1; i <= n; ++i) dfs(i), h[i] > ans ? ans = h[i] : 0;

    printf("%d ", ans);
    for (i = 1; i <= n; ++i)
        if (h[i] == ans) printf("%d %d\n", xa[i], ya[i]);
    return 0;
}

int read() {
    int x = 0, f = 1, c = getchar();
    while (c < '0' || c > '9') (c == '-') ? (f = -1) : 0, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}


