#include <stdio.h>
int read();
int n, vis[1003], a[1003];
void dfs(int d) {
    if (d > n) {
        int i;
        for (i = 1; i <= n; ++i) printf("%d ", a[i]);
        puts("");
        return;
    }
    int i;
    for (i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        a[d] = i, vis[i] = 1, dfs(d + 1), vis[i] = 0;
    }
}
int main() {
    n = read(), dfs(1);
    return 0;
}

int read() {
    int x = 0, f = 1, c = getchar();
    while (c < '0' || c > '9') (c == '-') ? (f = -1) : 0, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
