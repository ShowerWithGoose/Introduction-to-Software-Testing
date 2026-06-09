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

Vnode G[20000]; // @@ [Global array size is unnecessarily large and inconsistent with problem constraints (n <= 100), but not a direct cause of compilation error. However, the real issue is missing initialization of G[].next to NULL which leads to undefined behavior during traversal.]
int Visited[100]; // @@ [Size is too small: problem states n can be up to 100, so indices 0..99 are used, but if n=100, Visited[99] is last; however, in travelDFS/BFS loops go to i < n, so for n=100, i=99 is okay. But note: in main, N can be up to 100, so Visited[100] would be out of bounds if accessed. Should be at least size 101 or 256 to match MaxV.]

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
    if(head ->next == NULL)
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
    for (p = head; p->next != NULL; p = p->next)
    {
        if(p->next->adj > avex)
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
        printf("v1:%d v2:%d\n",v1,v2); // @@ [Debug print statement that should not be in final output; causes mismatch with expected output format, but not a compilation error. However, the actual compilation error is likely due to missing initialization of G[].next before use in insertEdge.]
        G[v1].next = insertEdge(G[v1].next, v2); // @@ [G[v1].next is used uninitialized. Global arrays are zero-initialized in C, so this may actually be safe (since static storage duration => initialized to 0/NULL). So this might not be the issue.]
        G[v2].next = insertEdge(G[v2].next, v1);
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
    printf("%d ", v);
    Visited[v] = 1;
    Que[head] = v;
    while (head <= tail) // @@ [Incorrect loop condition: should be 'head < tail' because tail points to next empty slot. Using 'head <= tail' may access uninitialized elements beyond valid queue entries, leading to undefined behavior. Also, queue size is fixed to 100, but n can be up to 100, so it's borderline safe, but logic error in condition.]
    {
        v = Que[head++]; // 取出队头元素
        p = G[v].next;  // 获取该顶点第一个邻接顶点
        // 访问该顶点下的每个邻接顶点
        for (; p != NULL; p = p->next)
            if (!Visited[p->adj])
            {
                printf("%d ", p->adj);
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
    printf("%d %d\n",N,E); // @@ [Extra debug output not in expected format; will cause output mismatch, but not compilation error.]
    for(int i = 0 ; i < N;i++) // @@ [Debug printing of adjacency list; not part of required output, causes failure in test cases expecting only traversal sequences.]
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
    /*travelDFS(G , N);
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