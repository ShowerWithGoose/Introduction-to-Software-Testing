#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define M 1000

typedef struct edge {
	int adjvex;
	int wei;
	struct edge *next;
} Elink;

typedef struct ver {
	Elink *link;
} Vlink;

int NV,NVE;
Vlink *Graph;
int *Visited;

typedef struct {
	int array[M];
	int front,rear;
} Q;

Q *Queue;

void initQ() {
	//printf("初始化队列\n");
	Queue=(Q *)calloc(1,sizeof(Q));
	Queue->front=Queue->rear=-1;
}

void initV() {
	//printf("初始化访问数组\n");
	int i;
	for(i=0; i<NV; i++)
		Visited[i]=0;
}

void showV(){
//	printf("显示访问数组%d,%d\n",NV,NVE);
	int i;
	for(i=0;i<NV;i++)
		printf("%d ",Visited[i]);
}

int emptyQ(Q *q) {
	return q->front==q->rear;
}

int enQueue(Q *q,int v) {
	if((q->rear+1)%M==q->front)
		return 0;
	else {
		q->array[++q->rear%M]=v;
		return 1;
	}
}

int deQueue(Q *q) {
	int v;
	q->front=(q->front+1) % M;
	v=q->array[q->front];
	return v;
}

Elink *insertEdge(Elink *head,int avex) {
	Elink *e,*p,*q=NULL;
	e=(Elink *)calloc(1,sizeof(Elink));
	e->adjvex=avex;
	e->wei=1;
	e->next=NULL;
	if(head==NULL||head->adjvex > e->adjvex) {
		e->next=head;
		head=e;
		return head;
	} else {
		p=head;
		while(p!=NULL && e->adjvex > p->adjvex) {
			q=p;
			p=p->next;
		}
		e->next=p;
		q->next=e;
	}
	return head;
}

void createGraph(Vlink *Graph,int n) {
	int i,v1,v2;
	for(i=0; i<n; i++) {
		scanf("%d%d",&v1,&v2);
		Graph[v1].link=insertEdge(Graph[v1].link,v2);
		Graph[v2].link=insertEdge(Graph[v2].link,v1);
	}
}

void deleteGraph(Vlink *Graph,int n) {
	Elink *p,*q,*r;
	//找到被删结点所有邻接结点
	for(p=Graph[n].link; p!=NULL; p=p->next) {
		int v=p->adjvex;
		q=Graph[v].link;
		if(q->adjvex==n) {
			Graph[v].link=Graph[v].link->next;
		} else {
			r=q;
			while( q->adjvex!=n) {
				r=q;
				q=q->next;
			}
			r->next=q->next;
		}
	}
}

void DFS(Vlink Graph[],int v) {
	Elink *p;
	Visited[v]=1;
	printf("%d ",v);
	for(p=Graph[v].link; p!=NULL; p=p->next) {
		if(!Visited[p->adjvex]) {
			DFS(Graph,p->adjvex);
		}
	}
}

void BFS(Vlink Graph[],int v) {
	Elink *p;
	initV();
	Visited[v]=1;
	enQueue(Queue,v);
	while(!emptyQ(Queue)) {
		v=deQueue(Queue);
		printf("%d ",v);
		for(p=Graph[v].link; p!=NULL; p=p->next)
			if(!Visited[p->adjvex]) {
				Visited[p->adjvex]=1;
				enQueue(Queue,p->adjvex);
			}
	}
}

void showAllVex(Vlink Graph[],int n) {
	int i;
	Elink *p;
	for(i=0; i<n; i++) {
		printf("%d ",i);
		p=Graph[i].link;
		while(p!=NULL) {
			printf("%d ",p->adjvex);
			p=p->next;
		}
		printf("\n");
	}
}

void testQueue() {
	initQ();
	printf("isemptyQ:%d\n",emptyQ(Queue));
	int i;
	for(i=1; i<9; i++)
		enQueue(Queue,i*i);
	for(i=1; i<9; i++)
		printf("pop %d\n",deQueue(Queue));
}

int main() {
	int v;
	scanf("%d%d",&NV,&NVE);

	Graph=(Vlink *)calloc(NV,sizeof(Vlink));
	Visited=(int *)calloc(NV,sizeof(int));
	createGraph(Graph,NVE);
	
	scanf("%d",&v);
	
	initV();
	DFS(Graph,0);
	printf("\n");
	initQ();
	BFS(Graph,0);
	printf("\n");
	deleteGraph(Graph,v);
//	showAllVex(Graph,NV);
	initV();
	DFS(Graph,0);
	printf("\n");
	BFS(Graph,0);
	return 0;
}

