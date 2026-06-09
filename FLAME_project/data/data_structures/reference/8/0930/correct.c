#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int A[105][105],visited[105]={0},n,N,queue[105],flag;
void DFS(int);
void BFS(int);

int main()
{
	int i,x,y,z;
	scanf("%d%d",&n,&N);
	for(i=0;i<N;i++){        //建立邻接表 
		scanf("%d%d",&x,&y);
		A[x][y]=1;
		A[y][x]=1;
	}
	scanf("%d",&z);
	DFS(0);
	printf("\n");
	for(i=0;i<105;i++)
	    visited[i]=0;
	BFS(0);	
	printf("\n");
	for(i=0;i<105;i++)
	    visited[i]=0;
	visited[z]=1;
	DFS(0);
	printf("\n");
	for(i=0;i<105;i++)
	    visited[i]=0;
	visited[z]=1;
	BFS(0);
	return 0;
}

void DFS(int v)   //深度优先遍历 
{
	int i;
	if(v)
	    printf(" ");
	printf("%d",v);
	visited[v]=1;
	for(i=0;i<n;i++)
		if(A[v][i]==1&&visited[i]==0)
		    DFS(i);
}

void BFS(int v)    //广度优先遍历 
{
	int front=-1,rear=-1,p,i;
	queue[++rear]=v;
	for(;front<=rear;){
		p=queue[++front];
		if(visited[p]==1)
		    continue;
		if(p)
		    printf(" ");
		printf("%d",p);
		visited[p]=1;
		for(i=0;i<n;i++){
			if(A[p][i]==1&&visited[i]==0)
			    queue[++rear]=i;
		}
	}
}

