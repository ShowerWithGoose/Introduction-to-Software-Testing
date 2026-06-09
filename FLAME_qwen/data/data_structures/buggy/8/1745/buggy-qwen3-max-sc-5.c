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
    while(l <= r) { // @@ [The queue is initialized with l=-1 and r uninitialized (default 0), but after q[++l]=0, l becomes 0 and r is still 0. However, the loop condition 'l <= r' is correct only if r was properly set to 0 before the loop. The real issue is that 'r' is never initialized to -1 or 0 consistently; in bfs(), 'r' remains uninitialized from global scope (which is 0), but in bfs_(), it's explicitly set. However, the main bug is that in bfs(), 'r' should be initialized to -1 or 0 before use. But more critically, the queue logic uses 'l' as both index and counter incorrectly: 'l' is incremented twice per iteration (once in condition check via 'q[l]', then again via 'l++'), causing skipped elements and out-of-bound access.]
        int x = q[l];
        printf("%d ",x);
        l ++; // @@ [This double increment of 'l' (once when accessing q[l], then again here) causes the BFS to skip every other node and eventually go out of bounds. The standard BFS uses a separate front pointer that increments once per dequeue. Here, 'l' is used as the front index, but it's incremented twice: once implicitly by using q[l] then explicitly by l++. This leads to incorrect traversal order and potential undefined behavior.]
        for(int i=0 ; i<n ; i++) {
            if(Vis[i] || !G[x][i]) continue;
            q[++ r] = i; // @@ [In bfs(), 'r' is not initialized before this function call. Globally, 'r' is zero-initialized, so it starts at 0. But after q[++l]=0 sets l=0, we have l=0, r=0. Then in the loop, if neighbors are added, r increases. However, the main flaw is the double increment of 'l'.]
            Vis[i] = 1;
        }
    }
}

void bfs_() {
    l = -1,r = 0; // @@ [Here 'r' is set to 0, but should be -1 to match typical queue initialization where both front and rear start before the first element. However, since q[++l]=0 follows, l becomes 0, and r=0 means the queue has one element. This is acceptable, but inconsistent with bfs() which doesn't initialize r. The bigger issue remains the double increment of 'l' in both bfs and bfs_.]
    q[++ l] = 0;
    Vis_[0] = 1;
    while(l <= r) { // @@ [Same double-increment bug as in bfs(): 'l' is used to access q[l], then immediately incremented again, causing skipped nodes.]
        int x = q[l];
        printf("%d ",x);
        l ++; // @@ [Double increment error: 'l' is already the current index; incrementing again skips the next element. Should only increment once per dequeue.]
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
    bfs(); printf("\n"); // @@ [Because of the BFS implementation bugs (double increment of 'l' and uninitialized/mismanaged queue pointers), the BFS outputs are incorrect or may crash.]
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