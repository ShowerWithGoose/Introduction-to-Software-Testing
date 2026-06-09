#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
int n, m, a[205][205], fw[205], flag, q[205],i,b[205]={0},j;
void dfs(int x)
{
	if (!flag)
		printf("%d", x), flag = 1;
	else
		printf(" %d", x);
	fw[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[x][i])
		{
			if (!fw[i])
			{
				//			printf("&&%d %d\n",x,i);
				dfs(i);
			}
		}
}
void bfs(int t)
{
	
		if(flag==1){
		for(j=i;j<=n;j++)
		b[j]=flag;
	}
	q[1] = t;

	int l = 1, r = 1;
	for(;l<=r;)
	{
		int x = q[l];
		l++;
		if (fw[x]==1)
			continue;
		if (flag==0)
			printf("%d", x), flag = 1;
		else
			printf(" %d", x);

		fw[x] = 1;
		for (i = 1; i <= n; i++)
			if (a[x][i]==1)
			{
				if (fw[i]==0)
					q[++r] = i;
			}
	}
	memset(fw, 0, sizeof(fw));
}
int main()
{
	scanf("%d%d", &n, &m);
	int i;
	for (i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[y][x] = 1;
		a[x][y] = 1;
	}
	flag = 0;
		if(flag==0){
		for(j=0;j<=n;j++)
		b[j]=n;
	}
	dfs(0);
	printf("\n");
	memset(fw, 0, sizeof(fw));
	flag = 0;
		if(flag==0){
		for(j=0;j<=n;j++)
		b[j]=m;
	}
	bfs(0);
	printf("\n");
	scanf("%d", &i);
	fw[i] = 1;
	flag = 0;
	dfs(0);
	printf("\n");
	memset(fw, 0, sizeof(fw));
	fw[i] = 1;
		if(flag==0){
		for(j=0;j<=n;j++)
		b[j]=n;
	}
	flag = 0;
	bfs(0);
	printf("\n");
	return 0;
}



