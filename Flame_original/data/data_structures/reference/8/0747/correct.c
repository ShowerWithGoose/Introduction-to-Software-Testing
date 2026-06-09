#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
    int adjvex;
    struct edge *next;
 }ELink;
ELink *p,*r;
typedef struct ver{
    ELink *link;
}VLink;
int Visited[100];
void DFS(VLink G[],int v,int t)
{
    ELink *p;
    Visited[v]=1;
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
         if(!Visited[p->adjvex]&&p->adjvex!=t)
             DFS(G,p->adjvex,t);
}
void  travelDFS(VLink G[],int n,int t)
{
    int i;
    for(i=0;i<n;i++) Visited[i]=0 ;
    for(i=0;i<n;i++)
        if(!Visited[i]&&i!=t) DFS(G,i,t);
}
int Q[100];
int  Front=0,Rear=99,Count=0;
void enQueue(int item)
{
    Rear=(Rear+1)%100;
    Q[Rear]=item;
    Count++;
 }
int deQueue()
{
    int e;
    e=Q[Front];
    Count--;
    Front=(Front+1)%100;
    return e;
}
void BFS(VLink G[],int v,int t)
{
    ELink *p;
    Visited[v]=1;
    enQueue(v);
    while(Count>0){
         v=deQueue();
         printf("%d ",v);
         for(p=G[v].link;p!=NULL;p=p->next )
             if(!Visited[p->adjvex]&&p->adjvex!=t ) {
                Visited[p->adjvex] = 1;
                enQueue(p->adjvex);
           }
     }
}
void travelBFS(VLink G[],int n,int t)
{
    int i;
    for(i=0;i<n;i++) Visited[i]=0 ;
    for(i=0;i<n;i++)
        if(!Visited[i]&&i!=t)
        {BFS(G,i,t);}
}

int main()
{
    int i,j,Nv,Ne,v1,v2,v0;
    scanf("%d%d",&Nv,&Ne);
    VLink G[Nv];
    for(i=0;i<Nv;i++)
        G[i].link=NULL;
    for(i=0;i<Ne;i++)
    {
        scanf("%d%d",&v1,&v2);
        p=(struct edge *)malloc(sizeof(struct edge));
        p->adjvex=v2;
        p->next=NULL;
        if(G[v1].link==NULL)
        {
            G[v1].link=p;
        }
        else
        {
            for(r=G[v1].link;r->next!=NULL&&r->next->adjvex<v2;r=r->next);
            if(r->next==NULL)
            {
                if(r->adjvex<v2)
                    r->next=p;
                else
                {
                    p->next=r;
                    G[v1].link=p;
                }
            }
            else
            {
                if(r->adjvex>v2)
                {
                    p->next=r;
                    G[v1].link=p;
                }
                else
                {
                    p->next=r->next;
                    r->next=p;
                }
            }
        }
        p=(struct edge *)malloc(sizeof(struct edge));
        p->adjvex=v1;
        p->next=NULL;
        if(G[v2].link==NULL)
            G[v2].link=p;
        else
        {
            for(r=G[v2].link;r->next!=NULL&&r->next->adjvex<v1;r=r->next);
            if(r->next==NULL)
            {
                if(r->adjvex<v1)
                    r->next=p;
                else
                {
                    p->next=r;
                    G[v2].link=p;
                }
            }
            else
            {
                if(r->adjvex>v1)
                {
                    p->next=r;
                    G[v2].link=p;
                }
                else
                {
                    p->next=r->next;
                    r->next=p;
                }
            }
        }
    }
    scanf("%d",&v0);
    travelDFS(G,Nv,Nv);
    printf("\n");
    travelBFS(G,Nv,Nv);
    printf("\n");
    travelDFS(G,Nv,v0);
    printf("\n");
    travelBFS(G,Nv,v0);

    return 0;
}

