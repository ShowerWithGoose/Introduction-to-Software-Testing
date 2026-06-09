//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define eps 1e-6
int G[105][105],mark[105],ndot,nline,queue[105];
void dfs(int v){
	int j;
	mark[v]=1;
	printf("%d ",v);
	for(j=0;j<ndot;j++){
		if(mark[j]==0&&G[v][j]==1){
			mark[j]=1; dfs(j);
		}
	}
}
void bfs(int v){
	int left=0,right=0,j;
	mark[v]=1;
	queue[right++]=v;
	while(left<right){
		int now=queue[left++];
		printf("%d ",now);
		for(j=0;j<ndot;j++){
			if(mark[j]==0&&G[now][j]==1){
				mark[j]=1; queue[right++]=j;
			}
		}
	}
	
}
int main(){
	int i,d1,d2,del;
	scanf("%d%d",&ndot,&nline);
	for(i=0;i<nline;i++){
		scanf("%d %d",&d1,&d2);
		G[d1][d2]=G[d2][d1]=1;
		
	}
	scanf("%d",&del);
	dfs(0); printf("\n");
	memset(mark,0,105);
	bfs(0); printf("\n");
	memset(mark,0,105);
	for(i=0;i<ndot;i++){
		G[del][i]=G[i][del]=0;
	}
	dfs(0); printf("\n");
	memset(mark,0,105);
	bfs(0); printf("\n");
	
	return 0;
}



