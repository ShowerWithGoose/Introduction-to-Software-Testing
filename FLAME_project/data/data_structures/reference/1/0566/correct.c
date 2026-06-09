#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void print();
void dfs(int k);
int n;
int used[15], j[15];
int main()
{
	int i;
	scanf("%d", &n);
	dfs(0);
	return 0;
}
void print()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("%d ", used[i]);
	}
	printf("\n");
}
void dfs(int k)
{
	int i;
	if (k == n)
	{
		print();
		return ;
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			if (!j[i])
			{
				j[i] = 1;
				used[k+1] = i;
				dfs(k+1);
				j[i] = 0;
			}
		}
	}
}

