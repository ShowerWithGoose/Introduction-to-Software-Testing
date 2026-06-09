#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VMAX 100

int G[VMAX][VMAX];
int EN,VN,visited[VMAX];

void Create_Graph(int n);
void DFS_Travel(int n,int i);
void BFS_Travel(int n);

int main()
{
	scanf("%d%d",&VN,&EN);
	Create_Graph(EN);
	
	int del;
	scanf("%d",&del);
	
	DFS_Travel(VN,0); puts("");
	memset(visited,0,VMAX);
	BFS_Travel(VN); puts("");
	memset(visited,0,VMAX);
	
	for(int i=0;i<VN;i++)
		G[i][del]=G[del][i]=0;
	
	DFS_Travel(VN,0); puts("");
	memset(visited,0,VMAX);
	BFS_Travel(VN); puts("");
	memset(visited,0,VMAX);
	
	return 0;
}

void DFS_Travel(int n,int i)
{
	printf("%d ",i);
	visited[i]=1;
	for(int j=0;j<n;j++)
	{
		if(G[i][j]==0) continue;
		if(!visited[j])
			DFS_Travel(n,j);
	}
}

void BFS_Travel(int n)
{
	int tmp[VMAX],front=0,rear=-1;
	int i,j;
	printf("%d ",0);
	visited[0]=1;
	tmp[++rear]=0;
	while(rear>=front)
	{
		i=tmp[front++];
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0) continue;
			if(!visited[j])
			{
				printf("%d ",j);
				tmp[++rear]=j;
				visited[j]=1;
			}
		}
	}
}

void Create_Graph(int n)
{
	int v1,v2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&v1,&v2);
		G[v1][v2]=1;
		G[v2][v1]=1;
	}
}

