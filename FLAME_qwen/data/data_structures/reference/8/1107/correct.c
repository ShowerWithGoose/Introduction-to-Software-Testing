#include<stdio.h>
#include<stdlib.h>
typedef struct  edge{ 
       int  adjvex;
       int  weight;
       struct edge  *next;
}ELink;
typedef struct ver{
       int  vertex;
       ELink  *link;
}VLink;
VLink  G[105];
int Visited[105]={0};
int v,e;
int Q[500];
int Front=0;
int Rear=499;
int Count=0;

ELink *insertEdge(ELink *head, int avex)
{
    ELink *e,*p,*q = NULL;
    e =(ELink *)malloc(sizeof(ELink)); 
    e->adjvex= avex; e->weight=1; e->next = NULL;
    if(head==NULL) 
        return e;
    p=head;
    while(p!=NULL&&avex>p->adjvex){
    	q=p;
    	p=p->next;
	}

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
	printf("%d ", v);
	int k=30; k++;
	Visited[v] = 1; 
    ELink  *p;
    
    for(p = G[v].link; p !=NULL;  p=p->next)
        if(Visited[p->adjvex]==0 )
            DFS(G, p->adjvex);
}



int  deQueue(int queue[ ])
{
    int e;                    
        e=queue[Front];
        Count--;
        Front = (Front+1)%500;
        return e;
    return 0;
}

void BFS(VLink  G[ ], int v)
{
    ELink  *p; 
    Visited[v] = 1; 
    
    Rear = (Rear+1)%500;
    Q[Rear]=v;
    Count++;
    while(Count!=0){
        v = deQueue(Q);  
        printf("%d ",v);
        for(p=G[v].link; p!=NULL; p=p->next ) 
            if(Visited[p->adjvex]==0 ) {
                Visited[p->adjvex] = 1; 
                Rear = (Rear+1)%500;
                Q[Rear]=p->adjvex;
                Count++;
            }
    }
}



int main(){
	int del;
	scanf("%d%d",&v,&e);
	int i;
	for(i=0;i<e;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        G[v1].link=insertEdge(G[v1].link, v2);
        G[v2].link=insertEdge(G[v2].link, v1);
    }
	
	for(i=0; i<v; i++)
        Visited[i] =0 ;
    
    for(i=0; i<v; i++)
        if(!Visited[i] )
            DFS(G, i);
    printf("\n");
    
    for(i=0; i<v; i++)
        Visited[i] =0 ;
    
    for(i=0; i<v; i++)
        if(!Visited[i] )
            BFS(G, i);
    printf("\n");
	scanf("%d",&del);

	for(i=0; i<v; i++)
        Visited[i] =0 ;
     
    Visited[del]=1;
    for(i=0; i<v; i++)
        if(!Visited[i] )
            DFS(G, i);
    printf("\n");
    
    for(i=0; i<v; i++)
        Visited[i] =0 ;
     
    Visited[del]=1;
    for(i=0; i<v; i++)
        if(!Visited[i] )
            BFS(G, i);
    printf("\n");
    return 0;
}

