#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 108
int Q[MAXSIZE];
int front=0,rear=MAXSIZE-1,cnt=0;//队的初始化 

void enqueue(int queue[],int item);
int dequeue(int queue[]);

typedef struct edge//定义边结点类型 
{
	int adj;//结点信息 
	struct edge *next;
 }ELink;
typedef struct ver//定义头结点类型：头节点序号直接用正整数编码 
{
	ELink *link;
}VLink;
VLink graph[105];
int  Visited[105]={0};

struct edge *insertEdge(ELink *head, int avex);
void BFS(VLink  G[ ], int v);
void  travelBFS(VLink  G[ ], int n,int op);
void DFS(VLink  G[ ], int v);
void  travelDFS(VLink  G[ ], int n,int op);

int hold;

int main()
{
	int n,m;//n顶点个数，m边数 
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++)
	{
		int v1,v2;
	    scanf("%d%d",&v1,&v2);//v1是顶点序号，v2是该顶点的邻接顶点 
		graph[v1].link=insertEdge(graph[v1].link, v2);
	    graph[v2].link=insertEdge(graph[v2].link, v1);
	}
/*
	for(int i=0;i<n;i++)
	{
		printf("%d : ",i);
		ELink *p;
		for(p=graph[i].link;p!=NULL;p=p->next)
		{
			printf("%d ",p->adj);
		}
		printf("\n");
	}*/
	scanf("%d",&hold);
	travelDFS(graph,n,0);
	travelBFS(graph,n,0);
	travelDFS(graph,n,1);
	travelBFS(graph,n,1);
	return 0;
}
struct edge *insertEdge(ELink *head, int avex)
{
    ELink *e,*p,*q;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj=avex; 
	e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    if(head->adj>avex)
    {
    	e->next=head;
    	head=e;
    	return head;
	}
    for(p=head,q=head; p!= NULL;q=p,p=p->next)
    {
    	if(p->adj>avex)
    	{
    		e->next=q->next;
			q->next=e;
    		return head;
		}
	}
	q->next=e;
	return head;
}
void enqueue(int queue[],int item)
{
	if(cnt==MAXSIZE)
		printf("full~~");
	else
	{
		rear=(rear+1)%MAXSIZE;
		queue[rear]=item;
		cnt++;
	}
 } 
int dequeue(int queue[])
{
	int e;
	if(cnt==0)
		printf("empty~~");//有的时候按需要改成return ; 
	else
	{
		e=queue[front];
		cnt--;
		front=(front+1)%MAXSIZE;
		return e;
	}
}
void  travelDFS(VLink  G[ ], int n,int op)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    if(op==1)
    	Visited[hold]=1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) 
			DFS(G, i);
    printf("\n");
}
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adj] )
             DFS(G, p->adj);
}
void  travelBFS(VLink  G[ ], int n,int op)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    if(op==1)
    	Visited[hold]=1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
    printf("\n");
}
void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点已入队
    enqueue(Q, v);
    while(cnt!=0){
         v = dequeue(Q);  //取出队头元素
         printf("%d ",v);//访问当前顶点
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adj] ) {
                    Visited[p->adj] = 1; //标识某顶点入队
                    enqueue(Q,p->adj);
           }
 }
}
 



