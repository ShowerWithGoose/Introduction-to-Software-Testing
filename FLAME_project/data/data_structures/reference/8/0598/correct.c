#define _CRT_SECURE_NO_DEPRECATE//或者#define_CRT_SECURE_NO_WARNINGS或者#pragma warning(disabled:4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
	int a;
	int b;
}Edge;

int compare(Edge* a, Edge* b) {
	int c = a->a + a->b - b->a - b->b;
	if (c) return c;
	return a->a - b->a;
}

typedef struct Neighbour {
	int neighbour;
	struct Neighbour* prev;
	struct Neighbour* next;
}Neighbour;

typedef struct Vertex {
	Neighbour* head;
	Neighbour* tail;
}Vertex;

typedef struct Graph {
	int numberOfVertices;
	Vertex** vertices;
}Graph;

Graph* initializeGraph(int numberOfVertices) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	Vertex** vertices = (Vertex**)malloc(numberOfVertices * sizeof(Vertex*));
	int i;
	for (i = 0; i < numberOfVertices; i++) {
		vertices[i] = (Vertex*)malloc(sizeof(Vertex));
		vertices[i]->head = NULL;
		vertices[i]->tail = NULL;
	}
	graph->numberOfVertices = numberOfVertices;
	graph->vertices = vertices;
	return graph;
}

void insertEdge(Graph* graph, Edge* edge) {
	Neighbour* neighbour = (Neighbour*)malloc(sizeof(Neighbour));
	neighbour->prev = graph->vertices[edge->a]->tail;
	if (!graph->vertices[edge->a]->head)
		graph->vertices[edge->a]->head = graph->vertices[edge->a]->tail = neighbour;
	else
		graph->vertices[edge->a]->tail = graph->vertices[edge->a]->tail->next = neighbour;
	graph->vertices[edge->a]->tail->neighbour = edge->b;
	graph->vertices[edge->a]->tail->next = NULL;
	neighbour = (Neighbour*)malloc(sizeof(Neighbour));
	neighbour->prev = graph->vertices[edge->b]->tail;
	if (!graph->vertices[edge->b]->head)
		graph->vertices[edge->b]->head = graph->vertices[edge->b]->tail = neighbour;
	else
		graph->vertices[edge->b]->tail = graph->vertices[edge->b]->tail->next = neighbour;
	graph->vertices[edge->b]->tail->neighbour = edge->a;
	graph->vertices[edge->b]->tail->next = NULL;
}

void toDFS(Graph* graph, int* visited, int index) {
	Neighbour* curr = graph->vertices[index]->head;
	while (curr) {
		if (!visited[curr->neighbour]) {
			printf("%d ", curr->neighbour);
			visited[curr->neighbour] = 1;
			toDFS(graph, visited, curr->neighbour);
		}
		curr = curr->next;
	}
}

void DFS2(Graph* graph) {
	int* visited = (int*)malloc(graph->numberOfVertices * sizeof(int));
	int i;
	for (i = 0; i < graph->numberOfVertices; i++) visited[i] = 0;
	toDFS(graph, visited, 0);
}

void DFS(Graph* graph, int index) {

	int* visited = (int*)malloc(graph->numberOfVertices * sizeof(int));
	int i;
	for (i = 0; i < graph->numberOfVertices; i++) visited[i] = 0;

	int* stack = (int*)malloc(graph->numberOfVertices * sizeof(int));
	int top = 0;

	stack[top++] = index;

	int now;
	Neighbour* curr;
	while (top) {
		now = stack[--top];
		if (!visited[now]) {
			printf("%d ", now);
			visited[now] = 1;
		}
		curr = graph->vertices[now]->tail;
		while (curr) {
			if (!visited[curr->neighbour])
				stack[top++] = curr->neighbour;
			curr = curr->prev;
		}
	}
}

void BFS(Graph* graph, int index) {

	int* visited = (int*)malloc(graph->numberOfVertices * sizeof(int));
	int i;
	for (i = 0; i < graph->numberOfVertices; i++) visited[i] = 0;

	int* queue = (int*)malloc(graph->numberOfVertices * sizeof(int));
	int head = 0, tail = 0;

	queue[tail++] = index;

	int now;
	Neighbour* curr;
	while (head != tail) {
		now = queue[head++];
		if (!visited[now]) {
			printf("%d ", now);
			visited[now] = 1;
		}
		curr = graph->vertices[now]->head;
		while (curr) {
			if (!visited[curr->neighbour])
				queue[tail++] = curr->neighbour;
			curr = curr->next;
		}
	}
}

void DFSignore(Graph* graph, int index, int ignore) {

	int* visited = (int*)malloc(graph->numberOfVertices * sizeof(int));
	int i;
	for (i = 0; i < graph->numberOfVertices; i++) visited[i] = 0;
	visited[ignore] = 1;

	int* stack = (int*)malloc(graph->numberOfVertices * sizeof(int));
	int top = 0;

	stack[top++] = index;

	int now;
	Neighbour* curr;
	while (top) {
		now = stack[--top];
		if (!visited[now]) {
			printf("%d ", now);
			visited[now] = 1;
		}
		curr = graph->vertices[now]->tail;
		while (curr) {
			if (!visited[curr->neighbour])
				stack[top++] = curr->neighbour;
			curr = curr->prev;
		}
	}
}

void BFSignore(Graph* graph, int index, int ignore) {

	int* visited = (int*)malloc(graph->numberOfVertices * sizeof(int));
	int i;
	for (i = 0; i < graph->numberOfVertices; i++) visited[i] = 0;
	visited[ignore] = 1;

	int* queue = (int*)malloc(graph->numberOfVertices * sizeof(int));
	int head = 0, tail = 0;

	queue[tail++] = index;

	int now;
	Neighbour* curr;
	while (head != tail) {
		now = queue[head++];
		if (!visited[now]) {
			printf("%d ", now);
			visited[now] = 1;
		}
		curr = graph->vertices[now]->head;
		while (curr) {
			if (!visited[curr->neighbour])
				queue[tail++] = curr->neighbour;
			curr = curr->next;
		}
	}
}

void quickSort(void** base, int number, int compare(const void*, const void*)) {

	int* stack = (int*)malloc(2 * number * sizeof(int));
	int p = 0;

	int beg, end;
	int left, right, mid;

	stack[p++] = 0;
	stack[p++] = number - 1;

	void* pivot;
	void* hold;

	while (p) {

		right = end = stack[--p];
		left = beg = stack[--p];
		mid = left + (right - left) / 2;

		pivot = *(void**)((char*)base + mid * sizeof(void*));

		while (left <= right) {

			while (compare(*(void**)((char*)base + left * sizeof(void*)), pivot) < 0) left++;
			while (compare(*(void**)((char*)base + right * sizeof(void*)), pivot) > 0) right--;

			if (left <= right) {

				hold = *(void**)((char*)base + left * sizeof(void*));
				*(void**)((char*)base + left * sizeof(void*)) = *(void**)((char*)base + right * sizeof(void*));
				*(void**)((char*)base + right * sizeof(void*)) = hold;

				left++;
				right--;
			}
		}
		if (left < end) {
			stack[p++] = left;
			stack[p++] = end;
		}
		if (right > beg) {
			stack[p++] = beg;
			stack[p++] = right;
		}
	}

	free(stack);
}

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	Graph* graph = initializeGraph(n);
	Edge** edges = (Edge**)malloc(m * sizeof(Edge*));
	int i;
	for (i = 0; i < m; i++) {
		edges[i] = (Edge*)malloc(sizeof(Edge));
		scanf("%d%d", &edges[i]->a, &edges[i]->b);
	}
	quickSort(edges, m, compare);
	for (i = 0; i < m; i++)
		insertEdge(graph, edges[i]);

	DFS(graph, 0);
	printf("\n");
	BFS(graph, 0);
	printf("\n");

	int ignore;
	scanf("%d", &ignore);
	DFSignore(graph, 0, ignore);
	printf("\n");
	BFSignore(graph, 0, ignore);
	printf("\n");

	return 0;

}
