#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int point,edge; 
int visited[100]={0};
int queue[100];
int front=0,rear=0;
int graph[100][100];
void travelDFS(int n)
{
	int i;
	visited[n]=1;
	printf("%d ",n);
	for(i=0;i<point;i++)
	{
		if(graph[n][i]==1&&visited[i]==0)
		{
			travelDFS(i);
		}
	}
}
void travelBFS(int n)
{
	int i,hold;
	queue[front]=n;
	rear++;
	while(front<=rear)
	{
		hold=queue[front];
		front++;
		if(visited[hold]==0)
		{
			printf("%d ",hold);
			visited[hold]=1;
			for(i=0;i<point;i++)
			{
				if(graph[hold][i]==1&&visited[i]==0)
				{
					queue[rear]=i;
					rear++;
				}
			}
		}
	}
}
int main()
{
	int u,v,shanchu;
	scanf("%d%d",&point,&edge);
	int i,j,k;
	for(i=0;i<edge;i++)
	{
		scanf("%d%d",&u,&v);
		graph[u][v]=1;
		graph[v][u]=1;
	}
	travelDFS(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	travelBFS(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	scanf("%d",&shanchu);
	visited[shanchu]=1;
	travelDFS(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	visited[shanchu]=1;
	front=0;rear=0;
	travelBFS(0);
	printf("\n");
	
	
	
	
	
	
	
	
	
	return 0;
 }  



