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
        return e; // @@ [The original code returned 'head' here, but it should return 'e' because 'e' is the new head when inserting at the front. Returning 'head' causes the new node to be lost, breaking the sorted insertion logic.]
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

    system("pause"); // @@ [The function 'system("pause")' is non-standard and may not be available on all systems (e.g., Linux), which can cause compilation or runtime issues. It should be removed for portability.]

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

int isEmpty(int Q[]) // @@ [The parameter 'Q[]' is unused in the function body. The function uses the global 'count' variable, so the parameter is unnecessary and misleading. However, this does not cause a compilation error but is poor practice. The real issue is in BFS queue handling.]
{
    return count == 0;
}

void enQueue(int Q[],int item) // @@ [This function uses the global 'rear' and 'count' but takes 'Q[]' as a parameter, which is inconsistent. Since Q is global, passing it is redundant and confusing. But more critically, the queue implementation uses global variables, yet the function signature suggests it operates on a passed array, leading to potential confusion but not direct compilation error.]
{
    Q[rear++] = item;
    count++;
}

int pushQueue(int Q[]) // @@ [Same issue as enQueue: takes Q[] as parameter but uses global 'front' and 'count'. Also, the function name 'pushQueue' is misleading for a dequeue operation. However, the critical bug is that in BFS, the node is printed AFTER dequeuing, but the traversal must start from 0 and print upon first visit. This leads to wrong order if multiple components exist, but problem states graph is connected. Still, the bigger issue is that the BFS prints the dequeued node, which is correct, but the queue functions are misdesigned with unnecessary parameters. However, the actual functional error is elsewhere.]
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
        printf("%d ",n); // @@ [The node is printed when dequeued, which is standard for BFS. However, the issue is that the BFS function is called for every unvisited node in travelBFS, but the problem states the graph is connected, so this loop runs only once. So this is likely correct. The real errors are in insertEdge and system("pause").]
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