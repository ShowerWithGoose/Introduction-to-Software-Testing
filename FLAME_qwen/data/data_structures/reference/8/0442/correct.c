#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, edge_n;
int maps[108][108];
int vis[108];
void dfs(int x)
{
	vis[x] = 1;
	printf("%d ", x);
	for (int i = 1; i < n; i++)
	{
		if (vis[i] == 0 && maps[x][i] == 1)
		{
			dfs(i);
		}
	}
}
int queue[108];
int head = -1, rear= 0;
void bfs()
{
	queue[++head] = 0;
	while (head >= rear)
	{
		int x = queue[rear++];
		if(vis[x] == 0)
		printf("%d ", x);
		vis[x] = 1;
		for (int i = 1; i < n; i++)
		{
			if (maps[x][i] == 1 && vis[i] == 0)
			{
				queue[++head] = i;
				
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &edge_n);
	memset(vis, 0, sizeof(vis));
	for (int  i = 0; i < edge_n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		maps[x][y] = maps[y][x] = 1;
	}
	int elim;
	scanf("%d", &elim);
	dfs(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	bfs();
	printf("\n");
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
	{
		maps[elim][i] = maps[i][elim] = 0;
	}
	dfs(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	bfs();
	return 0;
}

