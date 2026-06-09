#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))
#define M 1005
typedef int vertype;

//边结点
typedef struct edge {
    int adj;
    int wei;
    struct edge* link;
}ELink, * ELinkptr;

//头结点
typedef struct ver {
    vertype vertex;
    ELink* link;
}VLink, * VLinkptr;

VLink  graph[M];
int Visited[M];
int Front, Rear, Count;
int queue[M];

void createGraph(VLink graph[]);
ELinkptr insertEdge(ELink* head, int avex);
void travelDFS(VLink G[], int n);
void DFS(VLink G[], int v);
void travelBFS(VLink G[], int n);
void BFS(VLink G[], int v);
void VISIT(VLink G[], int v);
int deQueue(int queue[]);
void enQueue(int queue[], int v);
int isFull();
int isEmpty();
void init();

int main()
{
    int n, m, x;
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= m; i++)
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        graph[v1].link = insertEdge(graph[v1].link, v2);
        graph[v2].link = insertEdge(graph[v2].link, v1);
    }
    scanf("%d", &x);

    for (int i = 0; i < n; i++)
        Visited[i] = 0;
    travelDFS(graph, n);
    printf("\n");

    for (int i = 0; i < n; i++)
        Visited[i] = 0;
    travelBFS(graph, n);
    printf("\n");

    for (int i = 0; i < n; i++)
        Visited[i] = 0;
    Visited[x] = 1;
    travelDFS(graph, n);
    printf("\n");

    for (int i = 0; i < n; i++)
        Visited[i] = 0;
    Visited[x] = 1;
    travelBFS(graph, n);
    printf("\n");
}

void createGraph(VLink graph[])
{
    int i, n, v1, v2;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &v1, &v2);
        while (v2 != -1) {
            graph[v1].link = insertEdge(graph[v1].link, v2);
            graph[v2].link = insertEdge(graph[v2].link, v1);
            scanf("%d", &v2);
        }
    }
}

//在链表尾插入一个节点
ELinkptr insertEdge(ELink* head, int avex)
{
    ELink* e, * p;
    e = (ELink*)malloc(sizeof(ELink));
    e->adj = avex; e->wei = 1; e->link = NULL;
    if (head == NULL)
        return head = e;
    if (avex < head->adj)
    {
        //e->link = head;
        //return e;
    } // @@ The logic for inserting at the head when avex < head->adj is missing. The code falls through to the general insertion logic, which incorrectly appends or inserts in the middle, breaking the ascending order requirement for adjacency lists.

    for (p = head; p->link != NULL && avex > p->link->adj; p = p->link);

    e->link = p->link;
    p->link = e;
    return head;
}

void travelDFS(VLink G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            DFS(G, i);
}
void DFS(VLink G[], int v)
{
    ELink* p;
    Visited[v] = 1; //标识某顶点被访问过
    VISIT(G, v); //访问某顶点
    for (p = G[v].link; p != NULL; p = p->link)
        if (!Visited[p->adj])
            DFS(G, p->adj);
}


void travelBFS(VLink G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            BFS(G, i);
}
void BFS(VLink G[], int v)
{
    ELink* p;
    VISIT(G, v); //访问当前顶点
    Visited[v] = 1; //标识某顶点被访问过
    enQueue(queue, v);
    while (!isEmpty()) 
    {
        v = deQueue(queue); //取出队头元素
        p = G[v].link; //获取该顶点第一个邻接顶点
        //访问该顶点下的每个邻接顶点
        for (; p != NULL; p = p->link)
            if (!Visited[p->adj])
            {
                VISIT(G, p->adj); //访问当前顶点
                Visited[p->adj] = 1; //标识某顶点被访问过
                enQueue(queue, p->adj);
            }
    }
}

void VISIT(VLink G[], int v)
{
    printf("%d ", v);
}

//初始化
void init()
{
    Front = 0;
    Rear = M  - 1;
    Count = 0;
}

//判断队列是否为空
int isEmpty()
{
    return Count == 0;
}

//判断队列是否已满
int isFull()
{
    return Count == M ;
}

//入队
void enQueue(int queue[], int v)
{
    if (isFull()) // 队满，插入失败
        printf("Full queue !");
    else
    {
        Rear = (Rear + 1) % (M);
        queue[Rear] = v;
        Count++; // 队未满，插入成功
    }
}

//出队
int deQueue(int queue[])
{
    int e;
    if (isEmpty())
        printf("Empty queue !"); // 队空，删除失败
    else
    {
        e = queue[Front];
        Count--; // 队非空，删除成功
        Front = (Front + 1) % (M );
        return e;
    }
}