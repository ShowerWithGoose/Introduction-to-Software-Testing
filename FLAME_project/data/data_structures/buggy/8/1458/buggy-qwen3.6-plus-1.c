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
    for(i=0;i<n_V;i++) // @@ The loop condition `G[i].link->adj!=-1` is incorrect and dangerous. It should iterate through all vertices `0` to `n_V-1`. Also, the logic inside assumes a specific structure that might not hold if the list is empty or modified.
    {
        // Remove edges pointing to 'num' from adjacency lists of other vertices
        if (i == num) {
            G[i].link = NULL; // @@ Vertex 'num' itself should have its adjacency list cleared (effectively deleted). The original code only did this if `i==num` inside the loop, but the loop condition was flawed.
            continue;
        }
        
        ELink *curr = G[i].link;
        ELink *prev = NULL;
        while (curr != NULL) {
            if (curr->adj == num) {
                if (prev == NULL) {
                    G[i].link = curr->next;
                    free(curr);
                    curr = G[i].link;
                } else {
                    prev->next = curr->next;
                    free(curr);
                    curr = prev->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
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
        e->next=head; // @@ Incorrect insertion logic. If new node is smaller than head, it should become the new head. Original: `e->next=head->next; head->next=e;` which inserts after head.
        head=e;
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
    // G[n_V].link=insertEdge(G[n_V].link, -1); // @@ This line is unnecessary and potentially harmful as it accesses index n_V which is out of bounds for valid vertices 0..n_V-1, or adds a sentinel that complicates traversal. Standard adjacency lists don't need this if NULL termination is used.
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
    if(G[v].link!=NULL || v == num) // @@ Logic check: usually we print if visited. The condition `G[v].link!=NULL` prevents printing isolated vertices or deleted vertices if their link is NULL. However, if a vertex is deleted, we shouldn't traverse it. The main issue in BFS/DFS output format is usually trailing spaces or missing vertices.
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
    if(G[v].link!=NULL || v == num) // @@ Similar to DFS, ensure correct printing condition.
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
        return     Q[Front-1]; // @@ Error in circular queue dequeue. If Front becomes 0 after increment, Front-1 is -1. Should return Q[(Front-1+MaxE)%MaxE] or store value before incrementing.
    }
}