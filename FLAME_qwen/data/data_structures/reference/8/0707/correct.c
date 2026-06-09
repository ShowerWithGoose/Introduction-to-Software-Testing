#include<stdio.h>
#include <string.h>
int is[105][105]={0};
int flag,q[105],vis[105],ver;
void bfs(int a)
{
	q[1] = a;
	int l=1,r=1,i;
	while (l<=r)
	{
		int x=q[l];
		l++;
		if (vis[x]!=0)
			continue;
		if (flag==0)
			{
			printf("%d", x);
			flag=1;
			}
		else
			printf(" %d", x);

		vis[x] = 1;
		for (i=1;i<=ver;i++)
			if (is[x][i]!=0)
			{
				if (vis[i]==0)
					q[++r] = i;
			}
	}
	memset(vis, 0, sizeof(vis));
}
void dfs(int a)
{													
	if (flag==0)
		{printf("%d",a);
		flag=1;
		}
	else
		printf(" %d",a);
	vis[a]=1;
	int i;
	for (i=1;i<=ver;i++)
		if (is[a][i]!=0)
		{
			if (vis[i]==0)
			{
				dfs(i);
			}
		}
}
int main()
{
	int line,dot1,dot2,i,j;
	scanf("%d %d",&ver,&line);
	for(j=0;j<line;j++)
	{
	scanf("%d%d",&dot1,&dot2);
	is[dot1][dot2]=1;
	is[dot2][dot1]=1;
	}
	flag= 0;
	dfs(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	flag=0;
	bfs(0);
	printf("\n");
	scanf("%d",&i);
	vis[i]=1;
	flag=0;
	dfs(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	vis[i]=1;
	flag=0;
	bfs(0);
	printf("\n");
	return 0;
}

