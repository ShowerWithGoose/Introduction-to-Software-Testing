#include <stdio.h>
#include <stdlib.h>
typedef struct edge{
    int adj;
    int wei;
    struct edge *next;
}ELink;
typedef struct ver{
    ELink *link;
}VLink;
VLink G[300];
int V,E;
void createphoto(VLink photo[]);
void passDFS(VLink G[],int n,int delV);
void passBFS(VLink G[],int n,int delV);
int main()
{
    scanf("%d %d",&V,&E);
    createphoto(G);
    passDFS(G,V,-1);
    passBFS(G,V,-1);
    int n;
    scanf("%d",&n);
    passDFS(G,V,n);
    passBFS(G,V,n);
    return 0;
 } 
ELink  *insertEdge(ELink *head, int a)
{
    ELink *e,*p,*q = NULL;
    e =(ELink *)malloc(sizeof(ELink)); 
    e->adj= a;
    e->wei=1; 
    e->next = NULL;
    if(head == NULL)  
        return e;
    for(p=head; p!= NULL && a>p->adj;q=p,p=p->next) 
        ;
    if(p== head)
    {  
        e->next = p;
        return e;
    }
    else 
    {           
        q->next = e;
        e->next = p;
        return head;
    }
}

void createphoto(VLink photo[])
{
    for(int i=0;i<E;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        photo[v1].link=insertEdge(photo[v1].link, v2);
        photo[v2].link=insertEdge(photo[v2].link, v1);
    }
}
int Visited[300]={0}; 
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; 
    printf("%d ",v);
    for(p = G[v].link;p!=NULL;p=p->next)
        if(!Visited[p->adj] )
            DFS(G, p->adj);
}
void  passDFS(VLink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
    {
        Visited[i] = 0;
    }
    if(delV >= 0)
    { 
        Visited[delV]=1;
    }
    for(i=0; i<n; i++)
        if(!Visited[i] )
        DFS(G, i);
    printf("\n");
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

void enQueue(int queue[ ], int item)
{
    if(Count==MAXSIZE)                    
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
    if(Count==0)                  
        printf("Empty queue!");
    else{                    
       e=queue[Front];
        Count--;
        Front = (Front+1) % MAXSIZE;
        return e;
    }
    return 0;
}

void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    initQueue();  
    Visited[v] = 1; 
    enQueue(Q, v);
    while( Count==0){ @@ [The condition should be `Count != 0` or `!isEmpty()` to continue BFS while the queue is not empty. Using `Count==0` causes the loop to never execute.]
        v = deQueue(Q);  
        printf("%d ",v);
        for(p=G[v].link; p!=NULL; p=p->next )
            if( !Visited[p->adj] ) {
                Visited[p->adj] = 1; 
                enQueue(Q, p->adj);
            }
    }
}
void  passBFS(VLink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
    {
        Visited[i]=0;
    }
    if(delV >= 0)
    {
        Visited[delV]=1;
    }
    for(i=0; i<n; i++)
        if( !Visited[i] )
            BFS(G, i);
    printf("\n");

}