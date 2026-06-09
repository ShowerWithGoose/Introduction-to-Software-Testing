#include<stdio.h>
#include<stdlib.h>
int eNum, vNum;
int visited[100];
int E[100][100];
int Q[100];
int front, rear;
/*struct edge{
	int adjvex;
	struct edge *next;
};
struct ver{
	struct edge *head;
}V[100];*/
void DFS(int [][100], int);
void BFS(int [][100], int);
int main()
{
	int v1, v2, i, de;
	scanf("%d%d", &vNum, &eNum);
	for(i=0; i<eNum; i++)
	{
		scanf("%d%d", &v1, &v2);
		E[v1][v2]=E[v2][v1]=1; //标记两点相连 
	}
	//深度优先 
	DFS(E, 0);
	printf("\n");
	//广度优先
	for(i=0; i<vNum; i++) visited[i]=0;
	BFS(E, 0);
	printf("\n");
	//删除
	scanf("%d", &de);//要删除的点
	for(i=0; i<vNum; i++) E[i][de]=E[de][i]=0;
	//深度优先
	for(i=0; i<vNum; i++) visited[i]=0; //初始化
	visited[de]=1; //不可访问
	DFS(E, 0);
	printf("\n");
	//广度优先
	for(i=0; i<vNum; i++) visited[i]=0;
	BFS(E, 0);
	printf("\n");
}

void DFS(int E[][100], int i)
{
	int j;
	printf("%d ", i);
	visited[i]=1;
	for(j=0; j<vNum; j++)
	{
		if(j==i) continue;
		if(visited[j]!=1&&E[i][j]==1) DFS(E, j);
	}	
}

void BFS(int E[][100], int i)
{
	int j;
	Q[0]=i;
	printf("%d ", i);
	visited[i]=1;
	front=0; rear=1;
	while(front<rear)
	{
		i=Q[front++]; //用i标记队头，访问完后出队
		//访问： 
		for(j=0; j<vNum; j++)
		{
			if(E[i][j]==1 && visited[j]==0) 
			{
				printf("%d ", j); 
				Q[rear++]=j;
				visited[j]=1;
			}
		}
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

