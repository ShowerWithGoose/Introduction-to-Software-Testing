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

int l = -1,r,q[200]; // @@ The variable 'r' is not initialized to 0 here, and more importantly, the global state of l and r is not reset before the first bfs() call in main. In bfs(), r is used as the right pointer of the queue. It should be initialized to 0 (or -1 depending on implementation) before use. The current code relies on global initialization which is 0 for int, but l is -1. Let's look at bfs().
int Vis[110],Vis_[110];

void bfs() {
    q[++ l] = 0; // @@ l is -1 initially, so ++l makes it 0. q[0]=0. This is correct for the first call if l and r are properly managed. However, l and r are global and modified by bfs().
    Vis[0] = 1;
    while(l <= r) { // @@ r is globally initialized to 0. So initially l=0, r=0. Loop runs.
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
    l = -1,r = 0; // @@ This correctly resets l and r for the second BFS call.
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
    dfs_(0); printf("\n");
    bfs(); printf("\n"); // @@ The function bfs() uses global variables l, r, and Vis. These are not reset before this call. Specifically, 'l' and 'r' retain values from previous operations (though none here, they are global). More critically, 'Vis' array is not cleared. Since Vis is global, it is zero-initialized. But 'l' and 'r' need to be set correctly for the queue. In bfs(), l starts at -1 (global init) and r at 0 (global init). This works for the FIRST call to bfs. However, the problem is that the output order is wrong compared to expected.
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