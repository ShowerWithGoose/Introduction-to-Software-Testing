#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, j, aa[105][105], vista[105], q[105];

void actionone(int);
void actiontwo(int);

int main()
{
	int x, y;
	scanf("%d%d", &n, &m);
	int i;
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		aa[x][y] = 1;
		aa[y][x] = 1;
	}
	j = 0;
	actionone(0);
	printf("\n");
	
	memset(vista, 0, sizeof(vista));
	j = 0;
	actiontwo(0);
	printf("\n");
	scanf("%d", &i);
	vista[i] = 1;
	j = 0;
	actionone(0);
	printf("\n");
	
	memset(vista, 0, sizeof(vista));
	vista[i] = 1;
	j = 0;
	actiontwo(0);
	printf("\n");
	return 0;
}

void actionone(int x)
{
	if (!j)
		printf("%d", x), j = 1;
	else
		printf(" %d", x);
	vista[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (aa[x][i])
		{
			if (!vista[i])
			{
				actionone(i);
			}
		}
}
void actiontwo(int t)
{
	int l = 1, r = 1, i, x;
	q[1] = t;
	while (l <= r)
	{
		x = q[l];
		l++;
		if (vista[x])
			continue;
		if (!j)
			printf("%d", x), j = 1;
		else
			printf(" %d", x);

		vista[x] = 1;
		for (i = 1; i <= n; i++)
			if (aa[x][i])
			{
				if (!vista[i])
					q[++r] = i;
			}
	}
	memset(vista, 0, sizeof(vista));
}

