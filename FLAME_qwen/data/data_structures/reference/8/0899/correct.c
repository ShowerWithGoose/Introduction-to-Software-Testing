#include <stdio.h>
#include <stdlib.h>
int point,edgenum,deletepoint;
int visited[150];
typedef struct edge
{
    int adj;
    int wei;
    struct edge *next;
}Elink;
typedef struct ver
{
    Elink *link;
}Vlink;
Vlink G[150];
Elink *insertEdge(Elink *head,int avex)
{
    Elink *e,*p,*q=NULL;
    e=(Elink *)malloc(sizeof(Elink));
    e->adj=avex;
    e->wei=1;
    e->next=NULL;
    if(head==NULL)
    {
        head = e;
        return head;
    }
    for(p=head;p!=NULL&&avex>p->adj;q=p,p=p->next);
    if(p==head)
    {
        e->next=p;
        return e;
    }
    else
    {
        q->next=e;
        e->next=p;
        return head;
    }
}
void DFS(Vlink *G,int i)
{
    Elink *p;
    visited[i]=1;
    printf("%d ",i);
    for(p=G[i].link;p!=NULL;p=p->next)
    {
        if(!visited[p->adj])
        {
            DFS(G,p->adj);
        }
    }
}
void travelDFS(Vlink *G,int n,int del)
{
    int i;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    visited[del]=1;
    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            DFS(G,i);
        }
    }
}
int queue[150];
int front=0,rear=-1,count=0;
void enQueue(int *queue,int num)
{
    rear=(rear+1)%150;
    queue[rear]=num;
    count++;
}
int deQueue(int *queue)
{
    int e;
    e=queue[front];
    count--;
    front=(front+1)%150;
    return e;
}
void BFS(Vlink *G,int i)
{
    Elink *p;
    printf("%d ",i);
    visited[i]=1;
    enQueue(queue,i);
    while(count)
    {
        i=deQueue(queue);
        p=G[i].link;
        for(;p!=NULL;p=p->next)
        {
            if(!visited[p->adj])
            {
                printf("%d ",p->adj);
                visited[p->adj]=1;
                enQueue(queue,p->adj);
            }
        }
    }
}
void travelBFS(Vlink *G,int n,int del)
{
    int i;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    visited[del]=1;
    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            BFS(G,i);
        }
    }
}
int main(int argc, char const *argv[])
{
    int i=0;
    int v1,v2;
    scanf("%d %d",&point,&edgenum);
    for(i=0;i<edgenum;i++)
    {
        scanf("%d %d",&v1,&v2);
        G[v1].link=insertEdge(G[v1].link,v2);
        G[v2].link=insertEdge(G[v2].link,v1);
    }
    scanf("%d",&deletepoint);
    travelDFS(G,point,149);
    printf("\n");
    travelBFS(G,point,149);
    printf("\n");
    travelDFS(G,point,deletepoint);
    printf("\n");
    travelBFS(G,point,deletepoint);
    printf("\n");
    return 0;
}



