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
    while(head <= tail){  // @@ The condition should be `head < tail` to avoid accessing an uninitialized queue element when head equals tail. This can cause reading garbage or an extra unwanted vertex in the output.
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