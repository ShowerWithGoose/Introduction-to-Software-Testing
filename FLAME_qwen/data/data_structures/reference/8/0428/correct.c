#include<stdio.h>
#include<stdlib.h>
int a[102][102];
int visited[102]={0};
void BFS(int);
void DFS(int);
int n;
void initialize()
{
	int i;
	for(i=0;i<n;i++)
	visited[i]=0;
}
int main()
{
	int e,i,x,y,del;
	scanf("%d%d",&n,&e);
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	scanf("%d",&del);
	DFS(0);
	initialize();
	printf("\n");
	BFS(0);
	printf("\n");
	for(i=0;i<n;i++)
	{
		a[del][i]=0;
		a[i][del]=0;
	}
	DFS(0);
	initialize();
	printf("\n");
	BFS(0);
	
}
void DFS(int x)
{   
    int i;
	printf("%d ",x);
	visited[x]=1;
	for(i=0;i<n;i++)
	{
		if(a[x][i]&&visited[i]==0)
		DFS(i);
	}
	return ;
}
void BFS(int x)
{
	int i,front=0,rear=0;
	int queue[102]={x};
	printf("%d ",x);
	visited[x]=1;
	while(rear>=front)
	{   x=queue[front];
	    front++;
		for(i=0;i<n;i++)
	{
		if(a[x][i]&&visited[i]==0)
		{
			printf("%d ",i);
			visited[i]=1;
			queue[++rear]=i;
		}
		
	}
	}
	initialize();
}

