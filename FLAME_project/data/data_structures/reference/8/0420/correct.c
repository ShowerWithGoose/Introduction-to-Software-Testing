#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct edge
{
    int adjvex;
    struct edge *link;
};
struct ver
{
    int vertex;
    struct edge *list;
}G[100];

int visit[100]={0};
void Visit(struct ver G[],int v)
{
    printf("%d ",G[v].vertex);
}
void travelDFS(struct ver G[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(!visit[i])
        {
            DFS(G,i);
        }
    }
}
void DFS(struct ver G[],int v)
{
    struct edge *p;
    visit[v]=1;
    Visit(G,v);
    for(p=G[v].list;p!=NULL;p=p->link)
    {
        if(!visit[p->adjvex])
        {
            DFS(G,p->adjvex);
        }
    }
}

struct node
{
    int data;
    struct node *next;
};
struct node *front,*rear;
void initiaQueue()
{
    front=NULL;
    rear=NULL;
}
int isEmpty()
{
    return front==NULL;
}
void enLQueue(int item)
{
    struct node* p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=item;
    p->next=NULL;
    if(front==NULL)
    {
        front=p;
    }
    else
    {
        rear->next=p;
    }
    rear=p;
}
int deLQueue()
{
    struct node* p;
    int item;
    p=front;
    front=front->next;
    item=p->data;
    return item;
}
void travelBFS(struct ver G[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(!visit[i])
        {
            BFS(G,i);
        }
    }
}
void BFS(struct ver G[],int v)
{
    struct edge *p;
    visit[v]=1;
    enLQueue(v);
    while(!isEmpty())
    {
        v=deLQueue();
        Visit(G,v);
        p=G[v].list;
        for(;p!=NULL;p=p->link)
        {
            if(!visit[p->adjvex])
            {
                visit[p->adjvex]=1;
                enLQueue(p->adjvex);
            }
        }
    }
}
struct edge* insertlist(struct edge *list,int v)
{
    struct edge *p,*q,*r;
    p=(struct edge *)malloc(sizeof(struct edge));
    p->adjvex=v;
    p->link=NULL;
    if(list==NULL)
    {
        list=p;
    }
    else
    {
        r=list;
        for(q=list;q!=NULL;q=q->link)
        {
            if((q->adjvex)>(p->adjvex))
            {
                break;
            }
            r=q;
        }
        if(q!=list)
        {
            r->link=p;
            p->link=q;
        }
        else
        {
            p->link=list;
            list=p;
        }
    }
    return list;
}

int main()
{
    int n,L,a,b,c;
    int i;
    scanf("%d %d",&n,&L);
    for(i=0;i<n;i++)
    {
        G[i].vertex=i;
        G[i].list=NULL;
    }
    for(i=0;i<L;i++)
    {
        scanf("%d %d",&a,&b);
        G[a].list=insertlist(G[a].list,b);
        G[b].list=insertlist(G[b].list,a);
    }
    scanf("%d",&c);
    travelDFS(G,n);
    for(i=0;i<n;i++)
    {
        visit[i]=0;
    }
    printf("\n");
    travelBFS(G,n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        visit[i]=0;
    }
    visit[c]=1;
    travelDFS(G,n);
    for(i=0;i<n;i++)
    {
        visit[i]=0;
    }
    visit[c]=1;
    printf("\n");
    travelBFS(G,n);
    return 0;
}

