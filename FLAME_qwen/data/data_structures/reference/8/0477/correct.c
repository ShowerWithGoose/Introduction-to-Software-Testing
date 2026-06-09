#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct edge{
	int point;
	struct edge *next;
}Elink;
typedef struct vertex{
	int point;
	Elink *next;
}Vlink;
Elink *insert(Elink *head,int a){
	Elink *e ,*p;
	e = (Elink*)malloc(sizeof(Elink));
	e->next = NULL;
	e->point = a;
	if(head == NULL) {
		head = e;
		return head;
	}
	if(a<head->point){
		e->next = head;
		return e;
	}
	for(p = head;p->next!=NULL;p=p->next){
	if(a<p->next->point){
		e->next = p->next;
		p->next	= e; 
		return head;
	} 
	};//按照ppt算法这里会发生一个错误的转化 
	p->next = e;
	return head;
}
void DFS(Elink G[],int x);
void BFS(Elink G[],int x);//把函数定义在后面还可以避免全局变量无法使用 好哇 
Elink edge1[105];
int Visit[105];
int queue[20000];
int first = 0 , last = 0; 
int main(){
	int vn , en;
	int v1 , v2;
	scanf("%d %d",&vn,&en);
	for(int i =0;i<vn;i++){ 
		edge1[i].next = NULL;
	}
	for(int i =0;i<en;i++){
		scanf("%d %d",&v1,&v2);//第一个的point里是没东西的 但是后面的point里需要有东西 
		edge1[v1].next = insert(edge1[v1].next,v2);
		edge1[v2].next = insert(edge1[v2].next,v1);
	}
/*	for(int i = 0;i<vn;i++){
		Elink*p = edge1[i].next;
		printf("%d ",i);
		while(p!=NULL){
			printf("%d ",p->point);
			p = p->next;
		}
		printf("\n");
	}这里是打印出邻接表*/
	int dd = 0;
	scanf("%d",&dd);
	DFS(edge1,0);
	printf("\n");
	memset(Visit,0,105);
	BFS(edge1,0);
	printf("\n");
	memset(Visit,0,105);
	Visit[dd] = 1;//好哇
	DFS(edge1,0);
	printf("\n");
	memset(Visit,0,105);
	Visit[dd] = 1;
	BFS(edge1,0);
	printf("\n");	
	return 0;
}
void DFS(Elink G[],int x){
	Elink *p;
	Visit[x] = 1;
	printf("%d ",x);
	for(p = G[x].next;p!=NULL;p = p->next){
		if(!Visit[p->point]) 
		DFS(G,p->point);
	}
}
void BFS(Elink G[],int x){
	Visit[x] = 1; 
	printf("%d ",x);
	queue[last++] = x;
	Elink *p = NULL;
	while(first!=last){
		int v = queue[first++];
		for(p = G[v].next;p!=NULL;p = p->next){
			if(!Visit[p->point]){
				printf("%d ",p->point);
				Visit[p->point] = 1;
				queue[last++] = p->point;
			}
		}
	}
}

