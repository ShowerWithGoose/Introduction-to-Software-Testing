#include<stdio.h>
#include<stdlib.h>
int G[100][100];
int visited[100];
int queue[100];
int rear=-1;
int front=0;
int n;
void DFS(int [][100],int);
void BFS(int [][100],int);
int main(){
	int i,j,k;
	int m,goal;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&j,&k);
		G[j][k]=G[k][j]=1;
	}
	scanf("%d",&goal);
	
	for(i=0;i<n;i++)visited[i]=0;
	DFS(G,0);
	printf("\n");
	for(i=0;i<n;i++)visited[i]=0;
	BFS(G,0);
	printf("\n");
	for(i=0;i<n;i++)G[goal][i]=0;
	for(i=0;i<n;i++)G[i][goal]=0; 
	for(i=0;i<n;i++)visited[i]=0;
	DFS(G,0);
	printf("\n");
	for(i=0;i<n;i++)visited[i]=0;
	BFS(G,0);
	return 0;
}
void DFS(int g[][100],int v){
	int i;
	printf("%d ",v);
	visited[v]=1;
	for(i=0;i<n;i++)if(g[v][i]==1&&visited[i]==0)DFS(G,i);
}
void BFS(int g[][100],int v){
	int i;
	visited[v]=1;
	queue[++rear]=v;
	while(rear>=front){
		v=queue[front++];
		printf("%d ",v);
		for(i=0;i<n;i++){
			if(g[v][i]==1&&visited[i]==0){
				queue[++rear]=i;
				visited[i]=1;
			}
		}
	}
}

