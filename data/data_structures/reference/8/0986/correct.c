#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define eps 1e-6
typedef struct edge{
    int adjvex;
    struct edge *next;
}ELink;
typedef struct ver {
    int vertex;
    ELink *link;
}VLink;
VLink G[101];
int Visited[101];
void insertEdge(int v,int w)
{
    ELink *e,*p,*q;
    e=(ELink *)malloc(sizeof(ELink));
    e->adjvex=w;
    e->next=NULL;
    if(G[v].link==NULL)
    {
        G[v].link=e;
    }
    else 
    {
        if(G[v].link->adjvex>e->adjvex)
        {
            q=G[v].link;
            G[v].link=e;
            e->next=q;
        }
        for(p=G[v].link;p->next!=NULL&&p->next->adjvex<e->adjvex;p=p->next);
        q=p->next;
        p->next=e;
        e->next=q;
    }
}
void delete(VLink G[],int n,int v)
{
    ELink *p,*q;
    for(int i=0;i<n;i++)
    {
        if(i!=G[v].vertex)
        {
            if(G[i].link->adjvex==G[v].vertex)
            {
                q=G[i].link->next;
                G[i].link=q;
            }
            else
            {
                for(p=G[i].link;p->next!=NULL&&p->next->adjvex!=G[v].vertex;p=p->next);
                if(p->adjvex==G[v].vertex&&p->next!=NULL)
                {
                    q=p->next->next;
                    p->next=q;
                }
                else if(p->adjvex==G[v].vertex&&p->next==NULL)
                {
                    p=NULL;
                }
            }
        }
        else if(i==v)
        {
            G[i].link=NULL;
            G[i].vertex=-1;
        }
    }
    
}
void DFS(VLink G[],int v)
{
    ELink *p;
    Visited[v]=1;
    if(G[v].vertex!=-1)
    {
        printf("%d ",G[v].vertex);
    }
    for(p=G[v].link;p!=NULL;p=p->next)
    {
        if(!Visited[p->adjvex])
        {
            DFS(G,p->adjvex);
        }
    }
}
void travelDFS(VLink G[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        Visited[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(!Visited[i])
        {
            DFS(G,i);
        }
    }
}
int queue[1000],head=0,rear=-1;
int isempty()
{
    return head>rear;
}
void push(int x)
{
    queue[++rear]=x;
}
int pop()
{
    return isempty() ? -1 :queue[head++];
}
void BFS(VLink G[],int v)
{
    ELink *p;
    Visited[v]=1;
    push(v);
    while(!isempty())
    {
        v=pop();
        if(G[v].vertex!=-1)
        {
            printf("%d ",G[v].vertex);
        }
        for(p=G[v].link;p!=NULL;p=p->next)
        {
            if(!Visited[p->adjvex])
            {
                Visited[p->adjvex]=1;
                push(p->adjvex);
            }
        }
    }
}
void travelBFS(VLink G[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        Visited[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(!Visited[i])
        {
            BFS(G,i);
        }
    }
}
int main()
{
    int m,n,v,w,d;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&v,&w);
        insertEdge(v,w);
        insertEdge(w,v);
        G[i].vertex=i;
    }
    scanf("%d",&d);
    travelDFS(G,n);
    printf("\n");
    travelBFS(G,n);
    printf("\n");
    delete(G,n,d);
    travelDFS(G,n);
    printf("\n");
    travelBFS(G,n);
    printf("\n");
    return 0;
}
