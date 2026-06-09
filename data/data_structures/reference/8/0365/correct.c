#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, a[105][105];
int v[105], ok, q[105];
void dik(int x)
{
	if (!ok)
		printf("%d", x), ok = 1;
	else
		printf(" %d", x);
	v[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[x][i])
		{
			if (!v[i])
			{
				
				dik(i);
			}
		}
}
void bik(int t)
{
	q[1] = t;

	int l,r,i;
	r=1;
	l=1;
	while (l<=r)
	{
		int x=q[l];
		l++;
		if (v[x]==1)
			continue;
		if (ok!=1)
			{
				printf("%d",x);
				ok = 1;
			}
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
	ok = 0;
	dik(0);
	printf("\n");
	memset(v, 0, sizeof(v));
	ok = 0;
	bik(0);
	printf("\n");
	scanf("%d", &i);
	v[i] = 1;
	ok = 0;
	dik(0);
	printf("\n");
	memset(v, 0, sizeof(v));
	v[i] = 1;
	ok = 0;
	bik(0);
	printf("\n");
	return 0;
}

