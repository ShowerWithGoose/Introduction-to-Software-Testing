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
void DFS(Vlink G[],int vn);
void travelBFS(Vlink G[],int n);
void BFS(Vlink G[],int vn);

int main(){
	int i,vn,en,delver;
	scanf("%d%d",&vn,&en);
	creategraph(G,en);
	scanf("%d",&delver);
	travelDFS(G,vn);
	printf("\n");
	travelBFS(G,vn);
	printf("\n"); 
	delet=delver;
	travelDFS(G,vn);
	printf("\n");
	travelBFS(G,vn);
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
	Elink *en,*p;
	en=(Elink *)malloc(sizeof(Elink));
	en->adj=avex;
	en->wei=1;
	en->next=NULL;
	if(head==NULL){
		head=en;
		return head;
	}
	if (head->adj > en->adj) {
		/*Elink* tmp;
		tmp = (Elink*)malloc(sizeof(Elink));
		tmp->adj = head->adj;
		tmp->wei = 1;
		e->next = tmp;*/
		en->next = head;
		head = en;
		return head;
	}
	for (p = head; p->next != NULL; p = p->next) {
		if (en->adj < p->next->adj) {
			en->next = p->next;
			p->next = en;
			return head;
		}
	}
	p->next=en;
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

void DFS(Vlink G[],int vn){
	Elink *p;
	visit[vn]=1;//标记被访问了 
	printf("%d ",vn);
	for(p=G[vn].link;p!=NULL;p=p->next)
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

void BFS(Vlink G[],int vn){
	Elink *p;
	printf("%d ",vn);
	visit[vn]=1;
	enQueue(vn);
	while(!emptyQ()){
		vn=deQueue();
		p=G[vn].link;
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
	int en=NULL;
	en=Q[Front];  
	Count--;
	Front=Front+1;  
	return en;
}
int	emptyQ()
{
	return Count==0;
}







