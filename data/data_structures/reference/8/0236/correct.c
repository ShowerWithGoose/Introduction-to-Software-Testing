#include<stdio.h> 
int graph[100][100];
int visited[100]={0};
int queue[100], front=0, rear=-1;
int vnum, en;

int isempty()
{
	return front>rear;
}

void push(int x)
{
	queue[++rear]=x;
}

int pop()
{
 return 	isempty() ? -1 : queue[front++];
}

void dfs(int a)
{
	int j;
	printf("%d ", a);
	visited[a]=1;
	for(j=0; j<vnum; j++)
		if((visited[j]==0) && graph[a][j]==1)
			dfs(j);	
}

void DFS(int a)
{
	int i;
	for(i=0;i<vnum;i++)
		visited[i]=0;
	dfs(a);
	printf("\n");
}

void BFS(int a)
{
	int i;
	for(i=0;i<vnum;i++)
		visited[i]=0;
	front=0;
	rear=-1;
	bfs(a);
	printf("\n");
}

void bfs(int a)
{
	int temp, i;
	push(a);
	printf("%d ", a);
	visited[a]=1;
	while(!isempty())
	{
		temp=pop();
		for(i=0;i<vnum;i++)
			if((!visited[i]) && graph[temp][i])
			{
				push(i);
				printf("%d ", i);
				visited[i]=1;
			}
	}
}

void delV(int aim)
{
	int i;
	for(i=0;i<vnum;i++)
		graph[i][aim]=graph[aim][i]=0;
}

int main()
{
	int m, n, i, aim;
	scanf("%d %d", &vnum, &en);
	for(i=0; i<en; i++)
	{
		scanf("%d %d", &m, &n);
		graph[m][n]=graph[n][m]=1;
	}
	scanf("%d", &aim);
	DFS(0);
	BFS(0);
	delV(aim);
	DFS(0);
	BFS(0);
}

