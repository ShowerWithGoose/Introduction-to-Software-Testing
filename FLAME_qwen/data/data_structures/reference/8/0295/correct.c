#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 128
typedef struct edg {
	int adjvex;
	struct edg* next;
} edge;
typedef struct point {
	int name;
	edge* link;
} ver;
ver* insert(ver* head, int data);
void DFS(ver** graph, int v);
void BFS(ver** graph);
ver* delNode(ver* head, int tar);
void clear(int n_p);
ver* graph[SZ];
int flag[SZ];

ver* after[SZ];

int main() {

	int n_p, n_e;
	scanf("%d%d", &n_p, &n_e);
	int i;
	for (i = 0; i < n_p; i++) {
		graph[i] = (ver*)malloc(sizeof(ver));
		graph[i]->name = i;
		graph[i]->link = NULL;
	}
	for (i = 0; i < n_e; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		graph[v1] = insert(graph[v1], v2);
		graph[v2] = insert(graph[v2], v1);
	}
	/*edge* current=graph[2]->link;
	while(current!=NULL){
		printf("%d ",current->adjvex);
		current=current->next;
	}*/
	int del;
	scanf("%d", &del);


	DFS(graph, 0);
	clear(n_p);
	printf("\n");

	BFS(graph);
	printf("\n");
	clear(n_p);

	//printf("%d",graph[6]->link->adjvex);

	/*DFS(after, 0);
	printf("\n");
	clear(n_p);*/
	for (i = 0; i < n_p; i++) {
		graph[i] = delNode(graph[i], del);

	}
	DFS(graph, 0);
	clear(n_p);
	printf("\n");

	BFS(graph);
	printf("\n");
	clear(n_p);



	return 0;
}
ver* insert(ver* head, int data) {

	edge* add = (edge*)malloc(sizeof(edge));
	add->adjvex = data;
	add->next = NULL;
	if (head->link == NULL)
		head->link = add;
	else {
		edge* current = head->link;
		edge* last = NULL;
		while (current != NULL) {
			if (current->adjvex > data)
				break;
			else {
				last = current;
				current = current->next;
			}
		}
		if (last == NULL) {
			head->link = add;
			add->next = current;
		} else {
			last->next = add;
			add->next = current;
		}

	}
	return head;
}
void DFS(ver** graph, int v) {

	edge* p;
	flag[v] = 1;
	printf("%d ", v);
	for (p = graph[v]->link; p != NULL; p = p->next) {
		if (!flag[p->adjvex])
			DFS(graph, p->adjvex);

	}

}
void BFS(ver** graph) {
	ver* queue[SZ];
	int head = 0, tail = -1;
	queue[++tail] = graph[0];

	while (tail >= head) {
		if (!flag[queue[head]->name]) {
			printf("%d ", queue[head]->name);
			flag[queue[head]->name] = 1;
		}

		edge* p = queue[head++]->link;
		while (p != NULL) {
			if (!flag[p->adjvex]) {
				queue[++tail] = graph[p->adjvex];
			}
			p = p->next;
		}

	}

}
ver* delNode(ver* head, int tar) {
	edge* current = head->link;
	edge* last = NULL;
	while (current != NULL) {
		if (current->adjvex == tar)
			break;
		else {
			last = current;
			current = current->next;
		}
	}
	if (current == NULL) {
		return head;
	} else if (last == NULL) {

		head->link = current->next;
		free(current);
	} else {
		last->next = current->next;
		free(current);
	}

	return head;

}
void clear(int n_p) {
	int i;
	for (i = 0; i < n_p; i++) {
		flag[i] = 0;
	}
}

