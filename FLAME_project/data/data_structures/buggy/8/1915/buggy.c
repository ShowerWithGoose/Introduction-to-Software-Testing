#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

/*本篇为图的基本操作，包括创造邻接表，删除图的一个点；
图的深度遍历（递归），图的广度遍历（队列的使用）；
还有一些形参的注意事项*/
typedef struct  edge {
	int  adjvex;
	int  weight;
	struct edge *next;
} ELink;    //边结点

typedef struct ver {
	int  vertex;
	ELink *link;
} VLink;    //顶点结点
VLink  G[1024];

void insertEdge(VLink *head, int avex);
void deleteEdge(int delt);
//
int  Visited[1024] = {0}; //标识顶点是否被访问过，N为顶点数
void  travelDFS(VLink  G[ ], int n);
void DFS(VLink  G[ ], int v);
//
void  travelBFS(VLink  G[ ], int n);
void BFS(VLink  G[ ], int v);
void enQueue(int queue[ ], int item);
int  deQueue(int queue[ ]);
int n, E;

int main() {

	scanf("%d%d", &n, &E);
	for (int i = 0; i < n; i++)
		G[i].vertex = i;
	for (int i = 0; i < E; i++) {
		int ver1, ver2;
		scanf("%d%d", &ver1, &ver2);
		insertEdge( &G[ver1], ver2);   /*G[ver1]并不是一个指针，而是一个元素，只有传进去地址，才能对这个地址上的值进行操作*/
		insertEdge( &G[ver2], ver1);
	}
	travelDFS(G, n);
	printf("\n");
	travelBFS(G, n);
	printf("\n");
	int delt;
	scanf("%d", &delt);
	deleteEdge(delt);
	travelDFS(G, n);
	printf("\n");
	travelBFS(G, n);
}

void insertEdge(VLink *head, int avex) {    /**head使得head为指针，他的值是原数组的地址，因此能对原数组进行操作*/
	ELink *e, *p, *r;
	e = (ELink *)malloc(sizeof(ELink));
	e->adjvex = avex;
	e->weight = 1;
	e->next = NULL;
	if (head->link == NULL) {     /*如果还没有点。直接接到后面*/
		head->link = e;
	} else {
		r = head->link;
		for (p = head->link; p != NULL; r = p, p = p->next)
			if (p->adjvex > avex)
				break;
		if (p != NULL) {
			if (head->link == p) {     /*如果新的点要成为第一个结点，要如此做*/
				head->link = e;
				e->next = p;
			} else {                   /*否则如此*/
				r->next = e;
				e->next = p;
			}
		} else
			r->next = e;
	}
}

void deleteEdge(int delt) {
	for (int i = 0; i < n; i++) {
		if (i == delt)
			continue;
		else {
			ELink *p, *r = G[i].link;
			for (p = G[i].link; p != NULL; p = p->next) {
				if (p->adjvex == delt) {
					if (G[i].link == p) {
						G[i].link = p->next;
						free(p);
					} else {
						r->next = p->next;
						free(p);
					}

					break;
				}
			}
		}
	}
}

/**********深度优先**********/
void  travelDFS(VLink  G[ ], int n) {
	int i;
	for (i = 0; i < n; i++)
		Visited[i] = 0 ;
	/*for (i = 0; i < n; i++)
		if ( !Visited[i] )
			DFS(G, i);
	原本是可以这么写的，但是规定从零出发，所以没必要
			*/
	DFS(G, 0);
}

void DFS(VLink  G[ ], int v) {
	ELink  *p;
	Visited[v] = 1; //标识某顶点被访问过
	printf("%d ", G[v].vertex);
	for (p = G[v].link; p != NULL;  p = p->next)
		if ( !Visited[p->adjvex] )
			DFS(G, p->adjvex);
}
/**********广度优先**********/
int  QUEUE[1024];
int  Front = 0, Rear = 1023, Count = 0;

void  travelBFS(VLink  G[ ], int n) {
	int i;
	for (i = 0; i < n; i++)
		Visited[i] = 0 ;           /*前置准备：将所有点清零*/

	/*for (i = 0; i < n; i++)
		if ( !Visited[i] )
			BFS(G, i);
	原本是可以这么写的，但是规定从零出发，所以没必要
			*/

	BFS(G, 0);
}

/*广度遍历中心程序*/
void BFS(VLink  G[ ], int v) {
	ELink  *p;
	Visited[v] = 1; //标识某顶点已入队
	enQueue(QUEUE, v);
	while (Count) {
		v = deQueue(QUEUE);  //取出队头元素
		printf("%d ", G[v].vertex); //访问当前顶点
		for (p = G[v].link; p != NULL; p = p->next ) //访问该顶点的每个邻接顶点
			if ( !Visited[p->adjvex] ) {
				Visited[p->adjvex] = 1; //标识某顶点入队
				enQueue(QUEUE, p->adjvex);
			}
	}
}

void enQueue(int queue[ ], int
             item) {       /*而这里，因为传进来的QUEUE本身就是一个指针，所以queue指向的也是原本的地址*/
	if (Count == 1024)                    /* 队满，插入失败 */
		printf("Error!");
	else {
		Rear = (Rear + 1) % MAX;
		queue[Rear] = item;
		Count++;
		/* 队未满，插入成功 */
	}
}

int  deQueue(int queue[ ]) {
	int e;
	if (Count == 0) {
		printf("Empty queue!");
		return NULL;     /* 队空，删除失败 */
	} else {
		e = queue[Front];
		Count--;                             /* 队非空，删除成功 */
		Front = (Front + 1) % MAX;
		return e;
	}
}

