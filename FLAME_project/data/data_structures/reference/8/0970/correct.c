#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

int vcount,ecount,v1,v2;	//顶点个数、边的个数,边的两端
int vertex[100+10];			//顶点数据
int graph[100+10][100+10];	//边,邻接矩阵储存 
int visit[100+10];			//是否被访问过

void DFS(int);
void BFS(int);
int queue[100+10],front=-1,rear,pos=-1;	//使用下标

int main()
{
	scanf("%d %d",&vcount,&ecount);
	rear=vcount-1;
	for(int i=0;i<vcount;i++)	//初始化顶点信息 
		vertex[i]=i;
	for(int i=0;i<ecount;i++)	//初始化边信息 
	{
		scanf("%d %d",&v1,&v2);
		graph[v1][v2]=1;
		graph[v2][v1]=1;
	}
	DFS(0);
	puts("");
	for(int i=0;i<vcount;i++)
		visit[i]=0;
	BFS(0);
	puts("");
	for(int i=0;i<vcount;i++)
		visit[i]=0;
	front=pos=-1;
	rear--;
	int del;
	
	scanf("%d",&del);
	for(int i=0;i<vcount;i++)	//删除边 
	{
		graph[del][i]=0;
		graph[i][del]=0;
	}
	DFS(0);
	puts("");
	for(int i=0;i<vcount;i++)
		visit[i]=0;
	BFS(0);
	return 0;
}

void DFS(int start){
	visit[start]=1;
	printf("%d ",vertex[start]);
	for(int i=0;i<vcount;i++)
		if(graph[start][i]==1&&visit[i]==0)
			DFS(i);
	return;
}

void BFS(int start){
	if(pos==-1)
	{
		visit[start]=1;
		queue[++pos]=start;
	}
	for(int i=0;i<vcount;i++)
		if(graph[start][i]==1&&visit[i]==0)
		{
			visit[i]=1;
			queue[++pos]=i;
		}
	if(front<rear)
		BFS(queue[++front]);
	else if(front==rear)
	{
		for(int i=0;i<=rear;i++)
			printf("%d ",queue[i]);
		front++;
	}
	return;
}

