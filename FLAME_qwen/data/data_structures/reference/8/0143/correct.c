#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>



int graph[100][100], f[100], q[100];

void dfs(int x, int d,int n) 
{
	printf("%d ", x);
	f[x] = 1;
	int i;
	for ( i = 0; i < n; i++)
	{
  		if (graph[x][i] && i != d && !f[i])
		{
   			dfs(i, d,n);
  		}
 	}
}

void bfs(int d,int n) 
{
 	memset(f, 0x00, sizeof(int) * n);
 	int s = 0, t = 1;
 	q[0] = 0;
 	f[0] = 1;
 	while (s < t) 
	{
  		int x = q[s++];
  		printf("%d ", x);
  		int i; 
  		for (i = 0; i < n; i++) 
		{
   			if (graph[x][i] && i != d && !f[i])
			{
    			f[i] = 1;
    			q[t++] = i;
   			}
  		}
 	}
 	printf("\n");
}

int main(int argraphc, const char * argraphv[])
{
	int m;
	int n;
	int d;
	int i;
	scanf("%d%d", &n, &m);
	for ( i = 0; i < m; i++) 
	{
		int x, y;
		scanf("%d%d", &x, &y);
		graph[x][y] = graph[y][x] = 1;
	}
	memset(f, 0x00, sizeof(int) * n);
	dfs(0, 0,n);
	printf("\n");
	bfs(0,n);
	scanf("%d", &d);
	memset(f, 0x00, sizeof(int) * n);
	dfs(0, d,n);
	printf("\n");
	bfs(d,n);
	return 0; 
}

