#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int A[100][100];
int vnum,bnum;
int visited[100]={0};
int Q[100];
int front=-1,rear=-1;
void DFS(int v)
{
	printf("%d ",v);
	visited[v]=1;
	for(int i=0;i<vnum;i++){
		if(A[v][i]==1&&visited[i]==0){
			DFS(i);
			
		}
	}
}
void BFS(int v)
{
	if(visited[v]==0){
		printf("%d ",v);
		visited[v]=1;
	}
	for(int i=0;i<vnum;i++){
		if(A[v][i]==1&&visited[i]==0){
			printf("%d ",i);
			visited[i]=1;
			Q[++rear]=i;
		}
	}
	while(!(rear==front)){
		int w=Q[++front];
		BFS(w);
	}
}
void ori()
{
	for(int i=0;i<vnum;i++){
		visited[i]=0;
	}
	
}
void del(int x){
	for(int i=0;i<vnum;i++){
		A[x][i]=0;
		A[i][x]=0;
	}
}
int main()
{
	int delnum;
	scanf("%d%d",&vnum,&bnum);
	for(int i=0;i<vnum;i++){
		for(int j=0;j<vnum;j++){
			A[i][j]=0;
		}
	}
	for(int i=0;i<bnum;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		A[a][b]=A[b][a]=1;
	}
	scanf("%d",&delnum);
	DFS(0);
	printf("\n");
	ori();
	BFS(0);
	printf("\n");
	del(delnum);
	ori();
	DFS(0);
	printf("\n");
	ori();
	BFS(0);
}



