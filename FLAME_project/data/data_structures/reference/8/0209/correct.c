#include<stdio.h>
#include<stdlib.h>
#define MaxV 100
//======================================================
/*C语言实现邻接表*/
/*边节点*/ 
typedef struct Edge{
	int code;//边的编号 便于区分哪个边 
	int adjtex;/*该边的顶点节点指向的节点*/
	int weight;/*权*/ 
	struct Edge *next;/*指向下一边节点*/ 
}Elink;/*为边节点类型*/ 

/*顶点节点*/
typedef struct Vertex{
	int vertex;/*节点信息*/
	Elink* link;/*边节点指针*/ 
}Vlink;/*Vlink为每个线性表的类型*/


void insertEdge(Elink** head,int adjtex); 
void creatMap(Vlink Map[]);
void travelDFS(Vlink G[],int n);
void DFS(Vlink G[],int v);
void travelBFS(Vlink G[],int n);
void BFS(Vlink G[],int v);

int Queue[MaxV];// Max存队尾 MaxV+1存队头 Max+2存元素个数
int rear=-1,front=0,num=0,totalOfQueue=MaxV; 
int numOfVertex;
int numOfEdge;
Vlink Map_[MaxV];
int visited[MaxV];
int main()
{
	int n,i,j,k;
	int v1,v2;
	int delect_v;
	Elink* p;
	scanf("%d%d",&numOfVertex,&numOfEdge);
	for(i=0;i<numOfEdge;i++)
	{
		scanf("%d %d",&v1,&v2);
		insertEdge(&(Map_[v1].link),v2);
		insertEdge(&(Map_[v2].link),v1);
	}
	scanf("%d",&delect_v);
	
	for(i=0;i<numOfVertex;i++)  visited[i]=0;/*初始化*/ 
	travelDFS(Map_,numOfVertex);
	printf("\n");
	for(i=0;i<numOfVertex;i++)  visited[i]=0;/*初始化*/ 
	travelBFS(Map_,numOfVertex);
	printf("\n");
	for(i=0;i<numOfVertex;i++)  visited[i]=0;/*初始化*/ 
	visited[delect_v]=1;
	travelDFS(Map_,numOfVertex);
	printf("\n");
	for(i=0;i<numOfVertex;i++)  visited[i]=0;/*初始化*/ 
	visited[delect_v]=1;
	travelBFS(Map_,numOfVertex);
	printf("\n");
	return 1;
}
//======================================================
/*以邻接表为背景 进行对图的基本操作*/
/*此图为无向图，且不带权*/ 
/*在边节点最后再插入一个边节点 以边节点所在行顶点节点最开始处以及待插入节点作为参数*/
void insertEdge(Elink** head,int adjtex)
{
	Elink *e,*p;
	e=(Elink*)malloc(sizeof(Elink));
	e->adjtex=adjtex;
	e->weight=1;
	e->next=NULL;
	if(*head==NULL) *head=e;
	else
	{
		if((*head)->adjtex>adjtex)
		{
			e->next=*head;
			*head=e;
			return ;
		}
		p=*head;
		
		while(p->next!=NULL)
		{
			//if(p==*head)
			if(p->next->adjtex>adjtex)
			{
				e->next=p->next;
				p->next=e;
				return;
			}
			else
			p=p->next;
		}
		p->next=e;
	}
} 
/*创建一个图*/
void creatMap(Vlink Map[])
{
	int i;
	int n;/*图中的节点个数*/ 
	/*注意 v1 v2 均指节点编号 
	 *至于内容 该案例没有输入内容
	 *默认以编号作为内容 否则还需进行查找进行节点之间的链接*/
	int v1;
	int v2=0;
/**/scanf("%d",&n);//*输入节点个数*/
	for(i=0;i<n;i++)
	{
/**/scanf("%d",&v1);/*输入v1*/ 
		while(1)/*继续输入v2 直到没有*/ 
		{
/**/		scanf("%d",&v2);/*输入v2*/ 
			if(v2==-1) break;
			/*无向图 不带权*/
			insertEdge(&(Map[v1].link),v2);/*在v1尾部插入v2*/ 
			//insertEdge(&(Map[v2].link),v1);
		}
	 } 
} 
//======================================================

/*图的广度优先算法*/


void enQueue(int *Q,int a)//在总共N个元素的队列中队尾加入 
{
	num++;
	Q[(++rear)%totalOfQueue]=a;
	rear%=totalOfQueue;
}
int deQueue(int *Q)//删去队头元素 
{
	int temp=Q[front];
	num--;
	front=(front+1)%totalOfQueue;
	return temp;
}
void travelBFS(Vlink G[],int n)
{
	int i;
	
	for(i=0;i<n;i++)/*查看每一个节点是否访问过*/ 
	if(!visited[i]) 
	BFS(G,i);
}

void BFS(Vlink G[],int v) /*广度优先遍历map G[]中的v节点*/
/*先将第一个节点入队
 *然后按照如下规则：
 *从队中取出队头，访问 并 在队位插入该元素所有未访问边 边插入边标记访问 避免重复访问  
 *再次取队头重复*/ 
{
	Elink *p;
	printf("%d ",v);
	visited[v]=1;
	enQueue(Queue,v);/*在队列Q 的队尾中插入v*/ 
	while(num) 
	{
		v=deQueue(Queue);/*取出队头元素*/
		for(p=G[v].link;p!=NULL;p=p->next)
		/*访问每个边节点并入队，这样可避免重复*/ 
		{
			if(!visited[p->adjtex])
			{
				printf("%d ",p->adjtex);
				visited[p->adjtex]=1;
				enQueue(Queue,p->adjtex);
			}
		 } 
	}
 } 
void DFS(Vlink G[],int v)/*深度遍历map G[]中的 v顶点*/ 
{
	Elink* p;
	visited[v]=1;
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next)
	/*从v的第一个邻接点开始进行DFS，直到全部访问 
	 *此时一个连通分量的深度遍历已经完成*/ 
	if(!visited[p->adjtex]) 
	DFS(G,p->adjtex);
}

void travelDFS(Vlink G[],int n)/*深度遍历共有n个顶点的map G[],*/
{
	int i;
	
	for(i=0;i<n;i++)/*查看每一个节点是否访问过*/ 
	if(!visited[i]) 
		DFS(G,i);
	
} 




