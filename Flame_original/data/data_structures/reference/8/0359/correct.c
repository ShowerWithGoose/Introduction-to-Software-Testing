#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int map[101][101];
int tmp[101];
int vis[101];
int n,m,p;
void Dfs(int a)
{
	printf("%d ",a);
	vis[a]=1;
	for(int i=1;i<=n;i++)
	{
		if(map[a][i]==1&&vis[i]==0)
		{
			Dfs(i);
		}
	}
}
void Bfs(int a)
{
	int t;
	tmp[1]=a;
	for(int j=1,r=1;j<=r;)
	{
		t=tmp[j++];
		if(vis[t]==1)continue;
		printf("%d ",t);
		vis[t]=1;
		for(int i=1;i<=n;i++)
		{
			if(map[t][i]==1&&vis[i]==0)tmp[++r]=i;
		}
	}
}
int main()
{

	scanf(" %d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf(" %d%d",&u,&v);
		map[u][v]=1;
		map[v][u]=1;
	}
	scanf(" %d",&p);
	Dfs(0);
	printf("\n");
	memset(vis,0,101*sizeof(int));
	Bfs(0);
	printf("\n");
	memset(vis,0,101*sizeof(int));
	vis[p]=1;
	Dfs(0);
	printf("\n");
	memset(vis,0,101*sizeof(int));
	vis[p]=1;
	Bfs(0);
	return 0;
}

