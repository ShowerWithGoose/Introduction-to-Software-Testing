#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int node[105];
int edge[105][105];
int visit[105];
int dui[100000];
int sum;
void dfs(int now,int n,int ss);
void bfs(int now,int n);
void dfs(int now,int n,int ss){
	if(sum==ss-1){
		printf("%d\n",now);
		sum++;
	}
	else{
		printf("%d ",now);
		sum++;
	}
	visit[now]=1;
	for(int j=0;j<n;j++){
		if(edge[now][j]!=0&&visit[j]==0){
			dfs(j,n,ss);
		}
	}
	return ;
}
void bfs(int now,int n){
	int st=0;
	int end=0;
		dui[end++]=now;
	while(st<end){
		if(visit[dui[st]]==0){
			printf("%d ",dui[st]);
			visit[dui[st]]=1;
		}
		for(int j=0;j<n;j++){
			if(edge[dui[st]][j]!=0&&visit[j]==0){
				dui[end++]=j;
			}
		}
		st++;
	}
	printf("\n");
	return ;
}
int main(){
	int n,t;
	scanf("%d %d",&n,&t);
	for(int i=0;i<t;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		edge[a][b]=edge[b][a]=1;
		node[a]=node[b]=1;	
	}
	int m;
	scanf("%d",&m);
	dfs(0,n,n);	
	memset(visit,0,sizeof(visit));
	sum=0;
	bfs(0,n);
	memset(visit,0,sizeof(visit));
	node[m]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==m||j==m){
				edge[i][j]=0;
			}
		}
	}
	dfs(0,n,n-1);
	memset(visit,0,sizeof(visit));
	bfs(0,n);
	return 0;
}

