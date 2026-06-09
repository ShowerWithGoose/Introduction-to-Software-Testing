#include<stdio.h>
#include<stdlib.h>
int a[105][105]={0};
int vexmax,arcmax;//邻接矩阵 
int visited[105]={0};//记录顶点是否已经被遍历
struct q
{
	int data[105];
	int rear;
	int head;
}que;
void DFS(int n);
void BFS(int n);
int main()
{
    int i,u,v,x;//x为删除的顶点 
	scanf("%d %d",&vexmax,&arcmax);
	for(i=0;i<arcmax;i++)//创建临界矩阵 
	{
	    scanf("%d %d",&u,&v);
	    a[u][v]=1;
	    a[v][u]=1;
	}
	scanf("%d",&x);
	DFS(0);
	printf("\n");
	for(i=0;i<vexmax;i++)
	visited[i]=0;
	
	BFS(0);	
	printf("\n");
	for(i=0;i<vexmax;i++)
	visited[i]=0;
	 
	visited[x]=1;
	
	DFS(0);
	printf("\n");
	for(i=0;i<vexmax;i++)
	visited[i]=0;
	
	visited[x]=1;
	
	BFS(0);	
	printf("\n");
	return 0;
}
void DFS(int n)
{
	int i;
    printf("%d ",n);
    visited[n]=1;
    for(i=0;i<vexmax;i++)
    {
    	if(a[n][i]==1&&visited[i]==0)
    	{
    		DFS(i);
		}
	}
} 
void BFS(int n)
{
	int i;
	que.head=0;
	que.rear=1;
	que.data[0]=n;
	while(que.head<=que.rear)
	{
		if(visited[que.data[que.head]]==1)
		{
			que.head++;
			continue;
		}
		printf("%d ",que.data[que.head]);
		visited[que.data[que.head]]=1;//访问队头的元素 
		for(i=0;i<vexmax;i++)
		{
			if(a[que.data[que.head]][i]==1&&visited[i]==0)
			{
				que.data[que.rear]=i;
				que.rear++;
			}
		}
		 que.head++;
	}
}

