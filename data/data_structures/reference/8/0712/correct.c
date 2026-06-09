#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAXNODE 105
void DFS(int pos);
void zerolize();
void BFS(int pos);
int visit[MAXNODE] = {0};//标记结点是否被访问过，为0就是没被访问过，为1就是被访问过 
int queue[MAXNODE];
int edges[MAXNODE][MAXNODE] = {0};
int cpyedges[MAXNODE][MAXNODE] = {0};
int res[MAXNODE] = {0}; 
int cnt = -1;//cnt是下标，实际上有cnt+1个 
int front = 0,rear = 0;
int nodenum,edgenum,delnode;
int main(){
	scanf("%d%d",&nodenum,&edgenum);
	for(int i = 1; i <= edgenum; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		edges[x][y] = 1;
		edges[y][x] = 1;
	}
	scanf("%d",&delnode);
	DFS(0);
	for(int i = 0; i <= cnt;i++){
		printf("%d ",res[i]);
	}
	printf("\n");
	zerolize();
	
	BFS(0); 
	for(int i = 0; i <= cnt;i++){
		printf("%d ",res[i]);
	}
	printf("\n");
	zerolize();
	
	for(int i = 0; i <= nodenum;i++){
		edges[delnode][i] = 0;
		edges[i][delnode] = 0;
	}
	
	DFS(0);
	for(int i = 0; i <= cnt;i++){
		printf("%d ",res[i]);
	}
	printf("\n");
	zerolize();
	
	BFS(0); 
	for(int i = 0; i <= cnt;i++){
		printf("%d ",res[i]);
	}
	return 0;
}

void DFS(int pos){
	if(visit[pos] == 0){
		res[++cnt] = pos;
		visit[pos] = 1;
	}
	else return;
	for(int i = 0; i < nodenum; i++){
		if(edges[pos][i]){
			DFS(i);
		}
	} 
}

void BFS(int pos){
	queue[rear] = pos;
	visit[0] = 1;
	while(front < rear || (front == rear && rear < nodenum)){
		for(int i = 0; i < nodenum;i++){
			if(edges[queue[front]][i] && visit[i] == 0){
				queue[++rear] = i;
				visit[i] = 1;
			}	
		}
		res[++cnt] = queue[front++];
	}
//	res[++cnt] = queue[front];
}

void zerolize(){
	front = 0;
	rear = 0;
	memset(queue,0,sizeof(queue));
	cnt = -1;
	memset(res,0,sizeof(res));
	memset(visit,0,sizeof(visit));
}

