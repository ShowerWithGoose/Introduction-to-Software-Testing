#include <stdio.h>
#include <string.h>

int line[100][100];
int visit[100]={0};
int n;
int q[100];

void dfs(int i){
	printf("%d ",i);
	visit[i]=0;
	int j;
	for(j=1;j<n;j++){
		if(line[i][j]==0 || visit[j]==0)
			continue;
		dfs(j); 
	}
}
void bfs(int i){
	visit[i]=0;
	int head=0,tail=1;
	printf("0 ");
	q[head++]=i;
	int j;
	while(tail-head+1>0){
		int tmp=q[head++];
		for(j=1;j<n;j++){
			if(line[tmp][j]==0 || visit[j]==0)
				continue;
			printf("%d ",j);
			visit[j]=0;
			q[++tail]=j;
		} 
	}
}

int main(){
	int sum;
	scanf("%d %d",&n,&sum);
	int i;
	for(i=0;i<n;i++)
		visit[i]=1;
	int x,y;
	int de;
	for(i=0;i<sum;i++){
		scanf("%d %d",&x,&y);
		line[x][y]=line[y][x]=1;
	}
	scanf("%d",&de);
	dfs(0);
	printf("\n");
	for(i=0;i<n;i++)
		visit[i]=1;
	bfs(0);
	printf("\n");
	for(i=0;i<n;i++)
		visit[i]=1;
	visit[de]=0;
	dfs(0);
	printf("\n");
	for(i=0;i<n;i++)
		visit[i]=1;
	visit[de]=0;	
	bfs(0);
	return 0;
} 



