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
    q[++ l] = 0;
    Vis[0] = 1;
    while(l <= r) { @@ [The queue indices are incorrectly managed: 'l' is incremented before processing, and 'r' is never initialized properly. Also, 'r' should start at 0 or -1 consistently, but here 'r' is uninitialized (global default 0), yet 'l' starts at -1, leading to incorrect queue behavior.]
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
    l = -1,r = 0; @@ [Inconsistent queue initialization: 'r' is set to 0, but in standard BFS with array queue, if l=-1 then r should also be -1 initially, or both start at 0. More critically, the loop condition and increment logic mismatches standard BFS.]
    q[++ l] = 0;
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
    dfs_(0); printf("\n"); @@ [Wrong order: The problem requires DFS and BFS *before* deletion first, then DFS and BFS *after*. But here, it outputs DFS before, then DFS after, then BFS before, then BFS after. Expected: DFS_before, BFS_before, DFS_after, BFS_after.]
    bfs(); printf("\n");
    bfs_();
}
/*
9 10
0 1
0 2
1 4
1 3
1 8
8 6
3 6
7 2
7 5
5 2
3
*/