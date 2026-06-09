#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

#define maxe 105//最大顶点数 
int del=maxe;
typedef struct edge{
	int adj;
	int wei;
	struct edge *next;
}Elink;

typedef struct ver{
	Elink *link;
}Vlink;

Vlink graph[maxe];//邻接表 

int visit[maxe];//用于标记是否被访问 
int Q[maxe];//队 
int Front,Rear,Count; 
void creategraph(Vlink graph[],int n);
Elink *insertEdge(Elink *head,int avex);
void initQueue();//初始化队 
void enQueue(int item);//进队 
int deQueue();//出队 
int	emptyQ();//判断队是非为空 
void travelDFS(Vlink graph[],int n);
void DFS(Vlink graph[],int n);
void travelBFS(Vlink graph[],int n);
void BFS(Vlink graph[],int n);

int main(){
	int i,n,m,del;
	scanf("%d%d",&n,&m);
	creategraph(graph,m);
	scanf("%d",&del);
	travelDFS(graph,n);
	printf("\n");
	travelBFS(graph,n);
	printf("\n"); 
	del=del;
	travelDFS(graph,n);
	printf("\n");
	travelBFS(graph,n);
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
	Elink *m,*p;
	m=(Elink *)malloc(sizeof(Elink));
	m->adj=avex;
	m->wei=1;
	m->next=NULL;
	if(head==NULL){
		head=m;
		return head;
	}
	if (head->adj > m->adj) {
		/*Elink* tmp;
		tmp = (Elink*)malloc(sizeof(Elink));
		tmp->adj = head->adj;
		tmp->wei = 1;
		e->next = tmp;*/
		m->next = head;
		head = m;
		return head;
	}
	for (p = head; p->next != NULL; p = p->next) {
		if (m->adj < p->next->adj) {
			m->next = p->next;
			p->next = m;
			return head;
		}
	}
	p->next=m;
	return head;
}
//深度优先遍历 
void travelDFS(Vlink graph[],int n){
	int i;
	for(i=0;i<n;i++)
		visit[i]=0;
	visit[del]=1;
	for(i=0;i<n;i++)
		if(!visit[i])
			DFS(graph,i);
} 

void DFS(Vlink graph[],int n){
	Elink *p;
	visit[n]=1;//标记被访问了 
	printf("%d ",n);
	for(p=graph[n].link;p!=NULL;p=p->next)
	if(!visit[p->adj]) 
	DFS(graph,p->adj);
}
//广度优先遍历 
void travelBFS(Vlink graph[],int n){
	int i;
	initQueue();
	for(i=0;i<n;i++)
		visit[i]=0;
	visit[del]=1;
	for(i=0;i<n;i++)
		if(!visit[i])
		BFS(graph,i);
}

void BFS(Vlink graph[],int n){
	Elink *p;
	printf("%d ",n);
	visit[n]=1;
	enQueue(n);
	while(!emptyQ()){
		n=deQueue();
		p=graph[n].link;
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
	int m=NULL;
	m=Q[Front];  
	Count--;
	Front=Front+1;  
	return m;
}
int	emptyQ()
{
	return Count==0;
}







