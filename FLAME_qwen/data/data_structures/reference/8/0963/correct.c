#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct edge{
	int adjvex;//邻接节点
	int weight;
	struct edge *next;
}Elink;//边节点 
typedef struct ver{
	int vertex;//顶点 
	Elink *link; 
}Vlink;
Elink *insertEdge(Elink *head,int avex){
	Elink *e,*p;
	e=(Elink*)malloc(sizeof(Elink));
	e->adjvex=avex;
	e->weight=1;
	e->next=NULL;
	if(head!=NULL){
		for(p=head;p->next!=NULL;p=p->next);
		p->next=e;
	}
	else{
		head=e;
	}
	return head;
}
Vlink graph[200];
int visit[100]={0};
void DFS(Vlink g[],int v){
	Elink* p;
	visit[v]=1;
	printf("%d ",v);
	for(p=g[v].link;p!=NULL;p=p->next){
		if(!visit[p->adjvex])
		  DFS(g,p->adjvex);
	} 
}
void travelDFS(Vlink g[],int n){
	int i;
	for(i=0;i<n;i++){
		if(!visit[i])
			DFS(g,i);
	}
}

//广度优先遍历BFS
int queue[100];
int head,end;
void BFS(Vlink g[],int v){
	head=end=0;
	Elink *p;
	visit[v]=1;
	queue[end]=v;
	end++;
	while(head!=end){
		v=queue[head];
		printf("%d ",v);
		head++;
		for(p=g[v].link;p!=NULL;p=p->next) {
			if(!visit[p->adjvex]){
				visit[p->adjvex]=1;
				queue[end]=p->adjvex;
				end++;
			}
		}
	}
}
void travelBFS(Vlink g[],int n){
	int i;
	for(i=0;i<n;i++)
		if(!visit[i]) BFS(g,i);
}
int main(int argc,const char *argv[]){
	int n,a,i,v1,v2,cnt[150]={0},temp,j;
	for(i=0;i<200;i++)
		graph[i].link=NULL;
	scanf("%d%d",&n,&a);
//	printf("%d %d\n",n,a);
	for(i=0;i<a;i++){
		scanf("%d %d",&v1,&v2);
//		printf("%d %d\n",v1,v2);
		cnt[v1]++;
		cnt[v2]++;
		graph[v1].link=insertEdge(graph[v1].link,v2);
		graph[v2].link=insertEdge(graph[v2].link,v1);
	}
	Elink *p;
	for(i=0;i<n-1;i++){
		for(j=0;j<cnt[i]-1;j++){
			p=graph[i].link;
			while(p->next!=NULL){
				if(p->adjvex>p->next->adjvex){
					temp=p->adjvex;
					p->adjvex=p->next->adjvex;
					p->next->adjvex=temp;
				}
				p=p->next;
			}
		}
	}
/*	for(i=0;i<n;i++){
		printf("%d ",i);
		Elink *p;
		p=graph[i].link;
		while(p!=NULL){
			printf("%d ",p->adjvex);
			p=p->next;
		}
		printf("\n");
	}
	printf("\n");*/
	travelDFS(graph,n);
	printf("\n");
	for(i=0;i<n;i++) visit[i]=0;
	travelBFS(graph,n);
	printf("\n");
	int v;
	scanf("%d",&v);
	visit[v]=1;
/*	for(i=0;i<n;i++){
		p=graph[i].link;
		if(p->adjvex==v)
			graph[i].link=p->next;
		else{
			while(p->next!=NULL){
				if(p->next->adjvex==v){
					p->next=p->next->next;
				}
				p=p->next;
			}
		}
	}*/
	for(i=0;i<n;i++) visit[i]=0;
	visit[v]=1;
	travelDFS(graph,n);
	printf("\n");
	for(i=0;i<n;i++) visit[i]=0;
	visit[v]=1;
	travelBFS(graph,n);
	return 0;
}


