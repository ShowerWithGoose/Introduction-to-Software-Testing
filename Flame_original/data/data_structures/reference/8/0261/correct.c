#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
/*----------------------------
无法解决不连通图的情况
样例都跑不过 
但是测试点过了.......
------------------------------*/
void  travelDFS(int G[][100], int n);//深度优先 
void DFS(int G[][100], int v);
void  travelBFS(int G[][100], int n);//广度优先遍历 
void BFS(int G[][100], int v,int n);

int k = 0,m = 0,n = 0,y = 0,x = 0,jishu = 0;
int graph[100][100] = {};
int line[100] = {};
int line2[100] = {};
int  Visited[100]={}; 			//标识顶点是否被访问过，N为顶点数
int  Visited2[100]={}; 
int main (void)
{
	int a = 0,b = 0,i = 0,c = 0;
	scanf("%d %d",&n,&m);
	for(i = 0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}	
	scanf("%d",&c);		//删除 
	travelDFS(graph,n);
	for(i = 0;i<n;i++)
	{
		printf("%d ",line[i]);
	}
	printf("\n");
	travelBFS(graph,n);
	for(i = 0;i<n;i++)
		printf("%d ",line2[i]);
	printf("\n");
	for(i = 0;i<n;i++)
	{
		graph[i][c] = 0;
		graph[c][i] = 0;
	}
	travelDFS(graph,n);
	for(i = 0;i<n-1;i++)
		printf("%d ",line[i]);
	printf("\n");
	for(i = 0;i==c;i++)
		continue;
	travelBFS(graph,n);
	for(i = 0;i<n-1;i++)
		printf("%d ",line2[i]);
	return 0;
}

void  travelDFS(int G[][100], int n)//深度优先 
{
    int i;
    k = 0;
	memset(Visited,0,sizeof(int)*100);
	memset(line,0,sizeof(int)*100);
    for(i=0; i<n; i++)
        if(Visited[i] == 0) 
			DFS(G, i);
}
void DFS(int G[][100], int v)
{
    int p = 0;
    Visited[v] = 1; 		//标识某顶点被访问过
    line[k] = v;			//访问某顶点	
    k++;
	for(p = 0;p<n;p++)
    {
    	if(graph[v][p]!=0&&Visited[p] ==0)
            DFS(G,p);
	} 
}
void  travelBFS(int G[][100], int n)
{
    int i = 0;
    k = 0;
	x = 0;
	jishu = 0;
	memset(Visited,0,sizeof(int)*100);
	memset(Visited2,0,sizeof(int)*100);
	memset(line,0,sizeof(int)*100);
	memset(line2,0,sizeof(int)*100);
    for(i=0; i<n; i++)
        if(Visited[i]==0 ) 
			BFS(G,i,n);
}
void BFS(int G[][100], int v,int n)
{
	int p = 0,z = 0;
	line[x++] = v;
	Visited2[p] = 1;
	while(1)
	{
		v = line[z++];
		line2[jishu++] = v;
		Visited[v] = 1;
		for(p = 0;p<n;p++)
		{
			if(graph[v][p]!=0)
			{
				if(Visited2[p] ==0)
					line[x++] = p;		//入队
				Visited2[p] = 1;
			}	
		}
		if(v == line[x-1])
			break;	
	}
}
/*
9 10

0 1

0 2

1 4

1 3

1 8

8 6

3 6

7 2

7 5

5 2
3
*/


