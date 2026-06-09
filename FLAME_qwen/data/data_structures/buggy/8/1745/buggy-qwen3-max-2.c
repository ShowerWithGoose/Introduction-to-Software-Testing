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
    while(l <= r) { // @@ [The queue is never initialized properly: 'r' is uninitialized (remains 0 from global init), but elements are added with '++r', so the first element after 0 won't be processed because l starts at 0 and r is 0, making loop condition fail immediately after processing node 0. Also, 'l' is incremented twice per iteration: once in 'q[++l]' before loop body and again inside the loop.]
        int x = q[l];
        printf("%d ",x);
        l ++; // @@ [This double increment of 'l' causes skipping of queue elements and incorrect BFS traversal.]
        for(int i=0 ; i<n ; i++) {
            if(Vis[i] || !G[x][i]) continue;
            q[++ r] = i;
            Vis[i] = 1;
        }
    }
}

void bfs_() {
    l = -1,r = 0; // @@ [Here 'r' is set to 0, but in bfs() above, 'r' was never initialized, leading to inconsistent queue handling between bfs() and bfs_(). However, the main issue is the double increment of 'l'.]
    q[++ l] = 0;
    Vis_[0] = 1;
    while(l <= r) {
        int x = q[l];
        printf("%d ",x);
        l ++; // @@ [Same double increment error as in bfs(): 'l' is incremented in 'q[++l]' before the loop body and again here, causing incorrect queue processing.]
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