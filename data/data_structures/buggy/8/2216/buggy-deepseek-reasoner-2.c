#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxV 256
struct edge{ 
    int adj;
    struct edge *next;
};
typedef struct edge ELink;
typedef struct ver
{
    ELink *next; 
} Vnode, *Vnodep;

Vnode G[20000];
int Visited[100];

ELink* insertEdge(ELink *head, int avex)
{
    ELink *e, *p;
    e = (ELink *)malloc(sizeof(ELink));
    e->adj = avex;
    e->next = NULL;
    if (head == NULL)
    {
        head = e;
        return head;
    }
    if(head ->next == NULL)                  // @@ The insertion logic is flawed; it does not maintain ascending order properly.
    {
        if(head->adj > avex)
        {
            e->next = head;
            return e;
        }
        else
        {
            head->next = e;
            return head;
        }
    }
    for (p = head; p->next != NULL; p = p->next)  // @@ This loop only checks the next node's adj, but misses the case where avex should be inserted before head (when head->adj > avex and list has >1 nodes).
    {
        if(p->next->adj > avex)                 // @@ Insertion after p (instead of before head) can break the sorted order.
        {
            e->next = p->next;
            p->next = e;
            return head;
        }
    }
    p->next = e;
    return head;
}

void createGraph(Vnode graph[],int edge)
{
    int i, v1, v2;
    for (i = 0; i < edge; i++)
    {
        scanf("%d %d", &v1, &v2);
        printf("v1:%d v2:%d\n",v1,v2);          // @@ Extra debug output not required by the problem; will cause output mismatch.
        G[v1].next = insertEdge(G[v1].next, v2); // @@ Should use graph[v1].next, not the global G. The parameter graph is unused.
        G[v2].next = insertEdge(G[v2].next, v1); // @@ Same error as above.
    }
}

void DFS(Vnode G[], int v)
{
    ELink *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);
    for (p = G[v].next; p != NULL; p = p->next)
        if (!Visited[p->adj])
            DFS(G, p->adj);
}
void travelDFS(Vnode G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            DFS(G, i);
    printf("\n");
}

void BFS(Vnode G[], int v)
{
    int Que[100] = {0},head = 0,tail = 1;
    ELink *p;
    printf("%d ", v);                           // @@ BFS should print vertex when it is dequeued, not before enqueue.
    Visited[v] = 1;
    Que[head] = v;
    while (head <= tail)
    {
        v = Que[head++]; // 取出队头元素
        p = G[v].next;  // 获取该顶点第一个邻接顶点
        // 访问该顶点下的每个邻接顶点
        for (; p != NULL; p = p->next)
            if (!Visited[p->adj])
            {
                printf("%d ", p->adj);          // @@ BFS should print when vertex is dequeued, not when discovered.
                Visited[p->adj] = 1;
                Que[tail++] = p->adj;
            }
    }
}
void travelBFS(Vnode G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            BFS(G, i);
    printf("\n");
}
int main()
{
    int N, E, v_del;
    scanf("%d %d", &N, &E);
    createGraph(G , E);
    printf("%d %d\n",N,E);                      // @@ Extra debug output not required.
    for(int i = 0 ; i < N;i++)                  // @@ The following debug loop prints adjacency lists, which is not part of the required output.
    {
        printf("%d: ",i);
        ELink *p = G[i].next; 
        while(p !=NULL)
        {
            printf("%d ",p->adj);
            p = p->next;
        }
        puts("");
    }
    /*travelDFS(G , N);                          // @@ The required traversal calls are commented out, so the program does not produce any of the required sequences.
    memset(Visited, 0 , sizeof(Visited));

    travelBFS(G , N);
    memset(Visited, 0, sizeof(Visited));

    scanf("%d",&v_del);

    Visited[v_del] = 1;
    travelDFS(G, N);

    memset(Visited, 0, sizeof(Visited));
    Visited[v_del] = 1;
    travelBFS(G, N);*/
    return 0;
}