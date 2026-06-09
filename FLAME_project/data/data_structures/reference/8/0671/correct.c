#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int visited[105];
int G[105][105];
int queue[105];
int front = -1, rear = 0;
void enQueue(int);
int deQueue();
void DFS(int);
void BFS(int);
int vertex, edge;
int main()
{
	scanf("%d%d", &vertex, &edge);
	int i, temp1, temp2;
	for(i = 0; i < edge; i++)
	{
		scanf("%d%d", &temp1, &temp2);
		G[temp1][temp2] = G[temp2][temp1] = 1;
	}
	int delete1;
	scanf("%d", &delete1);
	DFS(0);
	putchar('\n');
	for(i = 0; i < vertex; i++) visited[i] = 0;
	BFS(0);
	putchar('\n');
	for(i = 0; i < vertex; i++)
	{
		G[delete1][i] = G[i][delete1] = 0;
	}
	for(i = 0; i < vertex; i++) visited[i] = 0;
	DFS(0);
	putchar('\n');
	for(i = 0; i < vertex; i++) visited[i] = 0;
	front = -1, rear = 0;
	BFS(0);
	return 0;
}
void enQueue(int n)
{
	queue[rear++] = n;
}
int deQueue()
{
	return queue[++front];
}
void DFS(int v)
{
	if(!visited[v])
	{
		printf("%d ", v);
		visited[v] = 1;
		int i;
		for(i = 0; i < vertex; i++)
		{
			if(G[v][i] && !visited[i])
				DFS(i);
		}
	}
}
void BFS(int v)
{
	if(!visited[v])
	{
		printf("%d ", v);
		enQueue(v);
		visited[v] = 1;
	}
	while(front != rear)
	{
		int temp = deQueue(), i;
		for(i = 0; i < vertex; i++)
		{
			if(G[temp][i] && !visited[i])
			{
				printf("%d ", i);
				enQueue(i);
				visited[i] = 1;
			}
		}
	}
	
}

