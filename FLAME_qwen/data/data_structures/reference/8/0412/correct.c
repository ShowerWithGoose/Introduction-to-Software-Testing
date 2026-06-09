#include <stdio.h>
#include <stdlib.h>

// #define INTERNAL

#ifdef INTERNAL
#include <assert.h>
#pragma warning(disable: 4996)
#endif

typedef unsigned char byte_t;

#define _OFFSET(X, OFFSET, SIZE) (((byte_t*)X) + (OFFSET) * (SIZE))

void _swap(byte_t* _a, byte_t* _b);
void swap(void* _a, void* _b, size_t _size);
void _copy(byte_t* _a, const byte_t* _b);
void copy(void* _a, const void* _b, size_t _size);


// Queue
#define QUEUE_SIZE 128

typedef struct tagQueue
{
	void* _base;
	size_t front;
	size_t rear;
	size_t _elemSize;
} Queue;

Queue* queue_init(Queue* queue, size_t _size);
Queue* queue_push(Queue* queue, void* value);
void* queue_front(Queue* queue);
Queue* queue_pop(Queue* queue);
Queue* queue_clear(Queue* queue);
int queue_empty(Queue* queue);
void queue_destroy(Queue* queue);


// Custom
#define VERTEX_NUM 105
int adjacencyMap[VERTEX_NUM][VERTEX_NUM];
int visited[VERTEX_NUM];
int vertexNum;

void init_map();
void clear_flag();
void remove_vertex(int id);
void addedge(int u, int v);
void dfs(int u);
void bfs(int u);
int main()
{
	int edgeNum;
	int u, v;

	scanf("%d %d", &vertexNum, &edgeNum);
	init_map();

	for (int i = 0; i < edgeNum; i++)
	{
		scanf("%d %d", &u, &v);
		addedge(u, v);
	}

	clear_flag();
	dfs(0);
	putchar('\n');

	clear_flag();
	bfs(0);
	putchar('\n');

	scanf("%d", &u);
	remove_vertex(u);

	clear_flag();
	dfs(0);
	putchar('\n');

	clear_flag();
	bfs(0);
	putchar('\n');

	return 0;
}

void init_map()
{
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
			adjacencyMap[i][j] = 0;
	}
}

void clear_flag()
{
	for (int i = 0; i < vertexNum; i++)
		visited[i] = 0;
}

void remove_vertex(int id)
{
	for (int i = 0; i < vertexNum; i++)
		adjacencyMap[id][i] = adjacencyMap[i][id] = 0;
}

void addedge(int u, int v)
{
	adjacencyMap[u][v] = adjacencyMap[v][u] = 1;
}

void dfs(int u)
{
	printf("%d ", u);
	visited[u] = 1;

	for (int i = 0; i < vertexNum; i++)
	{
		if (visited[i])
			continue;
		if (adjacencyMap[u][i])
			dfs(i);
	}
}

void bfs(int u)
{
	Queue queue;

	queue_init(&queue, sizeof(int));

	u = 0;
	queue_push(&queue, &u);
	while (!queue_empty(&queue))
	{
		copy(&u, queue_front(&queue), sizeof(int));
		queue_pop(&queue);
		if (visited[u])
			continue;
		printf("%d ", u);
		visited[u] = 1;
		for (int i = 0; i < vertexNum; i++)
		{
			if (visited[i])
				continue;

			if (adjacencyMap[u][i])
				queue_push(&queue, &i);
		}
	}

	queue_destroy(&queue);
}


/*
**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
** Utility Functions
**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*/
void _swap(byte_t* _a, byte_t* _b)
{
	*_a ^= *_b;
	*_b ^= *_a;
	*_a ^= *_b;
}

void swap(void* _a, void* _b, size_t _size)
{
	if (_a == _b)
		return;

	byte_t* a = (byte_t*)_a;
	byte_t* b = (byte_t*)_b;

	while (_size--)
	{
		_swap(a, b);
		a++;
		b++;
	}
}

void _copy(byte_t* _a, const byte_t* _b)
{
	*_a = *_b;
}

void copy(void* _a, const void* _b, size_t _size)
{
	if (_a == _b)
		return;

	byte_t* a = (byte_t*)_a;
	const byte_t* b = (const byte_t*)_b;

	while (_size--)
	{
		_copy(a, b);
		a++;
		b++;
	}
}


/*
**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
** Queue
**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*/
Queue* queue_init(Queue* queue, size_t _size)
{
	queue->_elemSize = _size;
	queue->_base = malloc(_size * QUEUE_SIZE);
	queue->front = queue->rear = 0;

	return queue;
}

Queue* queue_push(Queue* queue, void* value)
{
	if (queue->front == (queue->rear + 1) % QUEUE_SIZE)
		return queue;

	copy(_OFFSET(queue->_base, queue->rear, queue->_elemSize), value, queue->_elemSize);
	queue->rear++;
	if (queue->rear >= QUEUE_SIZE)
		queue->rear -= QUEUE_SIZE;

	return queue;
}

void* queue_front(Queue* queue)
{
	if (queue_empty(queue))
		return NULL;

	return _OFFSET(queue->_base, queue->front, queue->_elemSize);
}

Queue* queue_pop(Queue* queue)
{
	if (!queue_empty(queue))
		queue->front++;

	return queue;
}

Queue* queue_clear(Queue* queue)
{
	queue->front = queue->rear = 0;

	return queue;
}

int queue_empty(Queue* queue)
{
	return queue->front == queue->rear;
}

void queue_destroy(Queue* queue)
{
	free(queue->_base);
	queue->_base = NULL;
}

