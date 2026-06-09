#include <stdio.h>
int read();
int n, m;
int vis[103];
int e[103][103];
void clr() {
    puts("");
    for (int i = 0; i < n; ++i) vis[i] = 0;
}

void dfs(int u) {
    vis[u] = 1;
    printf("%d ", u);
    for (int v = 1; v < n; ++v)
        if (e[u][v] && !vis[v]) dfs(v);
}

int q[1003], st, en;
void bfs() {
    q[st = en = 1] = 0, vis[0] = 1;
    while (st <= en) {
        int u = q[st++];
        printf("%d ", u);
        for (int v = 1; v < n; ++v)
            if (e[u][v] && !vis[v]) q[++en] = v, vis[v] = 1;
    }
}

int main() {
    n = read(), m = read();
    for (int i = 0, u, v; i < m; ++i) {
        u = read(), v = read();
        e[u][v] = e[v][u] = 1;
    }
    int t = read();
    dfs(0), clr(), bfs(), clr(), vis[t] = 1, dfs(0), clr(), vis[t] = 1, bfs();
    return 0;
}

int read() {
    int x = 0, f = 1, c = getchar();
    while (c < '0' || c > '9') (c == '-') ? (f = -1) : 0, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
