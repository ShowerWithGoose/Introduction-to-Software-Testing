#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n, m, a[105][105];
int vis[105], k, q[105];
void g1(int x)
{
	if (!k)
	{
		printf("%d", x);
		k = 1;
	}
	else
		printf(" %d", x);
	vis[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[x][i])
			if (!vis[i])		
				g1(i);
	return;
}
void g2(int t)
{
	q[1] = t;

	int l = 1, r = 1, i;
	while (l <= r)
	{
		int x = q[l];
		l++;
		if (vis[x])
			continue;
		if (!k)
		{
			printf("%d", x);
			k = 1;
		}
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
	return;
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
	k = 0;
	g1(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	k = 0;
	g2(0);
	printf("\n");
	scanf("%d", &i);
	vis[i] = 1;
	k = 0;
	g1(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	vis[i] = 1;
	k = 0;
	g2(0);
	printf("\n");
	return 0;
}

