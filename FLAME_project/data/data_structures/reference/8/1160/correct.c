#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEXS 256

typedef struct edge
{
	int adjvex_index;
	struct edge *next_edge;
} Elink;

typedef struct vertex
{
	Elink *first_edge;
} Vlink;

Elink *initEdge(int new_adjvex_index);
void *appendEdge(Vlink graph[], int vertex_index, int new_adjvex_index);
void *appendEdgeInOrder(Vlink graph[], int vertex_index, int new_adjvex_index);
void graphDfsForAllVertexs(Vlink graph[], int total_vertexs);
void graphDfsForTheVertex(Vlink graph[], int vertex_index);
void enQueue(int queue[], int vertex_index);
int deQueue(int queue[]);
int isQueueEmpty(int queue[]);
void graphBfsForAllVertexs(Vlink graph[], int total_vertexs);
void graphBfsForTheVertex(Vlink graph[], int vertex_index);
void deleteVertex(Vlink graph[], int vertex_index);
void visit(Vlink graph[], int vertex_index);

Elink *initEdge(int new_adjvex_index)
{
	Elink *new_edge = (Elink *)malloc(sizeof(Elink));
	new_edge->adjvex_index = new_adjvex_index;
	new_edge->next_edge = NULL;
	return new_edge;
}
void *appendEdge(Vlink graph[], int vertex_index, int new_adjvex_index)
{
	if (graph[vertex_index].first_edge == NULL)
	{
		graph[vertex_index].first_edge = initEdge(new_adjvex_index);
	}
	else
	{
		Elink *op = graph[vertex_index].first_edge;
		while (op->next_edge != NULL)
		{
			op = op->next_edge;
		}
		op->next_edge = initEdge(new_adjvex_index);
	}
}
void *appendEdgeInOrder(Vlink graph[], int vertex_index, int new_adjvex_index)
{
	if (graph[vertex_index].first_edge == NULL)
	{
		graph[vertex_index].first_edge = initEdge(new_adjvex_index);
	}
	else
	{
		Elink *op = graph[vertex_index].first_edge;
		if (op->adjvex_index > new_adjvex_index)
		{
			graph[vertex_index].first_edge = initEdge(new_adjvex_index);
			graph[vertex_index].first_edge->next_edge = op;
		}
		while (op->next_edge != NULL && op->next_edge->adjvex_index < new_adjvex_index)
		{
			op = op->next_edge;
		}
		Elink *temp = op->next_edge;
		op->next_edge = initEdge(new_adjvex_index);
		op->next_edge->next_edge = temp;
	}
}

Vlink graph[MAX_VERTEXS];
int visited[MAX_VERTEXS] = {0};

void graphDfsForAllVertexs(Vlink graph[], int total_vertexs)
{
	for (int i = 0; i < total_vertexs; i++) // initialization
	{
		visited[i] = 0;
	}
	for (int i = 0; i < total_vertexs; i++)
	{
		if (!visited[i])
		{
			graphDfsForTheVertex(graph, i);
		}
	}
}
void graphDfsForTheVertex(Vlink graph[], int vertex_index)
{
	Elink *edge;
	visited[vertex_index] = 1;
	visit(graph, vertex_index);
	edge = graph[vertex_index].first_edge;
	for (; edge != NULL; edge = edge->next_edge)
	{
		if (!visited[edge->adjvex_index])
		{
			graphDfsForTheVertex(graph, edge->adjvex_index);
		}
	}
}

int vertex_queue[MAX_VERTEXS];
int vertex_queue_head = 0;
int vertex_queue_tail = 0;

void enQueue(int queue[], int vertex_index)
{
	vertex_queue[vertex_queue_head++] = vertex_index;
}
int deQueue(int queue[])
{
	return vertex_queue[vertex_queue_tail++];
}
int isQueueEmpty(int queue[])
{
	return (vertex_queue_head == vertex_queue_tail);
}

void graphBfsForAllVertexs(Vlink graph[], int total_vertexs)
{
	for (int i = 0; i < total_vertexs; i++) // initialization
	{
		visited[i] = 0;
	}
	for (int i = 0; i < total_vertexs; i++)
	{
		if (!visited[i])
		{
			graphBfsForTheVertex(graph, i);
		}
	}
}
void graphBfsForTheVertex(Vlink graph[], int vertex_index)
{
	Elink *edge;
	visit(graph, vertex_index);
	visited[vertex_index] = 1;
	enQueue(vertex_queue, vertex_index);
	while (!isQueueEmpty(vertex_queue))
	{
		vertex_index = deQueue(vertex_queue);
		edge = graph[vertex_index].first_edge;
		for (; edge != NULL; edge = edge->next_edge)
		{
			if (!visited[edge->adjvex_index])
			{
				visit(graph, edge->adjvex_index);
				visited[edge->adjvex_index] = 1;
				enQueue(vertex_queue, edge->adjvex_index);
			}
		}
	}
}

void deleteVertex(Vlink graph[], int vertex_index)
{
	for (int i = 0; i < MAX_VERTEXS; i++)
	{
		Elink *op = graph[i].first_edge;
		if (op == NULL)
		{
			continue;
		}
		while (op->adjvex_index == vertex_index)
		{
			free(graph[i].first_edge);
			graph[i].first_edge = op->next_edge;
			op = op->next_edge;
		}
		while (op->next_edge != NULL)
		{
			if (op->next_edge->adjvex_index == vertex_index)
			{
				Elink *temp = op->next_edge->next_edge;
				free(op->next_edge);
				op->next_edge = temp;
			}
			else
			{
				op = op->next_edge;
			}
		}
	}
}

void visit(Vlink graph[], int vertex_index)
{
	printf("%d ", vertex_index);
}

int main()
{
	int total_vertexs, total_edges;
	scanf("%d%d", &total_vertexs, &total_edges);
	for (int i = 0; i < total_edges; i++)
	{
		int from, to;
		scanf("%d%d", &from, &to);
		appendEdgeInOrder(graph, from, to);
		appendEdgeInOrder(graph, to, from);
	}
	for (int i = 0; i < total_vertexs; i++) // initialization
	{
		visited[i] = 0;
	}
	graphDfsForTheVertex(graph, 0);
	printf("\n");
	for (int i = 0; i < total_vertexs; i++) // initialization
	{
		visited[i] = 0;
	}
	graphBfsForTheVertex(graph, 0);
	printf("\n");
	int to_delete;
	scanf("%d", &to_delete);
	deleteVertex(graph, to_delete);
	for (int i = 0; i < total_vertexs; i++) // initialization
	{
		visited[i] = 0;
	}
	graphDfsForTheVertex(graph, 0);
	printf("\n");
	for (int i = 0; i < total_vertexs; i++) // initialization
	{
		visited[i] = 0;
	}
	graphBfsForTheVertex(graph, 0);

	return 0;
}
