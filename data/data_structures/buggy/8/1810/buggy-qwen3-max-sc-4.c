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
    scanf("%d", &ay); // @@ [The vertex to be deleted is read before performing the first traversal (before deletion), but according to the problem, the first traversals (DFS and BFS) should be done BEFORE deleting the vertex. However, the deletion hasn't occurred yet, so this is actually correct placement. But the real issue is that the BFS implementation is flawed.]
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
void bfs(int item) // @@ [This BFS implementation uses a manual queue but does not enforce visiting neighbors in ascending order. The problem requires that when accessing adjacent vertices, they must be visited in ascending order. However, this BFS adds neighbors to the queue in ascending order (since i goes from 0 to dot-1), which is correct. BUT: the main flaw is that the queue may contain duplicate nodes because it doesn't mark nodes as visited when enqueuing, only when dequeuing. This can lead to duplicates in the queue and potentially incorrect behavior or infinite loops in some cases, though with the memset before each call it might still work. However, more critically, the BFS function does not guarantee the correct order because multiple copies of the same node might be enqueued before being marked visited.]
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
                    queue[tail++] = i; // @@ [Node 'i' is enqueued without marking it as visited, so the same node could be enqueued multiple times from different parents, violating BFS correctness and possibly causing output duplication or exceeding queue bounds.]
        }
    }
}
void circulate()
{
    dfs(0);
    printf("\n");
    memset(visit, 0, sizeof(int)*MaxV); // @@ [This only resets 'visit' array, which is correct. However, note that 'queue' is global but not reset; however, since BFS uses head/tail indices locally, it's okay.]
    
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