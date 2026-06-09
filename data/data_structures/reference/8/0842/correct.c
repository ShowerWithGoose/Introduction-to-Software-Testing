#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int weights[200][200], visited[200], queue[200];
int VNum, ENum; //顶点数和边数
void DFS(int v);
void BFS(int v);

int main()
{
    int u, v, i;
    scanf("%d %d", &VNum, &ENum);
    for (i = 0; i < ENum; i++)
    {
        scanf("%d %d", &u, &v);
        weights[u][v] = weights[v][u] = 1;
    }
    DFS(0);
    printf("\n");
    memset(visited, 0, sizeof(visited)); //初始化

    BFS(0);
    printf("\n");
    memset(visited, 0, sizeof(visited)); //初始化
    memset(queue, 0, sizeof(queue));     //队列初始化

    int del;
    scanf("%d", &del);
    visited[del] = 1;
    DFS(0);
    printf("\n");
    memset(visited, 0, sizeof(visited));

    visited[del] = 1;
    BFS(0);
    printf("\n");

    return 0;
}

void DFS(int v)
{
    printf("%d ", v);
    visited[v] = 1;
    int i;
    for (i = 0; i < VNum; i++)
        if (weights[v][i] && !visited[i])
            DFS(i);                     
}
void BFS(int v)
{
    int head = 0, tail = 1, tmp; //队头，队尾，出列的元素
    queue[head] = v;           
    while (head <= tail)          
    {
        tmp = queue[head++]; 
        if (!visited[tmp])
        {
            printf("%d ", tmp); 
            visited[tmp] = 1;  
            int i;
            for (i = 0; i < VNum; i++)
                if (weights[tmp][i] && !visited[i])
                    queue[tail++] = i;            
        }
    }
}

