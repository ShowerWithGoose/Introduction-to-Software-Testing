#include <stdio.h>
#include <math.h>
#include <string.h>
#define M 1024
#define NULL ((void *)0)
#include <ctype.h>
#include <stdlib.h>

typedef struct edge {
	int adjvex;
	struct edge *next;
}ELink,*PElink;

typedef struct ver {
	ELink *link;
} VLink;
VLink G[110];

ELink *insertEdge(ELink *head, int avex) {
	ELink *e,*p,*q;
	int flag = 0;
	e = (ELink *)malloc(sizeof(ELink));
	e->adjvex = avex;
	e->next = NULL;
	if(head) {
		if(head->adjvex > avex){
			q = head;
			head = e;
			head->next = q;
			return head;
		}
		for(q = head; q->next != NULL; q = q->next) {
			if(q->next->adjvex > avex) {
				e->next = q->next;
				q->next = e;
				flag = 1;
				return head;
			}
		}
	}
	if(head == NULL) {
		head = e;
		return head;
	}
	if(flag == 0) {
		for(p = head; p->next != NULL; p=p->next);
		p->next = e;
	}
	return head;
}
int Visited[110]; //标识顶点是否被访问过，N为顶点数
int queue[110];
int front = 0,rear = 110 - 1,count = 0;

int isEmpty() {
	return count == 0;
}
int isFull() {
	return count == 110;
}

void enQueue(int q[],int item) { //进队
	if(isFull()) printf("Full queue!");
	else {
		rear = (rear + 1) % 110;
		queue[rear] = item;
		count++;
	}
}
int deQueue(int q[]) { //出队
	int c;
	if(isEmpty()) printf("Empty queue!");
	
		c = queue[front];
		count--;
		front = (front + 1) % 110;	
	
	return c;
}
void DFS(VLink G[], int v,int flag_d,int delete);
void BFS(VLink G[], int v,int flag_d,int delete);
void VISIT(VLink G[],int v);

void travelDFS(VLink G[], int n,int flag_d,int delete) {
	int i;
	for (i = 0; i < n; i++)
		Visited[i] = 0;
	for (i = 0; i < n; i++)
		if (!Visited[i]){
			if(flag_d == 1){
				if(i == delete) continue;
				else DFS(G, i,flag_d,delete);
			}
			else DFS(G, i,flag_d,delete);
		}
}

void DFS(VLink G[], int v,int flag_d,int delete) {
	ELink *p;
	Visited[v] = 1; //标识某顶点被访问过
	VISIT(G, v); //访问某顶点
	for (p = G[v].link; p != NULL; p = p->next)
		if (!Visited[p->adjvex]){
			if(flag_d == 1){
				if(p->adjvex == delete) continue;
				else DFS(G, p->adjvex,flag_d,delete);
			}
			else DFS(G, p->adjvex,flag_d,delete);
		}		
}

void travelBFS(VLink G[], int n,int flag_d,int delete) {
	int i;
	for (i = 0; i < n; i++)
		Visited[i] = 0;
	for (i = 0; i < n; i++)
		if (!Visited[i]){
			if(flag_d == 1){
				if(i == delete) continue;
				else BFS(G, i,flag_d,delete);
			}
			else BFS(G, i,flag_d,delete);
		}
}

void BFS(VLink G[], int v,int flag_d,int delete) {
	ELink *p;
	VISIT(G, v); //访问当前顶点
	Visited[v] = 1; //标识某顶点被访问过
	enQueue(queue, v);
	while (!isEmpty()) {
		v = deQueue(queue); //取出队头元素
		p = G[v].link; //获取该顶点第一个邻接顶点
		
		//访问该顶点下的每个邻接顶点
		for (; p != NULL; p = p->next)
			if (!Visited[p->adjvex]) {
				if(flag_d == 1){
					if(p->adjvex == delete) continue;
					else {
						VISIT(G, p->adjvex); //访问当前顶点
						Visited[p->adjvex] = 1; //标识某顶点被访问过
						enQueue(queue, p->adjvex);
					}	
				}
				else {
						VISIT(G, p->adjvex); //访问当前顶点
						Visited[p->adjvex] = 1; //标识某顶点被访问过
						enQueue(queue, p->adjvex);
					}
			}
	}
}
void VISIT(VLink G[], int v) {
	printf("%d ",v);
}
PElink search(VLink G[],ELink *q,int i){
	ELink *p;
	for(p = G[i].link;p->next != q;p = p->next);
	return p;
}
int main() {
	ELink *p,*q;
	int code,side;
	int code1,code2;
	int delete;
	int i,j,k;
	int n = 0;
	int flag_d = 0;
	scanf("%d%d",&code,&side);

	while(side > 0) {
		scanf("%d%d",&code1,&code2);
		G[code1].link = insertEdge(G[code1].link, code2);
		G[code2].link = insertEdge(G[code2].link, code1);
		side--;
	}
	travelDFS(G,code,flag_d,delete);
	printf("\n");
	travelBFS(G,code,flag_d,delete);
	printf("\n");

	scanf("%d",&delete);
	
	flag_d = 1;
	travelDFS(G,code,flag_d,delete);
	printf("\n");
	travelBFS(G,code,flag_d,delete);
	printf("\n");
	/*for(i = 0;i < code;i++){
		if(i == delete) continue;
		for(p = G[i].link;p->next != NULL;p = p->next){
			if(p->adjvex == delete){
				q = search(G,p,i);
				q->next = p->next;
				break;
			}
		}
		if(p->adjvex == delete) {
			q = search(G,p,i);
			q->next = NULL;
		}
	}*/
	
	return 0;
}


