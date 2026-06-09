#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include <ctype.h>
typedef struct edge
{
    int adj;
    struct edge *next;
}Edge,*Elink;
typedef struct ver
{
    Elink first;
}Ver;
Ver G[105];
int visited[105]={0},flag[105]={0};
int queue[105];
int front=0,rear=-1,count=0;
void enqueue(int queue[],int v)
{
    rear=rear+1;
    queue[rear]=v;
    count++;
}
int dequeue(int queue[])
{
    int e;
    e=queue[front];
    count--;
    front=front+1;
    return e;
}

Elink insertEdge(Elink head,int adj)
{
    Elink e,p,q;
    e=(Elink)malloc(sizeof(Edge));
    e->adj=adj;
    e->next=NULL;
    if(head->next==NULL)
    {
        head->next=p=e;
        return head;
    }
    for(q=head,p=head->next;p!=NULL;q=p,p=p->next)
    {
        if(e->adj<p->adj)
        {
            q->next=e;
            e->next=p;
            return head;
        }
    }
    q->next=e;
    return head;
}

void DFS(Ver G[],int v,int del)
{
    Elink p;
    visited[v]=1;
    visited[del]=1;
    printf("%d ",v);
    for(p=G[v].first->next;p!=NULL;p=p->next)
    {
        if(!visited[p->adj])
            DFS(G,p->adj,del);
    }
}
void travelDFS(Ver G[],int n,int del)
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
            DFS(G,i,del);
    }
}

void BFS(Ver G[],int v,int del)
{
    Elink p;
    flag[v]=1;
    flag[del]=1;
    enqueue(queue,v);
    while(count!=0)
    {
        v=dequeue(queue);
        printf("%d ",v);
        for(p=G[v].first->next;p!=NULL;p=p->next)
        {
            if(!flag[p->adj])
            {
                flag[p->adj]=1;
                enqueue(queue,p->adj);
            }
        }
    }
}
void travelBFS(Ver G[],int n,int del)
{
    int i;
    for(i=0;i<n;i++)
        flag[i]=0;
        flag[del]=1;
    for(i=0;i<n;i++)
    {
        if(!flag[i])
            BFS(G,i,del);
    }
}

int main()
{
    int Vnum,Enum,i,del;
    scanf("%d%d",&Vnum,&Enum);
    int v1,v2;
    for(i=0;i<Vnum;i++)
    {
        G[i].first=(Elink)malloc(sizeof(Edge));
        G[i].first->next=NULL;
    }
    for(i=0;i<Enum;i++)
    {
        scanf("%d%d",&v1,&v2);
        G[v1].first=insertEdge(G[v1].first,v2);
        G[v2].first=insertEdge(G[v2].first,v1);
    }
    scanf("%d",&del);
    travelDFS(G,Vnum,101);
    printf("\n");
    travelBFS(G,Vnum,101);
    printf("\n");
    travelDFS(G,Vnum,del);
    printf("\n");
    travelBFS(G,Vnum,del);
    printf("\n");
    return 0;
}

