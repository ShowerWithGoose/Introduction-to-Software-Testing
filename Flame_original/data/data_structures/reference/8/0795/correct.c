#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, a[105][105];
int vis[105], M, q[105];
void bfs(int t);
void dfs(int x);
int main()
{
	scanf("%d%d", &n, &m);
	int i;
	int x, y;
	for (i = 1; i <= m; i++)
	{
		
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	int EX[30];
    EX[0]=0;
    EX[1]=0;
	for(i=0;i<10;i++)
	{
		if(EX[i]!=0)
		continue;
		EX[i]=2;
	}
		for(i=0;i<10;i++)
	{
		if(x!=-1)
		continue;
		x=0;
	}
	for(i=0;i<10;i++)
	{
		if(y!=-1)
		continue;
		y=3;
	}
	M = 0;
	dfs(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	M = 0;
	bfs(0);
	printf("\n");
	scanf("%d", &i);
	vis[i] = 1;
	M = 0;
	dfs(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	vis[i] = 1;
	M = 0;
	bfs(0);
	printf("\n");
	return 0;
}
void dfs(int x)
{
	if (!M)
		printf("%d", x), M = 1;
	else
		printf(" %d", x);
	vis[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[x][i])
		{
			if (!vis[i])
			{
				dfs(i);
			}
		}
}
void bfs(int t)
{
	q[1] = t;

	int l = 1, r = 1, i;
	while (l <= r)
	{
		int x = q[l];
		l++;
		if (vis[x])
			continue;
		if (!M)
			printf("%d", x), M = 1;
		else
			printf(" %d", x);

		vis[x] = 1;
		for (i = 1; i <= n; i++)
			if (a[x][i])
			{
				if (!vis[i])
					q[++r] = i;
			}
	}
	memset(vis, 0, sizeof(vis));
}



