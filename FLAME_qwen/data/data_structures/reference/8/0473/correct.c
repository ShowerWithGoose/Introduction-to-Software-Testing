#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int n,m;
int edge[120][120],ans[120],q[120],vis[120];
void dfs(int u)
{
	vis[u] = 1;
	ans[++ans[0]]=u;
	
	for(int i=0;i<n;i++)
	 if(edge[u][i] && !vis[i])
	  dfs(i);
}
void bfs()
{
	int l=0,r=0;
	q[++r] = 0;
	while(l<r)
	{
		
		int u = q[++l];
		if(vis[u]) continue;
		vis[u]=1;
		printf("%d ",u);
		
		for(int i=0;i<n;i++)
		 if(edge[u][i] && !vis[i])
		  q[++r] = i;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int x,y,node;
	while(m--)
	{
		scanf("%d%d",&x,&y);
		edge[x][y]=1;
		edge[y][x]=1;	
	}
	scanf("%d",&node);
	dfs(0);
	for(int i=1;i<=ans[0];i++) printf("%d ",ans[i]);
	printf("\n");
	memset(vis,0,sizeof(vis));
	ans[0]=0;
	
	bfs();
	printf("\n");
	memset(vis,0,sizeof(vis));
	
	vis[node]=1;
	dfs(0);
	for(int i=1;i<=ans[0];i++) printf("%d ",ans[i]);
	printf("\n");
	memset(vis,0,sizeof(vis));
	ans[0]=0;
	
	vis[node]=1;
	bfs();
	memset(vis,0,sizeof(vis));
}

