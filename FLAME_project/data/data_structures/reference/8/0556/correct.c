#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 104

int graph[MAXSIZE][MAXSIZE];
int visited[MAXSIZE];
int queue[MAXSIZE];
int ENum,VNum;//顶点个数和边个数

void DFS(int a);
void BFS(int a);
int main()
{
	int x,y;
	int i;
	int del;
	
	scanf("%d%d",&ENum,&VNum);
	for(i=0;i<VNum;i++)
	{
		scanf("%d%d",&x,&y);
		graph[x][y]=1;
		graph[y][x]=1;
	}
	DFS(0);
	printf("\n");
	memset(visited,0,MAXSIZE);
	BFS(0);
	printf("\n");
	memset(visited,0,MAXSIZE);
	
	scanf("%d",&del);
	visited[del]=1;
	DFS(0);
	printf("\n");
	memset(visited,0,MAXSIZE);
	
	visited[del]=1;
	BFS(0);
	printf("\n");
	return 0;
}
void DFS(int a)
{
	int i;
	printf("%d ",a);
	visited[a]=1;
	for(i=0;i<ENum;i++)
		if(graph[a][i]==1&&visited[i]==0)
			DFS(i);
}
void BFS(int a)
{
	int t;
	int i,j;
	queue[0]=a;
	for(i=0,j=0;i<=j;)
	{
		t=queue[i++];
		if(visited[t]==1)
			continue;
		printf("%d ",t);
		visited[t]=1;//标记为已访问
		for(int i=0;i<ENum;i++)
		{
			if(graph[t][i]==1&&visited[i]==0)
				queue[++j]=i;
		}
		
	}
	
}

