#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int edg[105][105],Visited[105]={0},Que[105]={0};
int e,n;
void DFS(int v)
{
	int i;
	printf("%d ",v);
	Visited[v]=1;
	for(i=0;i<e;i++){
		if(edg[v][i]==1&&Visited[i]==0) DFS(i);
	}
}
void BFS(int v)
{
	int front=0,rear=1,a,i;
	Que[front]=v;
	while(front<=rear){
		a=Que[front];
		front++;
		if(Visited[a]==1) continue;
		else{
			printf("%d ",a);
			Visited[a]=1;
			for(i=0;i<e;i++){
				if(edg[a][i]==1&&Visited[i]==0) Que[rear++]=i;
			}
		}
	}
}
int main()
{
	int i,u,v,dele;
	scanf("%d%d",&e,&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&u,&v);
		edg[u][v]=1;
		edg[v][u]=1;
	}
	scanf("%d",&dele);
	DFS(0);printf("\n");
	memset(Visited,0,105);
	BFS(0);printf("\n");
	for(i=0;i<e;i++)
		edg[dele][i]=0;
	for(i=0;i<e;i++)
		edg[i][dele]=0;
	memset(Visited,0,105);
	DFS(0);printf("\n");
	memset(Visited,0,105);
	memset(Que,0,105);
	BFS(0);
	return 0;
}

