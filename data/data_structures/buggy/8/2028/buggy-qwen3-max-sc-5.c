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
        return e; // @@ [When inserting at the head, the function should return 'e', not 'head'. Returning 'head' here causes the new node to be lost.]
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

    system("pause"); // @@ [The function 'system' is declared in <stdlib.h>, which is included, but 'system("pause")' is platform-specific and may cause issues in non-Windows environments or online judges. However, this is unlikely to cause a compilation error. The real issue is elsewhere.]

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

int isEmpty(int Q[]) // @@ [The parameter 'Q[]' is unused in the function body. The function uses the global 'count' variable, so the parameter is unnecessary and misleading, but not a compilation error.]
{
    return count == 0;
}

void enQueue(int Q[],int item) // @@ [Same as above: the parameter 'Q[]' is unused because the queue operations use the global array 'Q'. This is logically inconsistent but not a compilation error.]
{
    Q[rear++] = item;
    count++;
}

int pushQueue(int Q[]) // @@ [Same issue: parameter 'Q[]' is unused. Also, the function name 'pushQueue' is misleading for a dequeue operation. However, the real bug is in BFS logic.]
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
    for(int i = 0;i < n;i++)
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
        printf("%d ",n); // @@ [The vertex is printed AFTER dequeuing, which is correct for BFS. However, note that the traversal starts from 'n', which is correct. But the real issue is that the BFS function reinitializes the queue every time it's called, which breaks multi-component traversal. However, the problem states the graph is connected, so this may not be the main issue.]
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