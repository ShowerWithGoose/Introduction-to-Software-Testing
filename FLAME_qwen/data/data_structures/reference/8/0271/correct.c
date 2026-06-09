#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int G[205][205];//邻接矩阵
int visited[200] = {0};//标志是否访问过
int queue[205];//BFS用到的队列
int vertex_num;//输入的顶点数 
int edge_num;//输入的边数
void DFS(int v)
{
	int i;
	visited[v] = 1;
	printf("%d ",v);
	for(i = 0;i < vertex_num; i++)
	{
		if(G[v][i] == 1 && visited[i] == 0)
		{
			DFS(i);
		}
	}
} 
void BFS(int v)
{
	int i;
	int head = 0;
	int rear = 1;
	int temp;
	queue[0] = v;
	while(head <= rear)
	{
		temp = queue[head];
		head++;
		if(visited[temp])	continue;
		else
		{
			printf("%d ",temp);
			visited[temp] = 1;
			for(i = 0;i < vertex_num; i++)
			{
				if(G[temp][i] == 1 && visited[i] == 0)
				{
					queue[rear++] = i;
				}
			}
		}
	}
}
int main()
{
	int i;
	int u,v;
	int num;
	scanf("%d %d",&vertex_num,&edge_num);
	for(i = 0;i < edge_num; i++)
	{
		scanf("%d %d",&u,&v);
		G[u][v] = G[v][u] = 1;
	}
	DFS(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	scanf("%d",&num);
	visited[num] = 1;
	DFS(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	memset(queue,0,sizeof(queue));
	visited[num] = 1;
	BFS(0);
	printf("\n");
	return 0;
}

