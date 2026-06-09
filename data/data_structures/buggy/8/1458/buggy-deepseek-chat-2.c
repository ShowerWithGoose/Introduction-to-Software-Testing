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
    for(i=0;G[i].link->adj!=-1;i++) // @@ [Error: This loop assumes all vertices have a link, but G[i].link may be NULL for vertices with no edges, causing a segmentation fault. Also, the condition G[i].link->adj!=-1 is incorrect because the sentinel -1 is only added for vertex n_V, not all vertices.]
    {
        for(p=G[i].link;p->next!=NULL;p=p->next) // @@ [Error: If G[i].link is NULL, this loop will crash. Also, the logic for deleting edges is flawed; it only checks the first edge and then subsequent edges, but the inner loop may skip edges incorrectly.]
        {
            if(G[i].link->adj==num) // @@ [Error: This condition only checks the first edge of each vertex, but the loop is iterating through all edges. It should check p->adj instead of G[i].link->adj.]
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
    if(head->adj>e->adj) // @@ [Error: This insertion logic is incorrect. It attempts to insert before the head but incorrectly sets e->next=head->next instead of e->next=head, and then sets head->next=e, which corrupts the list. The correct approach for sorted insertion should handle the head case properly.]
    {
        e->next=head->next;
        head->next=e;
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
    G[n_V].link=insertEdge(G[n_V].link, -1); // @@ [Error: Adding a sentinel -1 to vertex n_V is unnecessary and incorrect. The problem does not require sentinels, and this can cause issues in traversal and deletion logic.]
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
    if(G[v].link!=NULL) // @@ [Error: This condition skips printing vertex v if its link is NULL (i.e., isolated vertex after deletion). However, the problem requires printing all vertices in traversal order, even if they have no edges. The condition should be removed or adjusted.]
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
    if(G[v].link!=NULL) // @@ [Error: Same issue as in DFS; this condition may skip printing isolated vertices.]
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
        return     Q[Front-1]; // @@ [Error: The return value should be Q[Front] after incrementing Front, but here it returns Q[Front-1] which is the previous element. The correct order is: e = Q[Front]; Front = (Front+1)%MaxE; return e;]
    }
}