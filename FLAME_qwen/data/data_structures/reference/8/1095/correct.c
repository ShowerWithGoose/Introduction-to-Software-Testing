#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define Maxsize 200
typedef struct{
	int Vex[Maxsize];
	int Edge[Maxsize][Maxsize];
}Graph; 
Graph M;
int vexnum,arcnum;
bool flag=false;
bool visited[105];
int q[105];
void DFS(int x)
{
	if (!flag){
		printf("%d", x);
		flag=true;
	}
	else{
	    printf(" %d", x);
	}
	visited[x]=true;
	int i;
	for (i=1;i<=vexnum;i++)
		if (M.Edge[x][i])
		{
			if (visited[i]==false)
			{
				//			printf("&&%d %d\n",x,i);
				DFS(i);
			}
		}
}
void BFS(int t)
{
	q[1] = t;
	int l = 1, r = 1, i;
	while (l <= r)
	{
		int x = q[l];
		l++;
		if (visited[x]==true)
			continue;
		if (!flag){
			printf("%d", x);
			flag=true;
		}
		else{
			printf(" %d", x);
		}
		visited[x]=true;
		for (i=1;i<=vexnum;i++)
			if (M.Edge[x][i])
			{
				if (visited[i]==false)
					q[++r] = i;
			}
	}
	memset(visited,false,sizeof(visited));
}
int main()
{
	scanf("%d %d",&vexnum,&arcnum);
	int i;
	for (i=1;i<=arcnum;i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		M.Edge[x][y]=M.Edge[y][x]=1;
	}
	flag=false;
	DFS(0);
	printf("\n");
	memset(visited,false, sizeof(visited));
	flag=false;
	BFS(0);
	printf("\n");
	scanf("%d", &i);
	visited[i] = 1;
	flag=false;
	DFS(0);
	printf("\n");
	memset(visited,false, sizeof(visited));
	visited[i]=true;
	flag=false;
	BFS(0);
	printf("\n");
	return 0;
}



