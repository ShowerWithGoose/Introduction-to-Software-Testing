#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
    int adj;
    int wei;
    struct edge *next;
}elink;
typedef struct ver{
    elink *link;
} vlink;
vlink  gg[256];
int vv,ee;
void cregr(vlink graph[]);
void  trad(vlink gg[ ],int n,int delv);
void  trab(vlink gg[ ],int n,int delv);
int main(int gc,const char * gv[])
{
    scanf("%d %d",&vv,&ee);
    cregr(gg);
    trad(gg,vv,-1);
    trab(gg,vv,-1);
    int k;
    scanf("%d",&k);
    trad(gg,vv,k);
    trab(gg,vv,k);
    return 0;
}
elink *insed(elink *head,int avex)
{
    elink *e,*p,*q=NULL;
    e=(elink *)malloc(sizeof(elink));
    e->adj=avex;e->wei=1;e->next=NULL;
    if(head==NULL)
        return e;
    for(p=head;p!=NULL&&avex>p->adj;q=p,p=p->next)
        ;
    if(p==head)
	{
        e->next=p;
        return e;
    }
    else{
        q->next=e;
        e->next=p;
        return head;
    }
}
void cregr(vlink graph[])
{
	int i;
    for(i=0;i<ee;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insed(graph[v1].link,v2);
        graph[v2].link=insed(graph[v2].link,v1);
    }
}
int vis[256]={0};
void DFS(vlink gg[ ],int v)
{
    elink *p;
    vis[v]=1;
    printf("%d ",v);
    for(p=gg[v].link;p!=NULL;p=p->next)
        if(!vis[p->adj])
            DFS(gg,p->adj);
}
void trad(vlink gg[ ],int n,int delv)
{
    int i;
    for(i=0;i<n;i++)
        vis[i]=0 ;
    if(delv>=0)
        vis[delv]=1;
    for(i=0;i<n;i++)
        if(!vis[i])DFS(gg,i);
    printf("\n");
}
int qq[1000];
int Front,Rear,Count;
void initQueue(void)
{
    Front=0;
    Rear=1000-1;
    Count=0;
}
int ise(void)
{
    return Count==0;
}
int isf(void)
{
    return Count==1000;
}
void enq(int queue[ ],int item)
{
    if(isf())
        printf("Full queue!");
    else
	{
        Rear=(Rear+1)%1000;
        queue[Rear]=item;
        Count++;
    }
}
int deq(int queue[ ])
{
    int e;
    if(ise())
        printf("Empty queue!");
    else{
        e=queue[Front];
        Count--;
        Front=(Front+1)%1000;
        return e;
    }
    return 0;
}
void BFS(vlink gg[ ],int v)
{
    elink *p;
    initQueue();
    vis[v]=1;
    enq(qq,v);
    while(!ise())
	{
        v=deq(qq);
        printf("%d ",v);
        for(p=gg[v].link;p!=NULL;p=p->next )
            if(!vis[p->adj])
			{
                vis[p->adj]=1;
                enq(qq, p->adj);
            }
    }
}
void trab(vlink gg[ ],int n,int delv)
{
    int i;
    for(i=0;i<n;i++)
        vis[i]=0;
    if(delv>=0)
        vis[delv]=1;
    for(i=0;i<n;i++)
        if(!vis[i])
            BFS(gg,i);
    printf("\n");
}

