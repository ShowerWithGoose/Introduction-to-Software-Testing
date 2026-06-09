#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define ull unsigned long long

typedef struct bound//边
{
    int adj;
    int wei;
    struct bound* next;
}Elink;

typedef struct ver//顶点
{
    Elink* link;
}Vlink;

Vlink G[256];

int Vnum,Enum;

void createGraph(Vlink graph[]);

void dfs(Vlink G[], int n, int delV);
void bfs(Vlink G[], int n, int delV);
Elink* insert(int pos,Elink*head);
void DFS(Vlink G[], int v);

int main()
{
	scanf("%d %d",&Vnum,&Enum);

    createGraph(G);

    dfs(G,Vnum,-1);
    bfs(G,Vnum,-1);

    int ord;
    scanf("%d",&ord);

    dfs(G,Vnum,ord);
    bfs(G,Vnum,ord);

}


Elink* insert(int pos,Elink*head)
{
    Elink*p,*q,*r;
    p=(Elink*)malloc(sizeof(Elink));
    p->next=NULL;
    p->adj=pos;
    p->wei=1;

    for(q=head;q!=NULL&&q->adj<pos;r=q,q=q->next);

    if(head==NULL)
    {
        head=p;
        return p;
    }
    else if(q==head)
    {
        p->next=head;
        head=p;
        return p;
    }

    else 
    {
        r->next=p;
        p->next=q;
        return head;
    }


}

void createGraph(Vlink graph[])
{
    int v1,v2;
    for(int i=0;i<Enum;i++)
    {
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insert(v2,graph[v1].link);
        graph[v2].link=insert(v1,graph[v2].link);
    }
}

int visited[256]={0};

void DFS(Vlink G[], int v)
{
     Elink *p;
    visited[v] = 1; 
    printf("%d ", v);
   
    for(p = G[v].link; p !=NULL;  p=p->next)
        if( !visited[p->adj] )
            DFS(G, p->adj);

}

void dfs(Vlink G[], int n, int delV)//顶点
{
    int i;
    for(int i=0;i<n;i++)
     visited[i]=0;

     if(delV>=0)
     visited[delV]=1;

     for(i=0;i<n;i++)
     {
         if(visited[i]!=1)DFS(G,i);
        printf("\n");
     }
}


#define MAXSIZE     1000
int  Q[MAXSIZE];
int  Front, Rear,Count;
void  initQueue(void)
{
    Front = 0;
    Rear = MAXSIZE-1;
    Count = 0;
}
int  isEmpty(void)
{
    return Count == 0;
}
int  isFull(void)
{
    return Count == MAXSIZE;
}
void enQueue(int queue[ ], int item)
{
    if(isFull())                       
        printf("Full queue!");
    else{                            
        Rear = (Rear+1) % MAXSIZE;
        queue[Rear]=item;
        Count++;
    }
}
int  deQueue(int queue[ ])
{
    int e;
    if(isEmpty())                   
        printf("Empty queue!");
    else{                        
        e=queue[Front];
        Count--;
        Front = (Front+1) % MAXSIZE;
        return e;
    }
    return 0;
}


void BFS(Vlink  G[ ], int v)
{
    Elink  *p;
    initQueue();  
    visited[v] = 1; 
    enQueue(Q, v);
    while( !isEmpty()){
        v = deQueue(Q);  
        printf("%d ",v);
       
        for(p=G[v].link; p!=NULL; p=p->next ) 
            if( !visited[p->adj] ) {
                visited[p->adj] = 1; 
                enQueue(Q, p->adj);
            }
    }
}

void  bfs(Vlink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        visited[i] = 0 ;
    if(delV >= 0)  
        visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !visited[i] )
            BFS(G, i);
    printf("\n");
}

