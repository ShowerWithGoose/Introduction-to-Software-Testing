#include <stdio.h>
#include <stdlib.h>
int vertex[110][110];
int visited[110];
int queue[110];
int n;
void DFS(int v)
{
	int k;
	visited[v]=1;
	printf("%d ",v);
	for(k=0;k<n;k++)
	{
		if(vertex[v][k]==1&&visited[k]==0)
		DFS(k);
	}
}
void BFS(int v)
{
	int k;
	int first=0,final=0;
	visited[v]=1;
	queue[final++]=v;
	while(final>first)
	{
		v=queue[first++];
		printf("%d ",v);
		for(k=0;k<n;k++)
			if(vertex[v][k]==1&&visited[k]==0)
			{
				visited[k]=1;
				queue[final++]=k;
			}
	}
}
int main()
{
	int h,m;
	int a,b;
	int i,j;
	scanf("%d%d",&h,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		vertex[a][b]=1;
		vertex[b][a]=1;
	}
	scanf("%d",&m);
	DFS(0);
	printf("\n");
	for(i=0;i<h;i++)
		visited[i]=0;
	BFS(0);
	printf("\n");
	for(i=0;i<h;i++)
	{
		vertex[i][m]=0;
		vertex[m][i]=0;
	}
	for(i=0;i<h;i++)
		visited[i]=0;
	DFS(0);
	printf("\n");
	for(i=0;i<h;i++)
		visited[i]=0;
	BFS(0);
	printf("\n");
	return 0;
}

