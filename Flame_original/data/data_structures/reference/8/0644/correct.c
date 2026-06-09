#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int m,n;
int used[110],queue[110],picture[110][110];
void dfs(int root){
	int i=0;
	used[root]=1;
	printf("%d ",root);
	for(i=0;i<n;i++){
		if(picture[root][i]&&!used[i]) dfs(i);
	}
}
void bfs(){
	int front=0,rear=1,vis,i;
	queue[0]=0;
	while(front<=rear){
		vis=queue[front++];
		if(used[vis]) continue;
		printf("%d ",vis);
		used[vis]=1;
		for(i=0;i<n;i++){
			if(picture[vis][i]&&!used[i]) queue[rear++]=i;
		}
	}
}
int main(){
	int i=0,j=0;
	scanf("%d%d",&n,&m);
	int x,y,delet;
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		picture[x][y]=1;
		picture[y][x]=1;
	}
	scanf("%d",&delet);
	dfs(0);
	printf("\n");
	memset(used,0,sizeof(used));
	bfs();
	printf("\n");
	memset(used,0,sizeof(used));
	used[delet]=1;
	dfs(0);
	printf("\n");
	memset(used,0,sizeof(used));
	used[delet]=1;
	bfs();
	printf("\n");
	return 0;
}

