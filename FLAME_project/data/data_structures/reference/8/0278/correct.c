#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,a[105][105];
int p[105],flag,q[105];
int bfs(int t){
	q[1]=t;
	int left=1,right=1,i;
	while(left<=right){
		int x=q[left];
		left++;
		if(p[x])
		continue;
		if(flag==0)
		printf("%d",x),flag=1;
		else printf(" %d",x);
		p[x]=1;
		for(i=1;i<=n;i++)
		if(a[x][i]){
			if(p[i]==0)
			q[++right]=i;
		}
	}
	return 1;
}
int dfs(int x){
	if(flag==0)
	printf("%d",x),flag=1;
	else
	printf(" %d",x);
	p[x]=1;
	int i;
	for(i=1;i<=n;i++)
	if(a[x][i])
	if(p[i]==0)
	dfs(i);
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	dfs(0);
	printf("\n");
	for(i=0;i<105;i++)
	p[i]=0;
	flag=0;
	bfs(0);
	for(i=0;i<105;i++)
	p[i]=0;
	printf("\n");
	scanf("%d",&j);
	p[j]=1;
	flag=0;
	dfs(0);
	printf("\n");
	for(i=0;i<105;i++)
	p[i]=0;
	p[j]=1;
	flag=0;
	bfs(0);
	for(i=0;i<105;i++)
	p[i]=0;
	printf("\n");
	return 0;
}



