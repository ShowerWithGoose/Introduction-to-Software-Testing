#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M -210000000
struct Node
{
	int num;
}N[1000000];

void add(int num, int dex)
{
	if (N[dex].num > num)
	{
		if (N[dex * 2].num == M)
		{
			N[dex * 2].num = num;
			return;
		}
		else
		{
			add(num, dex * 2);
		}
	}
	else
	{
		if (N[dex * 2 + 1].num == M)
		{
			N[dex * 2 + 1].num = num;
			return;
		}
		else
		{
			add(num, dex * 2 + 1);
		}
	}
}

void dfs(int dex)
{
	int b = 1;
	if (N[dex * 2].num != M)
	{
		b = 0;
		dfs(dex * 2);
	}
	if (N[dex * 2 + 1].num != M)
	{
		b = 0;
		dfs(dex * 2 + 1);
	}
	if (b)
	{
		printf("%d %d\n", N[dex].num, (int)(log(dex) / log(2)) + 1);
	}
}

int main()
{
	for (int i = 0; i < 100000; i++)
	{
		N[i].num = M;
	}
	int n, t;
	scanf("%d", &n);
	scanf("%d", &t);
	N[1].num = t;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d", &t);
		add(t, 1);
	}
	dfs(1);
	return 0;
}

