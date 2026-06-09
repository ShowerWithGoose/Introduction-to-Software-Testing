#include<stdio.h>
#define N 100
int graph[N][N];
int Visited[N]={0};
int vn;  //顶点个数 
void DFS(int v);
void travelDFS(int n,int d);
void BFS(int v);
void travelBFS(int n,int d); 
int main()
{
	int en,i,j,d;
	scanf("%d%d",&vn,&en);
	while(en--)
	{
		scanf("%d%d",&i,&j);
		graph[i][j]=1;
		graph[j][i]=1;
	}
	scanf("%d",&d);
	travelDFS(vn,-1);
	travelBFS(vn,-1);
	for(i=d,j=0;j<vn;j++) graph[i][j]=0;
	for(j=d,i=0;i<vn;i++) graph[i][j]=0;
	travelDFS(vn,d);
	travelBFS(vn,d);
	return 0;
}
void travelDFS(int n,int d)
{
	int i;
	for(i=0;i<n;i++) Visited[i]=0;
	if(d>0) Visited[d]=1;
	for(i=0;i<n;i++)
		if(Visited[i]==0) DFS(i);
	printf("\n");
}
void DFS(int v)
{
	int i;
	printf("%d ",v);
	Visited[v]=1;
	for(i=0;i<vn;i++)
		if(graph[v][i]==1&&Visited[i]==0) DFS(i);
}
void travelBFS(int n,int d)
{
	int i;
	for(i=0;i<n;i++) Visited[i]=0;
	if(d>0) Visited[d]=1;
	for(i=0;i<n;i++)
		if(Visited[i]==0) BFS(i);
	printf("\n");
}
void BFS(int v)
{
	int queue[N+1],front=0,rear=0;
	int i;
	if(Visited[v]==1) return ;      //有几个连通分量，BFS这个函数就完整执行几次 
	queue[0]=v;
	Visited[v]=1;
	while(front<=rear)
	{
		v=queue[front++];
		printf("%d ",v);
		for(i=0;i<vn;i++)
		{
			if(graph[v][i]==1&&Visited[i]==0)
			{
				queue[++rear]=i;
				Visited[i]=1;
			}
		}
	}
}

