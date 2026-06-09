#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int visited[105];
int edge[105][105];
int num_V;
int num_E;
int deleted;
void makegraph(void){
	int i,a,b;
	scanf("%d%d",&num_V,&num_E);
	for(i=0;i<num_E;i++){
		scanf("%d%d",&a,&b);
		edge[a][b]=1,edge[b][a]=1;
	}
}
void deletepoint(void){
	int i;
	for(i=0;i<num_V;i++){
		edge[deleted][i]=0;
	}
	for(i=0;i<num_V;i++){
		edge[i][deleted]=0;
	}
}
void remakevisited(void){
	int i;
	for(i=0;i<105;i++){
		visited[i]=0;
	}
}
void DFS(int entrance){
	int i;
	printf("%d ",entrance);
	visited[entrance]=1;
	for(i=0;i<num_V;i++){
		if(edge[entrance][i]==1&&i!=entrance){
			if(!visited[i]){
				DFS(i);
			}
		}
	}
}
int queue[505];
int head,rear;
int isempty(void){
	return head>rear;
}
void push(int x){
	queue[++rear]=x;
}
int pop(void){
	return isempty()?-1: queue[head++];
}
void BFS(int entrance){
	int i,pre;
	push(entrance);
	printf("%d ",entrance);
	visited[entrance]=1;
	while(!isempty()){
		pre=pop();
		for(i=0;i<num_V;i++){
			if(edge[pre][i]==1&&i!=pre){
				if(!visited[i]){
					push(i);
					printf("%d ",i);
					visited[i]=1;
				}
			}
		}
	}
}
int main(){
	makegraph();
	scanf("%d",&deleted);
	DFS(0);
	remakevisited();
	printf("\n");
	head=0,rear=-1;
	BFS(0);
	remakevisited();
	printf("\n");
	deletepoint();
	DFS(0);
	remakevisited();
	printf("\n");
	head=0,rear=-1;
	BFS(0);
	remakevisited();
	return 0;
}

