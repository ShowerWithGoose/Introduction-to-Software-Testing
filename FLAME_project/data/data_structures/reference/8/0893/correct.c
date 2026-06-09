#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int n,m,a[105][105];
int tbl[105],tu,arr[105];
void dfs(int x)
{
	if (!tu)
		printf("%d",x),tu=1;
	else
		printf(" %d",x);
	tbl[x]=1;
	int i;
	for(i=1;i<=n;i++)
		if(a[x][i])
		{
			if(!tbl[i])
			{
				dfs(i);
			}
		}
}
void bfs(int t)
{
	arr[1] = t;
	int l=1,r=1,i;
	while(l<=r)
	{
		int x=arr[l];
		l++;
		if(tbl[x])
			continue;
		if(!tu)
			printf("%d",x),tu=1;
		else
			printf(" %d",x);
        tbl[x] = 1;
		for(i=1;i<=n;i++)
			if(a[x][i])
			{
				if(!tbl[i])
					arr[++r]=i;
			}
	}
	memset(tbl,0,sizeof(tbl));
}

int main()
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	tu=0;
	dfs(0);
	printf("\n");
	memset(tbl,0,sizeof(tbl));
	tu=0;
	bfs(0);
	printf("\n");
	scanf("%d",&i);
	tbl[i]=1;
	tu=0;
	dfs(0);
	printf("\n");
	memset(tbl,0,sizeof(tbl));
	tbl[i]=1;
	tu=0;
	bfs(0);
	printf("\n");
	return 0;
}



