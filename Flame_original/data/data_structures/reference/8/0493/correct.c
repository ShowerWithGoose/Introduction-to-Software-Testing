#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000

struct edge{
	int adj;
	int wei;
	struct edge *next;
};
typedef struct edge e_link;
struct ver{
	e_link *link;
	int flag;
};
typedef struct ver v_link;
v_link graph[M];
	int v,e;
e_link* insert(e_link* head,int avex){
	e_link * e,*p,*q=NULL;
	e=(e_link*)malloc(sizeof(e_link));
	e->adj=avex; 
	e->wei=1;
	e->next=NULL;
	if(head==NULL)  return e;
	for(p=head;p!=NULL&&avex>p->adj;q=p,p=p->next);
	if(p==head){
		e->next=p;
		return e;
	}
	else{
		q->next=e;
		e->next=p;
		return head;
	}
}
void build_graph(v_link g[]){
	for(int i=0;i<e;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		g[v1].link=insert(g[v1].link,v2);
		g[v2].link=insert(g[v2].link,v1);		
	}
}
int flag[M]={0};
void dfs(v_link g[],int v){
	e_link *p;
	flag[v]=1;
	printf("%d ",v);
	for(p=g[v].link;p!=NULL;p=p->next){
		if(flag[p->adj]==0)
		dfs(g,p->adj);
	}
}
void DFS(v_link g[],int n,int del){
	int i;
	for(i=0;i<n;i++){
	flag[i]=0;
	}
	if(del>=0)    flag[del]=1;
	for(i=0;i<n;i++){
		if(flag[i]==0){
			dfs(g,i);
		}
	}
	printf("\n");
}
int front=0,rear=M-1,num=0;
int que[M];
void enqueue(int q[],int item){
	rear=(rear+1)%M;
	q[rear]=item;
	num++;
}
void bfs(v_link g[],int v){
	e_link *p;
	flag[v]=1;
	enqueue(que,v);
	while(num!=0){
		v=que[front];
		num--;
		front=(front+1)%M;
		printf("%d ",v);
		for(p=g[v].link;p!=NULL;p=p->next){
			if(flag[p->adj]==0){
				flag[p->adj]=1;
				enqueue(que,p->adj);
			}
		}
	}
	
}
void BFS(v_link g[],int n,int del){
	int i;
	for(i=0;i<n;i++){
		flag[i]=0;
	}
	if(del>=0)  flag[del]=1;
	for(i=0;i<n;i++){
		if(flag[i]==0)
		bfs(g,i); 
		printf("\n");
	}
}
int main(){
	scanf("%d %d",&v,&e);
	build_graph(graph);
		DFS(graph,v,-1);
		BFS(graph,v,-1);	
			int d;
		scanf("%d",&d);
		DFS(graph,v,d);
		BFS(graph,v,d);
	return 0;
} 

