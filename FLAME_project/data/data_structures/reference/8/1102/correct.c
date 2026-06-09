#include <stdio.h>
#include <stdlib.h>

#define MaxV 256
typedef struct Edg{
    int  a;
    int  w;
    struct Edg  *next;
} ELink;

typedef struct ver{
    ELink  *next;
} VLink;
VLink  g[MaxV];

int v, E; 

void Cgraph(VLink graph[]);

void  travelDFS(VLink  g[ ], int n, int delV);
void  tB(VLink  g[ ], int n, int delV);

int main(int argc, const char * argv[]) {
    
    scanf("%d %d",&v,&E); 
    
    Cgraph(g);
    
    travelDFS(g,v,-1);
    tB(g,v,-1);
    
    int k;
    scanf("%d",&k);
    
    travelDFS(g,v,k);
    tB(g,v,k);
    
    return 0;
}

ELink  *iE(ELink *first, int avex)
{
    ELink *E,*p,*q = NULL;
    E =(ELink *)malloc(sizeof(ELink)); 
    E->a= avex; E->w=1; E->next = NULL;
    if(first == NULL)  
        return E;
    for(p=first; p != NULL && avex > p->a;  q = p, p = p->next) 
        ;
    if( p == first){  
        E->next = p;
        return E;
    }
    else {           
        q->next = E;
        E->next = p;
        return first;
    }
}

void Cgraph(VLink graph[])
{
    for(int i=0;i<E;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1].next=iE(graph[v1].next, v2);
        graph[v2].next=iE(graph[v2].next, v1);
    }
}


int Flag[MaxV]={0}; 

void DFS(VLink  g[ ], int v)
{
    ELink  *p;
    Flag[v] = 1; 
    printf("%d ", v);

    for(p = g[v].next; p !=NULL;  p=p->next)
        if( !Flag[p->a] )
            DFS(g, p->a);
}

void  travelDFS(VLink  g[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Flag[i] = 0 ;
    if(delV >= 0) 
        Flag[delV] = 1;
    for(i=0; i<n; i++)
        if( !Flag[i] ) DFS(g, i);
    printf("\n");
}


#define MAXSIZE     1000
int  Q[MAXSIZE];
int  Front, Rear,Count;
void  iQ(void)
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
void eQ(int queue[ ], int item)
{
    if(isFull())                       
        printf("Full queue!");
    else{                              
        Rear = (Rear+1) % MAXSIZE;
        queue[Rear]=item;
        Count++;
    }
}
int  dQ(int queue[ ])
{
    int E;
    if(isEmpty())                    
        printf("Empty queue!");
    else{                            
        E=queue[Front];
        Count--;
        Front = (Front+1) % MAXSIZE;
        return E;
    }
    return 0;
}


void BFS(VLink  g[ ], int v)
{
    ELink  *p;
    iQ();  
    Flag[v] = 1; 
    eQ(Q, v);
    while( !isEmpty()){
        v = dQ(Q);  
        printf("%d ",v);
       
        for(p=g[v].next; p!=NULL; p=p->next ) 
            if( !Flag[p->a] ) {
                Flag[p->a] = 1; 
                eQ(Q, p->a);
            }
    }
}

void  tB(VLink  g[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Flag[i] = 0 ;
    if(delV >= 0)  
        Flag[delV] = 1;
    for(i=0; i<n; i++)
        if( !Flag[i] )
            BFS(g, i);
    printf("\n");
}


