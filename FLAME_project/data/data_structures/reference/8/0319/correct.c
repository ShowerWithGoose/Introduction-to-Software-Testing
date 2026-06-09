#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 105

int edge[MAX][MAX];//邻接矩阵 
int Vnum;//顶点个数 
int queue[MAX],front=0,rear=-1;
int visited[MAX];

int isEmpty()//队列为空，返回-1 
{
	return (rear-front);
}
void push(int n)
{
	queue[++rear]=n;
}
int pop()
{
	return queue[front++];
}
void DFS(int n);
void BFS(int n); 

int main()
{
	int Enum,i,j,ver;
	scanf("%d%d",&Vnum,&Enum);
	while(Enum--)
	{
		scanf("%d%d",&i,&j);
		edge[i][j]=edge[j][i]=1;
	}
	
	DFS(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(0);
	printf("\n");
	
	scanf("%d",&ver);
	for(i=0;i<Vnum;i++)
	edge[ver][i]=edge[i][ver]=0;
	
	memset(visited,0,sizeof(visited));
	DFS(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(0);
	printf("\n");
	
	return 0;
}

void DFS(int n)
{
	int i;
	printf("%d ",n);
	visited[n]=1;
	
	for(i=0;i<Vnum;i++)
	if((visited[i]==0)&&(edge[n][i]==1))
	DFS(i);
}

void BFS(int n)
{
	int ver,i;
	push(n);
	printf("%d ",n);
	visited[n]=1;
	
	while(isEmpty()!=-1)
	{
		ver=pop();
		for(i=0;i<Vnum;i++)
		if((visited[i]==0)&&(edge[ver][i]==1))
		{
			push(i);
			printf("%d ",i);
			visited[i]=1;
		}
	}
}

