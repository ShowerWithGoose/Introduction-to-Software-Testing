#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct edge
{
	int adjvex;
	struct edge *next;	
}; 

struct ver
{
	int vertex;
	struct edge *link;	
};
int Visited[10000]={0};
struct ver graph[10000],graph1[10000];
int Q[10000],top=-1,low=0,store[10000],top1=-1,de;

struct edge *insertEdge(struct edge *head, int avex);
void travelDFS(struct ver G[ ], int n);
void DFS(struct ver G[ ], int v);
void travelBFS(struct ver G[ ], int n);
void BFS(struct ver G[ ], int v);

void travelDFS1(struct ver G[ ], int n);
void DFS1(struct ver G[ ], int v);
void BFS1(struct ver G[ ], int v);
void travelBFS1(struct ver G[ ], int n);
 
int main()
{
	int i,j,k;
	int n1,n2,v1,v2,temp;
	struct edge *p,*q;
	scanf("%d%d",&n1,&n2);
	for(i=0;i<n1;i++)
	{
		graph[i].link=NULL;
		graph[i].vertex=i;
	}
	for(i=0;i<n2;i++)
	{
		scanf("%d%d",&v1,&v2);
		graph[v1].link=insertEdge(graph[v1].link, v2);
		graph[v2].link=insertEdge(graph[v2].link, v1);
	}
	for(i=0;i<n1;i++)
	{
		q=p=graph[i].link;
		while(p!=NULL)
		{
			while(q->next!=NULL)
			{

				if(q->adjvex>q->next->adjvex)
				{
					temp=q->adjvex;
					q->adjvex=q->next->adjvex;
					q->next->adjvex=temp;
				}
				q=q->next;
			}
			p=p->next;
			q=graph[i].link;
		}
	}
	
	scanf("%d",&de);

	travelDFS(graph,n1);
	printf("\n");
	travelBFS(graph,n1);
	printf("\n");
	
	for(i=0;i<n1;i++)
	{	
		p=q=graph[i].link;
		while(p->adjvex==de)
		{ 
			p=p->next;
			graph[i].link=p;
		}
		p=q=graph[i].link;
		while(p!=NULL)
		{
			if(p->adjvex==de)
			{
				while(p->adjvex==de)
				{
					p=p->next;
					if(p==NULL)
						break; 
				}
				q->next=p;
				q=p;
				if(p!=NULL)
				{	
					p=p->next;
					
				}
			
			}
			else
			{
				q=p;
				p=p->next;
			}
		}
	}
	travelDFS1(graph,n1);
	printf("\n");
	travelBFS1(graph,n1);

		
	
	
	
	
	
	
	return 0;
}

struct edge *insertEdge(struct edge *head, int avex) 
{ 
struct edge *e,*p; 
e =(struct edge *)malloc(sizeof(struct edge)); 
e->adjvex= avex;
e->next =NULL; 
if(head == NULL) { head=e; return head; } 
for(p=head; p->next != NULL; p=p->next) 
; 
p->next = e; 
return head; 
}


void travelDFS(struct ver G[ ], int n) 
{ 
int i; 
for(i=0; i<n; i++) Visited[i] = 0 ; 
for(i=0; i<n; i++) 
if( !Visited[i] ) DFS(G, i); 
} 

void DFS(struct ver G[ ], int v)
{ 
struct edge *p; 
Visited[v] = 1; //标识某顶点被访问过 
printf("%d ",G[v].vertex);
for(p = G[v].link; p !=NULL; p=p->next) 
if( !Visited[p->adjvex] ) 
DFS(G, p->adjvex); 
}

void travelBFS(struct ver G[ ], int n) 
{ 
int i; 
for(i=0; i<n; i++) Visited[i] = 0 ; 
for(i=0; i<n; i++) 
if( !Visited[i] ) BFS(G, i); 
}

void BFS(struct ver G[ ], int v) 
{ 
struct edge *p; 
Visited[v] = 1; //标识某顶点已入队 
Q[++top]=v; 
while(top>=low){ 
v =Q[low++]; //取出队头元素 
printf("%d ",G[v].vertex);
for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点 
if( !Visited[p->adjvex] ) { 
Visited[p->adjvex] = 1; //标识某顶点入队 
Q[++top]=p->adjvex; 
} 
}
}







void travelDFS1(struct ver G[ ], int n) 
{ 
int i; 
for(i=0; i<n; i++) Visited[i] = 0 ; 
for(i=0; i<n; i++) 
{
	if(i!=de)
	{
		if( !Visited[i] ) DFS(G, i); 
	}
}

} 

void DFS1(struct ver G[ ], int v) 
{ 
struct edge *p; 
Visited[v] = 1; //标识某顶点被访问过 
printf("%d ",G[v].vertex);
for(p = G[v].link; p !=NULL; p=p->next) 
if( !Visited[p->adjvex] ) 
DFS(G, p->adjvex); 
}

void travelBFS1(struct ver G[ ], int n) 
{ 
int i; 
for(i=0; i<n; i++) Visited[i] = 0 ; 
for(i=0; i<n; i++) 
if(i!=de)
if( !Visited[i] ) BFS(G, i); 
}

void BFS1(struct ver G[ ], int v) 
{ 
struct edge *p; 
Visited[v] = 1; //标识某顶点已入队 
Q[++top]=v; 
while(top>=low){ 
v =Q[low++]; //取出队头元素 
printf("%d ",G[v].vertex);
for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点 
if( !Visited[p->adjvex] ) { 
Visited[p->adjvex] = 1; //标识某顶点入队 
Q[++top]=p->adjvex; 
} 
}
}


