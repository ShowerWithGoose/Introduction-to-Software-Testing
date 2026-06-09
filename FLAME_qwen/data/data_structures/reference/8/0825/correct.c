#include<stdio.h>
#include<stdlib.h>
#define MAX 256
typedef struct edge {
	int adj;
	int wei;
	struct edge *next;
} ELink;
typedef struct ver {
	struct edge *link;
} VLink;
int D,V;
VLink G[MAX];
int Visited[MAX]= {0};
int Queue[MAX];
int front=0,rear=-1,N=0;
void createGraph(VLink graph[]);
ELink *insertEdge(ELink *head,int avex);
void print(VLink graph[]);
void travelDFS(VLink graph[],int n);
void DFS(VLink graph[],int v);
void travelBFS(VLink graph[],int n);
void BFS(VLink graph[],int v);
void enQueue(int x);
int deQueue(void);
int empty(void);
void delete(int x);
void travelDFS_new(VLink graph[],int n,int x);
void DFS_new(VLink graph[],int v);
void travelBFS_new(VLink graph[],int n,int x);
void BFS_new(VLink graph[],int v);
int main() {
	createGraph(G);
//	print(G);
	travelDFS(G,D);
	printf("\n");
	travelBFS(G,D);
	printf("\n");
	int x;
	scanf("%d",&x);
	delete(x);
	travelDFS_new(G,D,x);
	printf("\n");
	travelBFS_new(G,D,x);
	return 0;
}
void createGraph(VLink graph[]) {

	scanf("%d %d",&D,&V);
	int i,v1,v2;
	for(i=0; i<V; i++) {
		scanf("%d %d",&v1,&v2);
		graph[v1].link=insertEdge(graph[v1].link,v2);
		graph[v2].link=insertEdge(graph[v2].link,v1);
	}
}
ELink *insertEdge(ELink *head,int avex) {
	ELink *e,*p,*q;
	e=(ELink *)malloc(sizeof(ELink));
	e->adj=avex;
	e->wei=1;
	e->next=NULL;
	if(head==NULL) {
		head=e;
		return head;
	}
	if(e->adj<head->adj) {
		e->next=head;
		head=e;
		return head;
	}
	int flag=0;
	for(p=head; p!=NULL; q=p,p=p->next) {
		if(p->adj>avex) {
			e->next=p;
			q->next=e;
			flag=1;
			return head;
		}
	}
	q->next=e;
	return head;
}
void print(VLink graph[]) {
	int i;
	ELink *p;
	for(i=0; i<D; i++) {
		printf("%d的链结点：",i);
		for(p=graph[i].link; p!=NULL; p=p->next) {
			printf("%d ",p->adj);
		}
		printf("\n");
	}
}
void delete(int x) {
	int i;
	ELink *p;
	for(i=0; i<D; i++) {
		for(p=G[i].link; p!=NULL; p=p->next) {
			if(p->adj==x)p->wei=0;
		}
	}
/*	for(i=0; i<D; i++) {
		printf("%d的链结点：",i);
		for(p=G[i].link; p!=NULL; p=p->next) {
			if(p->wei==1)printf("%d ",p->adj);
		}
		printf("\n");
	}*/
}
//深度遍历
void travelDFS(VLink graph[],int n) {
	int i;
	for(i=0; i<n; i++)Visited[i]=0;
	for(i=0; i<n; i++)
		if(!Visited[i])DFS(graph,i);
}
void DFS(VLink graph[],int v) {
	ELink *p;
	Visited[v]=1;
	printf("%d ",v);
	for(p=graph[v].link; p!=NULL; p=p->next) {
		if(!Visited[p->adj])
			DFS(graph,p->adj);
	}
}
void travelBFS(VLink graph[],int n) {
	int i;
	for(i=0; i<n; i++)Visited[i]=0;
	for(i=0; i<n; i++) {
		if(!Visited[i])BFS(graph,i);
	}
}
void BFS(VLink graph[],int v) {
	ELink *p;
	Visited[v]=1;
	enQueue(v);
	while(!empty()) {
		v=deQueue();;
		printf("%d ",v);
		for(p=graph[v].link; p!=NULL; p=p->next) {
			if(!Visited[p->adj]) {
				Visited[p->adj]=1;
				enQueue(p->adj);
			}

		}
	}
}

void travelDFS_new(VLink graph[],int n,int x) {
	int i;
	for(i=0; i<n; i++)Visited[i]=0;
	for(i=0; i<n; i++)
		if(i!=x)
			if(!Visited[i])DFS_new(graph,i);
}
void DFS_new(VLink graph[],int v) {
	ELink *p;
	Visited[v]=1;
	printf("%d ",v);
	for(p=graph[v].link; p!=NULL; p=p->next) {
		if(!Visited[p->adj]&&p->wei==1)
			DFS_new(graph,p->adj);
	}
}
void travelBFS_new(VLink graph[],int n,int x) {
	int i;
	for(i=0; i<n; i++)Visited[i]=0;
	for(i=0; i<n; i++) {
		if(i!=x)
			if(!Visited[i])BFS_new(graph,i);
	}
}
void BFS_new(VLink graph[],int v) {
	ELink *p;
	Visited[v]=1;
	enQueue(v);
	while(!empty()) {
		v=deQueue();;
		printf("%d ",v);
		for(p=graph[v].link; p!=NULL; p=p->next) {
			if(!Visited[p->adj]&&p->wei==1) {
				Visited[p->adj]=1;
				enQueue(p->adj);
			}

		}
	}
}
void enQueue(int x) {
	N++;
	Queue[++rear]=x;
}
int deQueue(void) {
	N--;
	return Queue[front++];
}
int empty(void) {
	return N==0;
}


