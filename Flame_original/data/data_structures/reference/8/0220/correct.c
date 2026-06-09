#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

#define maxe 105//最大顶点数 
int delet=maxe;
typedef struct edge{
	int adj;
	int wei;
	struct edge *next;
}Elink;

typedef struct ver{
	Elink *link;
}Vlink;

Vlink G[maxe];//邻接表 

int visit[maxe];//用于标记是否被访问 
int Q[maxe];//队 
int Front,Rear,Count; 
void creategraph(Vlink graph[],int n);
Elink *insertEdge(Elink *head,int avex);
void initQueue();//初始化队 
void enQueue(int item);//进队 
int deQueue();//出队 
int	emptyQ();//判断队是非为空 
void travelDFS(Vlink G[],int n);
void DFS(Vlink G[],int v);
void travelBFS(Vlink G[],int n);
void BFS(Vlink G[],int v);

int main(){
	int i,v,e,del;
	scanf("%d%d",&v,&e);
	creategraph(G,e);
	scanf("%d",&del);
	travelDFS(G,v);
	printf("\n");
	travelBFS(G,v);
	printf("\n"); 
	delet=del;
	travelDFS(G,v);
	printf("\n");
	travelBFS(G,v);
	return 0;
}

//创建一个图 
void creategraph(Vlink graph[],int n){
	int i,v1,v2;
	for(i=0;i<n;i++){
		scanf("%d%d",&v1,&v2);
		graph[v1].link=insertEdge(graph[v1].link,v2);
		graph[v2].link=insertEdge(graph[v2].link,v1);
	}
}

Elink *insertEdge(Elink *head,int avex){
	Elink *e,*p;
	e=(Elink *)malloc(sizeof(Elink));
	e->adj=avex;
	e->wei=1;
	e->next=NULL;
	if(head==NULL){
		head=e;
		return head;
	}
	if (head->adj > e->adj) {
		/*Elink* tmp;
		tmp = (Elink*)malloc(sizeof(Elink));
		tmp->adj = head->adj;
		tmp->wei = 1;
		e->next = tmp;*/
		e->next = head;
		head = e;
		return head;
	}
	for (p = head; p->next != NULL; p = p->next) {
		if (e->adj < p->next->adj) {
			e->next = p->next;
			p->next = e;
			return head;
		}
	}
	p->next=e;
	return head;
}
//深度优先遍历 
void travelDFS(Vlink G[],int n){
	int i;
	for(i=0;i<n;i++)
		visit[i]=0;
	visit[delet]=1;
	for(i=0;i<n;i++)
		if(!visit[i])
			DFS(G,i);
} 

void DFS(Vlink G[],int v){
	Elink *p;
	visit[v]=1;//标记被访问了 
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next)
	if(!visit[p->adj]) 
	DFS(G,p->adj);
}
//广度优先遍历 
void travelBFS(Vlink G[],int n){
	int i;
	initQueue();
	for(i=0;i<n;i++)
		visit[i]=0;
	visit[delet]=1;
	for(i=0;i<n;i++)
		if(!visit[i])
		BFS(G,i);
}

void BFS(Vlink G[],int v){
	Elink *p;
	printf("%d ",v);
	visit[v]=1;
	enQueue(v);
	while(!emptyQ()){
		v=deQueue();
		p=G[v].link;
		for(;p!=NULL;p=p->next)
			if(!visit[p->adj]){
				printf("%d ",p->adj);
				visit[p->adj]=1;
				enQueue(p->adj);
		}
	}
}
//队列操作
void initQueue()
{
	Front=0;
	Rear=-1;
	Count=0;
}

void enQueue(int item){
	Rear=Rear+1;
	Q[Rear]=item;
	Count++;
}

int deQueue(){  
	int e=NULL;
	e=Q[Front];  
	Count--;
	Front=Front+1;  
	return e;
}
int	emptyQ()
{
	return Count==0;
}







