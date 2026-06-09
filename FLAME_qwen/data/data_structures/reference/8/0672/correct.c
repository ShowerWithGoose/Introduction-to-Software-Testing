#include<stdio.h>
int g[100][100],n,m;
int vis[100];
int que[1001],head,tail;
void dfs(int u)
{
	printf("%d ",u);
	vis[u]=1;
	for(int i=0;i<n;i++)
		if(g[u][i]&&(!vis[i]))
			dfs(i);
}
void bfs()
{
	head=1;tail=0;
	que[++tail]=0;
	vis[0]=1;
	while(head<=tail)
	{
		int u=que[head++];
		printf("%d ",u);
		for(int i=0;i<n;i++)
			if(g[u][i]&&(!vis[i]))
			{
				que[++tail]=i;
				vis[i]=1;
			}
	}
}
void clear()
{
	puts("");
	for(int i=0;i<n;i++)vis[i]=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	dfs(0);
	clear();
	bfs();
	clear();
	int u;
	scanf("%d",&u);
	for(int i=0;i<n;i++)g[i][u]=g[u][i]=0;
	dfs(0);
	clear();
	bfs();
	clear();
}

