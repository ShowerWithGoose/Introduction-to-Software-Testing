#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct edge{
    int adjvex; 
    int weight;
    struct edge *next;

}Elink;

typedef struct ver{
    int vertex;
    Elink *link;
}Vlink;

Vlink Graph[256] = {0};

Elink *insertEdge(Elink *head,int v)    //升序链表
{
    Elink *e,*p,*q = NULL;
    e = (Elink*)malloc(sizeof(Elink));
    e->adjvex = v;
    e->weight = 1;
    e->next = NULL;
    if(head == NULL)
        return e;
    for(p = head;p != NULL && v > p->adjvex;q = p,p = p->next);
    if(p == head)
    {
        e->next = head;
        return e; // @@ [When inserting at the head, the new node 'e' should be returned as the new head, but the original code returns 'head', which is incorrect. This causes the first element to be skipped in adjacency lists.]
    }
    else
    {
        q->next = e;
        e->next = p;
        return head;
    }
}

void DFS(Vlink Graph[],int n);
void BFS(Vlink Graph[],int n);
void travelDFS(Vlink Graph[],int n,int del);
void travelBFS(Vlink Graph[],int n,int del);
int Visited[1005],del = 0;

int main()
{
    int num_ver,edge_num;
    scanf("%d%d",&num_ver,&edge_num);
    for(int i = 0;i < edge_num;i++)
    {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        Graph[v1].link = insertEdge(Graph[v1].link,v2);
        Graph[v2].link = insertEdge(Graph[v2].link,v1);
    }
    travelDFS(Graph,num_ver,-1);
    travelBFS(Graph,num_ver,-1);
    scanf("%d",&del);
    travelDFS(Graph,num_ver,del);
    travelBFS(Graph,num_ver,del);

    system("pause"); // @@ [The function 'system("pause")' is non-standard and may cause compilation or runtime issues on non-Windows systems. It should be removed for portability.]

    return 0;


}

void DFS(Vlink Graph[],int n)
{
    Elink *p;
    Visited[n] = 1;
    printf("%d ",n);
    for(p = Graph[n].link;p != NULL;p = p->next)
    {
        if(!Visited[p->adjvex])
            DFS(Graph,p->adjvex);
    }
}

void travelDFS(Vlink Graph[],int n,int del)
{
    for(int i = 0;i < n;i++)
        Visited[i] = 0;
    if(del >= 0)
        Visited[del] = 1;
    for(int i = 0; i < n;i++)
    {
        if(!Visited[i])
            DFS(Graph,i);
    }
    printf("\n");
}

/*Breadth First Search*/
int Q[1005];
int front,rear,count;

void initQ()
{
    front = 0;
    rear = 0;
    count = 0;
}

int isEmpty(int Q[]) // @@ [The parameter 'Q[]' is unnecessary since the queue 'Q' is a global array. However, this is not a critical error. The real issue is in BFS traversal order due to queue implementation being correct but traversal starting from every unvisited node instead of only 0.]
{
    return count == 0;
}

void enQueue(int Q[],int item) // @@ [Same as above: passing Q[] is redundant but not breaking. However, note that the BFS logic starts from every unvisited node, violating requirement to start only from vertex 0.]
{
    Q[rear++] = item;
    count++;
}

int pushQueue(int Q[]) // @@ [Function name 'pushQueue' is misleading (should be 'deQueue'), but more importantly, the BFS implementation visits all components, while problem states graph is connected and traversal must start from 0 only.]
{
    int item;
    item = Q[front++];
    count--;
    return item;
}

void travelBFS(Vlink Graph[],int n,int del)
{
    for(int i = 0;i < n;i++)
        Visited[i] = 0;
    if(del >= 0)
        Visited[del] = 1;
    for(int i = 0;i < n;i++) // @@ [This loop causes BFS to run from every unvisited vertex, but the problem requires traversal to start ONLY from vertex 0. Since the graph is connected, only i=0 should be considered.]
    {
        if(!Visited[i])
            BFS(Graph,i);
    }
    printf("\n");
}

void BFS(Vlink Graph[],int n)
{
    Elink *p;
    initQ();
    Visited[n] = 1;
    enQueue(Q,n);
    while(!isEmpty(Q))
    {
        n = pushQueue(Q);
        printf("%d ",n);
        for(p = Graph[n].link;p != NULL;p = p->next)
        {
            if(!Visited[p->adjvex])
            {
                Visited[p->adjvex] = 1;
                enQueue(Q,p->adjvex);
            }
        }
    }
}