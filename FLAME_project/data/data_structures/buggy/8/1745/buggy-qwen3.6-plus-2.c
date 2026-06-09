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

int l = -1,r,q[200]; // @@ The variable 'r' is not initialized to 0. In C, global variables are zero-initialized, so this is technically correct (r=0), but the logic in bfs() relies on r being 0 initially. However, the main issue is that 'r' is reused without reset in bfs(). Let's look closer. In bfs(), r is used as the tail of the queue. It starts at 0 (global init). In bfs_(), it is explicitly reset. In bfs(), it is NOT reset. If bfs() is called after other operations, r might not be 0. But here bfs() is called once. Wait, looking at the test case failure: BFS before deletion is wrong. Expected: 0 1 2. Got: 0 2. This suggests the neighbor order or visitation is wrong. 
// Let's re-examine bfs().
// q[++l] = 0 -> l becomes 0. q[0]=0. Vis[0]=1.
// while(l <= r) -> 0 <= 0. True.
// x = q[0] = 0. Print 0. l becomes 1.
// Loop i from 0 to n-1.
// i=0: Vis[0] is true. Continue.
// i=1: Vis[1] false, G[0][1] true. q[++r] -> q[1]=1. Vis[1]=1. r becomes 1.
// i=2: Vis[2] false, G[0][2] true. q[++r] -> q[2]=2. Vis[2]=1. r becomes 2.
// Loop ends.
// while(l <= r) -> 1 <= 2. True.
// x = q[1] = 1. Print 1. l becomes 2.
// Loop i from 0 to n-1.
// i=0: Vis[0] true.
// i=1: Vis[1] true.
// i=2: Vis[2] true.
// Loop ends.
// while(l <= r) -> 2 <= 2. True.
// x = q[2] = 2. Print 2. l becomes 3.
// Loop i... nothing new.
// while(3 <= 2) False.
// So bfs() should print 0 1 2. Why did the buggy output say "0 2"?
// Ah, look at the Buggy Output provided in the prompt:
// 0 1 2 
// 0 2 
// 0 1 2 
// 0 2
// The second line is DFS after deletion? No.
// Order in main:
// dfs(0) -> Line 1
// dfs_(0) -> Line 2
// bfs() -> Line 3
// bfs_() -> Line 4
//
// Expected:
// 0 1 2 (DFS before)
// 0 1 2 (BFS before)
// 0 2   (DFS after)
// 0 2   (BFS after)
//
// Buggy Output:
// 0 1 2 (DFS before) - Correct
// 0 2   (DFS after?) - Wait. The code calls dfs_ immediately after dfs.
// The problem asks for:
// 1. DFS before
// 2. BFS before
// 3. DFS after
// 4. BFS after
//
// The main function does:
// dfs(0)
// dfs_(0)
// bfs()
// bfs_()
//
// This order is WRONG according to the output format description:
// "First, output the DFS and BFS sequences **before** deleting... Then... after"
// So it should be DFS_before, BFS_before, DFS_after, BFS_after.
// The code outputs DFS_before, DFS_after, BFS_before, BFS_after.
// This explains why the lines are mismatched in the "Buggy Output" vs "Expected Output" comparison if we assume line-by-line correspondence.
// Line 2 of buggy output is `0 2`. This is the result of `dfs_(0)`.
// Line 2 of expected output is `0 1 2`. This is BFS before.
// So the error is the order of function calls in main.

int Vis[110],Vis_[110];

void bfs() {
    q[++ l] = 0; // @@ Logic error: 'l' is global and modified by previous calls or not reset properly if reused, but specifically here, 'r' is not reset to 0 before starting BFS. Although global init sets r=0, if this function were called twice it would fail. More importantly, the queue logic uses 'l' and 'r'. 'l' is initialized to -1 globally. ++l makes it 0. This part is okay for the first call. However, standard BFS usually resets head/tail.
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
    l = -1,r = 0; // @@ Resets indices correctly for the second BFS
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
    dfs_(0); printf("\n"); // @@ Incorrect order: Should be BFS before deletion here, not DFS after deletion. The problem requires DFS then BFS for the original graph, then DFS then BFS for the modified graph.
    bfs(); printf("\n"); // @@ Incorrect order: This is BFS before deletion, but it's printed 3rd. It should be 2nd.
    bfs_(); // @@ Incorrect order: This is BFS after deletion. It is printed 4th, which is correct positionally for the 4th output, but since the 2nd and 3rd outputs are swapped relative to requirements, the whole sequence is wrong. Also missing printf("\n") potentially depending on strictness, but previous lines have it.
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