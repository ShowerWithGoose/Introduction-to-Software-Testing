#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define pf printf
#define sc scanf
#define N 1024

struct edge{
	int adjvex;
	struct edge *next;
};
struct ver{
	int vertex;
	struct edge *link;
}graph[105];

struct edge *insertEdge(struct edge *head, int avex);
void  travelDFS(struct ver G[ ], int n,int m);
void DFS(struct ver G[ ], int v);
void  travelBFS(struct ver G[ ], int n,int m);
void BFS(struct ver G[ ], int v,int m);

int main()
{
	int numnodes,numedges,v1,v2,delv;
	struct edge *p,*q;
	sc("%d%d",&numnodes,&numedges);
	for(int i = 0;i < numedges;i++){
		sc("%d%d",&v1,&v2);
		graph[v1].vertex = v1;
		graph[v2].vertex = v2;
		graph[v1].link=insertEdge(graph[v1].link,v2);
      	graph[v2].link=insertEdge(graph[v2].link,v1);
	}
	sc("%d",&delv);
	/*for(int i = 0;i < numnodes;i++){
		pf("%d ",graph[i].vertex);
		for(p = graph[i].link;p != NULL;p = p->next)
			pf("%d ",p->adjvex);
		pf("\n");
	}*/

	travelDFS(graph,numnodes,numnodes);
	pf("\n");
	travelBFS(graph,numnodes,numnodes);
	pf("\n");
	
	travelDFS(graph,numnodes,delv);
	pf("\n");
	travelBFS(graph,numnodes,delv);
	pf("\n");
	return 0;
}

struct edge *insertEdge(struct edge *head, int avex)
{
    struct edge *e,*p,*t;
    e =(struct edge *)malloc(sizeof(struct edge));
    e->adjvex = avex; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    //t = head;
    for(p = head; p != NULL; t = p,p = p->next){
    	if(p != head && e->adjvex < p->adjvex){
    		e->next = p;
    		t->next = e;
    		return head;
		}
		if(p == head && e->adjvex < p->adjvex){
    		e->next = p;
    		head = e;
    		return head;
		}
	}
    t->next = e; 
    return head;
}

int Visited[N]={0}; //标识顶点是否被访问过，N为顶点数
void  travelDFS(struct ver G[ ], int n,int m)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0;
    Visited[m] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
}
void DFS(struct ver G[ ], int v)
{
    struct edge *p;
    
    Visited[v] = 1; //标识某顶点被访问过
    //VISIT(G, v); //访问某顶点
    pf("%d ",G[v].vertex);
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adjvex] )
             DFS(G, p->adjvex);
}

int  Visited1[N]={0};
void  travelBFS(struct ver G[ ], int n,int m)
{
    int i;
    for(i=0; i<n; i++) Visited1[i] = 0 ;
    Visited1[m] = 1;
    for(i=0; i<n; i++)
    	if( !Visited1[i] ) BFS(G, i,m);
}

void BFS(struct ver G[ ], int v,int m)
{
    struct edge *p;
    int Q[N],rear = -1,front = 0;
    Visited1[v] = 1;//标识某顶点已入队
    //enQueue(Q, v);
    Q[++rear] = v;
    while( front <= rear){
         v = Q[front++];  //取出队头元素
         //VISIT(G, v); //访问当前顶点
         if(G[v].vertex != m)
        	 pf("%d ",G[v].vertex);
         for(p = G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited1[p->adjvex] ) {
                    Visited1[p->adjvex] = 1; //标识某顶点入队
                    //enQueue(G, p->adjvex);
                    Q[++rear] = p->adjvex;
           }
     }
}


