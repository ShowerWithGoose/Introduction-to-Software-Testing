#include <stdio.h>
#include <stdlib.h>
#define MaxV 200

typedef struct edge{ 
	int  adjvex;
	struct edge *next;
}ELink;

typedef struct ver{
	int  vertex;
	ELink *link;
}VLink;

ELink *insertEdge(ELink *head, int avex);
void travelDFS(VLink G[], int n);
void DFS(VLink G[], int i);
void travelBFS(VLink G[], int n);
void BFS(VLink G[], int v);

VLink graph[MaxV];
int delete= MaxV;
int Visited_DFS[MaxV]={0}; 
int Visited_BFS[MaxV]={0}; 

int main()
{
	int number_of_v,number_of_e;
	int a,b;
	
	scanf("%d%d", &number_of_v, &number_of_e);
	
	for(int i=0; i<number_of_e; i++)
	{
		scanf("%d%d", &a,&b);
		graph[a].vertex = a;
		graph[b].vertex = b; 
		graph[a].link=insertEdge(graph[a].link, b);
      	graph[b].link=insertEdge(graph[b].link, a);
	}
	
	travelDFS(graph, number_of_v);
	puts("");
	travelBFS(graph, number_of_v);
	puts("");
	
	scanf("%d", &delete);
	
	travelDFS(graph, number_of_v);
	puts("");
	travelBFS(graph, number_of_v);
	puts("");

	return 0; 
}

ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p;
    e = (ELink *)malloc(sizeof(ELink));
    e->adjvex = avex;  
	e->next = NULL;
	
    if(head == NULL)  
	{ 
		head=e; 
		return head; 
	}
	
	if(head->adjvex>avex)  
	{
		e->next = head; 
		head = e; 
		return head; 
	}
	
    for(p=head; p->next!=NULL&&p->next->adjvex<avex; p=p->next)
    {
    	if( p->adjvex==avex )
    		return head;
	}
    
    e->next = p->next;
    p->next = e;

    return head;
}

void travelDFS(VLink G[], int n)
{
    int i;
    for(i=0; i<n; i++) 
		Visited_DFS[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited_DFS[i]&&G[i].vertex!=delete ) DFS(G,i);
}

void DFS(VLink G[], int i)
{
	ELink *p;
	Visited_DFS[i] = 1;
	if(G[i].vertex!=delete)
	{
		printf("%d ", G[i].vertex);
	}
	for(p = G[i].link; p !=NULL;  p=p->next)
	{
        if( p->adjvex!=delete&&!Visited_DFS[p->adjvex] )
            DFS(G, p->adjvex);
	}
}

void travelBFS(VLink G[], int n)
{
    int i;
    for(i=0; i<n; i++) Visited_BFS[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited_BFS[i]&&G[i].vertex!=delete ) BFS(G,i);
}

void BFS(VLink G[], int v)
{
    ELink *p;
    int front = 0,rear = 0;
    int Q[MaxV+1]={0};
    if(G[v].vertex!=delete)
	{
		printf("%d ", G[v].vertex);
	} 
	
    Visited_BFS[v] = 1; 
    Q[rear++] = v;        
    while( rear!=front )
	{  
        v = Q[front++]; 
        p = G[v].link;       
        for(; p != NULL ; p = p->next ) 
    	{ 
            if( !Visited_BFS[p->adjvex]&&p->adjvex!=delete )
			{
                if(G[p->adjvex].vertex!=delete)
				{
					 printf("%d ", G[p->adjvex].vertex);
				}
                Visited_BFS[p->adjvex] = 1;
                Q[rear++] = p->adjvex;
        	}
    	}
    }
}


