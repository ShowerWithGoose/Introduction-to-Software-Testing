
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
        return head;
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

    system("pause");
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

int isEmpty(int Q[])
{
    return count == 0;
}

void enQueue(int Q[],int item)
{
    Q[rear++] = item;
    count++;
}

int pushQueue(int Q[])
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
