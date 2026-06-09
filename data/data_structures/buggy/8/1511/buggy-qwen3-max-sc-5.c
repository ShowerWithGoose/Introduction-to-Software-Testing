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
        H[data[i][1]].link=insertEdge(H[data[i][0]].link,data[i][0]); // @@ [Incorrectly uses H[data[i][0]] instead of H[data[i][1]] when inserting the reverse edge, causing missing or incorrect adjacency list for vertex data[i][1]]
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
    e=(Elink *)malloc(sizeof(Elink)); // @@ [Missing #include <stdlib.h> for malloc, leading to compilation error]
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
            DFS(H,p->adjvex); // @@ [Calls DFS instead of DFS2, which uses the original graph G instead of the modified graph H, leading to incorrect traversal after deletion]
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

void BFS2(Vlink G[],int v) // @@ [Parameter name is G but should be H for clarity; however, more critically, the queue variables are reset incorrectly inside the function]
{
    for(int i=0;i<MaxV;i++)
    {
        Queue[i]=0;
        Front=0,Count=0,Rear=MaxV-1; // @@ [Resets global queue state inside loop, overwriting settings multiple times and leaving Rear as MaxV-1 instead of proper initial state (should be -1 or 0 depending on design). Also, this reset should happen once before BFS2 starts, not per vertex in a loop that doesn't exist here — but since BFS2 is called once from travelBFS2, it's misplaced logic. More importantly, Count is set to 0 but then enQueue increments it, yet the while condition checks Count!=0 — but the initial enQueue happens after this reset, so it may work, but the repeated assignment in a loop is unnecessary and confusing. However, the real issue is that the queue state is global and must be properly initialized before use. The bigger problem is that this initialization runs every time BFS2 is called, which is okay, but the loop is redundant. Still, not the main bug.]
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