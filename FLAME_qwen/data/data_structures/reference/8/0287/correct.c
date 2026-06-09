#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int G[105][105];
int visited[105]={0};
int m,n;
int queue[105];
void DFS(int v)
{
	int i;
	printf("%d ",v);
	visited[v]=1;
	for(i=0;i<n;i++)
		if(G[v][i]&&visited[i]==0)
			DFS(i);
}

void BFS(int v)
{
	int i,rear=1,front=0,tmp;
	queue[front]=v;
	while(front<=rear)
	{
		tmp=queue[front];
		front++;
		if(visited[tmp])
			continue;
		else
		{
			printf("%d ",tmp);
			visited[tmp]=1;
			for(i=0;i<n;i++)
				if(G[tmp][i]&&!visited[i])
					queue[rear++]=i;
		}
	}
}
int main()
{
	int i,j,k,v1,v2;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&v1,&v2);
		G[v1][v2]=1;
		G[v2][v1]=1;
	}
	scanf("%d",&j);
	
	DFS(0);
	puts("");
	for(i=0;i<n;i++)
		visited[i]=0;
		
	BFS(0);
	puts("");
	for(i=0;i<n;i++)
		visited[i]=0;
		
	visited[j]=1;
	DFS(0);
	puts("");
	
	for(i=0;i<n;i++)
		visited[i]=0;
	visited[j]=1;
	BFS(0);
	puts("");
	return 0;
}

