#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define INFINITE 42001
typedef struct edge{
	int adjvex;
	int weight;
	struct edge* next; 
}E;
typedef struct edge* pE;
typedef struct ver{
	int vertax;
	pE link;
}V;
V v[105];
int visit[105];
void insert(int a,int b);
void DFS(int m);
void BFS(int m);

int main(){
	pE p;
	int num_v,num_e,i,id_del,a,b;
	scanf("%d%d",&num_v,&num_e);
	for (i=0;i<num_v+5;i++){
		v[i].vertax=i;
		v[i].link=NULL;
	}
	for (i=0;i<num_e;i++){
		scanf("%d%d",&a,&b);
		insert(a,b);
		insert(b,a);
	}
	scanf("%d",&id_del);
	DFS(0);
	printf("\n");
	for (i=0;i<num_e+5;i++){
		visit[i]=0;
	}
	BFS(0);
	printf("\n");
	for (i=0;i<num_e+5;i++){
		visit[i]=0;
	}
	visit[id_del]=1;
	DFS(0);
	printf("\n");
	for (i=0;i<num_e+5;i++){
		visit[i]=0;
	}
	visit[id_del]=1;
	BFS(0);
	return 0;
}

void insert(int a,int b){
	int i,j;
	pE p,r;
	r=(pE)malloc(sizeof(E));
	r->next=NULL;
	r->adjvex=b;
	p=v[a].link;
	if (v[a].link==NULL){
		v[a].link=r;
		return;
	}
	else{
		if (b<v[a].link->adjvex){
			r->next=v[a].link;
			v[a].link=r;
			return;
		}
		else{
			while (p->next!=NULL&&p->next->adjvex<b){
				p=p->next;
			}
			r->next=p->next;
			p->next=r;
		}
	}
}

void DFS(int m){
	pE p;
	visit[m]=1;
	printf("%d ",m);
	for (p=v[m].link;p!=NULL;p=p->next){
		if (visit[p->adjvex]==0){
			DFS(p->adjvex);
		}
	}
}

void BFS(int m){
	int queue[205],fro,rear;
	pE p;
	printf("%d ",m);
	visit[m]=1;
	queue[0]=m; fro=0; rear=0;
	while (rear>=fro){
		for (p=v[queue[fro++]].link;p!=NULL;p=p->next){
			if (visit[p->adjvex]==0){
				printf("%d ",p->adjvex);
				visit[p->adjvex]=1;
				queue[++rear]=p->adjvex;
			}
		}
	}
}

