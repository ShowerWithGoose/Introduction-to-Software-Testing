#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define max 500
int graph[max][max],visited[max],q[max];
int n,m;//顶点和边数
void DFS(int start);
void BFS(int start);
int main(){
	int i,j,k;
	int del;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&j,&k); //录入矩阵 
		graph[j][k]=1;
		graph[k][j]=1;
	}
	DFS(0);
	puts("");
	
	memset(visited,0,sizeof(visited));
	BFS(0);
	puts("");
	
	scanf("%d",&del);
	memset(visited,0,sizeof(visited));
	visited[del]=1;		//	要删除的元素设置为已访问 
	DFS(0);
	puts("");
	
	memset(visited,0,sizeof(visited));
	memset(q,0,sizeof(q));
	visited[del]=1;		//	要删除的元素设置为已访问 
	BFS(0);
	puts("");
	return 0;
}
void DFS(int start)
{
	int i;
	printf("%d ",start);
	visited[start] = 1;
	for(i=0;i<n;i++)
	{
		if(graph[start][i]&&!visited[i])
		{
			DFS(i);
		}
	}
	
}
void BFS(int start)
{
	int front,rear,temp;
	front=0;
	rear=1;
	q[front] = start;
	while(front<=rear)
	{
		temp=q[front];	//出队 
		front++;			//出队
		if(visited[temp])	//如果访问过
			continue;	 
		else
		{
			printf("%d ",temp);		//打印出队元素 
			visited[temp]=1;			//已访问 
			for(int i=0;i<n;i++)
				if (graph[temp][i] && !visited[i])	//如果矩阵元素为 1 且未访问过 
					q[rear++]=i;		//入队 
		}		
	}
}

