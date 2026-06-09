#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int graph[101][101];
int flag[101];
int queue[101];

void DFS(int u,int p)
{
	int i;
	if(u == 0)
	{
		printf("%d",u);
	}
	else
	{
		printf(" %d",u);
	}
	flag[u] = 1;
	for(i = 0;i < p;i++)
	{
		if(graph[u][i] == 1 && flag[i] == 0)
		{
			DFS(i,p);
		}
	}
}

void BFS(int u,int p)
{
	int i,j,k;
	int temp;
	queue[0] = u;
	for(i = 0,j = 0;i <= j;)
	{
		temp = queue[i++];
		if(flag[temp] == 1)
		{
			continue;
		}
		if(temp == 0)
		{
			printf("%d",temp);
		}
		else
		{
			printf(" %d",temp);
		}
		flag[temp] = 1;
		for(k = 0;k < p;k++)
		{
			if(graph[temp][k] == 1 && flag[k] == 0)
			{
				queue[++j] = k;
			}
		}
	}
}
int main()
{
	int p,l;
	scanf("%d%d",&p,&l);
	int u,v;
	int x;
	int i,j;
	for(i = 0;i < 101;i++)
	{
		for(j = 0;j < 101;j++)
		{
			graph[i][j] = 0;
		}
	}
	memset(flag,0,sizeof(flag));
	memset(queue,0,sizeof(queue));
	for(i = 0;i < l;i++)
	{
		scanf("%d%d",&u,&v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	scanf("%d",&x);
	DFS(0,p);
	printf("\n");
	memset(flag,0,sizeof(flag));
	BFS(0,p);
	printf("\n");
	memset(flag,0,sizeof(flag));
	
	for(i = 0;i < p;i++)
	{
		graph[i][x] = 0;
	}
	for(i = 0;i < p;i++)
	{
		graph[x][i] = 0;
	}
	DFS(0,p);
	printf("\n");
	memset(flag,0,sizeof(flag));
	BFS(0,p);
	printf("\n");
	memset(flag,0,sizeof(flag));
	return 0;
}
