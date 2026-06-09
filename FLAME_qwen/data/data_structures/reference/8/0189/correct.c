#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 105
int weight[max][max];
int visited[max];
int queen[max];
int m, n;
void DFSsearch(int start);
void BFSsearch(int start);
int main()
{
	int i, j, k;

	int x;
	int u, v;//u表示行，v表示列
	scanf("%d%d", &m, &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		weight[u][v] = 1;
		weight[v][u] = 1;
	}
	scanf("%d", &x);
	DFSsearch(0);
	printf("\n");
	for (i = 0; i < m; i++)
		visited[i] = 0;
	BFSsearch(0);
	printf("\n");
	for (i = 0; i < m; i++)
		visited[i] = 0;
	visited[x] = 1;
	DFSsearch(0);
	printf("\n");
	for (i = 0; i < m; i++)
		visited[i] = 0;
	visited[x] = 1;
	BFSsearch(0);
	printf("\n");
	return 0;
}
void DFSsearch(int start)
{
	int i = 0;
	printf("%d ", start);
	visited[start] = 1;
	for (i = 0; i < m; i++)
	{
		if (visited[i] == 0 && weight[start][i] == 1)
		{
			DFSsearch(i);
		}
	}
}

void BFSsearch(int start)
{
	int frout=-1,rear=0,i,temp;
	queen[0] = start;
	while (frout < rear)
	{
		temp = queen[++frout];
		if (visited[temp] == 1) continue;
		else {
			printf("%d ", temp);
			visited[temp] = 1;
			for (i = 0; i < m; i++)
			{
				if (visited[i] != 1 && weight[temp][i] == 1)
					queen[++rear] = i;
			}
		}
	}
}
