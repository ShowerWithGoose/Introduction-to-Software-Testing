#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxV 256
typedef struct edge
{
    int adj; // 节点
    int wei; // 权重
    struct edge *next;
} ELink;
typedef struct ver
{
    ELink *link;
} VLink;
VLink G[MaxV];

int Visited[MaxV] = {0}; // 标识顶点是否被访问过，N为顶点数
struct Queue
{
    int num;
    struct Queue *next;
};
struct Queue *Q = NULL;
void enQueue(struct Queue **Qptr, int v)
{
    if (*Qptr == NULL)
    {
        *Qptr = (struct Queue *)malloc(sizeof(struct Queue));
        (*Qptr)->num = v;
        (*Qptr)->next = NULL;
    }
    else
    {
        struct Queue *Q = *Qptr, *add_Q = NULL;
        while (Q->next != NULL)
            Q = Q->next;
        add_Q = (struct Queue *)malloc(sizeof(struct Queue));
        (add_Q)->num = v;
        (add_Q)->next = NULL;
        Q->next = add_Q;
    }
}
int emptyQ(struct Queue **Qptr)
{
    if (*Qptr == NULL)
        return 1;
    else
        return 0;
}
int deQueue(struct Queue **Qptr)
{
    int v = (*Qptr)->num;
    (*Qptr) = (*Qptr)->next;
    return v;
}

ELink *insertEdge(ELink *head, int avex)
{
    ELink *e, *p;
    e = (ELink *)malloc(sizeof(ELink));
    e->adj = avex;
    e->wei = 1;
    e->next = NULL;
    if (head == NULL)
    {
        head = e;
        return head;
    }
    for (p = head; p->next != NULL && p->next->adj < avex; p = p->next)
        ;
    e->next = p->next;
    p->next = e;
    return head;
}

int createGraph(VLink graph[])
{
    int i, m, n, v1, v2;
    scanf("%d %d", &m, &n);
    for(int k = 0;k < m;k++){
        ELink *e;
        e = (ELink *)malloc(sizeof(ELink));
        e->adj = k;
        e->wei = 1;
        e->next = NULL;
        graph[k].link = e;
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &v1, &v2);
        graph[v1].link = insertEdge(graph[v1].link, v2);
        graph[v2].link = insertEdge(graph[v2].link, v1);
    }
    return m;
}
void VISIT(VLink *graph, int v)
{
    printf("%d ", graph[v].link->adj);
}

void DFS(VLink G[], int v)
{
    ELink *p;
    Visited[v] = 1; // 标识某顶点被访问过
    VISIT(G, v);    // 访问某顶点
    for (p = G[v].link; p != NULL; p = p->next)
        if (!Visited[p->adj])
            DFS(G, p->adj);
}
void travelDFS(VLink G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            DFS(G, i);
}
void travelDFS_1(VLink G[], int n, int D)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    Visited[D] = 1;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            DFS(G, i);
}

void BFS(VLink G[], int v)
{
    ELink *p;
    VISIT(G, v);    // 访问当前顶点
    Visited[v] = 1; // 标识某顶点被访问过
    enQueue(&Q, v); // 入口的第一个顶点入队
    while (!emptyQ(&Q))
    {                                  //  循环，直到队空为止
        v = deQueue(&Q);               // 取出队头元素
        p = G[v].link;                 // 获取该顶点第一个邻接顶点
        for (; p != NULL; p = p->next) // 访问该顶点下的每个邻接顶点
            if (!Visited[p->adj])
            {
                VISIT(G, p->adj);    // 访问当前顶点
                Visited[p->adj] = 1; // 标识某顶点被访问过
                enQueue(&Q, p->adj); // 邻接顶点依次分别入队
            }
    }
}

void travelBFS(VLink G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            BFS(G, i);
}
void travelBFS_1(VLink G[], int n, int D)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    Visited[D] = 1;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            BFS(G, i);
}

int main()
{
    int m = createGraph(G);
    // for (int i = 0; i < m; i++)
    // {
    //     ELink *e = G[i].link;
    //     while (e != NULL)
    //     {
    //         printf("%d ", e->adj);
    //         e = e->next;
    //     }
    //     printf("\n");
    // }
    int D = 0;
    scanf("%d", &D);
    travelDFS(G, m);
    printf("\n");
    travelBFS(G, m);
    printf("\n");
    travelDFS_1(G, m, D);
    printf("\n");
    travelBFS_1(G, m, D);
    return 0;
}
