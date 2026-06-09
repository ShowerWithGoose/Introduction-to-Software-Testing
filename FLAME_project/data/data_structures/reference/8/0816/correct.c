#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
typedef int vertype;
typedef struct edge{
       int  adjvex;//连接结点 
       int  weight;//权重 
       struct edge  *next;
 }ELink;
typedef struct ver{
      vertype  vertex;
      ELink  *link;
}VLink; //顶点头 
 VLink G[101];
 int Visited[101]={0};
void createGraph(int v1,int v2);
ELink  *insertEdge(ELink *head, int avex);
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; 
    printf("%d ", v);
    for(p = G[v].link; p !=NULL;  p=p->next)
        if( !Visited[p->adjvex] )
            DFS(G, p->adjvex);
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
int  Q[1000];
int  Front, Rear,Count;
void  initQueue(void)
{
    Front = 0;
    Rear = 1000-1;
    Count = 0;
}
int  isEmpty(void)
{
    return Count == 0;
}
int  isFull(void)
{
    return Count == 1000;
}
void enQueue(int queue[ ], int item)
{
    if(isFull())                      
        printf("Full queue!");
    else{                             
        Rear = (Rear+1) % 1000;
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
        Front = (Front+1) % 1000;
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
    while( !isEmpty()){
        v = deQueue(Q);  
        printf("%d ",v);
        for(p=G[v].link; p!=NULL; p=p->next ) 
            if( !Visited[p->adjvex] ) {
                Visited[p->adjvex] = 1; 
                enQueue(Q, p->adjvex);
            }
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
int main()
{
	int vnum,lnum,v,w;
	scanf("%d%d",&vnum,&lnum);
	for(int i=0;i<lnum;i++)
	{
		scanf("%d%d",&v,&w);
		createGraph(v,w);
	}
	int del;
	scanf("%d",&del);
	travelDFS(G,vnum,-1);
	travelBFS(G,vnum,-1);
	travelDFS(G,vnum,del);
	travelBFS(G,vnum,del);
	return 0;
 } 
 ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p,*q = NULL;
    e =(ELink *)malloc(sizeof(ELink)); 
    e->adjvex= avex; e->weight=1; e->next = NULL;
    if(head == NULL)  
        return e;
    for(p=head; p != NULL && avex > p->adjvex;  q = p, p = p->next) 
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
void createGraph(int v1,int v2)
{
        G[v1].link=insertEdge(G[v1].link, v2);
        G[v2].link=insertEdge(G[v2].link, v1);
}




