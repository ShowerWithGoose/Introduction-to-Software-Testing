#include<stdio.h>
#include<string.h>
int G[101][101];
int Visited[101];
void bubbleSort(int v, int n);
void travelDFS(int n, int warn);
void DFS(int v);
void travelBFS(int n, int warn);
void BFS(int v);
int Q[100];
int main()
{
	int vern, edgen, v1, v2, v;
	int i, j;
	memset(G, -1, sizeof(G));
	memset(Q, -1, sizeof(Q));
	scanf("%d %d", &vern, &edgen);
	for (i = 0; i < edgen; i++)
	{
		scanf("%d %d", &v1, &v2);
		for (j = 0; G[v1][j] != -1; j++);
		G[v1][j] = v2;
		for (j = 0; G[v2][j] != -1; j++);
		G[v2][j] = v1;
	}
	scanf("%d", &v);
	for (i = 0; i < vern; i++)
	{
		for (j = 0; G[i][j] != -1; j++);
		bubbleSort(i, j);
	}
	travelDFS(vern,v);
	printf("\n");
	travelBFS(vern,v);
	printf("\n");
	for (i = 0; i < vern; i++)
	{
		for (j = 0; G[i][j] != -1; j++)
		{
			if (G[i][j] == v)
				G[i][j] = 1000;
		}
	}
	for (j = 0; G[v][j] != -1; j++)
		G[i][j] = 1000;
	travelDFS(vern,v);
	printf("\n");
	travelBFS(vern,v);

	return 0;
}
void bubbleSort(int v, int n)
{
	int i, j, hold, flag;
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (G[v][j] > G[v][j + 1])
			{
				hold = G[v][j];
				G[v][j] = G[v][j + 1];
				G[v][j + 1] = hold;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
void travelDFS(int n, int warn)
{
	int i;
	for (i = 0; i < n; i++)
		Visited[i] = 0;
	for (i = 0; i < n; i++)
	{
		if (i == warn)
			continue;
		else
		{
			if (Visited[i] == 0)
				DFS(i);
		}
	}
}
void DFS(int v)
{
	int i;
	if (Visited[v] == 0)
		printf("%d ", v);
	Visited[v] = 1;//标识顶点v被访问
	for (i = 0; G[v][i] != -1; i++)
	{
		if (G[v][i] != 1000)
		{
			if (Visited[G[v][i]] == 0)
				DFS(G[v][i]);
		}
	}
}
void travelBFS(int n, int warn)
{
	int i;
	for (i = 0; i < n; i++)
		Visited[i] = 0;
	for (i = 0; i < n; i++)
	{
		if (i == warn)
			continue;
		else
		{
			if (Visited[i] == 0)
				BFS(i);
		}
	}
}
void BFS(int v)
{
	int i, j;
	printf("%d ", v);
	Visited[v] = 1;
	for (j = 0; Q[j] != -1; j++);
	Q[j] = v;
	while (Q[0] != -1)
	{
		v = Q[0];
		for (j = 0; Q[j] != -1; j++)
			Q[j] = Q[j + 1];
		for (i = 0; G[v][i] != -1; i++)
		{
			if (G[v][i] != 1000)
			{
				if (Visited[G[v][i]] == 0)
				{
					printf("%d ", G[v][i]);
					Visited[G[v][i]] = 1;
					for (j = 0; Q[j] != -1; j++);
					Q[j] = G[v][i];
				}
			}
		}
	}
}
