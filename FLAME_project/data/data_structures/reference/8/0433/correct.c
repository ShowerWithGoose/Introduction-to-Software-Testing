#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int ver[100][100]={0};
int top=0;
int m,n;
int visited[100]={0};
int outcome[100]={0};
void DFS(int to)
{
	int i;
	outcome[top++]=to;
	visited[to]=1;
	for(i=0;i<m;i++)
	{
		if(ver[to][i]==1&&visited[i]==0)
			DFS(i);
	} 
}
void BFS(int a)
{
	int queue[100];
	int head=0;
	int tail=0;
	queue[0]=a;
	int i;
	for(i=head;i<=tail;i++)
	{
		if(visited[queue[i]]==0)
		{
			outcome[top++]=queue[i];
			visited[queue[i]]=1;
			int j;
			for(j=0;j<m;j++)
			{
				if(ver[queue[i]][j]==1&&visited[j]==0)
				{
					queue[++tail]=j;
				}
			} 
		}
		head++;
	}
	
} 
void delet(int k)
{
	int i;
	for(i=0;i<m;i++)
	{
		ver[i][k]=0;
		ver[k][i]=0;
	}
}
int main()
{
	scanf("%d %d ",&m,&n);
	int i;
	int x,y;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		ver[x][y]=1;
		ver[y][x]=1;
	}
	DFS(0);
	for(i=0;i<m;i++)
		printf("%d ",outcome[i]);
	printf("\n");
	top=0;
	memset(visited,0,100);
	BFS(0);
	for(i=0;i<m;i++)
		printf("%d ",outcome[i]);
	printf("\n");
	top=0;
	memset(visited,0,100);
	
	//É¾³ýµã 
	int k;
	scanf("%d",&k);
	delet(k);
	DFS(0);
	for(i=0;i<m-1;i++)
		printf("%d ",outcome[i]);
	printf("\n");
	top=0;
	memset(visited,0,100);
	BFS(0);
	for(i=0;i<m-1;i++)
		printf("%d ",outcome[i]);
	printf("\n");
} 

