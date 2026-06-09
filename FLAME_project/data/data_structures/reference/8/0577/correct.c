#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,m,a[105][105],vis[105],g,q[105];
void dfs(int x)
{
	if(!g){
		printf("%d",x);
		g=1;
	}
	else{
		printf(" %d",x);
	}
	vis[x] = 1;
	int i;
	for(i=1;i<=n;i++){
		if (a[x][i]){
			if (!vis[i])dfs(i);
		}
	}
}
void bfs(int t)
{
	q[1] = t;
	int l=1,r=1,i;
	while (l<=r){
		int x = q[l];
		l++;
		if (vis[x])continue;
		if (!g){
			printf("%d",x);
			g=1;
		}
		else{
			printf(" %d",x);
		}
		vis[x]=1;
		for (i=1;i<=n;i++){
			if (a[x][i]){
				if (!vis[i])q[++r] = i;
			}
		}
	}
	memset(vis, 0, sizeof(vis));
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,x,y;
	for(i=1;i<=m;i++){
		scanf("%d%d", &x, &y);
		a[x][y]=1;
		a[y][x]=1;
	}
	g=0;
	dfs(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	g=0;
	bfs(0);
	printf("\n");
	scanf("%d",&i);
	vis[i]=1;
	g=0;
	dfs(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	vis[i]=1;
	g=0;
	bfs(0);
	printf("\n");
	return 0;
}

