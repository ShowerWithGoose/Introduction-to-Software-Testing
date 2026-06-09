#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int picture[100][100],n,e;
int visit[100],queue[100];
void dfs(int v){
	printf("%d ",v);
	visit[v]=1;
	int i;
	for(i=1;i<=n;i++) if(picture[v][i]){
		if(!visit[i]) dfs(i);
	}
}
void bfs(int v){
	queue[1]=v;
	int front=1,rear=1,i;
	while(front<=rear){
		int v=queue[front++];
		if(visit[v]) continue;
		else printf("%d ",v);
		visit[v]=1;
		for(i=1;i<=n;i++) if(picture[v][i]){
			if(!visit[i]) queue[++rear]=i;
		}
	}
	memset(visit,0,sizeof(visit));
}
int main(){
	int i,op,x,y;
	scanf("%d %d",&n,&e);
	for(i=1;i<=e;i++){
		scanf("%d %d",&x,&y);
		picture[x][y]=1;picture[y][x]=1;
	}
	dfs(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	bfs(0);
	printf("\n");
	scanf("%d",&op);
	visit[op]=1;
	dfs(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	visit[op]=1;
	bfs(0);
}

