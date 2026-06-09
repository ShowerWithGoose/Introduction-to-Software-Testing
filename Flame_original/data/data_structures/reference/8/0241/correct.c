#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int tu[200][200];
int visit[200];
int count_1, count_2;
void DFS(int n);
void BFS(int n);
int main()
{
	int u, v;
	scanf("%d%d", &count_1, &count_2);
	for (int ling = 0; ling < count_2; ling++)
	{
		scanf("%d%d", &u, &v);
		tu[u][v] = 1;
		tu[v][u] = 1;
	}
	DFS(0);
	printf("\n");
	memset(visit, 0, sizeof(visit));
	BFS(0);
	printf("\n");
	int m;
	scanf("%d", &m);
	visit[m] = 1;
	memset(visit, 0, sizeof(visit));
	visit[m] = 1;
	DFS(0);
	printf("\n");
	memset(visit, 0, sizeof(visit));
	visit[m] = 1;
	BFS(0);
	printf("\n");
}
void DFS(int n)
{
	printf("%d ", n);
	visit[n] = 1;
	for (int ling = 0; ling < count_1; ling++)
	{
		if (tu[n][ling] && !visit[ling])	//如果矩阵元素为 1 且未访问过
		{
			DFS(ling);		//DFS访问 
		}
	}
}
void BFS(int n)
{
	int duilie[200];
	int head = 0;
	int tail = 1;
	int jilu;
	duilie[head] = n;
	while (head <= tail)
	{
		jilu = duilie[head];	
		if (jilu >= 200 || jilu < 0)
		{
			break;
		}
		head++;			
		if (!visit[jilu])	
		{
			printf("%d ",jilu);		
			visit[jilu] = 1;			//已访问 
			for (int ling = 0; ling < count_1; ling++)
				if (tu[jilu][ling] && !visit[ling])	//如果矩阵元素为 1 且未访问过 
					duilie[tail++] = ling;		//入队 
		}

	}
}
