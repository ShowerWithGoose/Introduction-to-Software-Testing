#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MaxV    256
int visited[101];
//int v[101][101];
int v0=-1;
/*typedef struct  edge{ 
    int  adj;
    int  wei;
    struct edge  *next;
}Elink;

typedef struct ver{
       ELink *link;
}Vlink;
VLink  G[MaxV];


Elink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= avex; 
	e->wei=1; 
	e->next = NULL;
    if(head == NULL){
		head=e; 
		return head; 
	}
    for(p=head; p->next != NULL; p=p->next)
    	;
    p->next = e;  
    return head;
}
*/

/*
void createGraph(VLink graph[]){ 
	int i,n,v1,v2;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d %d",&v1,&v2);
    	while(v2 != -1){
      		//graph[v1].link=insertEdge(graph[v1].link, v2);
      		//graph[v2].link=insertEdge(graph[v2].link, v1);
      		graph[v1][v2]= graph[v2][v1]= 1;
      		scanf("%d",&v2);
    	}
  	}
} 
*/

/*void dfs(int t, int i)
{
	int j;
 	visited[i] = 1;
 	if(i!=v0)
		printf("%d ",i); //打印顶点，也可以其它操作 
	for(j = 0; j < t; j++)
		if(v[i][j] == 1 && !visited[j])
 			DFS(t, j); //对为访问的邻接顶点递归调用
}
*/

typedef struct
{
	//char vc[MAXVEX]; /* 顶点表 */
	int v[101][101];/* 邻接矩阵，可看作边表 */
	int n,m; /* 图中当前的顶点数和边数 */ 
}MGraph;

/* 邻接矩阵的深度优先递归算法 */
void dfs(MGraph G, int i)
{
	int j;
 	visited[i] = 1;
 	if(i!=v0)
 		printf("%d ", i);/* 打印顶点，也可以其它操作 */
	for(j = 0; j < G.n; j++)
		if(G.v[i][j] == 1 && !visited[j])
 			dfs(G, j);/* 对为访问的邻接顶点递归调用 */
}
/* 邻接矩阵的深度遍历操作 */
void DFS(MGraph G)
{
	int i;
 	for(i = 0; i < G.n; i++)
 		visited[i] = 0; /* 初始所有顶点状态都是未访问过状态 */
	for(i = 0; i < G.n; i++)
 		if(!visited[i]) /* 对未访问过的顶点调用DFS，若是连通图，只会执行一次 */ 
			dfs(G, i);
}


/* 循环队列的顺序存储结构 */
typedef struct
{
	int data[1000];  /* 存储空间初始分配量 */
	int front;    	/* 头指针 */
	int rear;		/* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
}Queue;

/* 初始化一个空队列Q */
int InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return 1;
}

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
int QueueEmpty(Queue Q)
{ 
	if(Q.front==Q.rear) /* 队列空的标志 */
		return 1;
	else
		return 0;
}

/* 若队列未满，则插入元素e为Q新的队尾元素 */
int EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%100 == Q->front)	/* 队列满的判断 */
		return 0;
	Q->data[Q->rear]=e;			/* 将元素e赋值给队尾 */
	Q->rear=(Q->rear+1)%100;/* rear指针向后移一位置， */
								/* 若到最后则转到数组头部 */
	return 1;
}

/* 若队列不空，则删除Q中队头元素，用e返回其值 */
int DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* 队列空的判断 */
		return 0;
	*e=Q->data[Q->front];				/* 将队头元素赋值给e */
	Q->front=(Q->front+1)%100;	/* front指针向后移一位置， */
									/* 若到最后则转到数组头部 */
	return 1;
}

/* 邻接矩阵的广度遍历算法 */
void BFS(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.n; i++)
       	visited[i] = 0;
    InitQueue(&Q);		/* 初始化一辅助用的队列 */
    for(i = 0; i < G.n; i++)  /* 对每一个顶点做循环 */
    {
		if (!visited[i])	/* 若是未访问过就处理 */
		{
			visited[i]=1;		/* 设置当前顶点访问过 */
			if(i!=v0)
				printf("%d ", i);/* 打印顶点，也可以其它操作 */
			EnQueue(&Q,i);		/* 将此顶点入队列 */
			while(!QueueEmpty(Q))	/* 若当前队列不为空 */
			{
				DeQueue(&Q,&i);	/* 将队对元素出队列，赋值给i */
				for(j=0;j<G.n;j++) 
				{ 
					/* 判断其它顶点若与当前顶点存在边且未访问过  */
					if(G.v[i][j] == 1 && !visited[j]) 
					{ 
 						visited[j]=1;			/* 将找到的此顶点标记为已访问 */
 						if(j!=v0)
							printf("%d ", j);	/* 打印顶点 */
						EnQueue(&Q,j);				/* 将找到的此顶点入队列  */
					} 
				} 
			}
		}
	}
}

int main()
{
	int i;
	int j;
	int n;//点个数 
	int m;//边个数 
	int v1,v2;
	MGraph G;
	scanf("%d %d",&n,&m);
	G.n=n;
	G.m=m;
	for(i=1;i<=n;i++);
		for(j=1;j<=n;j++)
			if(i==j)
				G.v[i][j]=0;
			else
				G.v[i][j]=999;
	for(i=1;i<=m;i++){
		scanf("%d %d",&v1,&v2);
		G.v[v1][v2]=1;
		G.v[v2][v1]=1;
	}
	scanf("%d",&v1);
	DFS(G);
	printf("\n");
	for(i=1;i<=n;i++)
		visited[i]=0;
	BFS(G);
	printf("\n");
	for(i=1;i<=n;i++)
		visited[i]=0;
	v0=v1;
//删除 点 v0	
	for(i=1;i<=n;i++)
		if(i==v0)
			for(j=1;j<=n;j++)
				if(i!=j)
					G.v[i][j]=999;
		for(j=1;j<=n;j++)
			if(j==v0&&i!=j)
				G.v[i][j]=999;
	DFS(G);
	printf("\n");
	for(i=1;i<=n;i++)
		visited[i]=0;
	BFS(G);
	for(i=1;i<=n;i++)
		visited[i]=0;
	return 0;
}

