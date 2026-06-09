#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
int a[100][100];
int visit [100];
int n,s,del;
int queue[110],head=0,end=0;
void dfs(int now){
	int i;
	visit[now]=1;
	printf("%d ",now);
	for(i=0;i<n;i++){
		if(a[now][i]==1&&visit[i]==0)
			dfs(i);
	}
}
void bfs(int now){
	int i;
	visit[now]=1;
	printf("%d ",now);
	for(i=0;i<n;i++){
		if(a[now][i]==1&&visit[i]==0){
			visit[i]=1;
			queue[end]=i;
			end++;
		}
	}
	while(head!=end){
		i=queue[head];
		head++;
		bfs(i);
	}
}
int main(){
	int i,x,y;
	scanf("%d %d",&n,&s);
	for(i=0;i<s;i++){
		scanf("%d %d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	scanf("%d",&del);
	dfs(0);
	printf("\n");
	memset(visit,0,100);
	bfs(0);
	printf("\n");
	memset(visit,0,100);
	visit[del]=1;
	dfs(0);
	printf("\n");
	memset(visit,0,100);
	visit[del]=1;
	bfs(0);
	return 0;
}

