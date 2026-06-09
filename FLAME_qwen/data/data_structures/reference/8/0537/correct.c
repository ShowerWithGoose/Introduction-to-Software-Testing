#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ver[500];
int G [500][500]={0};
int visit[500]={0};
int top,side;
int que[500];
int front=1,rear=1;

void dfs(int t)
{
	int i;
	printf("%d ",t);
	visit[t]=1;
	for(i=0;i<top;i++)
	{
		if(G[t][i]==1&&visit[i]==0)
		dfs(i);
	}
}

void bfs(int t)
{
    int i,p;
	que[rear]=t;
	while(front<=rear)
	{
		p=que[front++];
		if(visit[p]==1)
		continue;
		else
		printf("%d ",p);
		visit[p]=1;
		for(i=1;i<=top;i++)
		{
			if(G[p][i]==1&&visit[i]==0)
			que[++rear]=i;
		}
	}	
}
int main()
{
	int n1,n2,i,del;
	scanf("%d%d",&top,&side);
	for(i=0;i<side;i++)
	{
		scanf("%d%d",&n1,&n2);
		G[n1][n2]=1;
		G[n2][n1]=1;
	} 
	scanf("%d",&del);
	
	dfs(0);
	printf("\n");
	for(i=0;i<top;i++)
	{
		visit[i]=0;
	}
	
	bfs(0);
	front=rear=1;
	printf("\n");
	for(i=0;i<top;i++)
	{
		visit[i]=0;
	}
	
	for(i=0;i<top;i++)
	G[i][del]=0;
	for(i=0;i<top;i++)
	G[del][i]=0;
	
	dfs(0);
	printf("\n");
	for(i=0;i<top;i++)
	{
		visit[i]=0;
	}
	
	for(i=0;i<top;i++)
	G[i][del]=0;
	for(i=0;i<top;i++)
	G[del][i]=0;

	bfs(0);
	printf("\n");
	for(i=0;i<top;i++)
	{
		visit[i]=0;
	}
	return 0;
}

