#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int mat[105][105],num,edge;
int visit[105],q[105];
void clear(int x[])
{
	int i;
	for(i=0;i<num;i++)
	x[i]=0;
}
void dfs(int x)
{
	printf("%d ", x);
	visit[x] = 1;
	int i;
	for (i = 1; i <= num; i++)
		if (mat[x][i])
		if (visit[i]==0)
		dfs(i);
}
void bfs(int t)
{
	q[1] = t;

	int l = 1, r = 1, i;
	while (l <= r)
	{
		int x = q[l];
		l++;
		if (visit[x])
			continue;
			printf("%d ", x);

		visit[x] = 1;
		for (i = 1; i <= num; i++)
			if (mat[x][i])
			{
				if (!visit[i])
					q[++r] = i;
			}
	}
}
int main()
{
	int i,j,a1,a2,dele;
	scanf("%d %d",&num,&edge);
	for(i=1;i<=edge;i++)
	{
		scanf("%d %d",&a1,&a2);
		mat[a2][a1]=mat[a1][a2]=1;
	}
	scanf("%d",&dele);
	dfs(0);
	printf("\n");
	clear(visit);
	bfs(0);
	printf("\n");
	clear(visit);
	visit[dele]=1;
	dfs(0);
	printf("\n");
	clear(visit);
	visit[dele]=1;
	bfs(0);
}

