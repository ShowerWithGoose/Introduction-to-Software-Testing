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
    scanf("%d", &ay); // @@ [The vertex to be deleted is read before performing the first traversal (before deletion), but according to the problem, the first DFS/BFS should be done on the original graph BEFORE reading or deleting the vertex. This causes the first traversal to be skipped and only the post-deletion traversal is performed.]
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
    while(head <= tail){ // @@ [The BFS implementation uses a manual queue but does not reset 'head' and 'tail' properly across calls. More critically, the condition 'head <= tail' may access beyond initialized queue elements because 'tail' can grow without bound relative to queue size, but more importantly, this BFS function is designed to run standalone, yet it's called after memset in circulate(), so logic is okay, BUT: the real issue is that the BFS prints nodes as they are dequeued, which is correct, however the queue array is global and not reinitialized per call, but since circulate() calls memset(visit) and BFS uses visit to avoid revisiting, it might still work. However, the major error is in main() input order.]
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
}