#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxV 100
int G[MaxV][MaxV];
int visit[MaxV], queue[MaxV];
int dot, side;
void dfs(int x);
void bfs(int x);
void delete_ay(int x);
void circulate();
int main()
{
    scanf("%d%d", &dot, &side);
    int u, v;
    while(side--){
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;
    }
    int ay;
    scanf("%d", &ay);
    circulate();
    
    delete_ay(ay);
    
    circulate();
    return 0;
}
void dfs(int item)
{
    printf("%d ", item);
    visit[item] = 1;
    for(int i = 0; i < dot; i++){
        if(G[item][i] == 1 && visit[i] == 0){
            dfs(i);
        }
    }
    return;
}
void bfs(int item)
{
    int head = 0, tail = 1, tmp;
    queue[head] = item;
    while(head <= tail){
        tmp = queue[head];
        head++;
        if(visit[tmp] == 1)
            continue;
        else if(visit[tmp] == 0){
            printf("%d ", tmp);
            visit[tmp] = 1;
            for(int i = 0; i < dot; i++)
                if(G[tmp][i] == 1 && visit[i] == 0)
                    queue[tail++] = i;
        }
    }
}
void circulate()
{
    dfs(0);
    printf("\n");
    memset(visit, 0, sizeof(int)*MaxV);
    
    bfs(0);
    printf("\n");
    memset(visit, 0, sizeof(int)*MaxV);
}
void delete_ay(int ay)
{
    
    for(int i = 0; i < dot; i++){
            G[ay][i] = 0;
            G[i][ay] = 0;
    }
} // @@ [The BFS implementation uses a fixed-size queue but does not reset the queue array between traversals. However, the real issue is that in `circulate()`, after DFS, the visit array is reset correctly, but during BFS, nodes may be enqueued multiple times because the queue is not cleared. In particular, the `queue` array retains old values from previous BFS calls, which can lead to incorrect traversal if those stale values are processed. Although in this specific test case it doesn't manifest due to small size, the more critical error is actually in the order of operations: the program reads the vertex to delete *before* doing the first traversal, which is correct per problem statement, but the reference program shows that deletion should happen *after* the first two traversals. However, looking at the test input and output, the actual bug causing the WA is subtle: the output has trailing spaces, but the expected output does not. However, the problem says "Wrong Answer", and the sample outputs differ only by trailing space. But the instructions say to mark logical/semantic errors. The real semantic error is that the BFS queue is not properly managed — specifically, the queue is global and not reinitialized before each BFS, so leftover data from prior BFS (though in this code there's only one BFS before deletion and one after) might interfere. However, in this specific code, `circulate()` is called twice: once before deletion and once after. Before the first BFS, `queue` is uninitialized but only indices up to `tail` are used, and `tail` starts at 1. But the deeper issue is that the BFS loop condition `head <= tail` is incorrect — it should be `head < tail` because `tail` points to the next available slot. With `head <= tail`, it processes one extra invalid element. In the test case, after deletion, BFS(0): queue[0]=0, head=0,tail=1. Loop: head<=tail → 0<=1 → process queue[0]=0 → head=1. Then check head=1 <= tail=1 → true → tmp=queue[1] which was never set (garbage), leading to undefined behavior. This is the critical error.]