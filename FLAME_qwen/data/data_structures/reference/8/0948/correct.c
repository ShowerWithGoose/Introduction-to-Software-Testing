#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int G[100][100];//邻接矩阵
int visited[100];//访问标志位
int queue[100];//队列
int front,rear=-1;
int n;//顶点的个数
void DFS(int i);//深度优先遍历
void BFS(int i);//广度优先遍历
int main()
{
	int e;//边的个数
	scanf("%d%d",&n,&e);
	int i,j,begin,end,deln;
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&begin,&end);
		G[begin][end]=1;
		G[end][begin]=1;
	}
	scanf("%d",&deln);
	//=======深度优先遍历=======
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
			DFS(i);
	}
	putchar('\n');
	//==========================
	//=======广度优先遍历=======
	for(i=0;i<n;i++)
		visited[i]=0;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
			BFS(i);
	}
	putchar('\n');
	//============================
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(j==deln||i==deln)
			G[i][j]=0;
	}
	//=======深度优先遍历=======
	for(i=0;i<n;i++)
		visited[i]=0;
	visited[deln]=1;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
			DFS(i);
	}
	putchar('\n');
	
	//===========================
	
	//=======广度优先遍历=======
	for(i=0;i<n;i++)
		visited[i]=0;
	visited[deln]=1;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
			BFS(i);
	}
	putchar('\n');
	//==========================
	return 0;
}
void DFS(int i)
{
	printf("%d ",i);
	visited[i]=1;
	int j=0;
	for(j=0;j<n;j++)
	{
		if(G[i][j]==1&&visited[j]==0)
			DFS(j);
	}
}
void BFS(int i)
{
	printf("%d ",i);
	visited[i]=1;
	queue[++rear]=i;
	int j=0;
	while(front<=rear)
	{
		i=queue[front];
		front++;
		for(j=0;j<n;j++)
		{
			if(G[i][j]==1&&visited[j]==0)
				{
					printf("%d ",j);
					visited[j]=1;
					queue[++rear]=j;
				}	
		}
	}
	
}
