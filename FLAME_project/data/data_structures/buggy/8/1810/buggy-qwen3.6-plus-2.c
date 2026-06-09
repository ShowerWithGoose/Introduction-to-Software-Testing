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
    printf("\n"); // @@ The output format requires no trailing space or specific newline handling, but the main issue is likely logical. However, looking at the expected output "0 1 2" vs buggy "0 1 2 ", the reference program prints a space after every number including the last one. The expected output in the problem description usually tolerates trailing spaces in many OJs, but let's look closer. Actually, the Buggy Output shows "0 1 2 " (with trailing space) and Expected is "0 1 2". Wait, the provided Buggy Output in the prompt is:
// 0 1 2 
// 0 1 2 
// 0 2 
// 0 2 
// And Expected:
// 0 1 2
// 0 1 2
// 0 2
// 0 2
// The difference is often just whitespace. But let's look at the logic.
// The logic seems correct for DFS/BFS.
// Let's re-read the prompt carefully.
// "Wrong Answer".
// Test Case Input:
// 3 3
// 0 1
// 1 2
// 0 2
// 1
//
// Graph: Triangle 0-1-2. Delete 1.
// Before delete:
// DFS from 0: Visit 0. Neighbors 1, 2. Visit 1 (asc order). From 1, neighbors 0, 2. 0 visited. Visit 2. From 2, neighbors 0, 1. Both visited. Back to 1. Back to 0. Neighbor 2 visited.
// Sequence: 0 1 2.
// BFS from 0: Queue [0]. Pop 0. Print 0. Neighbors 1, 2. Enqueue 1, 2. Queue [1, 2].
// Pop 1. Print 1. Neighbors 0, 2. 0 visited. 2 visited? No, but it's already in queue? Standard BFS marks visited when enqueuing or dequeuing?
// In the code: `visit[tmp] = 1` happens when dequeuing (printing).
// So when processing 0:
// Check neighbor 1: G[0][1]==1, visit[1]==0. Enqueue 1.
// Check neighbor 2: G[0][2]==1, visit[2]==0. Enqueue 2.
// Queue: [1, 2]. Head=1, Tail=2.
// Loop: head(1) <= tail(2).
// tmp = queue[1] = 1. Head becomes 2.
// visit[1] is 0. Print 1. visit[1]=1.
// Neighbors of 1: 0 (visited), 2 (visit[2]==0). Enqueue 2.
// Queue: [1, 2, 2]. Tail becomes 3.
// Loop: head(2) <= tail(3).
// tmp = queue[2] = 2. Head becomes 3.
// visit[2] is 0. Print 2. visit[2]=1.
// Neighbors of 2: 0 (visited), 1 (visited).
// Loop: head(3) <= tail(3).
// tmp = queue[3] = 2. Head becomes 4.
// visit[2] is 1. Continue.
// Loop: head(4) <= tail(3). False. End.
// Output: 0 1 2 2.
// Ah! The BFS implementation marks nodes as visited only when they are *dequeued*, not when they are *enqueued*. This causes duplicates in the queue if a node is reachable via multiple paths before being processed.
// The standard BFS should mark `visit[i] = 1` when adding to the queue to prevent adding it again.
    
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
}