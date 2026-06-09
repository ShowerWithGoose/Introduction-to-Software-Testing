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
    scanf("%d", &ay); // @@ [The vertex to be deleted is read BEFORE the first traversal (before deletion), but according to the problem, the first DFS/BFS should be performed on the original graph BEFORE deleting the vertex. However, the deletion happens in delete_ay(ay) which is called AFTER circulate(), so this is actually correct. But note: the problem says "Finally, input the vertex number to be deleted on a new line." — so input order is correct. So no error here.]

    circulate(); // This prints DFS and BFS of original graph
    
    delete_ay(ay); // Deletes the vertex from adjacency matrix
    
    circulate(); // This prints DFS and BFS of graph after deletion
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
void bfs(int item) // @@ [This BFS implementation is flawed: it uses a global queue array and does not reset head/tail properly across calls. Also, the logic inside the while loop may skip printing or enqueueing correctly because it checks visit[tmp] AFTER dequeuing, but multiple copies of same node might be enqueued. Moreover, the queue is global and not reinitialized between BFS calls, leading to leftover data. Additionally, the BFS does not guarantee ascending order traversal because it enqueues neighbors in ascending order, but if earlier nodes enqueue a high-numbered node, and later a lower one gets enqueued again, ordering may break — but more critically, the algorithm is not standard BFS due to incorrect handling of visited state during enqueue vs dequeue.]
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
}