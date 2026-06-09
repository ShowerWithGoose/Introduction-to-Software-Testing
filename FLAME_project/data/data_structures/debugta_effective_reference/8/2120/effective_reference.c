#include<stdio.h>
#include<stdlib.h>
typedef char VertexType; /* 顶点类型应由用户定义  */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */
typedef struct {
	VertexType vertex[100]; /* 顶点表 */
	EdgeType arc[100][100];/* 邻接矩阵，可看作边表 */
	int vCount, eCount; /* 图中当前的顶点数和边数  */
} MGraph;
/* 建立无向网图的邻接矩阵表示 */
typedef struct QueueNode {
	struct QueueNode * next;
	int data;
} QueueNode, *QueueNodePtr;
typedef struct Queue {
	QueueNodePtr front, rear;
} Queue;
void EnQueue(Queue *L, int e);
void DeQueue(Queue *L, int *e);
void CreateMGraph(MGraph *G);
void DFSTraverse(MGraph r);
void BFSTraverse(MGraph r);
void DFS(MGraph r, int i);
MGraph G;
int flag[100];
int main() {
	CreateMGraph(&G);
	DFSTraverse(G);
	BFSTraverse(G);
	int del;
	scanf("%d", &del);
	for (int i = 0; i < G.vCount; i++) {
		G.arc[del][i] = G.arc[i][del] = 65535;
	}
	G.vertex[del] = 0;
	DFSTraverse(G);
	BFSTraverse(G);
}
void BFSTraverse(MGraph r) {
	for (int i = 0; i < r.vCount; i++) {
		flag[i] = 0;
	}
	Queue queue;
	queue.front = queue.rear = (QueueNodePtr)malloc(sizeof(QueueNode));
	queue.front->next = NULL;
	for (int i = 0; i < r.vCount; i++) {
		if (!flag[i]) {
			flag[i] = 1;
			if (r.vertex[i] == 1)printf("%d ", r.vertex[i]-1);
			EnQueue(&queue, i);
			while (queue.front != queue.rear) {
				int del;
				DeQueue(&queue, &del);
				for (int l = 0; l < r.vCount; l++) {
					if (r.arc[del][l]==1 && (!flag[l])) {
						EnQueue(&queue, l);
						flag[l] = 1;
						printf("%d ", r.vertex[l]-1);
					}
				}
			}
		}
	}
	printf("\n");
}
void DFSTraverse(MGraph r) {
	for (int i = 0; i < r.vCount; i++) {
		flag[i] = 0;
	}
	for (int i = 0; i < r.vCount; i++) {
		if (!flag[i])DFS(r, i);
	}
	printf("\n");
}
void DFS(MGraph r, int i) {
	flag[i] = 1;
	if (r.vertex[i])printf("%d ", r.vertex[i] - 1);
	for (int j = 0; j < r.vCount; j++) {
		if (!flag[j] && r.arc[i][j] == 1)
			DFS(r, j);
	}
}
void EnQueue(Queue *L, int e) {
	QueueNodePtr r = (QueueNodePtr)malloc(sizeof(QueueNode));
	r->data = e;
	r->next = NULL;
	L->rear->next = r;
	L->rear = r;
}
void DeQueue(Queue *L, int *e) {
	QueueNodePtr r;
	if (L->rear == L->front)return;
	r = L->front->next;
	*e = r->data;
	L->front->next = r->next;
	if (L->rear == r)L->rear = L->front;
	free(r);
}
void CreateMGraph(MGraph *G) {
	int i, j, del;
	scanf("%d %d", &G->vCount, &G->eCount); /* 输入顶点数和边数 */
	for (i = 0; i < G->vCount; i++) /* 读入顶点信息,建立顶点表 */
		G->vertex[i] = i + 1;
	for (i = 0; i < G->vCount; i++)
		for (j = 0; j < G->vCount; j++)
			G->arc[i][j] = 65535;	/* 邻接矩阵初始化 */
	for (del = 0; del < G->eCount; del++) { /* 读入numEdges条边，建立邻接矩阵 */
		scanf("%d %d", &i, &j);
		G->arc[j][i] = G->arc[i][j] = 1; /* 因为是无向图，矩阵对称 */
	}
}

