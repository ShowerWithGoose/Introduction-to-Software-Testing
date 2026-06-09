#define _CRT_SECURE_NO_WARNINGS 
#define uchar unsigned char
#define uint unsigned int
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable:6031)
#define maxn 100
int graph[maxn][maxn] = { {0} };
int visit[maxn] = { 0 };
int l, m, de;
typedef struct Queue {
	int queue[maxn];
	int front;
	int rear;
}Queue;

void push(Queue* q, int n)
{
	q->queue[q->rear++] = n;
	visit[n] = 1;
}

int pop(Queue* q)
{
	int out = q->queue[q->front];
	printf("%d ", q->queue[q->front++]);
	return out;
}

void InitQueue(Queue* q)			//初始化队列
{
	memset(q->queue, 0, sizeof(q->queue));
	q->front = 0;
	q->rear = 0;
}

int isEmpty(Queue* q)
{
	return q->front == q->rear;
}

void DFS(int n)
{
	printf("%d ", n);
	visit[n] = 1;
	for (int i = 0; i < l; i++)
		if (!visit[i]&&graph[n][i])
			DFS(i);
}
void BFS(int n)
{
	Queue q;
	InitQueue(&q);
	push(&q, n);
	while (!isEmpty(&q))
	{
		int out = pop(&q);
		for (int i = 0; i < l; i++)
		{
			if (!visit[i] && graph[i][out] == 1)
				push(&q, i);
		}
	}
}
int main()
{	
	scanf("%d%d", &l, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	scanf("%d", &de);
	DFS(0);
	printf("\n");
	memset(visit, 0, sizeof(visit));
	BFS(0);
	memset(visit, 0, sizeof(visit));
	printf("\n");
	for (int i = 0; i < l; i++) 
	{
		graph[de][i] = 0;
		graph[i][de] = 0;
	}
	DFS(0);
	memset(visit, 0, sizeof(visit));
	printf("\n");
	BFS(0);
	memset(visit, 0, sizeof(visit));
	printf("\n");
	return 0;
}

