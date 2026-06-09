#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXNUM 100

int A[MAXNUM][MAXNUM];
int visited[MAXNUM],num,clear=-1;
int QUEUE[MAXNUM],front=0,rear=-1;

void TRAVEL_DFS();
void DFS(int v); 
void TRAVEL_BFS();
void BFS(int v);

int main(){
	int n,i,a,b;
	scanf("%d%d",&num,&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		A[a][b]=A[b][a]=1;
	}
	TRAVEL_DFS();
	TRAVEL_BFS();
	scanf("%d",&clear);
	for(i=0;i<num;i++)
		A[i][clear]=A[clear][i]=0;
	TRAVEL_DFS();
	TRAVEL_BFS();
	return 0;
}

void TRAVEL_BFS(){
	int i;
	front=0,rear=-1;
	for(i=0;i<num;i++)
		visited[i]=0;
	for(i=0;i<num;i++)
		if(!visited[i]&&i!=clear){
			BFS(i);
			putchar('\n');
		}
}

void BFS(int v){
	int i;
	QUEUE[++rear]=v;
	visited[v]=1;
	while(front<=rear){
		v=QUEUE[front++];
		printf("%d ",v);
		for(i=0;i<num;i++)
			if(!visited[i]&&A[v][i]){
				QUEUE[++rear]=i;
				visited[i]=1;
			}
	}
}

void TRAVEL_DFS(){
	int i;
	for(i=0;i<num;i++)
		visited[i]=0;
	for(i=0;i<num;i++)
		if(!visited[i]&&i!=clear){
			DFS(i);
			putchar('\n');
		}
}

void DFS(int v){
	int i;
	printf("%d ",v);
	visited[v]=1;
	for(i=0;i<num;i++){
		if(!visited[i]&&A[v][i])
			DFS(i);
	}
}



