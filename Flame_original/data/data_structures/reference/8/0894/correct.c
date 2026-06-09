#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int G[200][200];
int visited[200];
void DFS(int x);
void BFS(int x);
int stack[200];
int max,stack_front=0,stack_rear=0;
int main()
{
	int i,j,k,num_vertex,num_edge,shan;
	scanf("%d%d",&num_vertex,&num_edge);
//	printf("%d %d\n",num_vertex,num_edge);
	for(i=1;i<=num_edge;i++)
	{
		scanf("%d%d",&j,&k);
//		printf("%d %d\n",j,k);
		if(j>max)max=j;
		if(k>max)max=k;
		G[j][k]=G[k][j]=1;
	}
	scanf("%d",&shan);
//	printf("%d",shan);
	DFS(0);
	memset(visited,0,sizeof(visited));
	printf("\n0 ");
	BFS(0);
	for(i=0;i<stack_rear;i++)
		printf("%d ",stack[i]); 
	memset(visited,0,sizeof(visited));	
	printf("\n"); 
	for(i=0;i<=max;i++)
		G[i][shan]=G[shan][i]=0;
//	printf("\n\n");
//	for(i=1;i<=max;i++)
//	{
//		for(j=1;j<=max;j++)
//			printf("%d ",G[i][j]);
//		printf("\n");
//	} 
	DFS(0);
	memset(visited,0,sizeof(visited));
	memset(stack,0,sizeof(stack));
	stack_rear=stack_front=0;
	printf("\n0 ");
	BFS(0);
	for(i=0;i<stack_rear;i++)
		printf("%d ",stack[i]); 
	return 0;
}
void DFS(int x)
{
	visited[x]=1;
	int i;
	printf("%d ",x);
	for(i=0;i<=max;i++)
	{
		if(G[x][i]!=0&&visited[i]==0)
			DFS(i);
	}
}
void BFS(int x)
{
	int i;
	visited[x]=1;
	if(stack_rear>=stack_front)
	{
		for(i=0;i<=max;i++)
		if(G[x][i]!=0&&visited[i]==0)
		{
			visited[i]=1;
			stack[stack_rear++]=i;
		}
		BFS(stack[stack_front++]);
	}
}

