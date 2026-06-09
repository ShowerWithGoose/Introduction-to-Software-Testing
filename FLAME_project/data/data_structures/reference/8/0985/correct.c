#include<stdio.h>
#include<string.h>

int n,m;
int e[505][505];
int vis[505];
int flg=9999;

int q[5005];
int s,t;

void dfs(int u)
{
	if(vis[u]==1)
		return ;
	printf("%d ",u);
	vis[u]=1;
	for(int i=0;i<n;i++)
	{
		if(!e[u][i]||i==flg||i==u)
			continue;
		dfs(i);
	}
}

void bfs()
{
	memset(vis,0,sizeof(vis));
	s=0,t=0;
	q[t++]=0,vis[0]=1;
	while(s<t)
	{
		int u=q[s++];
		printf("%d ",u);
		for(int i=0;i<n;i++)
		{
			if(!e[u][i]||u==i||i==flg)
				continue;
			if(!vis[i])
				vis[i]=1,q[t++]=i;
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u][v]=e[v][u]=1;
	}
	dfs(0);
	printf("\n");
	bfs();
	scanf("%d",&flg);
	printf("\n");
	memset(vis,0,sizeof(vis));
	dfs(0);
	printf("\n");
	bfs();
	return 0;
}

