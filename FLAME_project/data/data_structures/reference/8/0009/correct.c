#include <stdio.h>
#include <stdlib.h>


int g_matrix[100][100];

int dfs(int start, int* result, int* visited, int n, int index)
{
	result[index] = start;
	visited[start] = 1;
	index++;
	for (int i = 0; i < n; i++)
	{
		if (g_matrix[start][i] == 1 && visited[i] == 0)
		{
			index = dfs(i, result, visited, n, index);
		}
	}
	return index;
}

int bfs(int* result, int n)
{
	int visited[100] = { 0 };
	int start = 0;
	int end = 0;

	result[end++] = 0;
	visited[0] = 1;
	while (start < end)
	{
		int dat = result[start];
		for (int i = 0; i < n; i++)
		{
			if (g_matrix[dat][i] == 1 && visited[i] == 0)
			{
				result[end++] = i;
				visited[i] = 1;
			}
		}
		start++;
	}
	return end;
}


int main()
{
	int n = 0;
	int m = 0;
	memset(g_matrix, 0, sizeof(g_matrix));

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		g_matrix[v1][v2] = 1;
		g_matrix[v2][v1] = 1;
	}

	// É¾³ı½Úµã
	int k = 0;
	scanf("%d", &k);

	int result[100] = { 0 };
	int visited[100] = { 0 };
	int index = 0;
	int count = dfs(0, result, visited, n, index);
	for (int i = 0; i < count; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");

	memset(result, 0, sizeof(result));
	count = bfs(result, n);
	for (int i = 0; i < count; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		g_matrix[k][i] = 0;
		g_matrix[i][k] = 0;
	}

	memset(result, 0, sizeof(result));
	memset(visited, 0, sizeof(visited));
	index = 0;
	count = dfs(0, result, visited, n, index);
	for (int i = 0; i < count; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");

	memset(result, 0, sizeof(result));
	count = bfs(result, n);
	for (int i = 0; i < count; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");

	//system("pause");
	return 0;
}



