#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define max 30
#define MAXSIZE  1000

typedef struct edge {
	int no;
	struct edge* next;
}ELink;

typedef struct ver {
	int no;
	ELink* next;
}VLink;

VLink vertex[max],*V;
ELink* E;
int Vcnt, Ecnt , created[max],visited[max];

void insert(int v1,int v2);
void creatG();
void DFS();
void BFS();
void travelDFS(int delV);
void travelBFS(int delV);
void del(int v);

int main() {
	int d;
	scanf("%d %d", &Vcnt, &Ecnt);
	creatG();
	travelDFS(-1);
	travelBFS(-1);
	printf("\n");
	scanf("%d", &d);
	visited[d] = 1;//假装已经访问过了
	travelDFS(d);
	travelBFS(d);

	return 0;
}

void creatVnode(int v) {
	vertex[v].no = v;
	vertex[v].next = NULL;
}
void creatEnode(int v) {
	E = (ELink*)malloc(sizeof(ELink));
	E->next = NULL;
	E->no = v;
}

void insert(int v1, int v2) {
	int temp;
	ELink* q,*pre=NULL;
	
	
	creatEnode(v2);
	
	q = vertex[v1].next;
	if (q == NULL) {
		creatVnode(v1);
		creatEnode(v2);
		vertex[v1].next = E;
		return;
	}
	for (q = vertex[v1].next; q != NULL && q->no < v2; pre = q, q = q->next)
		;
	if (q == vertex[v1].next) {
		E->next = q;
		vertex[v1].next = E;
	}
	else {
		pre->next = E;
		E->next = q;
	}
}

void creatG() {
	int i,v1,v2;
	for (i = 0; i < Ecnt; i++) {
		scanf("%d %d", &v1, &v2);
		insert(v1, v2);
		insert(v2, v1);
	}
}
void DFS(int v) {
	ELink* t;
	visited[v] = 1; //标识某顶点被访问过
	printf("%d ", v);
	for (t = vertex[v].next; t != NULL; t = t->next)
		if (!visited[t->no])
			DFS(t->no);

}

void travelDFS(int delV) {
	int i;
	for (i = 0; i < Vcnt; i++) 
		visited[i] = 0;
	if(delV >= 0)
		visited[delV] = 1;
	for (i = 0; i < Vcnt; i++)
		if (!visited[i]) //访问过变1 没访问是0
			DFS(i);
	printf("\n");
}


int  Q[MAXSIZE];
int  Front, Rear, Count;
void  initQueue()
{
	Front = 0;
	Rear = MAXSIZE - 1;
	Count = 0;
}
int  isEmpty()
{
	return Count == 0;
}
int  isFull()
{
	return Count == MAXSIZE;
}
void enQueue(int item)
{
	if (isFull())                       /* 队满，插入失败 */
		printf("Full queue!");
	else {                              /* 队未满，插入成功 */
		Rear = (Rear + 1) % MAXSIZE;
		Q[Rear] = item;
		Count++;
	}
}
int  deQueue(int queue[])
{
	int e;
	if (isEmpty()) {                    /* 队空，删除失败 */
		printf("Empty queue!");
		return -1;
	}
	else {                            /* 队非空，删除成功 */
		e = queue[Front];
		Count--;
		Front = (Front + 1) % MAXSIZE;
		return e;
	}
}

void BFS(int v) {
	ELink* t;
	initQueue();
	visited[v] = 1; //标识某顶点已入队
	enQueue(v);
	while (!isEmpty()) {
		v = deQueue(Q);  //取出队头元素
		printf("%d ", vertex[v].no); //访问当前顶点
		for (t = vertex[v].next; t != NULL; t = t->next) //访问该顶点的每个邻接顶点
			if (!visited[t->no]) {
				visited[t->no] = 1; //标识某顶点入队
				enQueue(t->no);
			}
	}

}
void travelBFS(int delV) {
	int i;
	for (i = 0; i < Vcnt; i++) visited[i] = 0;
	if (delV >= 0)
		visited[delV] = 1;
	for (i = 0; i < Vcnt; i++)
		if (!visited[i]) 
			BFS(i);
}


