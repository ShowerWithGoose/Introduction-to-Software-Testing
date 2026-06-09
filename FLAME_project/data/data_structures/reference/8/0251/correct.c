#include <stdio.h>
#include <stdlib.h>

int n, m, a[105][105];
int e[105], flag, q[105];

void *(memset) (void *s,int c,size_t n)
{
	 char k = c;   
	unsigned char *t;
	for(t = s;n>0;++t,--n)
		*t = k;
	return s;
}

void DFS(int x)
{
	if (flag==0)
	{
			printf("%d", x);
		 flag = 1;
	}
	
	else
	{
		printf(" %d", x);
	}
	
	e[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[x][i])
		{
			if (e[i]==0)
			{
				DFS(i);
			}
		}
}
void BFS(int t)
{
	q[1] = t;

	int l = 1, r = 1, i;
	while (l <= r)
	{
		int x = q[l];
		l++;
		if (e[x])
			continue;
		if (flag==0)
		{
			printf("%d", x);
			flag = 1;
		}
			
		else
			printf(" %d", x);

		e[x] = 1;
		for (i = 1; i <= n; i++)
			if (a[x][i])
			{
				if (e[i]==0)
				{
						q[++r] = i;
				}
				
			}
	}
	memset(e, 0, sizeof(e));
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
	flag = 0;
	DFS(0);
	printf("\n");
	memset(e, 0, sizeof(e));
	flag = 0;
	BFS(0);
	printf("\n");
	scanf("%d", &i);
	e[i] = 1;
	flag = 0;
	DFS(0);
	printf("\n");
	memset(e, 0, sizeof(e));
	e[i] = 1;
	flag = 0;
	BFS(0);
	printf("\n");
	return 0;
}


