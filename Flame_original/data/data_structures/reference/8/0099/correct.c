#include<stdio.h>
int vis[120][120];
int fl[120];
int n,m;
void dfs(int x)
{
	printf("%d ",x);
	int i;fl[x]=1;
	for(i=0;i<n;i++)
		{
			if(vis[x][i]&&!fl[i])
				dfs(i);
		}
}int q[100000];
int l,r;
void bfs()
{
	fl[0]=1;q[++r]=0;int i;
	while(r>=l)
	{
		int x=q[l];
		printf("%d ",x);
		l++;
		for(i=0;i<n;i++)
			{
				if(vis[x][i]&&!fl[i])
					{
						q[++r]=i;
						fl[i]=1;
					}
			}
	}
}
int sum,a[120];
int main()
{
	scanf("%d%d",&n,&m);int i,j;
	int st,ed;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&st,&ed);
		vis[st][ed]=vis[ed][st]=1;
	}
	dfs(0);printf("\n");l=0,r=-1;
	for(i=0;i<n;i++)fl[i]=0;
	
	bfs();printf("\n");
	l=0,r=-1;
	for(i=0;i<n;i++)fl[i]=0;
	int stop;
	while(~scanf("%d",&stop))
	{
		fl[stop]=1;
		a[++sum]=stop;
	}
	dfs(0);printf("\n");l=0,r=-1;
	for(i=0;i<n;i++)fl[i]=0;
	for(i=1;i<=sum;i++)fl[a[i]]=1;
	bfs();printf("\n");
	l=0,r=-1;
}

