#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vertex[109][109], judge[109], Queue[109];

void DFS(int v, int t)
{
	judge[t] = -1;
	printf("%d ", t);
	int i;
	for (i = 0; i < v; i++)
	{
		if (vertex[t][i] == 1)
		{
			if (judge[i]!= -1)
			{
				DFS(v, i);
			}
		}
	}
}

void beforeD(int v)
{
	int i, j;
	for (i = 0; i < v; i++)
		for (j = 0; j < v; j++)
			if (vertex[i][j] == 1)
				if (judge[i] != -1)
				{
					DFS(v, i);
					break;
				}
	printf("\n");
	return;
}

void BFS(int v, int t)
{
	int i, start = 0, end = -1;
	printf("%d ", t);
	judge[t] = -1;
	Queue[++end] = t;
	while (start <= end)
	{
		t = Queue[start++];
		for (i = 0; i < v; i++)
		{
			if (vertex[t][i])
				if (judge[i] != -1)
				{
					printf("%d ", i);
					judge[i] = -1;
					Queue[++end] = i;
				}
		}
	}
	return;
}
void beforeB(int v)
{
	int i, j;
	for (i = 0; i < v; i++)
	{
		for (j = 0; j < v; j++)
			if (vertex[i][j] == 1)
				if (judge[i] != -1)
				{
					BFS(v, i);
					break;
				}
	}
	printf("\n");
	return;
}

int main(void)
{
	int i, j, k, ver, side;
	scanf("%d%d", &ver, &side);
	for (k = 0; k < side; k++)
	{
		scanf("%d %d", &i, &j);
		vertex[i][j] = vertex[j][i] = 1;
	}
	beforeD(ver);
	memset(judge, 0, sizeof(judge));
	beforeB(ver);
	int d;
	scanf("%d", &d);
	for (i = 0; i < ver; i++)
	{
		vertex[i][d] = vertex[d][i] = 0;
	}
	memset(judge, 0, sizeof(judge));
	beforeD(ver);
	memset(Queue, -1, sizeof(Queue));
	memset(judge, 0, sizeof(judge));
	beforeB(ver);
}



