#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m, a[105][105];
int visit[105], first, q[105];
void dfs(int x)
{
	if (first==0)
	{
		printf("%d", x), first = 1;
	}
	else
	{
		printf(" %d", x);
	}
	visit[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[x][i])
		{
			if (visit[i]==0)
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
		if (visit[x])
		{
			continue;
		}
		if (first==0)
		{
			printf("%d", x), first = 1;
		}
		else
		{
			printf(" %d", x);
		}
		visit[x] = 1;
		for (i = 1; i <= n; i++)
		{
			if (a[x][i])
			{
				if (!visit[i])
				{
					q[++r] = i;
				}
			}
		}
	}
	memset(visit, 0, sizeof(visit));
}
int main()
{
	scanf("%d%d", &n, &m);
	int i, j, k;
	for (i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	first = 0;
	dfs(0);
	printf("\n");
	memset(visit, 0, sizeof(visit));
	first = 0;
	bfs(0);
	printf("\n");
	scanf("%d", &i);
	visit[i] = 1;
	first = 0;
	dfs(0);
	printf("\n");
	memset(visit, 0, sizeof(visit));
	visit[i] = 1;
	first = 0;
	bfs(0);
	printf("\n");
	return 0;
}



