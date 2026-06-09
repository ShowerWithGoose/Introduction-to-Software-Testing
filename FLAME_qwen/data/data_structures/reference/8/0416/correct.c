#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int G[100][100];
int vertex[100];
int visit[100]={0};

int dot,line;//顶点数，边数 

void DFS(int v);
void BFS(int v);

int main()
{
	
	scanf("%d %d",&dot,&line);
	int v1,v2;
	for(int i=0;i<line;i++)
	{
		scanf("%d %d",&v1,&v2);
		G[v1][v2]=1;
		G[v2][v1]=1;
	}
	DFS(0);
	printf("\n");
	
	memset(visit,0,sizeof(visit));
	
	BFS(0);
	printf("\n");
	
	int del;
	scanf("%d",&del);
	memset(visit,0,sizeof(visit));
	visit[del]=1;//“访问过了”效果等同于删去
	
	DFS(0);
	printf("\n");
	
	memset(visit,0,sizeof(visit));
	memset(vertex,0,sizeof(vertex));
	visit[del]=1;
	
	BFS(0);
	printf("\n");
	return 0;
}

void DFS(int v)
{
	printf("%d ",v);
	visit[v]=1; //已访问
	for(int i=0;i<dot;i++)
		if(G[v][i]==1 && visit[i]==0) //矩阵元素为1且未访问过
			DFS(i); 
}

void BFS(int v)
{
	int head=0,rear=1,tmp;
	vertex[head]=v; //入队
	while(head<=rear)
	{
		tmp=vertex[head++];//出队
		if(visit[tmp]==0) //未访问过 
		{
			printf("%d ",tmp);//打印出队元素
			visit[tmp]=1;
			for(int i=0;i<dot;i++)
				if(G[tmp][i]==1 && visit[i]==0)
					vertex[rear++]=i;
		}
		else
			continue;		
	} 
	
}

