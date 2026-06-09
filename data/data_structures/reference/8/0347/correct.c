#include<stdio.h>
#include<stdlib.h>
int g[105][105];
int visit[105];
int que[1010];
int front,rear;
int vnum,ednum,del;
void init_graph(){
	int i,j;
	for(i=0;i<vnum;i++){
		for(j=0;j<vnum;j++){
			g[i][j] = 0;
		}
	}
}
void init_visit(){
	int i;
	for(i=0;i<vnum;i++){
		visit[i] = 0;
	}
}
void createG(){
	int i,v1,v2;
	init_graph();
	for(i=0;i<ednum;i++){
		scanf("%d%d",&v1,&v2);
		g[v1][v2] = 1;
		g[v2][v1] = 1;
	}
}
void DFS(int start){
	int i;
	printf("%d ",start);
	visit[start] = 1;
	for(i=0;i<vnum;i++){
		if(g[start][i]==1&&!visit[i]){
			DFS(i);
		}
	}
}
void BFS(int start){
	init_visit();
	int i,temp;
	for(i=0;i<1010;i++){
		que[i] = 0;
	}
	front = 0;
	rear = 0;
	que[rear] =  start;
	rear++;
	visit[start] = 1;
	while(front<rear){
		temp = que[front];
		front++;
		printf("%d ",temp);
		for(i=0;i<vnum;i++){
			if(!visit[i]&&g[temp][i]==1){
				que[rear] = i;
				rear++;
				visit[i] = 1;
			}
		}
	}
}
int main()
{
	int i,j,k;
	scanf("%d%d",&vnum,&ednum);
	createG();
	init_visit();
	scanf("%d",&del);
	DFS(0);
	printf("\n");
	BFS(0);
	printf("\n");
	for(i=0;i<vnum;i++){
		g[del][i] = 0;
		g[i][del] = 0;
	}
	init_visit();
	DFS(0);
	printf("\n");
	BFS(0);
	printf("\n");
	return 0;
}

