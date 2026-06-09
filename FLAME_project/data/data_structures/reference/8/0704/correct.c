#include <stdio.h>
#include <stdlib.h>
#define MaxV 256
typedef struct edge
{
    int adjvex;
    struct edge *next;
} Elink;
typedef struct ver
{
    Elink *link;
} Vlink;
Vlink G[MaxV];
Elink *insertEdge(Vlink *Ver, Elink *head, int avex)
{
    Elink *e, *p;
    e = (Elink *)malloc(sizeof(Elink));
    e->adjvex = avex;
    e->next = NULL;
    if (head == NULL)
    {
        head = e;
        return head;
    }
    for (p = head; p->next != NULL && avex > p->next->adjvex; p = p->next)
        ;
    if (p == head && p->adjvex > avex)
    {
        e->next = p;
        Ver->link = e;
        return e;
    }
    else
    {
        e->next = p->next;
        p->next = e;
        return head;
    }
}
void createGraph(Vlink graph[], int edgenum)
{
    int i, v1, v2;
    for (i = 0; i < edgenum; i++)
    {
        scanf("%d %d", &v1, &v2);
        // printf("%d %d\n", v1, v2);
        graph[v1].link = insertEdge(&graph[v1], graph[v1].link, v2);
        graph[v2].link = insertEdge(&graph[v2], graph[v2].link, v1);
    }
}
int Visited[MaxV] = {0}; //标识顶点是否被访问过，N为顶点数
void DFS(Vlink G[], int v)
{
    Elink *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ", v);
    for (p = G[v].link; p != NULL; p = p->next)
        if (Visited[p->adjvex] == 0)
            DFS(G, p->adjvex);
}
void travelDFS(Vlink G[], int n, int del)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    Visited[del] = 1;
    for (i = 0; i < n; i++)
        if (Visited[i] == 0)
            DFS(G, i);
    printf("\n");
}
int Q[MaxV];
int rear = -1, front = 0;
void enQueue(int queue[], int v)
{
    queue[++rear] = v;
}
int deQueue(int queue[])
{
    return queue[front++];
}
int isemptyQ()
{
    return rear < front ? 1 : 0;
}
void BFS(Vlink G[], int v)
{
    Elink *p;
    printf("%d ", v);
    Visited[v] = 1; //标识某顶点被访问过
    enQueue(Q, v);  // 入口的第一个顶点入队
    while (isemptyQ() == 0)
    {                                  //  循环，直到队空为止
        v = deQueue(Q);                //取出队头元素
        p = G[v].link;                 //获取该顶点第一个邻接顶点
        for (; p != NULL; p = p->next) //访问该顶点下的每个邻接顶点
            if (Visited[p->adjvex] == 0)
            {
                printf("%d ", p->adjvex); //访问当前顶点
                Visited[p->adjvex] = 1;   //标识某顶点被访问过
                enQueue(Q, p->adjvex);    //邻接顶点依次分别入队
            }
    }
}
void travelBFS(Vlink G[], int n, int del)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    Visited[del] = 1;
    for (i = 0; i < n; i++)
        if (Visited[i] == 0)
            BFS(G, i);
    rear = -1, front = 0;
    printf("\n");
}

int main()
{
    int VerNum, EdgeNum;
    scanf("%d %d", &VerNum, &EdgeNum);
    createGraph(G, EdgeNum);
    int VerToDelete;
    scanf("%d", &VerToDelete);
    travelDFS(G, VerNum, MaxV - 1);
    travelBFS(G, VerNum, MaxV - 1);
    travelDFS(G, VerNum, VerToDelete);
    travelBFS(G, VerNum, VerToDelete);
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

0 3
0 2
3 2
2 1
0 1
3 1
*/
