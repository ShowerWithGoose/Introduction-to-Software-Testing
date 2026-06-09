#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

typedef struct Edge{
    int adj;
    int val;
    struct edge* next;
}*edge,Elink;

typedef struct Vertex{
    edge link;
}vertex;

struct edg1{
    int link[10];
    int num;
};

vertex  graph[1000];
int visited[1000]={0},Vertex_num=0,Edge_num=0,i=0,j=0,del_v;
struct edg1 edg[1000];

edge insertEdge(edge head, int avex)
{
    int temp;
    edge e,p,pre;
    e =(edge)malloc(sizeof(Elink));
    e->adj= avex; e->val=1; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    for(p=head; p->next != NULL; p=p->next)
        ;
    p->next=e;
    return head;
}

void DFS(vertex G[],int v)
{
    edge p;
    visited[v]=1;
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
    {
        if(!visited[p->adj])
        {
            DFS(G,p->adj);
        }
    }
}

void DFS_map(vertex G[],int Vnum)
{
    for(i=0;i<Vnum;i++)
    {
        if(!visited[i])
        {
            DFS(G,i);
        }
    }
    printf("\n");
}

void BFS(vertex G[],int v)
{
    int q[1000],front=-1,rear=-1;
    edge p;
    visited[v]=1;
    q[++rear]=v;
    while(rear-front>0)
    {
        v=q[++front];
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next)
        {
            if(!visited[p->adj])
            {
                visited[p->adj]=1;
                q[++rear]=p->adj;
            }
        }
    }
}
void BFS_map(vertex G[],int Vnum)
{
    for(i=0;i<Vnum;i++)
    {
        if(!visited[i])
        {
            BFS(G,i);
        }
    }
    printf("\n");
}

int cmp(const int *a,const int *b)
{
    return (*a-*b);
}

int main()
{
    int v1,v2;
    scanf("%d%d",&Vertex_num,&Edge_num);
    for(i=0;i<Vertex_num;i++)
    {
        edg[i].num=0;
    }
    i=Edge_num;
    while(i--)
    {
        scanf("%d%d",&v1,&v2);
        edg[v1].link[edg[v1].num++]=v2,edg[v2].link[edg[v2].num++]=v1;
    }
    for(i=0;i<Vertex_num;i++)
    {
        qsort(edg[i].link,edg[i].num,sizeof(edg[i].link[0]),cmp);
    }
    for(i=0;i<Vertex_num;i++)
    {
        for(j=0;j<edg[i].num;j++)
        {
            graph[i].link=insertEdge(graph[i].link,edg[i].link[j]);
            graph[edg[i].link[j]].link=insertEdge(graph[edg[i].link[j]].link,i);
        }
    }
    scanf("%d",&del_v);

    DFS_map(graph,Vertex_num);

    for(i=0;i<Vertex_num;i++)
    {
        visited[i]=0;
    }
    BFS_map(graph,Vertex_num);

    for(i=0;i<Vertex_num;i++)
    {
        visited[i]=0;
    }
    visited[del_v]=1;
    DFS_map(graph,Vertex_num);

    for(i=0;i<Vertex_num;i++)
    {
        visited[i]=0;
    }
    visited[del_v]=1;
    BFS_map(graph,Vertex_num);
    return 0;
}



