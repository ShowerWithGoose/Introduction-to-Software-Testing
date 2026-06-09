#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int n, m, a[105][105],COUNT[105], temt, longago[105];
void DFS(int zipper);
void BFS(int t);
int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	int i;
	for (i = 1; i <= m; i++)
	{
		int zipper, loss;
		scanf("%d", &zipper);
		scanf("%d", &loss);
		a[zipper][loss]=a[loss][zipper] = 1;
	}
	temt = 0;
	DFS(0);
	putchar(10);
	memset(COUNT, 0, sizeof(COUNT));
	temt = 0;
	BFS(0);
	putchar(10);
	scanf("%d", &i);
	COUNT[i] = 1;
	temt = 0;
	DFS(0);
	putchar(10);
	memset(COUNT, 0, sizeof(COUNT));
	COUNT[i] = 1;
	temt = 0;
	BFS(0);
	putchar(10);
	return 0;
}
void BFS(int t)
{
	longago[1] = t;
	int l = 1, r = 1, i;
	while (l <= r)
	{
		int zipper = longago[l];
		l++;
		if (COUNT[zipper])
			continue;
		if (!temt)
			printf("%d", zipper), temt = 1;
		else
			printf(" %d", zipper);

		COUNT[zipper] = 1;
		for (i = 1; i <= n; i++)
			if (a[zipper][i])
			{
				if (!COUNT[i])
					longago[++r] = i;
			}
	}
	memset(COUNT, 0, sizeof(COUNT));
}
void DFS(int zipper)
{
	if (!temt)
		printf("%d", zipper), temt = 1;
	else
		printf(" %d", zipper);
	COUNT[zipper] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[zipper][i])
		{
			if (!COUNT[i])
			{
				DFS(i);
			}
		}
}

