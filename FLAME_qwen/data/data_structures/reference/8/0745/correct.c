#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000005
#define ll long long
#define ull unsigned long long
int martix[300][300],visit[300],queue[300];
int n,m,i,j,b,d,delate;
void dfs(int x);
void bfs(int x);
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&b,&d);
		martix[b][d]=martix[d][b]=1;
	}
	dfs(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	bfs(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	
	scanf("%d",&delate);	
	visit[delate]=1;
	dfs(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	visit[delate]=1;
	bfs(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	
	return 0;
}
void bfs(int x)
{
	int head=0,tail=1,y;
	queue[head]=x;
	while(head<=tail)
	{
		y=queue[head++];
		if(visit[y]==0)
		{
			printf("%d ",y);
			visit[y]=1;
			for(i=0;i<n;i++)
			{
				if(martix[y][i]==1&&visit[i]==0)
				{
					queue[tail++]=i;
				}
			}
		}
	}
}
void dfs(int x)
{
	printf("%d ",x);
	visit[x]=1;
	int k;
	for(k=0;k<n;k++)
	{
		if(martix[x][k]==1&&visit[k]==0)
		{
			dfs(k);
		}
	}
}

