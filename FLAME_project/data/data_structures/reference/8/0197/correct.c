#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// defination
#define MaxV 100

// var
typedef struct edge
{
    int adjvex;
    struct edge *next;
} ELink;
typedef struct ver
{
    int vertex;
    ELink *link;
} VLink;

int Vertex[MaxV];
int G[MaxV][MaxV];
int Visited[MaxV]; //标识顶点是否被访问过，vcount为顶点数
int vcount, ecount, deletev;

int Q[MaxV];
int front = -1;
int rear = -1;

// fun
ELink *insertEdge(ELink *head, int avex);
void travelDFS(VLink G[], int n);
void DFS(int[][MaxV], int);
void BFS(int[][MaxV], int);
void enQueue(int[], int *, int);
int emptyQ(int, int);
int deQueue(int[], int *);
int main()
{
    scanf("%d%d", &vcount, &ecount);

    for (int i = 0; i < ecount; i++)
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        G[v1][v2] = G[v2][v1] = 1;
    }
    DFS(G, 0);printf("\n");
    for(int i=0;i<vcount;i++)
    Visited[i]=0;
    BFS(G, 0);printf("\n");
    for(int i=0;i<vcount;i++)
    Visited[i]=0;
    scanf("%d", &deletev);
    for(int i=0;i<vcount;i++)
    G[deletev][i] = 0;
    for(int i=0;i<vcount;i++)
    G[i][deletev] = 0;
    DFS(G, 0);printf("\n");
    for(int i=0;i<vcount;i++)
    Visited[i]=0;
    BFS(G, 0);
    return 0;
}
/*
ELink *insertEdge(ELink *head, int avex)
{
    ELink *e, *p;
    e = (ELink *)malloc(sizeof(ELink));
    e->adjvex = avex;
    e->next = NULL;
    if (head == NULL)
    {
        head = e;
        return head;
    }
    for (p = head; p->next != NULL; p = p->next)
        ;
    p->next = e;
    return head;
}
void travelDFS(int G[][], int n)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            DFS(G, i);
} */
void DFS(int G[][MaxV], int v)
{
    Visited[v] = 1; //标识某顶点被访问过
    //访问当前顶点
    printf("%d ",v);
    for (int p = 0; p < vcount; p++)
        if (!Visited[p] && G[v][p] == 1)
            DFS(G, p);
}
void BFS(int G[][MaxV], int v)
{
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, &rear, v);
    while (!emptyQ(front, rear))
    {
        v = deQueue(Q, &front); //取出队头元素
        //访问当前顶点
        printf("%d ",v);
        for (int p = 0; p < vcount; p++) //访问该顶点的每个邻接顶点
            if (!Visited[p] && G[v][p] == 1)
            {
                Visited[p] = 1; //标识某顶点入队
                enQueue(Q, &rear, p);
            }
    }
}
void enQueue(int Q[], int *rear, int v)
{
    Q[++*rear] = v;
}
int emptyQ(int front, int rear)
{
    return front == rear;
}
int deQueue(int Q[], int *front)
{
    return Q[++*front];
}

