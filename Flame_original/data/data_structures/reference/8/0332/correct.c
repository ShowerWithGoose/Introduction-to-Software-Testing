#include<stdio.h>
#include<stdlib.h>
typedef char VertexType; /* 顶点类型应由用户定义  */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */
typedef struct {
	VertexType vexs[100]; /* 顶点表 */
	EdgeType arc[100][100];/* 邻接矩阵，可看作边表 */
	int numNodes, numEdges; /* 图中当前的顶点数和边数  */
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
MGraph p;
int visited[100];
int main() {
	CreateMGraph(&p);
	DFSTraverse(p);
	BFSTraverse(p);
	int k;
	scanf("%d", &k);
	for (int i = 0; i < p.numNodes; i++) {
		p.arc[k][i] = p.arc[i][k] = 65535;
	}
	p.vexs[k] = 0;
	DFSTraverse(p);
	BFSTraverse(p);
}
void BFSTraverse(MGraph r) {
	for (int i = 0; i < r.numNodes; i++) {
		visited[i] = 0;
	}
	Queue queue;
	queue.front = queue.rear = (QueueNodePtr)malloc(sizeof(QueueNode));
	queue.front->next = NULL;
	for (int i = 0; i < r.numNodes; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			if (r.vexs[i] == 1)printf("%d ", r.vexs[i]-1);
			EnQueue(&queue, i);
			while (queue.front != queue.rear) {
				int k;
				DeQueue(&queue, &k);
				for (int l = 0; l < r.numNodes; l++) {
					if (r.arc[k][l]==1 && (!visited[l])) {
						EnQueue(&queue, l);
						visited[l] = 1;
						printf("%d ", r.vexs[l]-1);
					}
				}
			}
		}
	}
	printf("\n");
}
void DFSTraverse(MGraph r) {
	for (int i = 0; i < r.numNodes; i++) {
		visited[i] = 0;
	}
	for (int i = 0; i < r.numNodes; i++) {
		if (!visited[i])DFS(r, i);
	}
	printf("\n");
}
void DFS(MGraph r, int i) {
	visited[i] = 1;
	if (r.vexs[i])printf("%d ", r.vexs[i] - 1);
	for (int j = 0; j < r.numNodes; j++) {
		if (!visited[j] && r.arc[i][j] == 1)
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
	int i, j, k;
	scanf("%d %d", &G->numNodes, &G->numEdges); /* 输入顶点数和边数 */
	for (i = 0; i < G->numNodes; i++) /* 读入顶点信息,建立顶点表 */
		G->vexs[i] = i + 1;
	for (i = 0; i < G->numNodes; i++)
		for (j = 0; j < G->numNodes; j++)
			G->arc[i][j] = 65535;	/* 邻接矩阵初始化 */
	for (k = 0; k < G->numEdges; k++) { /* 读入numEdges条边，建立邻接矩阵 */
		scanf("%d %d", &i, &j);
		G->arc[j][i] = G->arc[i][j] = 1; /* 因为是无向图，矩阵对称 */
	}
}

