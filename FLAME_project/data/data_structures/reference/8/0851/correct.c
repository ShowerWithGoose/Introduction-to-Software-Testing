#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ep 1e-6
#define pi 3.14159265
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define NumberOf(x) (sizeof(x) / sizeof(x[0]))
#define max(A, B) ((A) > (B) ? (A) : (B))

struct vertex{
    struct edge *link;
}Ver[105];
struct edge{
    int adjvex;
    struct edge *next;
};
int v[105]={0};
int Visited[105]={0};
int queue[1005]={0};
int front=0,rear=0;
void travelDFS(struct vertex *Ver,int venum,int deletenum);
void DFS(struct vertex *Ver,int i,int deletenum);
void travelBFS(struct vertex *Ver,int venum,int deletenum);
void BFS(struct vertex *Ver,int i,int deletenum);
int main()
{
    int venum,ednum,i;
    int v1,v2;
    struct edge *q=NULL,*p=NULL;
    scanf("%d%d",&venum,&ednum);
    for(i=0;i<ednum;i++)
    {
        scanf("%d%d",&v1,&v2);
        if(v[v1]==0)
        {
            Ver[v1].link=(struct edge *)malloc(sizeof(struct edge));
            Ver[v1].link->adjvex=v2;
            Ver[v1].link->next=NULL;
            v[v1]=1;
        }
        else
        {
            q=(struct edge *)malloc(sizeof(struct edge));
            q->adjvex=v2;
            q->next=NULL;
            if(Ver[v1].link->adjvex>v2)
            {
                p=Ver[v1].link;
                Ver[v1].link=q;
                Ver[v1].link->next=p;
            }
            else
            {
                for(p=Ver[v1].link;p->next!=NULL&&p->next->adjvex<v2;p=p->next);
                if(p->next==NULL)
                p->next=q;
                else
                {
                    q->next=p->next;
                    p->next=q;
                }
            }
        }
        if(v[v2]==0)
        {
            Ver[v2].link=(struct edge *)malloc(sizeof(struct edge));
            Ver[v2].link->adjvex=v1;
            Ver[v2].link->next=NULL;
            v[v2]=1;
        }
        else
        {
            q=(struct edge *)malloc(sizeof(struct edge));
            q->adjvex=v1;
            q->next=NULL;
            if(Ver[v2].link->adjvex>v1)
            {
                p=Ver[v2].link;
                Ver[v2].link=q;
                Ver[v2].link->next=p;
            }
            else
            {
                for(p=Ver[v2].link;p->next!=NULL&&p->next->adjvex<v1;p=p->next);
                if(p->next==NULL)
                p->next=q;
                else
                {
                    q->next=p->next;
                    p->next=q;
                }
            }
        }        
    }
    int deletenum;
    scanf("%d",&deletenum);
    travelDFS(Ver,venum,-1);
    travelBFS(Ver,venum,-1);
    travelDFS(Ver,venum,deletenum);
    travelBFS(Ver,venum,deletenum);    
}

void travelDFS(struct vertex *Ver,int venum,int deletenum)
{
    int i;
    for(i=0;i<venum;i++)
    Visited[i]=0;
    for(i=0;i<venum;i++)
    {
        if(Visited[i]==0&&i!=deletenum)
        DFS(Ver,i,deletenum);
    }
    putchar('\n');
}
void DFS(struct vertex *Ver,int i,int deletenum)
{
    struct edge *p=NULL;
    Visited[i]=1;
    if(i!=deletenum)
    printf("%d ",i);
    for(p=Ver[i].link;p!=NULL;p=p->next)
    {
        if(Visited[p->adjvex]==0&&p->adjvex!=deletenum)
        {
            DFS(Ver,p->adjvex,deletenum);
        }
    }
}
void travelBFS(struct vertex *Ver,int venum,int deletenum)
{
    int i;
    for(i=0;i<venum;i++)
    Visited[i]=0;
    for(i=0;i<venum;i++)
    {
        if(Visited[i]==0&&i!=deletenum)
        BFS(Ver,i,deletenum);
    }
    putchar('\n');
}

void BFS(struct vertex *Ver,int i,int deletenum)
{
    struct edge *p;
    Visited[i]=1;
    if(i!=deletenum)
    queue[rear++]=i;
    while(front!=rear)
    {
        i=queue[front];
        front++;
        if(i!=deletenum)
        printf("%d ",i);
        for(p=Ver[i].link;p!=NULL;p=p->next)
        {
            if(Visited[p->adjvex]==0&&p->adjvex!=deletenum)
            {
                Visited[p->adjvex]=1;
                queue[rear++]=p->adjvex;
            }
        }
    }
}


