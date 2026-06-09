#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int visited[105]={0};
typedef struct edge
{
    int adjvex;
    struct edge *next;
}Elink;
typedef struct ver
{
    int vertex;
    Elink *link;
}Vlink;
void dfs(Vlink G[],int v)
{
    Elink *p;
    visited[v]=1;
    printf("%d ",G[v].vertex);
    for(p=G[v].link;p!=NULL;p=p->next)
        if(!visited[p->adjvex])
           dfs(G,p->adjvex);
}
void bfs(Vlink G[],int v)
{
    Elink *p,*q;
    Vlink *queue[105],*g;
    int f=-1,r=0;
    queue[0]=&G[v];
    visited[v]=1;
    while(f<r)
    {
        g=queue[++f];
        printf("%d ",g->vertex);
        for(p=g->link;p!=NULL;p=p->next)
            if(!visited[p->adjvex])
            {
                visited[p->adjvex]=1;
                queue[++r]=&G[p->adjvex];
            }
    }
}
int main()
{
    Vlink G[105];
    Elink *p,*q,*d;
    int n,m,del,v1,v2,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        G[i].link=NULL;
        G[i].vertex=i;
    }
    while(m--)
    {
        scanf("%d%d",&v1,&v2);
        p=(Elink *)malloc(sizeof(Elink));
        p->adjvex=v2;
        p->next=NULL;
        if(G[v1].link==NULL)
        {
            G[v1].link=p;
        }
        else
        {
            for(q=G[v1].link;q!=NULL&&v2>q->adjvex;d=q,q=q->next);
            if(q==G[v1].link)
            {
                p->next=q;
                G[v1].link=p;
            }
            else
            {
                p->next=q;
                d->next=p;
            }
        }
        p=(Elink *)malloc(sizeof(Elink));
        p->adjvex=v1;
        p->next=NULL;
        if(G[v2].link==NULL)
        {
            G[v2].link=p;
        }
        else
        {
            for(q=G[v2].link;q!=NULL&&v1>q->adjvex;d=q,q=q->next);
            if(q==G[v2].link)
            {
                p->next=q;
                G[v2].link=p;
            }
            else
            {
                p->next=q;
                d->next=p;
            }
        }

    }
    scanf("%d",&del);
    dfs(G,0);
    printf("\n");
    for(i=0;i<n;i++) visited[i]=0;
    bfs(G,0);
    printf("\n");
    /*for(p=G[del].link;p!=NULL;p=p->next)
    {
        for(x=p->adjvex,q=G[x].link;q!=NULL&&q->adjvex!=del;d=q,q=q->next);
        if(q==G[x].link) G[x].link=q->next;
        else d->next=q->next;
        free(q);
    }*/
    for(i=0;i<n;i++) if(i!=del) visited[i]=0;
    dfs(G,0);
    printf("\n");
    for(i=0;i<n;i++) if(i!=del) visited[i]=0;
    bfs(G,0);
    printf("\n");
    return 0;
}












