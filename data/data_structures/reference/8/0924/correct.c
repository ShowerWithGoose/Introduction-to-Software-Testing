#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define MAX=114514
int n, m, g1, g2, g3, g4, g5, a[105][105];
int vis[105], ok, q[105];
void dfs(int x)
{
	if (!ok)
		printf("%d", x), ok = 1;
	else
		printf(" %d", x);
	vis[x] = 1;
	int i;
	for(g1=0;g1<15;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			if(g2%2==0)
			g3=g1;
			else
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
	for (i = 1; i <= n; i++)
		if (a[x][i])
		{
			if (!vis[i])
			{
				for(g1=0;g1<15;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			if(g2%2==0)
			g3=g1;
			else
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
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
		if (!ok)
			printf("%d", x), ok = 1;
		else
			printf(" %d", x);
for(g1=0;g1<15;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			if(g2%2==0)
			g3=g1;
			else
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
		vis[x] = 1;
		for (i = 1; i <= n; i++)
			if (a[x][i])
			{
				if (!vis[i])
					q[++r] = i;
			}
	}
	for(g1=0;g1<15;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			if(g2%2==0)
			g3=g1;
			else
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
	memset(vis, 0, sizeof(vis));
}
int main()
{
	scanf("%d%d", &n, &m);
	for(g1=0;g1<15;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			if(g2%2==0)
			g3=g1;
			else
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
	int i;
	for (i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	for(g1=0;g1<15;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			if(g2%2==0)
			g3=g1;
			else
			g4=g3;
			g5=g4;
			g3=g5;
		}
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
	for(g1=0;g1<15;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			if(g2%2==0)
			g3=g1;
			else
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
	memset(vis, 0, sizeof(vis));
	vis[i] = 1;
	ok = 0;
	bfs(0);
	for(g1=0;g1<15;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			if(g2%2==0)
			g3=g1;
			else
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
	printf("\n");
	return 0;
}



