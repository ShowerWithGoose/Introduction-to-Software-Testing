#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
int a[250][250],v[250],n,s,del;
int queue[250],head=0,end=0;
void dfs(int tmp);
void bfs(int tmp);
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
	memset(v,0,100);
	bfs(0);
	printf("\n");
	memset(v,0,100);
	v[del]=1;
	dfs(0);
	printf("\n");
	memset(v,0,100);
	v[del]=1;
	bfs(0);
	return 0;
}
void dfs(int tmp){
	int i;
	v[tmp]=1;
	printf("%d ",tmp);
	for(i=0;i<n;i++){
		if(a[tmp][i]==1&&v[i]==0)
			dfs(i);
	}
}
void bfs(int tmp){
	int i;
	v[tmp]=1;
	printf("%d ",tmp);
	for(i=0;i<n;i++){
		if(a[tmp][i]==1&&v[i]==0){
			v[i]=1;
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



