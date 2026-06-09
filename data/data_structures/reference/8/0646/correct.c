#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxn 100+5

int G[maxn][maxn];
int visit[maxn];
int ver,edges;

void dfs(int i);
void bfs();
void deleteVer(int i);

int main()
{
	scanf("%d%d",&ver,&edges);
	for(int i = 0;i < edges;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u][v]=G[v][u]=1;
	}
	memset(visit,0,sizeof(visit));
	for(int i=0;i<ver;i++)
		if(visit[i] == 0)dfs(i);
	printf("\n");
	
	memset(visit,0,sizeof(visit));
	bfs();printf("\n");
	
	int target=0;
	scanf("%d",&target);
	deleteVer(target);
	
	memset(visit,0,sizeof(visit));
	for(int i=0;i<ver;i++)
		if(visit[i] == 0 && i!= target)dfs(i);
	printf("\n");
	
	memset(visit,0,sizeof(visit));
	bfs();printf("\n");
	
	return 0;
}

void dfs(int i)
{
	if(i)
	{
		printf(" ");
	}
	printf("%d",i);
	visit[i]=1;
	for(int j=0;j<ver;j++)
	{
		if(j==i)continue;
		if(G[i][j]==1&&!visit[j])
			dfs(j);
	}
}

void bfs()
{
	int queue[maxn];
	int front = 0;int rear = 0;
	queue[rear++] = 0;
	visit[0]=1;
	while(front<rear){
		int i = queue[front++];
		if(i)printf(" ");
		printf("%d",i);
		for(int j=0;j<ver;j++)
		{
			if(j == i)continue;
			if(G[i][j] == 1&& !visit[j])
			{
				queue[rear++]=j;visit[j]=1;
			}
		}
	}
}

void deleteVer(int t)
{
	for(int i=0;i < ver;i++)
	{
		for(int j=0;j < ver;j++)
		{
			if(i == t || j == t)G[i][j]=0;
		}
	}
}

