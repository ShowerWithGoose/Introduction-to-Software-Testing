#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int N,M;
int edge[101][101];
int vis[101];
int del_num = -1;

void addEdge(int u, int v){
    edge[u][v] = 1;
    edge[v][u] = 1;
}

void dfs(int u){
    printf("%d ", u);
    vis[u] = 1;
    for (int v = 0; v < N; v++){
        if (!edge[u][v] || vis[v] || v == del_num)continue;
        dfs(v);
    }
}

void bfs(){
    int q[200];
    q[0] = 0;
    vis[0] = 1;
    int st = 0, ed = 1;
    while (st < ed){
        int u = q[st++];
        printf("%d ", u);
        for (int v = 0; v < N; v++){
            if (!edge[u][v] || vis[v] || v == del_num)continue;
            vis[v] = 1;
            q[ed++] = v;
        }
    }
}

int main(){
#ifdef VSCODE
    freopen("input.in", "r", stdin);
#endif
    int u,v;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++){
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    memset(vis, 0, sizeof(vis));
    dfs(0);putchar('\n');
    memset(vis, 0, sizeof(vis));
    bfs();putchar('\n');
    scanf("%d", &del_num);
    memset(vis, 0, sizeof(vis));
    dfs(0);putchar('\n');
    memset(vis, 0, sizeof(vis));
    bfs();putchar('\n');
    return 0;
}

// typedef struct PIC_NODE{
//     int v;
//     struct PIC_NODE *next;
// }NODE;

// NODE *head[200];
// NODE edges[500];
// int cnt = 0;
// int del_num = -1;

// void addEdge(int u, int v){
//     edge[++cnt].next = head[u];
//     edge[cnt].v = v;
//     head[u] = &edge[cnt];
// }
