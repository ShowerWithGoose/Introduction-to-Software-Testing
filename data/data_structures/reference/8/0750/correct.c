#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define ll long long
int weight[110][110],visited[110],e,l,queue[1010];

void dfs(int v)
{
	int i;//i不能共用 
	visited[v]=1;
	printf("%d ",v);
	for(i=0;i<e;i++)
	{
		if(weight[v][i]==1&&visited[i]==0) dfs(i);
	}
}

void bfs(int v)
{
	int i,front=0,rear=-1,temp;
	queue[++rear]=v;
	while(front<=rear)
	{
		temp=queue[front++];
		if(visited[temp]==1) continue;
		printf("%d ",temp);
		visited[temp]=1;
		for(i=0;i<e;i++)
		{
			if(weight[temp][i]==1&&visited[i]==0) queue[++rear]=i;
		}
	}
}

int main()
{
	int v1,v2;
	scanf("%d%d",&e,&l);
	while(l--)
	{
		scanf("%d%d",&v1,&v2);
		weight[v1][v2]=1;
		weight[v2][v1]=1;
	}
	dfs(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	bfs(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	scanf("%d",&v1);
	for(int i=0;i<e;i++)
	{
		if(weight[v1][i]==1)
		{
			weight[v1][i]=0;
			weight[i][v1]=0;
		}
	}
	dfs(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	bfs(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	return 0;	
}

