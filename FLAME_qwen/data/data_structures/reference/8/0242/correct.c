#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MaxV 256
int v,e;
int g[105][105];
int Visited[105] = {0}; //标识顶点是否被访问过，N为顶点数
void dfs(int x)
{
	int i;
	printf("%d ",x);
	Visited[x]=1;
	for(i=0;i<=v;i++)
	{
		if(g[x][i]==1)
		{
			if(Visited[i]==0)
			{
				dfs(i);
			}
		}
	}
}
void bfs(int x)
{
	int queue[105],i,j;
	int head=0,tail=0;
	queue[tail++]=x;
	Visited[x]=1;
	int tem;
	while(head<tail)
	{
		tem=queue[head++];
		if(Visited[tem]==1&&tem!=0)
			continue;
		printf("%d ",tem);
		Visited[tem]=1;
		for(i=0;i<=v;i++)
		{
			if(g[tem][i]!=0&&Visited[i]==0)
			{
				queue[tail++]=i;
			}
		}
	}
	memset(Visited,0,sizeof(Visited));
}
int main()
{
	int i,x,y,cut;
	scanf("%d%d",&v,&e);
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&x,&y);
		g[x][y]=1;
		g[y][x]=1;
	}
	scanf("%d",&cut);
	dfs(0);
	printf("\n");
	for(i=0;i<105;i++)
	{
		Visited[i]=0;
	}
	bfs(0);
	printf("\n");
	for(i=0;i<105;i++)
	{
		Visited[i]=0;
	}
	for(i=0;i<=v;i++)
	{
		g[cut][i]=0;
		g[i][cut]=0;
	}
	dfs(0);
	printf("\n");
	for(i=0;i<105;i++)
	{
		Visited[i]=0;
	}
	bfs(0);
	
}

