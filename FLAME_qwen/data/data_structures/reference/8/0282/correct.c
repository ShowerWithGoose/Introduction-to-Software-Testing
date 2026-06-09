#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE  512
int vdelete;
int vnum,ednum;
int G[101][101];
int store[101];
int Queue[101];
void DFS(int n);
void BFS(int n);
int main()
{
	int i,v1,v2;
	scanf("%d%d",&vnum,&ednum);
	for(i=0;i<ednum;i++)
	{
		scanf("%d%d",&v1,&v2);
		G[v1][v2]=1;
		G[v2][v1]=1;
	}
	DFS(0);
	printf("\n");
	for(i=0;i<101;i++)store[i]=0;
	BFS(0);
	printf("\n");
	scanf("%d",&vdelete);
	for(i=0;i<101;i++)store[i]=0;
	store[vdelete]=1;
	DFS(0);
	printf("\n");
	for(i=0;i<101;i++)store[i]=0;
	store[vdelete]=1;
	BFS(0);
	printf("\n");
	return 0;
}
void DFS(int n)
{
	int i;
	printf("%d ",n);
	store[n]=1;
	for(i=0;i<vnum;i++)
	{
		if(G[n][i]==1&&store[i]==0)
		{
			DFS(i);
		}
	}
}
void BFS(int n)
{
	int front=0,rear=0,pre;
	Queue[0]=n;
	while(front<=rear)
	{
		pre=Queue[front++];
		if(store[pre]==1)continue;
		else printf("%d ",pre);
		store[pre]=1;
		for(int i=1;i<vnum;i++)
		{
			if(G[pre][i]==1&&store[i]==0)
			{
				Queue[++rear]=i;
			}
		}
	}
}

