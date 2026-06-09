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
    
    scanf("%d",&n_V); // @@ [The program reads only n_V (number of vertices) but not the number of edges m. According to input format, it should read "n m" on the first line.]
    createGraph(G);
    scanf("%d",&num);
    
    travelDFS(G,n_V);
    printf("\n");
    initQueue();
    travelBFS(G,n_V);
    //删除编号为num的结点
    for(i=0;G[i].link->adj!=-1;i++) // @@ [This loop condition assumes that every vertex's adjacency list ends with a node having adj == -1, but this sentinel node is only added for vertex n_V (which is out of valid range [0, n_V-1]). Accessing G[i].link when G[i].link is NULL leads to undefined behavior. Also, the deletion logic is flawed and does not correctly remove all edges to 'num'.]
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
        e->next=head->next; // @@ [This incorrectly inserts 'e' after head instead of before. It should be: e->next = head; return e; to insert at front. This breaks ascending order insertion.]
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

    scanf("%d",&n_W); // @@ [This reads the number of edges, but according to input format, the first line already had n and m. However, in main(), only n_V was read, so this tries to read m here. But the problem is that the first scanf in main() only reads one integer, so this works by accident. However, the bigger issue is that the graph creation assumes vertices are from 0 to n_V-1, but then adds a sentinel node at G[n_V], which is out of bounds.]
    for(i=0; i<n_W; i++)
    {
        scanf("%d%d",&v1,&v2);
        G[v1].link=insertEdge(G[v1].link, v2);
        G[v2].link=insertEdge(G[v2].link, v1);
    }
    G[n_V].link=insertEdge(G[n_V].link, -1); // @@ [n_V is not a valid vertex (vertices are 0 to n_V-1). Writing to G[n_V] is out-of-bounds access (buffer overflow), since G is defined as G[MaxV] and n_V <= 100, but MaxV=100, so G[100] is invalid (index 0..99). Also, inserting -1 as a sentinel is unnecessary and causes issues in traversal and deletion.]
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
    if(G[v].link!=NULL)
        printf("%d ",v); // @@ [Vertex 0 must always be printed even if it has no neighbors (but graph is connected, so this may not occur). However, more critically, when a vertex is deleted by setting its adjacency list to NULL, this skips printing it. But in the "before deletion" phase, all vertices should be printed. The real issue is that during "after deletion", the deleted vertex should not appear, but the current deletion method (setting G[num].link=NULL) causes this condition to skip printing it — which is correct. However, the bigger flaw is that the deletion is done physically, but the traversal still iterates over all vertices including the deleted one, and if G[v].link is NULL, it won't print v. But according to problem, the deleted vertex should not appear in the output. However, the traversal starts from 0 and the graph remains connected, so if the deleted vertex is isolated by NULLing its list, but other vertices still have edges to it, then those edges were not properly removed — leading to attempts to visit the deleted vertex. But in this code, during traversal, if we reach a neighbor pointing to 'num', and 'num' hasn't been visited, we will call DFS/BFS on it. However, in DFS, if G[num].link is NULL, it will print num (because G[num].link != NULL is false, so it skips printf, but wait: the printf is inside if(G[v].link!=NULL). So if a vertex has no neighbors (like deleted vertex), it won't be printed. But the deleted vertex should never be traversed because edges to it should be removed. However, the deletion logic is incomplete — it doesn't remove all occurrences of 'num' from adjacency lists, so during traversal, we might still try to go to 'num', and then in DFS(num), since G[num].link is NULL, it won't print anything, but Visited_D[num] is set to 1, so it's silently skipped. This leads to missing output or incorrect sequences. But the core error is the flawed deletion and the sentinel node.]
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
    if(G[v].link!=NULL)
        printf("%d ",v); // @@ [Same issue as in DFS: if a vertex has no neighbors (like deleted vertex), it won't be printed. But during "before deletion", all vertices have neighbors (graph connected), so it's okay. But during "after deletion", the deleted vertex should not be printed, and if it's reached via an uncleared edge, it won't print, but the traversal logic is broken because the queue operations are also flawed (see deQueue).]
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
                printf("%d ",p->adj); // @@ [This prints the neighbor immediately upon discovery, but standard BFS prints when dequeuing. This changes the order. The reference program prints when dequeuing. This causes incorrect BFS sequence.]
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
        return     Q[Front-1]; // @@ [After incrementing Front, the element to return is Q[Front-1] only if Front was incremented modulo MaxE. But if Front was MaxE-1, then (Front+1)%MaxE = 0, and Q[-1] is accessed? No: Front starts at 0. Initially, Rear = MaxE-1. First enqueue: Rear becomes 0, Q[0]=item. Then deQueue: Front becomes (0+1)%MaxE=1, returns Q[0] — correct. But the logic is unconventional. However, the real issue is that in BFS, the starting vertex is printed before enqueuing, then dequeued and its neighbors processed. But the printing of neighbors happens when they are discovered, not when dequeued, which is non-standard and leads to wrong order.]
    }
}