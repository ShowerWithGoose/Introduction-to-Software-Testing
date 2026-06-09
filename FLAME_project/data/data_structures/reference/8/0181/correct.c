#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char G[105][105];
int num;
int visited[102];

void dfs(int n){
	int i;
	printf("%d ",n);
	visited[n]=1;
	for(i=0;i<num;i++){
		if(G[n][i]==1&&visited[i]==0){
			dfs(i);
		}
	}
}
void bfs(int n){
	int q[200]={0};
	int p;
	int i,rear=-1,tail=0;

		q[tail++]=n;
		while(rear+1!=tail){
			p=q[++rear];
			visited[p]=1;
			printf("%d ",p);
			for(i=0;i<num;i++){
				if(visited[i]==0&&G[p][i]==1){
					q[tail++]=i;
					visited[i]=1;
				}
			}
		}
	
	
}

int main(){
	int j,n;
	int a,b;
	scanf("%d %d",&num,&j);
	
	for(n=1;n<=j;n++){
		scanf("%d %d",&a,&b);
		G[a][b]=1;
		G[b][a]=1;
	}
	scanf("%d",&n);
	
	dfs(0);
	puts("");
	memset(visited,0,sizeof(visited));
	bfs(0);
	puts("");
	memset(visited,0,sizeof(visited));
	
	for(j=0;j<=100;j++){
		G[n][j]=0;
		G[j][n]=0;
	}
	dfs(0);
	puts("");
	memset(visited,0,sizeof(visited));
	bfs(0);
	puts("");
	memset(visited,0,sizeof(visited));
	
//	for(n=0;n<num;n++){
//		for(j=0;j<num;j++)
//			printf("%d ",G[n][j]);
//	puts("");
//	}
	return 0;
}




