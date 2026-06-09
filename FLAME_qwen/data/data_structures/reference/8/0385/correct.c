#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 100

int G[MAXV][MAXV] = {0};
int vertex, edge;//顶点数目与边的数目
int visited[MAXV];//访问过了的节点
int dele_ver;//要删除的节点
int queue[MAXV];//创建队列
int head = -1, rear = -1, cnt = 0;//队列要素

void DFS(int k);
void BFS(int k);
void enqueue(int k);//入队
int dequeue(void);//出队

int main()
{
    scanf("%d%d", &vertex, &edge);
    for(int i = 0; i < edge; i++){
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }
    scanf("%d", &dele_ver);
    memset(visited, 0, sizeof(visited));
    DFS(0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    BFS(0);
    printf("\n");
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            if(G[i][j] != 0 && (i == dele_ver || j == dele_ver))
                G[i][j] = 0;
        }
    }
    memset(visited, 0, sizeof(visited));
    DFS(0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    BFS(0);
    printf("\n");
    return 0;
}

void BFS(int k)
{
    rear = head = -1;
    cnt = 0;
    enqueue(k);
    while(cnt != 0){
        int k = dequeue();
        printf("%d ", k);
        for(int i = 0; i < vertex; i++){
            if(G[i][k] != 0 && visited[i] != 1){
                enqueue(i);
            }
        }
    }
}

int dequeue()
{
    int k;
    head = (head + 1) % MAXV;
    cnt--;
    k = queue[head];
    return k;
}

void enqueue(int k)
{
    visited[k] = 1;
    rear = (rear + 1) % MAXV;
    cnt++;
    queue[rear] = k;
}

void DFS(int k)
{
    printf("%d ",k);
    visited[k] = 1;
    for(int i =0; i < vertex; i++){
        if(G[k][i] != 0 && visited[i] != 1){
            DFS(i);
        }
    }
}




