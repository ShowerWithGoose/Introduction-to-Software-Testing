#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000
typedef struct edge
{
    int adj;
    int wei;
    struct edge *next;
} ELink;

typedef struct ver
{
    int vertex;
    ELink *link;
} VLink;
VLink *G[max];
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
    p = head;
    ELink *form;
    while (1)
    {
        if ((p->adj) > avex)
        {
            if (p == head)
            {
                e->next = p;
                return e;
            }
            else
            { 
                e->next = p;
                form->next = e;
                return head;
            }
        }
        else if (p->next == NULL)
        {
            p->next = e;
            return head;
        }
        form = p;
        p = p->next;
    }
}
void createGraph(VLink *graph[], int line)
{

    int v1, v2;

    for (int i = 1; i <= line; i++)
    {
        scanf("%d %d", &v1, &v2);
        getchar();
        graph[v1]->link = insertEdge(graph[v1]->link, v2);
        graph[v2]->link = insertEdge(graph[v2]->link, v1);
    }
}
int Visited[max] = {0}; // 标识顶点是否被访问过，N为顶点数

void DFS(VLink *G[], int v)
{
    ELink *p;
    Visited[v] = 1; // 标识某顶点被访问过
    // VISIT(G, v);
    printf("%d ", v); // 访问某顶点
    for (p = G[v]->link; p != NULL; p = p->next)
        if (Visited[p->adj] == 0)
            DFS(G, p->adj);
}
int Q[10 * max] = {};
int head = 0;
int tail = -1;
void travelDFS(VLink *G[], int n, int del)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    if (del != -1)
    {
        Visited[del] = 1;
    }
    for (i = 0; i < n; i++)
        if (Visited[i] == 0)
            DFS(G, i);
}
void enQueue(int Q[], int v)
{
    tail++;
    Q[tail] = v;
}
int deQueue(int Q[])
{
    head++;
    return Q[head - 1];
}
int emptyQ(void)
{
    if ((tail - head + 1) == 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void BFS(VLink *G[], int v)
{
    ELink *p;
    Visited[v] = 1; // 标识某顶点已入队
    enQueue(Q, v);
    while (emptyQ() != 1)
    {
        v = deQueue(Q); // 取出队头元素
        // VISIT(G, v); //访问当前顶点
        printf("%d ", v);
        for (p = G[v]->link; p != NULL; p = p->next) // 访问该顶点的每个邻接顶点
            if (!Visited[p->adj])
            {
                Visited[p->adj] = 1; // 标识某顶点入队
                enQueue(Q, p->adj);
            }
    }
}
// 标识顶点是否被访问，N为顶点数
void travelBFS(VLink *G[], int n, int del)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    if (del != -1)
    {
        Visited[del] = 1;
    }
    for (i = 0; i < n; i++)
        if (!Visited[i])
            BFS(G, i);
}

int main()
{
    int note, line;
    scanf("%d %d", &note, &line);
    getchar();
    for (int i = 0; i < line; i++)
    {
        G[i] = (VLink *)malloc(sizeof(VLink));
        G[i]->link = NULL;
        G[i]->vertex = i;
    }

    createGraph(G, line);
    travelDFS(G, note, -1);
    printf("\n");
    travelBFS(G, note, -1);
    printf("\n");
    int del;
    scanf("%d", &del);
    travelDFS(G, note, del);
    printf("\n");
    travelBFS(G, note, del);
    printf("\n");
    // for (int i = 0; i < note; i++)
    // {
    //     ELink *p;
    //     for (p = G[i]->link; p != NULL; p = p->next)
    //     {
    //         printf("%d ", p->adj);
    //     }
    //     printf("\n");
    // }
    return 0;
}

