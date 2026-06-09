#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int A[105][105],visit[105];
int queue[105];
int front=0,rear=-1;
void travelDFS(int n,int del){
	int i;
	for(i=0;i<n;i++){
		
		if(!visit[i])
		DFS(i,n,del);
	}
}
void DFS(int v,int n,int del){
	int i,j;
	visit[v]=1;
	if(v!=del)
	printf("%d ",v);
	for(i=v,j=0;j<n;j++)
	if(!visit[j]&&A[i][j]==1)
	DFS(j,n,del);
}
void travelBFS(int n,int del){
	int i;
	for(i=0;i<n;i++)
	if(!visit[i])
	BFS(i,n,del);
}
void BFS(int v,int n,int del){
	int i,j;
	if(v!=del)
	printf("%d ",v);
	visit[v]=1;
	queue[++rear]=v;
	while(front<=rear){
		v=queue[front];
		front++;
		for(i=v,j=0;j<n;j++){
			if(!visit[j]&&A[i][j]==1){
				if(j!=del)
				printf("%d ",j);
				visit[j]=1;
				queue[++rear]=j;
			}
		}
	}
}
int main()
{
	int n1,n2,i,j;
	int x1,x2,del;
	scanf("%d%d",&n1,&n2);
	for(i=0;i<n2;i++){
		scanf("%d%d",&x1,&x2);
		A[x1][x2]=1;
		A[x2][x1]=1;
	}
	scanf("%d",&del);
	travelDFS(n1,-1);
	printf("\n");
	memset(visit,0,sizeof(visit));
	travelBFS(n1,-1);
		printf("\n");
	memset(visit,0,sizeof(visit));
	for(i=del,j=0;j<n1;j++)
	{
	A[i][j]=0;
	A[j][i]=0;}
	
	travelDFS(n1,del);
	memset(visit,0,sizeof(visit));
		printf("\n");
	travelBFS(n1,del);
		printf("\n");
	memset(visit,0,sizeof(visit));
	return 0;
}

