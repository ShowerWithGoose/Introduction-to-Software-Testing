#include <ctype.h>
#include <iso646.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int weights[200][200],visited[200]={0},que[200]={0};
int num,numE;

void DFS(int n);
void BFS(int n);
void SetZero(int a[],int n);

int main()
{	
	int u,v,i,del;
	scanf("%d %d",&num,&numE);
	for(i=0;i<numE;i++)
	{
		scanf("%d %d",&u,&v);
		weights[u][v]=1;
		weights[v][u]=1;
	}
	scanf("%d",&del);
	DFS(0);
    printf("\n");
    SetZero(visited,numE);
	BFS(0);
    printf("\n");
	SetZero(visited,numE);
	visited[del]=1; 
	DFS(0);
    printf("\n");
	SetZero(visited,numE);
	visited[del]=1; 
	BFS(0);
    printf("\n");
	return 0;
}

void DFS(int n)
{
	int i;
	printf("%d ",n);
	visited[n]=1;
	for(i = 0; i < num; i++)
		if (weights[n][i] && !visited[i])
		{
			DFS(i);	
		}
}
void BFS(int n)
{
	int i,head=0,tail=1,tmp;
	que[head]=n;
	while(head<=tail)
	{
		tmp=que[head++];
		if(visited[tmp]);
		else
		{
			printf("%d ",tmp);
			visited[tmp]=1;	
			for(i=0;i<num;i++)
				if (weights[tmp][i] && !visited[i])	
					que[tail++]=i;
		}
	}
}
void SetZero(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        a[i]=0;
    }
}

