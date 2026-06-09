#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, a[105][105];
int v[105], y, q[105];
void dfs(int x)
{
	if (!y)
		printf("%d", x), y = 1;
	else
		printf(" %d", x);
	v[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[x][i])
		{
			if (!v[i])
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
		if (v[x])
			continue;
		if (!y)
			printf("%d", x), y = 1;
		else
			printf(" %d", x);

		v[x] = 1;
		for (i = 1; i <= n; i++)
			if (a[x][i])
			{
				if (!v[i])
					q[++r] = i;
			}
	}
	memset(v, 0, sizeof(v));
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
	y = 0;
	dfs(0);
	printf("\n");
	memset(v, 0, sizeof(v));
	y = 0;
	bfs(0);
	printf("\n");
	scanf("%d", &i);
	v[i] = 1;
	y = 0;
	dfs(0);
	printf("\n");
	memset(v, 0, sizeof(v));
	v[i] = 1;
	y = 0;
	bfs(0);
	printf("\n");
	return 0;
}

