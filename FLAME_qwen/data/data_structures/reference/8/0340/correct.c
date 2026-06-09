#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int e[110][110];
int v[110],n;
void dfs(int x)
{
	int bk=0;printf("%d ",x);
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0&&e[x][i]==1)
		{
			v[i]=1;
			dfs(i);bk=1;
		}
	}
}
int list[1100];
void bfs()
{
	int head=1,tail=0;
	list[++tail]=0;
	while(head<=tail)
	{
		int x=list[head];
		printf("%d ",x);
		for(int i=1;i<=n;i++)
		{
			if(e[x][i]==1&&v[i]==0)
			{
				v[i]=1;
				list[++tail]=i;
			}
		}
		head++;
	}
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	memset(e,0,sizeof(e));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);e[x][y]=1;e[y][x]=1;
	}
	int p;scanf("%d",&p);
	memset(v,0,sizeof(v));
	v[0]=1;dfs(0);printf("\n");
	memset(v,0,sizeof(v));
	bfs(0);printf("\n");
	
	memset(v,0,sizeof(v));v[p]=1;
	v[0]=1;dfs(0);printf("\n");
	memset(v,0,sizeof(v));v[p]=1;
	bfs(0);printf("\n");
	return 0;
}

