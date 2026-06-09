#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct edge{
	int adjvex;
    struct edge *next;
}Elink;
typedef struct ver{
       struct edge  *link;
}Vlink;
struct ver  G[110],g[110];
struct edge  *insertEdge(struct edge *head, int avex)
{
    struct edge *e,*p,*q = NULL;
    e =(struct edge *)malloc(sizeof(struct edge)); /* 创建一个数据项为avex的新结点 */
    e->adjvex= avex; e->next = NULL;
    if(head == NULL)  /* head是一个空表 */
        return e;
    for(p=head; p != NULL && avex > p->adjvex;  q = p, p = p->next) /* 找到插入位置 */
        ;
    if( p == head){  /* 在头结点前插入 */
        e->next = p;
        return e;
    }
    else {           /* 在结点p前插入一个结点 */
        q->next = e;
        e->next = p;
        return head;
    }
}
int  Visited[110]={0}; //标识顶点是否被访问过，N为顶点数
void DFS(struct ver  G[ ], int v)
{//在图G中，从顶点v开始进行深度优先遍历
    struct edge  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adjvex] )
             DFS(G, p->adjvex);
}

void  travelDFS(struct ver  G[ ], int n,int flag)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    if(flag>=0)
    Visited[flag]=1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
}
int Q[110];
int front=0,rear=119,count=0;
void  initQueue(void)
{
    front = 0;
    rear = 109;
    count = 0;
}
int Empty()
{
	return count==0;
}
void enqueue(int queue[ ], int item)
{                      
        rear = (rear+1) % 110;
        queue[rear]=item;
 //       printf("%d!\n",item);
        count++;
    
}
int dequeue(int Q[])
{
	int k;
//	printf("%d?\n",Q[front]); 
	if(!Empty()){
	k=Q[front];
	count--;
	front=(front+1)%110;
	return k;
}
	return 0;
}
void BFS(struct ver  G[ ], int v)
{
    struct edge  *p;
    initQueue();
    Visited[v] = 1; //标识某顶点已入队
    enqueue(Q, v);
    while( !Empty()){
        v = dequeue(Q);  //取出队头元素
        printf("%d ",v);
        //VISIT(G, v); //访问当前顶点
        for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
            if( !Visited[p->adjvex] ) {
                Visited[p->adjvex] = 1; //标识某顶点入队
                enqueue(Q, p->adjvex);
            }
    }
}
void  travelBFS(struct ver  G[ ], int n,int flag)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    if(flag>=0)
    Visited[flag]=1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}
	
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		G[a].link=insertEdge(G[a].link,b);
		G[b].link=insertEdge(G[b].link,a);
	}
	for(int i=0;i<n;i++)
	{
		struct edge *p;
		for(p = G[i].link; p !=NULL;  p=p->next)
		{
			;//printf("%d ",p->adjvex);
		}
//		printf("\n");
	}
	travelDFS(G,n,-1);
	printf("\n");
	for(int i=0;i<=n;i++)
	Visited[i]=0;
	travelBFS(G,n,-1);
	printf("\n");
	int c;
	scanf("%d",&c);
	travelDFS(G,n,c);
	printf("\n");
	travelBFS(G,n,c);
}











