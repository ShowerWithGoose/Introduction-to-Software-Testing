#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int matrix[120][120];
int queue[120];

int visited[120]={0};
void DFS (int v,int num)
{
	int i;
	visited[v]=1;
	printf("%d ",v);
	for(i=0;i<num;i++)
	{
		if(visited[i]!=1&&matrix[v][i]!=0)
		DFS(i,num);
	} 
}
void BFS(int v,int num)
{
	int i;
	int front=-1,rear=0;
	printf("%d ",v);
	visited[v]=1;
	queue[0]=v;
	while(front<rear)//队伍不空
	{	
	    v=queue[++front];
		for(i=0;i<num;i++)
		{
		    if(visited[i]!=1&&matrix[v][i]!=0)
			{
				printf("%d ",i);
				visited[i]=1;
				queue[++rear]=i;
			    
			}	
		}
	} 
}
int main()
{
	int n,m,i,j,v1,v2,item;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&v1,&v2);
		matrix[v1][v2]=1;
		matrix[v2][v1]=1;
	}
	scanf("%d",&item);
	
	DFS(0,n);
	printf("\n");
	memset(visited,0,sizeof(int)*120);
	BFS(0,n);
	printf("\n");
	memset(visited,0,sizeof(int)*120);
	memset(queue,0,sizeof(int)*120);
	for(i=0;i<n;i++)//删除结点 
	{
		if(i==item)
		{
			for(j=0;j<n;j++)
			matrix[item][j]=0;
		}
		if(matrix[i][item]==1)
		matrix[i][item]=0;
	}
	DFS(0,n);
	printf("\n");
	memset(visited,0,sizeof(int)*120);
	BFS(0,n);
	printf("\n");
	return 0;
}

