#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct edge{
    int  adj;
    int  wei;
    struct edge  *next;
} ELink;

typedef struct ver{
    ELink  *link;
} VLink;
VLink  G[256];
int  Q[1001];
int  Front,Rear,Count;
int V,E;
int i,j; 
int Visited[256]={0}; 
void createGraph(VLink graph[]);
void  travelDFS(VLink  G[ ], int n, int delV);
void  travelBFS(VLink  G[ ], int n, int delV);
void BFS(VLink  G[ ], int v);
void DFS(VLink  G[ ], int v);
int main(int argc, const char * argv[]) {
    
    scanf("%d %d",&V,&E); 
    
    createGraph(G);
    
    travelDFS(G,V,-1);
    travelBFS(G,V,-1);
    
    int k;
    scanf("%d",&k);
    
    travelDFS(G,V,k);
    travelBFS(G,V,k);
    
    return 0;
}

ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p,*q = NULL;
    e =(ELink *)malloc(sizeof(ELink)); 
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  
        return e;
    for(p=head; p != NULL && avex > p->adj;  q = p, p = p->next) 
        ;
    if( p == head){  
        e->next = p;
        return e;
    }
    else {           
        q->next = e;
        e->next = p;
        return head;
    }
}
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; 
    printf("%d ", v);

    for(p = G[v].link; p !=NULL;  p=p->next)
        if( !Visited[p->adj] )
            DFS(G, p->adj);
}
void createGraph(VLink graph[])
{
    for(i=0;i<E;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link, v2);
        graph[v2].link=insertEdge(graph[v2].link, v1);
    }
}
void  travelDFS(VLink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)  
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
    printf("\n");
}

void  initQueue(void)
{
    Front = 0;
    Rear = 1001-1;
    Count = 0;
}
int  deQueue(int queue[ ])
{
    int e;
    if(isEmpty())                  
        printf("Empty queue!");
    else{                          
        e=queue[Front];
        Count--;
        Front = (Front+1) % 1001;
        return e;
    }
    return 0;
}
int  isEmpty(void)
{
    return Count == 0;
}
int  isFull(void)
{
    return Count == 1001;
}
void enQueue(int queue[ ], int item)
{
    if(isFull())                       
        printf("Full queue!");
    else{                             
        Rear = (Rear+1) % 1001;
        queue[Rear]=item;
        Count++;
    }
}

void  travelBFS(VLink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)  
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] )
            BFS(G, i);
    printf("\n");
}
void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    initQueue();  
    Visited[v] = 1; 
    enQueue(Q, v);
    while( !isEmpty()){
        v = deQueue(Q);  
        printf("%d ",v);
        for(p=G[v].link; p!=NULL; p=p->next )
            if( !Visited[p->adj] ) {
                Visited[p->adj] = 1; 
                enQueue(Q, p->adj);
            }
    }
}


