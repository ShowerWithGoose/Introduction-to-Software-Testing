#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int G[103][103]={0};int n,m,shan;
int vis[103]={0};
int queue[103],ps=0,pt=-1;
void DFS(int x)
{
	int i;vis[x]=1;printf("%d ",x);
	for(i=0;i<n;i++)if(G[x][i]&&!vis[i])DFS(i);
	return;
}
void BFS()
{
	int x,i;vis[0]=1;queue[++pt]=0;
	while(ps<=pt)
	{
		x=queue[ps];printf("%d ",x);
		for(i=0;i<n;i++)if(G[x][i]&&!vis[i])
		{
			queue[++pt]=i;vis[i]=1;
		}
		ps++;
	}
}
void s_dfs(int x)
{
	int i;vis[x]=1;printf("%d ",x);
	for(i=0;i<n;i++)if(G[x][i]&&!vis[i]&&i!=shan)s_dfs(i);
	return;
}
void s_bfs()
{
	int x,i;vis[0]=1;queue[++pt]=0;
	while(ps<=pt)
	{
		x=queue[ps];printf("%d ",x);
		for(i=0;i<n;i++)if(G[x][i]&&!vis[i]&&i!=shan)
		{
			queue[++pt]=i;vis[i]=1;
		}
		ps++;
	}
}
int main()
{
	int i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		G[a][b]=G[b][a]=1;
	}
	scanf("%d",&shan);
	DFS(0);printf("\n");memset(vis,0,sizeof(vis));
	BFS();printf("\n");memset(vis,0,sizeof(vis));ps=0;pt=-1;
	s_dfs(0);printf("\n");memset(vis,0,sizeof(vis));
	s_bfs();
	return 0;
}

