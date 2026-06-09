#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef int Status;
#define MAX_SIZE 1000
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define VISITED 1
#define UNVISITED 0

int visited[MAX_SIZE];

typedef enum {
    DG,
    UDG,
    NG,
    UNG
} GraphKind;

typedef struct {
	int v;;
} Vertex;

typedef struct {
	Vertex VerTexs[MAX_SIZE];
	int Edges[MAX_SIZE][MAX_SIZE];
	int VerTex;
	int Edge;
	GraphKind kind;
} Graph;

typedef struct {
	int front;
	int rear;
	Vertex vertex[MAX_SIZE];
} Queue;

void InitQueue(Queue *queue) {
	queue->front=0;
	queue->rear=0;
}

void OfferQueue(Queue *queue, Vertex vertex) {
	queue->vertex[queue->rear]=vertex;
	queue->rear=queue->rear+1;
}

Vertex PollQueue(Queue *queue) {
	Vertex vertex;
	vertex=queue->vertex[queue->front];
	queue->front=queue->front+1;
	return vertex;
}

/** 创建无向图 */
Status CreateUDG(Graph *G) {
	int i,j;
	Vertex *v1=(Vertex*)malloc(sizeof(Vertex));
	Vertex *v2=(Vertex*)malloc(sizeof(Vertex));
	G->kind=UDG;
	scanf("%d",&G->VerTex);
	scanf("%d",&G->Edge);
	for(i=0; i<G->VerTex; i++) {
		G->VerTexs[i].v=i;
	}
	for(i=0; i<G->VerTex; i++) {
		for(j=0; j<G->VerTex; j++) {
			G->Edges[i][j]=0;
		}
	}
	for(i=0; i<G->Edge; i++) {
		scanf("%d",&v1->v);
		scanf("%d",&v2->v);
		if(v1->v==-1||v2->v==-1) return ERROR;
		G->Edges[v1->v][v2->v]=1;
		G->Edges[v2->v][v1->v]=G->Edges[v1->v][v2->v];
	}
	free(v1);
	free(v2);
	return OK;
}

void DFSFind(Graph *G,int index) {
	int i;
	printf("%d ",G->VerTexs[index].v);
	visited[index]=VISITED;
	for(i=DFSLocation(G,G->VerTexs[index].v); i!=0; i=DFSLocation(G,G->VerTexs[index].v)) {
		DFSFind(G,i);
	}
}

/** 深度优先遍历 */
void DFS(Graph *G) {
	int i;
	for(i=0; i<G->VerTex; i++) {
		visited[i]=UNVISITED;
	}
	for(i=0; i<G->VerTex; i++) {
		if(visited[i]==UNVISITED) {
			DFSFind(G,i);
		}
	}
}

void DFS1(Graph *G,int index) {
	int i;
	for(i=0; i<G->VerTex; i++) {
		visited[i]=UNVISITED;
	}
	visited[index]=VISITED;
	for(i=0; i<G->VerTex; i++) {
		if(visited[i]==UNVISITED) {
			DFSFind(G,i);
		}
	}
}

void BFSFind(Graph *G,Queue *queue) {
	int i,index,mode=0;
	Vertex vertex0;
	vertex0=PollQueue(queue);
	index=vertex0.v;
	if(visited[index]==UNVISITED) {
		printf("%d ",G->VerTexs[index].v);
		visited[index]=VISITED;
	}
	int DefultWeight;
	if(G->kind==UDG||G->kind==DG) DefultWeight=0;
	for(i=0; i<G->VerTex; i++) {
		if(G->Edges[index][i]!=DefultWeight&&visited[i]==UNVISITED) {
			printf("%d ",G->VerTexs[i].v);
			visited[i]=VISITED;
			OfferQueue(queue,G->VerTexs[i]);
			mode=1;
		}
	}
	if(mode==1)
	BFSFind(G,queue);
	else 
	return;
}

/** 广度优先遍历 */
void BFS(Graph *G) {
	int i;
	Queue *queue=(Queue *)malloc(sizeof(Queue));
	InitQueue(queue);
	for(i=0; i<G->VerTex; i++) {
		visited[i]=UNVISITED;
	}
	for(i=0; i<G->VerTex; i++) {
		if(visited[i]==UNVISITED) {
			if(queue->front==queue->rear)
			OfferQueue(queue,G->VerTexs[i]);
			BFSFind(G,queue);
		}
	}
	if(queue->front!=queue->rear){
		BFSFind(G,queue);
	}
}

void BFS1(Graph *G,int index) {
	int i;
	Queue *queue=(Queue *)malloc(sizeof(Queue));
	InitQueue(queue);
	for(i=0; i<G->VerTex; i++) {
		visited[i]=UNVISITED;
	}
	visited[index]=VISITED;
	for(i=0; i<G->VerTex; i++) {
		if(visited[i]==UNVISITED) {
			if(queue->front==queue->rear)
			OfferQueue(queue,G->VerTexs[i]);
			BFSFind(G,queue);
		}
	}
	if(queue->front!=queue->rear){
		BFSFind(G,queue);
	}
}

int DFSLocation(Graph *G,Vertex vertex) {
	int n,j;
	n=vertex.v;
	if(n==-1) return ERROR;
	int DefultWeight;
	if(G->kind==UDG||G->kind==DG) DefultWeight=0;
	for(j=0; j<G->VerTex; j++) {
		if(G->Edges[n][j]!=DefultWeight) {
			if(visited[j]==UNVISITED)
				return j;
		}
	}
	return 0;
}

int main() {
	Status status;
	Graph *G=(Graph*)malloc(sizeof(Graph));
	int i,del;
	status=CreateUDG(G);
	scanf("%d",&del);
	DFS(G);
	printf("\n");
	BFS(G);
	printf("\n");
	if(del==-1) return ERROR;
	for(i=0;i<G->VerTex;i++){
		G->Edges[del][i]=0;
		G->Edges[i][del]=0;
	}
	DFS1(G,del);
	printf("\n");
	BFS1(G,del);
}

