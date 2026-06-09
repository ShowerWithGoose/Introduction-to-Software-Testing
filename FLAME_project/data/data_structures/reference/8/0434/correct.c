#include <stdio.h>
#include <stdlib.h>
#define MaxV 256
#define MAXSIZE     1000

struct edge
{
    int  adj;
    int  wei;
    struct edge  *next;
};

struct ver
{
    struct edge  *link;
};

struct ver G[MaxV];
int V, E; 

void  travelDFS(struct ver G[ ], int n, int delV);
void  travelBFS(struct ver G[ ], int n, int delV);

int main(int argc, const char * argv[]) 
{
    int i,v1,v2,k;
    struct edge *head,*e,*p,*q = NULL;
    
    scanf("%d %d",&V,&E); 
    for(i=0;i<E;i++)
    {
        scanf("%d %d",&v1,&v2);
        
	    e =(struct edge *)malloc(sizeof(struct edge)); 
	    e->adj= v2; 
		e->wei=1; 
		e->next = NULL;
		head=G[v1].link;
		
	    if(head == NULL)  
	        G[v1].link=e;
	    for(p=head; p != NULL && v2 > p->adj;  q = p, p = p->next);
	    
	    if( p == head)
		{  
	        e->next = p;
	        G[v1].link=e;
	    }
	    else 
		{           
	    	q->next = e;
	        e->next = p;
	        G[v1].link=head;
	    }
	    
	    e =(struct edge *)malloc(sizeof(struct edge)); 
	    e->adj= v1; 
		e->wei=1; 
		e->next = NULL;
		head=G[v2].link;
		
	    if(head == NULL)  
	        G[v2].link=e;
	    for(p=head; p != NULL && v1 > p->adj;  q = p, p = p->next);
	    
	    if( p == head)
		{  
	        e->next = p;
	        G[v2].link=e;
	    }
	    else 
		{           
	    	q->next = e;
	        e->next = p;
	        G[v2].link=head;
	    }
    }
    
    travelDFS(G,V,-1);
    travelBFS(G,V,-1);
    
    scanf("%d",&k);
    
    travelDFS(G,V,k);
    travelBFS(G,V,k);
    
    return 0;
}

int Visited[MaxV]={0}; 
// 深度优先遍历
void DFS(struct ver G[ ], int v)
{
    struct edge *p;
    Visited[v] = 1; 
    printf("%d ", v);
    
    for(p = G[v].link; p !=NULL;  p=p->next)
        if( !Visited[p->adj] )
            DFS(G, p->adj);
}

void  travelDFS(struct ver  G[ ], int n, int delV)
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
// 广度优先遍历 
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
    else
	{                           
        e=queue[Front];
        Count--;
        Front = (Front+1) % MAXSIZE;
        return e;
    }
    return 0;
}

void BFS(struct ver  G[ ], int v)
{
    struct edge  *p;
    initQueue();  
    Visited[v] = 1; 
    enQueue(Q, v);
    while( !isEmpty())
	{
        v = deQueue(Q);  
        printf("%d ",v);

        for(p=G[v].link; p!=NULL; p=p->next ) 
            if( !Visited[p->adj] ) 
			{
                Visited[p->adj] = 1; 
                enQueue(Q, p->adj);
            }
    }
}

void  travelBFS(struct ver  G[ ], int n, int delV)
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
