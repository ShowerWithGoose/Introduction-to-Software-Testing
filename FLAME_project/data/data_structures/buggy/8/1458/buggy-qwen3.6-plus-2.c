#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MaxV 100
#define MaxE 512

typedef struct edge
{
    int adj;
    int wei;
    struct edge *next;
} ELink;
typedef struct ver
{
    ELink *link;
} VLink;

VLink G[MaxV];
int Q[MaxE];
int Front,Rear,Count;
int n_V;
int num;//要被删除的顶点编号
    
ELink *insertEdge(ELink *head, int avex);
void createGraph(VLink graph[]);
int Visited_D[MaxV]; //标识顶点是否被访问过
int Visited_B[MaxV];
void travelDFS(VLink G[], int n);
void DFS(VLink G[], int v);
void travelBFS(VLink G[], int n);
void BFS(VLink G[], int v);
void initQueue();
int isEmpty();
int isFull();
void enQueue(int);
int deQueue();

int main()
{
    int i;
    ELink *p;
    
    scanf("%d",&n_V);
    createGraph(G);
    scanf("%d",&num);
    
    travelDFS(G,n_V);
    printf("\n");
    initQueue();
    travelBFS(G,n_V);
    //删除编号为num的结点
    for(i=0;G[i].link->adj!=-1;i++) // @@ The loop condition G[i].link->adj!=-1 is incorrect. It assumes every vertex has a sentinel node with adj=-1, but more importantly, it fails to handle vertices that might become isolated or have NULL links correctly after deletion logic or if the sentinel wasn't added properly. Also, iterating up to n_V is safer. The sentinel approach in createGraph is non-standard and error-prone.
    {
        for(p=G[i].link;p->next!=NULL;p=p->next)
        {
            if(G[i].link->adj==num)
            {
                G[i].link=G[i].link->next;
                break;
            }
            else if(p->next->adj==num)
            {
                p->next=p->next->next;
                break;
            }
        }
        if(i==num)
            G[i].link=NULL;
    }
    printf("\n");
    travelDFS(G,n_V);
    printf("\n");
    initQueue();
    travelBFS(G,n_V);
    return 0;
}
ELink *insertEdge(ELink *head, int avex)//在链表尾插入一个节点
{
    ELink *e,*p;
    int flag=0;
    p=head;
    e=(ELink *)malloc(sizeof(ELink));
    e->adj=avex;
    e->wei=1;
    e->next=NULL;
    if(head == NULL)
    {
        head=e;
        return head;
    }
    if(head->adj>e->adj)
    {
        e->next=head->next; // @@ Logic error: If inserting before head, e->next should be head, not head->next. This loses the rest of the list or creates a cycle/incorrect structure.
        head->next=e; // @@ Logic error: Should update head to e. Here it keeps old head and appends e after it, but e->next was set to head->next. This effectively inserts e as the second node, not the first, violating sorted order if e < head.
        flag=1;
    }
    else
        for(p=head; p->next != NULL; p=p->next)
        {
            if(p->next->adj>e->adj)
            {
                e->next=p->next;
                p->next=e;
                flag=1;
                break;
            }
        }
    if(flag==0)
        p->next = e;
    return head;
}
void createGraph(VLink G[])
{
    int i,n,v1,v2;
    int n_W;

    scanf("%d",&n_W);
    for(i=0; i<n_W; i++)
    {
        scanf("%d%d",&v1,&v2);
        G[v1].link=insertEdge(G[v1].link, v2);
        G[v2].link=insertEdge(G[v2].link, v1);
    }
    G[n_V].link=insertEdge(G[n_V].link, -1); // @@ Error: Accessing G[n_V] is out of bounds if vertices are 0 to n_V-1. Also, adding a sentinel -1 node is problematic for traversal logic which expects valid vertex indices or NULL termination. It complicates deletion and traversal.
}
void travelDFS(VLink G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        Visited_D[i] = 0;
    for (i = 0; i < n; i++)
        if (!Visited_D[i])
            DFS(G, i);
}
void DFS(VLink G[], int v)
{
    ELink *p;
    Visited_D[v] = 1; //标识某顶点被访问过
    //访问某顶点
    if(G[v].link!=NULL) // @@ Incorrect check. A vertex might exist (be part of the graph) but have no edges (isolated, though problem says connected, after deletion it might be isolated if it was leaf? No, problem says graph remains connected). However, the main issue is that we should print the vertex if it's visited, regardless of whether it has edges, unless it's the deleted vertex. The deleted vertex handling is missing here.
        printf("%d ",v);
    for (p = G[v].link; p != NULL; p = p->next)
        if (!Visited_D[p->adj])
            DFS(G, p->adj);
}
void travelBFS(VLink G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        Visited_B[i] = 0;
    for (i = 0; i < n; i++)
        if (!Visited_B[i])
            BFS(G, i);
}
void BFS(VLink G[], int v)
{
    ELink *p;
    //访问当前顶点
    Visited_B[v] = 1; //标识某顶点被访问过
    if(G[v].link!=NULL) // @@ Same issue as DFS. Should check if vertex is valid/not deleted.
        printf("%d ",v);
    enQueue(v);
    while (!isEmpty())
    {
        v = deQueue(); //取出队头元素
        p = G[v].link; //获取该顶点第一个邻接顶点
//访问该顶点下的每个邻接顶点
        for (; p != NULL; p = p->next)
            if (!Visited_B[p->adj])
            {
                Visited_B[p->adj] = 1; //标识某顶点被访问过
                printf("%d ",p->adj);
                enQueue(p->adj);
            }
    }
}
void initQueue()
{
    Front=0;
    Rear=MaxE-1;
    Count=0;
}
int isEmpty()
{
    return Count==0;
}
int isFull()
{
    return Count==MaxE;
}
void enQueue(int a)
{
    if (isFull()) // 队满，插入失败
        printf("Full queue !");
    else
    {
        Rear=(Rear+1)%MaxE;
        Q[Rear]=a;
        Count++; // 队未满，插入成功
    }
}
int deQueue()
{
    if (isEmpty())
        printf("Empty queue !"); // 队空，删除失败
    else
    {
        Count--; // 队非空，删除成功
        Front=(Front+1)%MaxE;
        return     Q[Front-1]; // @@ Error: When Front becomes 0 after incrementing from MaxE-1 (due to modulo), Front-1 becomes -1, accessing invalid memory. Correct way is to store value before incrementing or use (Front-1+MaxE)%MaxE.
    }
}