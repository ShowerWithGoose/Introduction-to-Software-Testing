#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, a[105][105];
int vis[105], ok, q[105];
void dt(int x)
{
	if (ok==0)
		printf("%d", x), ok = 1;
	else
		printf(" %d", x);
	vis[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[x][i])
		{
			if (vis[i]==0)
			{
				dt(i);
			}
		}
}
void fcp(int m){
	int i;
	for(i=0;i<104;i++){
		vis[i]=0;
	}
	vis[i]='\0';
}
void bfs(int t)
{
	int x;
	q[1] = t;

	int l = 1, r = 1, i;
	while (l <= r)
	{
		x = q[l];
		l++;
		if (vis[x])
			continue;
		if (ok==0)
			printf("%d", x), ok = 1;
		else
			printf(" %d", x);

		vis[x] = 1;
		for (i = 1; i <= n; i++)
			if (a[x][i])
			{
				if (vis[i]==0)
					q[++r] = i;
			}
	}
	fcp(0);
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
	dt(0);
	printf("\n");
	fcp(0);
	ok = 0;
	bfs(0);
	printf("\n");
	scanf("%d", &i);
	vis[i] = 1;
	ok = 0;
	dt(0);
	printf("\n");
	fcp(0);
	vis[i] = 1;
	ok = 0;
	bfs(0);
	printf("\n");
	return 0;
}

