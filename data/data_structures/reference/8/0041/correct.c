

#include <stdio.h>
#include <stdlib.h>

#define MaxV    110
int  Visited[MaxV]={0}; 
typedef struct  edge 
{
   int adj;
   struct edge *next;
}Elink;

typedef struct  ver
{
   Elink *link;
}Vlink;
Vlink  G[MaxV]; 


typedef struct qnode
{
    int num;
}Queue;
Queue Q[MaxV];
int Qtotal = 0, front = 0, rare = -1;

Elink  *insertEdge(Elink *head, int avex);
Elink  *Sort(Elink *head); 
void travelDFS(Vlink  G[], int n); 
void DFS(Vlink  G[], int v);   
void CleanVisited(int j);
void travelBFS(Vlink  G[], int n); 
void BFS(Vlink  G[], int v);    
void inQueue(int v);    
int outQueue();        
void DeleteV(int v,int Vnum);    

int main()
{
    int Vnum, Enum, i, v1, v2;
    scanf("%d %d",&Vnum,&Enum);
    for(i=0; i<Enum; i++)
    {
        scanf("%d %d",&v1,&v2);
        G[v1].link=insertEdge(G[v1].link, v2);
        G[v2].link=insertEdge(G[v2].link, v1);
    }
    for(i=0; i<Vnum; i++)
        G[i].link=Sort(G[i].link);
    travelDFS(G, Vnum);
    printf("\n");
    CleanVisited(Vnum);
    travelBFS(G, Vnum);
    printf("\n");
    CleanVisited(Vnum);
    while( (scanf("%d",&v1))!=EOF )
        DeleteV(v1,Vnum);
    travelDFS(G, Vnum);
        printf("\n");
    CleanVisited(Vnum);
    travelBFS(G, Vnum);
    return 0;
}

Elink  *insertEdge(Elink *head, int avex)
{
    Elink *e,*p;
    e =(Elink *)malloc(sizeof(Elink));
    e->adj = avex; e->next = NULL;
    if(head == NULL)
    {
        head=e;
        return head;
    }
    
    for(p=head; p->next != NULL; p=p->next);
    p->next = e;
    return head;
}

Elink  *Sort(Elink *headptr) 
{
    Elink *pre=NULL, *flag=NULL, *p = headptr, *temp;
    int num;    
    while(p != flag)
    {
        num=0;
        while((p->next) != flag)
        {
            if(p->adj > (p->next)->adj) 
            {
                temp = (p->next);    
                (p->next) = (p->next->next);   
                temp->next = p;    
                if(num>0)  
                    pre->next = temp;
                pre = temp;   
                if(num == 0)   
                    headptr = temp;
            }
            else   
            {
                pre = p;
                p = (p->next);
            }
            num++;
        }
        flag = p;    
        p = headptr; 
    }
    return headptr;
}

void travelDFS(Vlink  G[], int n) 
{
    int i;
    for(i=0; i<n; i++)
    {
        if( Visited[i] == 0 && G[i].link!=NULL )
            DFS(G,i);
    }
}

void DFS(Vlink  G[], int v)    
{
    Elink  *p;
    Visited[v] = 1; 
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
    {
        if( Visited[p->adj] == 0 && G[p->adj].link!=NULL )
            DFS(G, p->adj);
    }
}

void CleanVisited(int j)    
{
    int i=0;
    while( i<=j)
    {
        if(Visited[i] == 1) 
            Visited[i]=0;
            i++;
    }
}

void travelBFS(Vlink  G[], int n) 
{
    int i;
    for(i=0; i<n; i++)
    {
        if( Visited[i] == 0 && G[i].link!=NULL )
            BFS(G,i);
    }
}

void BFS(Vlink  G[], int v)   
{
    Elink  *p;
    printf("%d ",v);
    Visited[v] = 1; 
    inQueue(v);  
    while( front <= rare ) 
    {
        v = outQueue();  
        p = G[v].link;  
        for(; p != NULL; p = p->next ) 
        {
            if( Visited[p->adj] == 0 )
            {
                printf("%d ",p->adj); 
                Visited[p->adj] = 1; 
                inQueue(p->adj);
            }
        }
    }
}

void inQueue(int v)
{
    Q[++rare].num = v;
}

int outQueue()
{
    int v;
    v = Q[front++].num;
    return v;
}

void DeleteV(int v, int Vnum)
{
    int i;
    Elink  *p, *pre=NULL;
    Visited[v] = -1;    
    for(i=0; i<Vnum; i++)
    {
        pre = NULL; 
        if(Visited[i] != -1)
        {
            for(p = G[i].link; p !=NULL; p = p->next)
            {
                if(p->adj == v)  
                {
                    if(pre == NULL)  
                        G[i].link = p->next;
                    else    
                        pre->next = p->next;
                }
                else   
                    pre = p;
            }
        }
    }
}

