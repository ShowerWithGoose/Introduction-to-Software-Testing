#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, a[105][105];
int vis[105], ok, q[105];
void dfs(int x)
{
    int i;
	if (ok==0)
		{printf("%d", x);
		 ok=1;}
	else
		printf(" %d", x);
	vis[x]=1;
	for (i=1;i<=n;i++)
		if (a[x][i]!=0)
		{
			if (vis[i]==0)
			{
            dfs(i);
			}
		}
}
void bfs(int t)
{
	q[1] = t;
	int lnode=1,rnode=1,i;
	while (lnode<=rnode)
	{
		int x = q[lnode];
		lnode++;
		if (vis[x]!=0)
			continue;
		if (ok==0)
			{printf("%d", x);
			ok = 1;}
		else
			printf(" %d", x);

		vis[x] = 1;
		for (i=1;i<=n;i++)
			if (a[x][i]!=0)
			{
				if (vis[i]==0)
					q[++rnode] = i;
			}
	}
	memset(vis, 0, sizeof(vis));
}
int main()
{
	scanf("%d%d", &n, &m);
	int i;
	for (i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	ok = 0;
	dfs(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	ok = 0;
	bfs(0);
	printf("\n");
	scanf("%d", &i);
	vis[i] = 1;
	ok = 0;
	dfs(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	vis[i] = 1;
	ok = 0;
	bfs(0);
	printf("\n");
	return 0;
}


