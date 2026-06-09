#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct Edge {
	int adjvex;
	struct Edge* next;
} Edge,*PEdge;

typedef struct Vertex {
	int vertex;
	PEdge link;
} Vertex,*PVertex;


void adjListAdd(PVertex vertex,int v,PEdge pe) {
	PEdge p=vertex[v].link;
	if(p==NULL) vertex[v].link=pe;
	else {
		if(pe->adjvex<p->adjvex) {
			vertex[v].link=pe;
			pe->next=p;
		} else {
			while(p->next!=NULL&&p->next->adjvex<pe->adjvex) {
				p=p->next;
			}
			pe->next=p->next;
			p->next=pe;
		}
	}
	return;
}

void adjListCreate(int edge[][2],PVertex vertex,int e) {
	int i=0,j=0;
	PEdge pe=NULL;
	for(i=0; i<e; i++) {
		for(j=0; j<2; j++) {
			pe=(PEdge)malloc(sizeof(Edge));
			pe->adjvex=edge[i][j];
			pe->next=NULL;
			adjListAdd(vertex,edge[i][1-j],pe);
		}
	}
	return;
}

void adjListDelete(PVertex vertex,int node) {
	PEdge p1=NULL,p2=NULL,p3=NULL;
	p1=vertex[node].link;
	while(p1!=NULL) {
		p2=vertex[p1->adjvex].link;
		if(p2->adjvex==node) vertex[p1->adjvex].link=p2->next;
		else {
			while(p2->next!=NULL&&p2->next->adjvex!=node) {
				p2=p2->next;
			}
			if(p2->next==NULL) {
				printf("Error!\n");
			} else {
				p2->next=p2->next->next;
			}
		}
		p1=p1->next;
	}
	return;
}

void DFSvisit(PVertex vertex,int v,int flag[]) {
	PEdge p=NULL;
	flag[v]=1;
	printf("%d ",vertex[v].vertex);
	for(p=vertex[v].link; p!=NULL; p=p->next) {
		if(!flag[p->adjvex]) DFSvisit(vertex,p->adjvex,flag);
	}
	return;
}

void DFS(PVertex vertex,int v) {
	int  flag[v];
	int i;
	for(i=0; i<v; i++) flag[i] = 0 ;
	DFSvisit(vertex,0,flag);
	printf("\n");
	return;
}

typedef struct Queue {
	int data[105];
	int head;
	int rear;
} Queue;

Queue Q= {{0},1,0};

int emptyQ() {
	if(Q.head==(Q.rear+1)%105) return 1;
	else return 0;
}

void enQueue(int v) {
	Q.rear=(Q.rear+1)%105;
	Q.data[Q.rear]=v;
	return;
}

int deQueue() {
	int p=Q.data[Q.head];
	Q.head=(Q.head+1)%105;
	return p;
}

void BFSvisit(PVertex vertex, int v,int flag[]) {
	PEdge p=NULL;
	flag[v] = 1; //标识某顶点已入队
	enQueue(v);
	while(!emptyQ()) {
		v = deQueue();  //取出队头元素
		printf("%d ",vertex[v].vertex); //访问当前顶点
		for(p=vertex[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
			if(!flag[p->adjvex] ) {
				flag[p->adjvex] = 1; //标识某顶点入队
				enQueue(p->adjvex);
			}
	}
	return;
}

//标识顶点是否被访问守，N为顶点数
void  BFS(PVertex vertex, int v) {
	int flag[v];
	int i;
	for(i=0; i<v; i++) flag[i] = 0 ;
	BFSvisit(vertex, 0,flag);
	printf("\n");
	return;
}


int main() {
	int v=0,e=0;
	scanf("%d %d",&v,&e);

	PVertex vertex=(PVertex)malloc(sizeof(Vertex)*v);

	int i=0,j=0;
	for(i=0; i<v; i++) {
		vertex[i].vertex=i;
		vertex[i].link=NULL;
	}

	int edge[e][2];
	for(i=0; i<e; i++) {
		scanf("%d %d",&edge[i][0],&edge[i][1]);
	}
	adjListCreate(edge,vertex,e);
	DFS(vertex,v);
	BFS(vertex,v);

	int node=0;
	scanf("%d",&node);
	adjListDelete(vertex,node);
	DFS(vertex,v);
	BFS(vertex,v);
	return 0;
}


















