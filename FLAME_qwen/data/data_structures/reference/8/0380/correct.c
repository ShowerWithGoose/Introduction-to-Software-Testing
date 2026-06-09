#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NUM 105

int vertex;
int road;
int visited[MAX_NUM];
int matrix[MAX_NUM][MAX_NUM];

int queue[MAX_NUM];
int head;
int rear;

void DFS(int num, int n);
void BFS(int n);

int main()
{
	int a, b;
	
	scanf("%d %d", &vertex, &road);
	
	for( int i = 0; i < road; i++ )
	{
		scanf("%d %d", &a, &b);
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
	
	DFS(0, vertex);
	printf("\n");
	
	for( int i = 0; i < vertex; i++ )
		visited[i] = 0;
	
	queue[0] = 0;
	head = 0;
	rear = 1;
	
	BFS(vertex);
	printf("\n");
	for( int i = 0; i < vertex; i++ )
		visited[i] = 0;
	
	scanf("%d", &a);
	visited[a] = 1;
	
	int begin = 0;
	if( visited[0] )
		begin = 1;
	queue[0] = begin;
	head = 0;
	rear = 1;
	
	DFS(begin, vertex);
	printf("\n");
	
	for( int i = 0; i < vertex; i++ )
		visited[i] = 0;
	visited[a] = 1;
	BFS(vertex);
	
	return 0;
}

void DFS(int num, int n)
{
	if( !visited[num] )
	{
		printf("%d ", num);
		visited[num] = 1;
		
		for( int j = 0; j < n; j++ )
			if( matrix[num][j] )
				DFS(j, n);
	}
	
	return;
}

void BFS(int n)
{
	while( head < rear )
	{
		printf("%d ", queue[head]);
		visited[queue[head]] = 1;
		
		for( int i = 0; i < n; i++ )
			if( matrix[queue[head]][i] && !visited[i] )
			{
				queue[rear++] = i;
				visited[i] = 1;
			}
		
		head++;
	}
	
	return;
}

