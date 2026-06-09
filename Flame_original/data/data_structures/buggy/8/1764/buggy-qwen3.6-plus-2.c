#include <stdio.h>
#include <stdlib.h>
#define MAXV 256
struct edge{
    int adj;
    struct edge *next;
};
typedef struct edge Elink;
struct ver{
    Elink *link;
};
typedef struct ver Vlink;
struct node{
    int v;
    int V;
};
struct node list[MAXV];
int Visited[MAXV]={0};
void sort(struct node array[],int n);
Elink *insertedge(Elink *head,int avex);
void travelDFS(Vlink G[],int n);
void DFS(Vlink G[],int v);
void travelBFS(Vlink G[],int n);
void BFS(Vlink G[],int v);
int queue[MAXV];
int rear=MAXV-1,front=0,count=0;
int empty();
void enqueue(int x);
int dequeue();
int delver=-1;
int main()
{
    int vercnt,edgecnt;
    scanf("%d%d",&vercnt,&edgecnt);
    printf("%d %d\n",vercnt,edgecnt); // @@ Unnecessary debug output that violates the required output format.
    Vlink graph[vercnt];
    int i=0;
    for(i=0;i<vercnt;i++)
    {
        graph[i].link=(Elink*)malloc(sizeof(Elink)); // @@ Allocates memory unnecessarily and immediately leaks it by overwriting the pointer with NULL on the next line.
        graph[i].link=NULL;
    }
    for(i=0;i<edgecnt;i++)
    {
        scanf("%d%d",&list[i].v,&list[i].V);
        printf("%d %d\n",list[i].v,list[i].V); // @@ Unnecessary debug output that violates the required output format.
    }
    sort(list,edgecnt);
    for(i=0;i<edgecnt;i++)
    {
        graph[list[i].v].link=insertedge(graph[list[i].v].link,list[i].V);
        graph[list[i].V].link=insertedge(graph[list[i].V].link,list[i].v);
    }
    /*travelDFS(graph,vercnt); // @@ The required traversal function calls are commented out, resulting in no valid output being generated for the test cases.
    printf("\n");
    travelBFS(graph,vercnt);
    printf("\n");*/
    scanf("%d",&delver);
    printf("%d",delver); // @@ Unnecessary debug output that violates the required output format.
    /*graph[delver].link=NULL; // @@ The post-deletion traversal logic is commented out. Furthermore, simply nullifying the link list does not remove incoming edges from other vertices, and the traversal functions incorrectly allow the deleted vertex to act as a bridge.
    travelDFS(graph,vercnt);
    printf("\n");
    travelBFS(graph,vercnt);*/
    return 0;
}
void sort(struct node array[],int n)
{
    int i,j;
    struct node tmp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(array[i].v>array[j].v)
            {
                tmp=array[i];
                array[i]=array[j];
                array[j]=tmp;
            }
            if(array[i].v==array[j].v)
            {
                if(array[i].V>array[j].V)
                {
                    tmp=array[i];
                    array[i]=array[j];
                    array[j]=tmp;
                }
            }
        }
    }
}
Elink *insertedge(Elink *head,int avex)
{
    Elink *e,*p;
    e=(Elink*)malloc(sizeof(Elink));
    e->adj=avex;
    e->next=NULL;
    if(head==NULL)
    {
        head=e;
        return head;
    }
    else
    {
        for(p=head;p->next!=NULL;p=p->next);
        p->next=e;
        return head;
    }
}
void travelDFS(Vlink G[],int n)
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
void DFS(Vlink G[],int v)
{
    Elink *p;
    Visited[v]=1;
    if(v!=delver) // @@ Logical error: checking only for printing does not prevent the deleted vertex from being used as a traversal bridge. The vertex should be marked as visited initially or its edges should be completely removed.
    {
        printf("%d ",v);
    }
    for(p=G[v].link;p!=NULL;p=p->next)
    {
        if(!Visited[p->adj])
        {
            DFS(G,p->adj);
        }
    }
}
void travelBFS(Vlink G[],int n)
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
void BFS(Vlink G[],int v)
{
    Elink *p;
    Visited[v]=1;
    enqueue(v);
    while(!empty())
    {
        v=dequeue();
        if(v!=delver) // @@ Logical error: checking only for printing does not prevent the deleted vertex from being used as a traversal bridge. The vertex should be marked as visited initially or its edges should be completely removed.
        {
            printf("%d ",v);
        }
        for(p=G[v].link;p!=NULL;p=p->next)
        {
            if(!Visited[p->adj])
            {
                Visited[p->adj]=1;
                enqueue(p->adj);
            }
        }
    }
}
int empty()
{
    return count==0;
}
void enqueue(int x)
{
    rear=(rear+1)%MAXV;
    queue[rear]=x;
    count++;
}
int dequeue()
{
    int x;
    x=queue[front];
    count--;
    front=(front+1)%MAXV;
    return x;
}