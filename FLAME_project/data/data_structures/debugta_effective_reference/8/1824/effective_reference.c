#include <stdio.h>
#include <stdlib.h>
#define MAX 105
void DFS(int g[][MAX],int start,int point_num);
void BFS(int g[][MAX],int start,int point_num);

int Graph[MAX][MAX],visited[MAX],visited2[MAX];
int queue[MAX],front=0,rear=MAX-1,Graph__end=0;


int main(){
	int point_num,edge_num,x,y,del;
	scanf("%d%d",&point_num,&edge_num);
	for(int i=0;i<edge_num;i++){
		scanf("%d%d",&x,&y);
		Graph[x][y]=1;
		Graph[y][x]=1;
	}
	DFS(Graph,0,point_num);
	printf("\n");
	BFS(Graph,0,point_num);
	printf("\n");
	memset(visited,0,sizeof(visited));
	memset(visited2,0,sizeof(visited2));
	scanf("%d",&del);
	visited[del]=1;
	visited2[del]=1;
		DFS(Graph,0,point_num);
		printf("\n");
		BFS(Graph,0,point_num);
	return 0;
}

void DFS(int g[][MAX],int start,int point_num){
	int i;
	printf("%d ",start);
	visited[start]=1;
	for(i=1;i<point_num;i++){
		if((g[start][i])&&(visited[i]==0)){
			DFS(g,i,point_num);
		}
	}
}

void BFS(int g[][MAX],int start,int point_num){
	int i,head;
	printf("%d ",start);
	visited2[start]=1;
	rear=(rear+1)%MAX;
	queue[rear]=start;
	Graph__end++;
	while(Graph__end!=0){
		head=queue[front];
		front=(front+1)%MAX;
		Graph__end--;
		for(i=1;i<point_num;i++){
			if((g[head][i])&&(visited2[i]==0)){
				printf("%d ",i);
				visited2[i]=1;
				rear=(rear+1)%MAX;
				queue[rear]=i;
				Graph__end++;
			}
		}
	}
}

