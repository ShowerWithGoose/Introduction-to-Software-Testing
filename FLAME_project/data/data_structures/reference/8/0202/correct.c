#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int G[120][120];
int queue[120],visited[120];
int i,j;
void DFS(int v,int t){//Depth
    visited[t]=-1;
    printf("%d ",t);
    int i;
    for(i=0;i<v;i++){
    	if(G[t][i]==1){
    		if(visited[i]!=-1){
    			DFS(v,i);
			}
		}
	}
	return ;
}
void travelDFS(int v){
	int i,j;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			if(G[i][j]==1){
				if(visited[i]!=-1){
					DFS(v,i);
					break;
				}
			}
		}
	}
	printf("\n");
	return ;
}
int isempty(int q[],int front,int rear){
	if(front<=rear)return 0;
	else return 1;
} 
void BFS(int v,int t){//Breadth
    int front=0,rear=-1;
    printf("%d ",t);
    visited[t]=-1;
    queue[++rear]=t;
    while(!isempty(queue,front,rear)){
    	t=queue[front++];
    	for(i=0;i<v;i++){
    		if(G[t][i]){
    			if(visited[i]!=-1){
    				printf("%d ",i);
    				visited[i]=-1;
    				queue[++rear]=i;
				}
			}
		}
	}
	return ;
} 
void travelBFS(int v){
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			if(G[i][j]==1){
				if(visited[i]!=-1){
					BFS(v,i);
					break;
				}
			}
		}
	}
	printf("\n");
	return ;
}
int main(){
	int ver;
	int edge;
	int u,v;
	scanf("%d%d",&ver,&edge);
	for(i=0;i<edge;i++){
		scanf("%d%d",&u,&v);
		G[u][v]=G[v][u]=1;
	}
	travelDFS(ver);
	memset(visited,0,sizeof(visited));
	travelBFS(ver);
	memset(visited,0,sizeof(visited));
	memset(queue,-1,sizeof(queue));
	int num;
	scanf("%d",&num);
	for(i=0;i<ver;i++){
		G[i][num]=G[num][i]=0;
	}
	travelDFS(ver);
	memset(visited,0,sizeof(visited));
	travelBFS(ver);
	return 0;
}

