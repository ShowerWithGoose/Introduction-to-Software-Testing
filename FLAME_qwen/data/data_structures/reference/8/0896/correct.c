#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int N,L_len;
int graph[105][105]={0};
int a,b,delete_point;
int visit[105]={0};
int queue[1005];
int front = -1;
int rear = 0;
int num = 0;
void DFS(int begin);
void BFS(int begin);
void inqueue(int begin);
int outqueue();
int isempty(); 
int main()
{
	scanf("%d %d",&N,&L_len);
	for(int i = 0;i<L_len;i++)
	{
		scanf("%d %d",&a,&b);
		graph[a][b]=graph[b][a]=1;
	}
	scanf("%d",&delete_point);	
	DFS(0);
	printf("\n");
	front = -1;
	rear = 0;
	for(int i =0;i<1005;i++)
	{
		queue[i] = -1;
	}
	memset(visit,0,sizeof(visit));
	BFS(0);
	printf("\n");
	for(int i = 0;i<N;i++)
	{
		graph[delete_point][i] = 0;
		graph[i][delete_point] = 0;
		L_len--;
	}
	memset(visit,0,sizeof(visit));
	for(int i =0;i<1005;i++)
	{
		queue[i] = -1;
	}
	DFS(0);
	printf("\n");
	front = -1;
	rear = 0;
	num = 0;
	memset(visit,0,sizeof(visit));
	BFS(0);
	printf("\n");
}

void DFS(int begin)
{
	printf("%d ",begin);
	visit[begin] = 1;
	for(int i =0;i<N;i++)
	{
		if(graph[begin][i]==1 && visit[i]!=1)
		{
			DFS(i);
		}
	}
}

void BFS(int begin)
{
	inqueue(begin);
	while(isempty()!=1)
	{
		int item = outqueue();
		printf("%d ",item);
		for(int i = 0;i<N;i++)
		{
			if(visit[i]==0 && graph[item][i]==1)
			{
				inqueue(i);
			}
		}
	}
}
void inqueue(int item)
{
	visit[item] = 1;
	queue[rear] = item;
	rear++;
	num++;
}

int outqueue()
{
	int item;
	item = queue[++front];
	num--;
	return item;
}

int isempty()
{
	return num==0;
}

