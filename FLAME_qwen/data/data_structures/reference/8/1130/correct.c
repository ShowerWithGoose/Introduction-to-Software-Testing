#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 110

int n, m;
int g[N][N];
int del_point; 

int vis[N];

int q[N]; int hh, tt;


void dfs(int u, int flag) {
    vis[u] = 1;
    printf("%d ", u);
    for(int v = 0; v<N; v++) {
        if(flag && del_point == v) continue;
        if(g[u][v] && !vis[v]) {
            dfs(v, flag);
        }
    }
}

void bfs(int s, int flag) {
    hh = tt = 0;
    q[tt++] = s; vis[s] = 1;

    while(hh != tt) {
        int u = q[hh++];
        printf("%d ", u);
        for(int v = 0; v<N; v++) {
            if(flag && del_point == v) continue;
            if(g[u][v] && !vis[v]) {
                q[tt++] = v;
                vis[v] = 1;
            }
        }
    }
}


int main() {

    scanf("%d%d", &n, &m);
    for(int i = 0; i<m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }

    scanf("%d", &del_point);

    memset(vis, 0, sizeof vis);
    dfs(0, 0); 
    puts("");

    memset(vis, 0, sizeof vis);
    bfs(0, 0);
    puts("");

    memset(vis, 0, sizeof vis);
    dfs(0, 1); 
    puts("");

    memset(vis, 0, sizeof vis);
    bfs(0, 1);
    puts("");

    return 0;
}



