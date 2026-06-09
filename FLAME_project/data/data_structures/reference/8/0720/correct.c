#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int G[105][105],n,m;
int q[105],vis[105];
void bfs()
{
	memset(vis,0,sizeof(vis));
	int head=1,tail=0;
	q[++tail]=0;vis[0]=1;
	while(head<=tail)
	{
		int j=q[head++];
		for(int i=0;i<n;i++){
			if(G[j][i]&&!vis[i]){
				q[++tail]=i;vis[i]=1;
			}
		}
		printf("%d ",j);
	}puts("");
}
void dfs(int j)
{
	vis[j]=1;
	printf("%d ",j);
	for(int i=0;i<n;i++){
		if(!vis[i]&&G[j][i])dfs(i);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		G[u][v]=G[v][u]=1;
	}
	int node;scanf("%d",&node);
	memset(vis,0,sizeof(vis));
	dfs(0);puts("");
	bfs();
	for(int i=0;i<n;i++){
		G[node][i]=0;
		G[i][node]=0;
	}
	memset(vis,0,sizeof(vis));
	dfs(0);puts("");
	bfs();
	return 0; 
}

