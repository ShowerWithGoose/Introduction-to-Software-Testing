#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Edge{
    int adj;
    struct Edge *next;
}edge[100];
struct Edge *link[100];
void bubbleSort(struct Edge *head)//冒泡排序 
{
    struct Edge *p,*q;
    int tmp;
    for(p=head;p->next!=NULL;p=p->next)
    {
        for(q=p->next;q->next!=NULL;q=q->next)
        {
            if(p->adj>q->adj)
            {
                tmp=p->adj;
                p->adj=q->adj;
                q->adj=tmp;
            }
        }
    }
}
struct Edge *insertEdge(struct Edge *head,int adv)
{
    struct Edge *p,*e;
    e=(struct Edge *)malloc(sizeof(struct Edge));
    e->adj=adv;
    e->next=NULL;
    if(head==NULL)
    {
        head=e;
        return head;
    }
    else
    {
        for(p=head;p->next!=NULL;p=p->next)
        {
        }
        p->next=e;
        return head;
    }
}
int visited[105]={0};
void DFS(struct Edge *G[],int v)
{
    struct Edge *p;
    visited[v]=1; //标识某顶点被访问过
    if(G[v]!=NULL)
    {
        printf("%d ",v); //访问某顶点
    }
    for(p=G[v];p!=NULL;p=p->next)
    {
        if(!visited[p->adj])
        {
            DFS(G,p->adj);
        }
    }
}
void travelDFS(struct Edge *G[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            DFS(G,i);
        }
    }
}
int Queue[105]={0};
int front=0;
int rear=0;
void BFS(struct Edge *G[],int v)
{
    struct Edge *p;
    visited[v]=1;//标识某顶点已入队
    Queue[rear++]=v;
    while(front!=rear)
    {
        v=Queue[front++];//取出队头元素
        if(G[v]!=NULL)
        {
            printf("%d ",v); //访问某顶点
        }
        for(p=G[v];p!=NULL;p=p->next)//访问该顶点的每个邻接顶点
        {
            if(!visited[p->adj])
            {
                visited[p->adj]=1;//标识某顶点入队
                Queue[rear++]=p->adj;
            }
        }
    }
}
void travelBFS(struct Edge *G[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            BFS(G,i);
        }
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,x,y;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        link[x]=insertEdge(link[x],y);
        link[y]=insertEdge(link[y],x);
    }
    int del;
    scanf("%d",&del);
    for(i=0;i<n;i++)
    {
        bubbleSort(link[i]);
    }
    travelDFS(link,n);
    printf("\n");
    travelBFS(link,n);
    printf("\n");
    struct Edge *p,*q,*r;
    for(q=link[del];q!=NULL;q=q->next)
    {
        for(p=link[q->adj],r=p;p!=NULL;p=p->next)
        {
            if(p->adj==del)
            {
                if(p==link[q->adj]) // @@ The variable 'i' is used here, but it holds the loop index from the previous loop (value n), not the current neighbor's index. It should be link[q->adj].
                {
                    link[q->adj]=p->next; // @@ Similarly, link[i] is incorrect. It should update the head of the adjacency list for vertex q->adj.
                }
                else
                {
                    r->next=p->next;
                }
                break;
            }
            r=p;
        }
    }
    link[del]=NULL;
    travelDFS(link,n);
    printf("\n");
    travelBFS(link,n);
    printf("\n");
}