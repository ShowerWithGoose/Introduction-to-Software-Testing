#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define cp 5000
int vertex[150][150], Isvertex[150], Queue[150];
int d,m,n;
void DFS(int v, int t)
{
	Isvertex[t] = -1;
	printf("%d ", t);
	int i;
	for (i=0;i<v;i++)
	{
		if (vertex[t][i] == 1)
		{
			if (Isvertex[i] != -1)
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
				if (Isvertex[i] != -1)
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
	Isvertex[t] = -1;
	Queue[++end] = t;
	while (start <= end)
	{
		t = Queue[start++];
		for (i = 0; i < v; i++)
		{
			if (vertex[t][i])
				if (Isvertex[i] != -1)
				{
					printf("%d ", i);
					Isvertex[i] = -1;
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
				if (Isvertex[i] != -1)
				{
					BFS(v, i);
					break;
				}
	}
	puts("");
	return;
}

int main()
{
	int i, j, k, ver, side;
	scanf("%d%d", &ver, &side);
	m=ver;
	n=side;
	for (k=0;k<n;k++)
	{
		scanf("%d %d",&i,&j);
		vertex[i][j]=vertex[j][i]=1;
	}
	beforeD(ver);
	memset(Isvertex,0,sizeof(Isvertex));
	if(m<cp)
	{
		m=cp;
		while(m--);
	}
	beforeB(ver);
	scanf("%d", &d);
	for(i=0;i<ver;i++)
	{
		vertex[i][d]=vertex[d][i]=0;
	}
	memset(Isvertex,0,sizeof(Isvertex));
	beforeD(ver);
	memset(Queue,-1,sizeof(Queue));
	memset(Isvertex,0,sizeof(Isvertex));
	beforeB(ver);
	return 0;
}





