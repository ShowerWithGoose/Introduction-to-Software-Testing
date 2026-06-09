#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct edge{
	int adjvex;
	struct edge *next;
}ELink;

typedef struct ver{
	int vertex;
	ELink *link;
}VLink;

VLink edge[100];
int visited[100] = {0};
int Q[1000];
int front,rear;

void ADJLIST(VLink G[],int n,int e);
void travel_DFS(VLink G[],int n,int del);
void travel_BFS(VLink G[],int n,int del);
void DFS(VLink G[],int v);
void BFS(VLink G[],int v);

int main(){
	int a,e,n;
	scanf("%d%d",&n,&e);
	ADJLIST(edge,n,e);
	
	travel_DFS(edge,n,-1);
	travel_BFS(edge,n,-1);
	
	scanf("%d",&a);
	travel_DFS(edge,n,a);
	travel_BFS(edge,n,a);
	
	return 0;
}

ELink *build(ELink *G,int n){
	ELink *p,*q,*r;
	p = (ELink *)malloc(sizeof(ELink));
	p->adjvex = n,p->next = NULL;
	if(G == NULL)
		return p;
	else{
		for(q = G,r = NULL;q != NULL;r = q,q = q->next){
			if(n < q->adjvex)
				break;
		}
		if(r == NULL){
			p->next = G;
			return p;
		}
		else{
			p->next = q;
			r->next = p;
			return G;
		}
	}
}

void ADJLIST(VLink G[],int n,int e){
	int i,vi,vj;
	for(i = 0;i < e;i++){
		scanf("%d%d",&vi,&vj);
		edge[vi].link = build(edge[vi].link,vj);
		edge[vj].link = build(edge[vj].link,vi);
	}
}

void travel_DFS(VLink G[],int n,int del){
	int i;
	for(i = 0;i < n;i++){
		visited[i] = 0;
	}
	if(del >= 0){
		visited[del] = 1;
	}
	for(i = 0;i < n;i++){
		if(visited[i] == 0)
			DFS(G,i);
	}
	printf("\n");
}

void DFS(VLink G[],int v){
	ELink *p;
	printf("%d ",v);
	visited[v] = 1;
	for(p = G[v].link;p != NULL;p = p->next){
		if(visited[p->adjvex] == 0)
			DFS(G,p->adjvex);
	}
}

void travel_BFS(VLink G[],int n,int del){
	int i;
	for(i = 0;i < n;i++){
		visited[i] = 0;
	}
	if(del >= 0)
		visited[del] = 1;
	for(i = 0;i < n;i++){
		if(visited[i] == 0)
			BFS(G,i);
	}
	printf("\n");
}

void BFS(VLink G[],int v){
	ELink *p;
	front = 0;
	rear = 0;
	visited[v] = 1;
	Q[rear] = v;
	while(front >= rear){
		v = Q[rear++];
		printf("%d ",v);
		for(p = G[v].link;p != NULL;p = p->next){
			if(visited[p->adjvex] == 0){
				visited[p->adjvex] = 1;
				Q[++front] = p->adjvex;
			}
		}
	}
}



