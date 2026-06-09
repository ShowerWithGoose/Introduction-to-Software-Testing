#include<stdio.h>
#define MaxV 100
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
Vlink G[MaxV];
Vlink H[MaxV];
Elink *insertEdge(Elink *,int);
int Visited[MaxV]={0};
void travelDFS(Vlink [],int);
void DFS(Vlink [],int);
void travelBFS(Vlink [],int);
void BFS(Vlink [],int);
void travelDFS2(Vlink [],int,int);
void DFS2(Vlink [],int);
void travelBFS2(Vlink [],int,int);
void BFS2(Vlink [],int);
int Queue[MaxV];
int Front=0,Rear=MaxV-1,Count=0;
void enQueue(int);
int deQueue();
int data[MaxV*(MaxV-1)][2];
int main()
{
    int n,l,i;
    scanf("%d %d",&n,&l);
    for(i=0;i<l;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        data[i][0]=v1;
        data[i][1]=v2;
        G[v1].link=insertEdge(G[v1].link,v2);
        G[v2].link=insertEdge(G[v2].link,v1);
    }

    int wipe;

    scanf("%d",&wipe);

    travelDFS(G,n);
    printf("\n");
    travelBFS(G,n);
    printf("\n");

    for(i=0;i<l;i++)
    {
        if(data[i][0]==wipe||data[i][1]==wipe)
        {
            int j;
            for(j=i;j+1<l;j++)
            {
                data[j][0]=data[j+1][0];
                data[j][1]=data[j+1][1];
            }
            l--;
        }
    }

    for(i=0;i<l;i++)
    {
        //printf("%d %d\n",data[i][0],data[i][1]);
        H[data[i][0]].link=insertEdge(H[data[i][0]].link,data[i][1]);
        H[data[i][1]].link=insertEdge(H[data[i][0]].link,data[i][0]); // @@ Typo: should use H[data[i][1]].link as the first argument to insertEdge, otherwise the adjacency list for the second vertex is incorrectly built.
    }

    travelDFS2(H,n,wipe);
    printf("\n");
    travelBFS2(H,n,wipe);
    //printf("\n");

    return 0;
}

Elink *insertEdge(Elink *head,int avex)
{
    Elink *e,*p,*q;
    e=(Elink *)malloc(sizeof(Elink)); // @@ Compilation error: missing #include <stdlib.h> for malloc function declaration.
    e->adjvex=avex;
    e->next=NULL;
    if(head==NULL)
    {
        head=e;
        return head;
    }
    else
    {
        for(p=head,q=NULL;p!=NULL;q=p,p=p->next)
        {
            if(e->adjvex<p->adjvex)
            {
                if(q==NULL)
                {
                    e->next=p;
                    return e;
                }
                else
                {
                    e->next=p;
                    q->next=e;
                    return head;
                }
            }
        }
        q->next=e;
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
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
    {
        if(!Visited[p->adjvex])
        {
            DFS(G,p->adjvex);
        }
    }
}

void travelDFS2(Vlink H[],int n,int w)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i!=w)
        {
            Visited[i]=0;
        }
        else
        {
            Visited[i]=1;
        }
    }
    for(i=0;i<n;i++)
    {
        if(Visited[i]!=1)
        {
            DFS2(H,i);
        }
    }
}

void DFS2(Vlink H[],int v)
{
    Elink *p;
    Visited[v]=1;
    printf("%d ",v);
    for(p=H[v].link;p!=NULL;p=p->next)
    {
        if(!Visited[p->adjvex])
        {
            DFS(H,p->adjvex); // @@ Logical error: should recursively call DFS2(H,p->adjvex) instead of DFS to maintain correct traversal logic for the modified graph.
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
    enQueue(v);
    while(Count!=0)
    {
        v=deQueue();
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next)
        {
            if(!Visited[p->adjvex])
            {
                Visited[p->adjvex]=1;
                enQueue(p->adjvex);
            }
        }
    }
}

void travelBFS2(Vlink H[],int n,int w)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i!=w)
        {
            Visited[i]=0;
        }
        else
        {
            Visited[i]=1;
        }
    }
    for(i=0;i<n;i++)
    {
        if(Visited[i]!=1)
        {
            BFS2(H,i);
        }
    }
}

void BFS2(Vlink G[],int v)
{
    for(int i=0;i<MaxV;i++)
    {
        Queue[i]=0;
        Front=0,Count=0,Rear=MaxV-1; // @@ Logical error: queue state variables are reset inside the loop, causing redundant operations. Should be moved outside the loop.
    }

    Elink *p;
    Visited[v]=1;
    enQueue(v);
    while(Count!=0)
    {
        v=deQueue();
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next)
        {
            if(!Visited[p->adjvex])
            {
                Visited[p->adjvex]=1;
                enQueue(p->adjvex);
            }
        }
    }
}


void enQueue(int item)
{
    if(Count==MaxV)
    {
        printf("Full queue!");
    }
    Rear=(Rear+1)%MaxV;
    Queue[Rear]=item;
    Count++;
}
int deQueue()
{
    int e;
    if(Count==0)
    {
        printf("Empty queue!");
    }
    e=Queue[Front];
    Count--;
    Front=(Front+1)%MaxV;
    return e;
}