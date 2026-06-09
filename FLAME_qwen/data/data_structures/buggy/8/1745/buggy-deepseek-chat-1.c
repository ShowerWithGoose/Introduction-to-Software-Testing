#include<stdio.h>
#include<string.h>
#include<ctype.h>

int n,m,del;
int G[110][110];
int vis[110],vis_[110];

void dfs(int x) {
    printf("%d ",x);
    vis[x] = 1;
    for(int i=0 ; i<n ; i++) {
        if(i == x || vis[i] || !G[x][i]) continue;
        dfs(i);
    }
}

void dfs_(int x) {
    printf("%d ",x);
    vis_[x] = 1;
    for(int i=0 ; i<n ; i++) {
        if(i == x || vis_[i] || i == del || !G[x][i]) continue;
        dfs_(i);
    }
}

int l = -1,r,q[200];
int Vis[110],Vis_[110];

void bfs() {
    q[++ l] = 0; // @@ [Error: l is initialized to -1, so q[++l] becomes q[0], but r is uninitialized (0 by default), causing the while condition l <= r to fail immediately because l=0 and r=0, so the loop never executes. The queue should use separate front and rear pointers.]
    Vis[0] = 1;
    while(l <= r) {
        int x = q[l];
        printf("%d ",x);
        l ++;
        for(int i=0 ; i<n ; i++) {
            if(Vis[i] || !G[x][i]) continue;
            q[++ r] = i;
            Vis[i] = 1;
        }
    }
}

void bfs_() {
    l = -1,r = 0;
    q[++ l] = 0; // @@ [Error: Same issue as in bfs(); l is set to -1, then q[++l] = q[0], but r is set to 0, so the while condition l <= r is true initially (0 <= 0), but the logic of incrementing l before printing and using l as index is flawed. The correct approach is to use separate front and rear pointers, e.g., int front=0, rear=0; q[rear++]=0; while(front<rear) { int x=q[front++]; ... }]
    Vis_[0] = 1;
    while(l <= r) {
        int x = q[l];
        printf("%d ",x);
        l ++;
        for(int i=0 ; i<n ; i++) {
            if(Vis_[i] || !G[x][i] || i == del) continue;
            q[++ r] = i;
            Vis_[i] = 1;
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1 ; i<=m ; i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u][v] = 1;
        G[v][u] = 1;
    }
    scanf("%d",&del);
    dfs(0); printf("\n");
    dfs_(0); printf("\n");
    bfs(); printf("\n");
    bfs_();
}