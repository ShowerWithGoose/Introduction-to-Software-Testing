#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define ll long long
int G[105][105];

int v,e;
int first=0,last=0;

void dfs(int p,int visited[])
{
	printf("%d ",p);
	visited[p]=1;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==0&&G[p][i]!=0) dfs(i,visited);
	}
}
void bfs(int p,int visited[],int queue[])
{
	queue[last]=p;
	last++;
	visited[p]=1;
	while(first<last)
	{
		printf("%d ",queue[first]);
		first++;
		for(int i=0;i<v;i++)
		{
//			printf("%d\n",visited[i]);
			if(visited[i]==0&&G[queue[first-1]][i]!=0)
			{
				queue[last]=i;
				visited[i]=1;
				last++;
			}	
		}	
	}	
}
int main()
{
	int queue[105]={0};
	int visited[105]={0};
	scanf("%d%d",&v,&e);
	int a,b;
	for(int i=0;i<e;i++)
	{
		scanf("%d%d",&a,&b);
		G[a][b]=1;G[b][a]=1;
	}
	dfs(0,visited);
	printf("\n");
	for(int i=0;i<v;i++)
	{
		visited[i]=0;
	}
	bfs(0,visited,queue);
	printf("\n");
	for(int i=0;i<v;i++)
	{
		visited[i]=0;
	}
	int delet;
	scanf("%d",&delet);
	for(int i=0;i<v;i++)
	{
		G[i][delet]=0;
	}
	first=0;last=0;
	dfs(0,visited);
	printf("\n");
	for(int i=0;i<v;i++)
	{
		visited[i]=0;
	}
	bfs(0,visited,queue);
	return 0;
}


