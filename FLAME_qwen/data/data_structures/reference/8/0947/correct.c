#include<stdio.h>
int G[105][105];
int visited[105]={0};
int queue[10000];

void DFS(int a,int n)
{
	int i;
	printf("%d ",a);
	visited[a]=1;
	for(i=0;i<n;i++)
	{
		if(G[a][i]==1&&visited[i]==0)
		DFS(i,n);
	}
}

void BFS(int a,int n)
{
	int head=0,tail=0;
	int i,b;
	queue[0]=a;
	visited[a]=1;
	while(tail>=head)
	{
		b=queue[head];
		head++;
		printf("%d ",b);
		for(i=0;i<n;i++)
		{
			if(G[b][i]==1&&visited[i]==0)
			{
				queue[++tail]=i;
				visited[i]=1;
			}
		}
	}
}
int main()
{
	int v,e,i=0,v1,v2,del;
	scanf("%d%d",&v,&e);
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&v1,&v2);
		G[v1][v2]=G[v2][v1]=1;
	}
	scanf("%d",&del);
	DFS(0,v);
	printf("\n");
	for(i=0;i<v;i++)
	{
		visited[i]=0;
	}
	BFS(0,v);
	printf("\n");
	for(i=0;i<v;i++)
	{
		G[del][i]=G[i][del]=0;
		visited[i]=0;
	}
	DFS(0,v);
	printf("\n");
	for(i=0;i<v;i++)
	{
		visited[i]=0;
	}
	BFS(0,v);
    return 0;
}

