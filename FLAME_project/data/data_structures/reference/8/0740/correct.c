#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int visit[521]={0},graph[521][521]={0};

void DELECTVISIT(int t)
{
	int i;
	for(i=0;i<t;i++)
	visit[i]=0;
}

void DFS(int v,int dot)
{
	int i;
	visit[v]=1;
	printf("%d ",v);
	for(i=0;i<dot;i++)
	{
		if(visit[i]==0&&graph[v][i]==1)
		DFS(i,dot);
	}

}

void DELECTN(int d,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		if(i==d||j==d)
		graph[i][j]=0;
	}
}


void BFS(int v,int dot)
{
	int queue[521]={0};
    int last=1,head=0;
	int i;
	queue[head]=v;
	while(last-head!=0)
	{
		v=queue[head];
		head++;
		if(visit[v]==0)
		{
			printf("%d ",v);
			visit[v]=1;
			for(i=0;i<dot;i++)
			{
				if(visit[i]==0&&graph[v][i]==1)
				{
					queue[last++]=i;
				}
			}
		}
	}

}

int main()
{
    int dot_n,edge_n,x,y,i,j,del;
    scanf("%d%d",&dot_n,&edge_n);
    for(i=0;i<edge_n;i++)
    {
		scanf("%d%d",&x,&y);
		graph[x][y]=1;
		graph[y][x]=1;
    }
	scanf("%d",&del);
	DFS(0,dot_n);	printf("\n");
	DELECTVISIT(dot_n);
	BFS(0,dot_n);	printf("\n");
	DELECTVISIT(dot_n);
	DELECTN(del,dot_n);
	DFS(0,dot_n);	printf("\n");
	DELECTVISIT(dot_n);
	BFS(0,dot_n);	printf("\n");
	DELECTVISIT(dot_n);
	return 0;
}

