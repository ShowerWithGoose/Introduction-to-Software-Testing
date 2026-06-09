#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define maxp 100
int n,k;
int visited[maxp]={0};
typedef struct edge{
  int ep;
  int weight;
  struct edge *next;
}elink;
typedef struct ver{
  int vp;
  struct edge *link;
}vlink;
vlink *g[maxp];
vlink *insertp(vlink *head,int num);
void  trdfs(vlink *G[],int x);
void  dfs(vlink *G[],int v);
void  trbfs(vlink *G[],int x);
void  bfs(vlink *G[],int v);
int q[100];
int front=0,rear=0;
void inqueue(int k);
int dequeue();
int emptyq();
int main()
{
    int lpt,rpt,del;
	scanf("%d%d",&n,&k);
	int i,j;
	for(j=0;j<n;j++)
    {
        g[j]=(vlink *)malloc(sizeof(vlink));
        g[j]->vp=j;
        g[j]->link=NULL;
    }
	for(i=0;i<k;i++)
    {
        scanf("%d%d",&lpt,&rpt);
        g[lpt]=insertp(g[lpt],rpt);
        g[rpt]=insertp(g[rpt],lpt);
    }
    scanf("%d",&del);
	trdfs(g,n);
	printf("\n");
	for(i=0;i<n;i++)
    visited[i]=0;
	trbfs(g,n);
	printf("\n");
	front=0;
	rear=0;
	for(i=0;i<100;i++)
        q[i]=0;
    for(i=0;i<n;i++)
    visited[i]=0;
    visited[del]=1;
    trdfs(g,n);
    printf("\n");
    for(i=0;i<n;i++)
    visited[i]=0;
    visited[del]=1;
    trbfs(g,n);
}
vlink *insertp(vlink *head,int num)
{
    elink *p,*t,*r;
    p=(elink *)malloc(sizeof(elink));
    p->ep=num;
    p->next=NULL;
    if(head->link==NULL)
    {
    head->link=p;
    return head;
    }
        t=head->link;
        r=t;
        while(t!=NULL&&t->ep<p->ep)
        {
            r=t;
            t=t->next;
        }
        if(t!=NULL)
        {
            if(t==r)
            {
                p->next=t;
                head->link=p;
            }
            else
            {
                p->next=t;
                r->next=p;
            }
        }
        else
        r->next=p;
    return head;
}
void trdfs(vlink *G[],int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        if(visited[i]==0)
            dfs(G,i);
    }
}
void dfs(vlink *G[],int v)
{
    elink *p;
    visited[v]=1;
    printf("%d ",v);
    for(p=G[v]->link;p!=NULL;p=p->next)
    {
        if(visited[p->ep]!=1)
            dfs(G,p->ep);
    }
}
void  trbfs(vlink *G[],int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        if(visited[i]==0)
        bfs(G,i);
    }
}
void bfs(vlink *G[],int v)
{
    elink *p;
    visited[v]=1;
    inqueue(v);
    while(emptyq()!=1)
    {
        v=dequeue();
        printf("%d ",v);
        for(p=G[v]->link;p!=NULL;p=p->next)
        {
            if(visited[p->ep]==0)
            {
                inqueue(p->ep);
                visited[p->ep]=1;
            }
        }
    }
}
void inqueue(int k)
{
    rear++;
    q[rear]=k;
}
int dequeue()
{
    front++;
    return q[front];
}
int emptyq()
{
    if(front>=rear)
        return 1;
    else
        return 0;
}



