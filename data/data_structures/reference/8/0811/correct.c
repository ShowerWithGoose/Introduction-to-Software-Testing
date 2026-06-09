#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 110
struct edge { //边结点
	int adjvex; //邻接顶点
	struct edge *next;
};
struct ver { //顶点结点
	struct edge *link;
};
struct ver G[MAX];
int visited[MAX]; //标记是否访问
int queue[MAX]; //BFS队列
int front = 0, rear = -1, count = 0; //队头，队尾，队列中元素数
int vertexNum, edgeNum, Vdel;
struct edge *insertEdge(struct edge *head, int avex) {
	struct edge *e, *p, *q = NULL;
	e = (struct edge *)malloc(sizeof(struct edge));
	e->adjvex = avex;
	e->next = NULL;
	if (head == NULL) {
		head = e;
		return head;
	} else if (head->adjvex > avex) { //插到head前
		e->next = head;
		head = e;
	} else {
		for (q = p = head; p != NULL && p->adjvex < avex; q = p, p = p->next);
		if (q == NULL) {
			p->next = e;
		} else {
			q->next = e;
			e->next = p;
		}
		return head;
	}
};

void DFS(struct ver G[], int v) {
	struct edge *p;
	visited[v] = 1;
	printf("%d ", v);
	for (p = G[v].link; p != NULL; p = p->next) {
		if (!visited[p->adjvex]) {
			DFS(G, p->adjvex);
		}
	}
}
void BFS(struct ver G[], int v) {
	int temp;
	visited[v] = 1;
	queue[++rear] = v;
	count++;
	while (count != 0) {
		temp = queue[front++];
		count--;
		printf("%d ", temp);
		for (struct edge *p = G[temp].link; p != NULL; p = p->next) {
			if (!visited[p->adjvex]) {
				visited[p->adjvex] = 1;
				queue[++rear] = p->adjvex;
				count++;
			}
		}
	}
}
int main() {
	scanf("%d %d", &vertexNum, &edgeNum); //读入顶点数，边数
	int v1, v2;
	for (int i = 0; i < edgeNum; i++) {
		scanf("%d %d", &v1, &v2);
		G[v1].link = insertEdge(G[v1].link, v2);
		G[v2].link = insertEdge(G[v2].link, v1);
	}
	scanf("%d", &Vdel); //读入待删除结点序号
//	for (int i = 0; i < vertexNum; i++) {
//		printf("%d -> ", i);
//		for (struct edge *p = G[i].link; p != NULL; p = p->next) {
//			printf("%d ", p->adjvex);
//		}
//		printf("\n");
//	}
	DFS(G, 0); //1.删除前DFS
	printf("\n");
	memset(visited, 0, sizeof(visited));
	BFS(G, 0); //2.删除前BFS
	printf("\n");
	memset(visited, 0, sizeof(visited));
	visited[Vdel] = 1; //删除一个顶点
	DFS(G, 0); //3.删除后DFS
	printf("\n");
	memset(visited, 0, sizeof(visited));
	visited[Vdel] = 1; //删除一个顶点
	BFS(G, 0); //4.删除后BFS
	return 0;
}

