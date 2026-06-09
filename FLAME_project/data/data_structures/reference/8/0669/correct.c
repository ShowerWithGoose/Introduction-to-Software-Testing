#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int edge[1000][1000];
int Visit[10010];
int queue[10010];
int n,l,Delete,n1,n2,v;
int i,j,k,front=0,rear=0;
void Dfs(int i)
{
	int j;
	printf("%d ",i);
	Visit[i]=1;
	for(j=0;j<n;j++)
	{
		if(edge[i][j]==1&&!Visit[j]) Dfs(j);
	}
}
void TravelDfs()
{
	for(i=0;i<n;i++)
		if(!Visit[i]) Dfs(i);
}
void to()
{
	for(i=0;i<n;i++)
	{
		Visit[i]=0;
	}
}
void Bfs(int i)
{
	printf("%d ",i);
	Visit[i]=1;
	queue[++rear]=i;
	while(rear!=front)
	{
		v=queue[++front];
		if(!Visit[v])
		{
				printf("%d ",v);
				Visit[v]=1;
		}
		for(j=0;j<n;j++)
		{
			if(edge[v][j]==1&&!Visit[j]) queue[++rear]=j;
		}
	}
}
void TravelBfs()
{
	for(i=0;i<n;i++)
	{
		if(!Visit[i]) Bfs(i);
	}
}
int main()
{
	scanf("%d%d",&n,&l);
	for(i=0;i<l;i++)
	{
		scanf("%d%d",&n1,&n2);
		edge[n1][n2]=1;
		edge[n2][n1]=1;
	}
	scanf("%d",&Delete);
	TravelDfs();printf("\n");to();
	TravelBfs();printf("\n");to();
	for(i=0;i<n;i++)
	{
		edge[i][Delete]=0;
		edge[Delete][i]=0;
	}
	Visit[Delete]=1;
	TravelDfs();printf("\n");to();Visit[Delete]=1;
	TravelBfs();printf("\n");
	
}

