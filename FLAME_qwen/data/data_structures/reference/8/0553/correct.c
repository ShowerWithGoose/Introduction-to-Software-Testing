#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int map[105][105] = { 0 };
int order[105];
int flag[105];
int n, e,step;
void print(int n0)
{
	int i;
	printf("0");
	for (i = 1; i < n0; i++)
		printf(" %d", order[i]);
	printf("\n");
}
void init()
{
	memset(flag, 0, sizeof(flag));
	memset(order, 0, sizeof(order));
	step = 0;
}
void dfs(int v)
{
	int i;
	order[step] = v;
	step++;
	flag[v] = 1;
	for (i = 0; i < n; i++)
	{
		if (map[v][i] == 1 && flag[i] == 0)
			dfs(i);
	}
	return;
}
void bfs(int v)
{
	order[0] = v;
	flag[v] = 1;
	int head = 0, tail = 1,i;
	while (head < tail)
	{
		for (i = 0; i < n; i++)
		{
			if (map[order[head]][i] == 1 && flag[i] == 0)
			{
				order[tail] = i;
				flag[i] = 1;
				tail++;
			}
		}
		head++;
	}
}
int main()
{
	scanf("%d%d", &n, &e);
	int i, v1, v2,v0;
	for (i = 1; i <= e; i++)
	{
		scanf("%d%d", &v1, &v2);
		map[v1][v2] = 1;
		map[v2][v1] = 1;
	}
	init();
	dfs(0);
	print(n);
	init();
	bfs(0);
	print(n);
	scanf("%d", &v0);
	for (i = 0; i < n; i++)
	{
		map[v0][i] = map[i][v0] = 0;
	}
	init();
	dfs(0);
	print(n-1);
	init();
	bfs(0);
	print(n-1);
	return 0;
}
