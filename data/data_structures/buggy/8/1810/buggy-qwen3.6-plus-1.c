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
    int u, v; // @@ Compilation Error: In C89/C90 standard, variables must be declared at the beginning of a block. Declaring them after scanf causes a compilation error.
    while(side--){
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;
    }
    int ay; // @@ Compilation Error: Same as above, variable declaration after executable statements is invalid in C89.
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
    for(int i = 0; i < dot; i++){ // @@ Compilation Error: C89 does not support declaring loop control variables inside the for-loop initialization statement.
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
    while(head <= tail){ // @@ Logical Error: The loop condition should be head < tail. Using <= causes an extra iteration that accesses uninitialized/out-of-bounds queue elements when the queue is empty.
        tmp = queue[head];
        head++;
        if(visit[tmp] == 1)
            continue;
        else if(visit[tmp] == 0){
            printf("%d ", tmp);
            visit[tmp] = 1;
            for(int i = 0; i < dot; i++) // @@ Compilation Error: C89 loop variable declaration issue.
                if(G[tmp][i] == 1 && visit[i] == 0)
                    queue[tail++] = i; // @@ Logical Error: Neighbors are enqueued without being marked as visited, which leads to duplicate entries in the queue and potential array overflow. visit[i] should be set to 1 here.
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
    
    for(int i = 0; i < dot; i++){ // @@ Compilation Error: C89 loop variable declaration issue.
            G[ay][i] = 0;
            G[i][ay] = 0;
    }
}