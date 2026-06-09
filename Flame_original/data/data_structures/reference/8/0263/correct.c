#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a, b;
int flag, s[101][101];
int visit[101], q[101];

void dfs(int x){
	if(!flag){
		printf("%d",x);
		flag=1;
	}
	else printf(" %d",x);
	visit[x]=1;
	int i;
	for(i=0;i<a;i++){
		if(s[x][i]){
			if(!visit[i]) dfs(i);
		}
	}
}

void bfs(int t){
	q[1]=t;
	int l=1,r=1,i;
	while(l<=r)
	{
		int x=q[l];l++;
		if(visit[x])continue;
		
		if(!flag)printf("%d",x),flag=1;
		else printf(" %d",x);
		visit[x]=1;
		for(i=1;i<=a;i++)
		    if(s[x][i]){
			    if(!visit[i]) q[++r]=i;
		    }
	}
	memset(visit,0,sizeof(visit));
}

int main()
{
	scanf("%d%d",&a,&b);
	int i, x, y;
	for(i=0;i<b;i++)
	{
		scanf("%d %d",&x,&y);
		s[x][y]=1;
		s[y][x]=1;
	}
	
	memset(visit,0,sizeof(visit));
	flag=0;dfs(0);printf("\n");
	memset(visit,0,sizeof(visit));
	flag=0;bfs(0);printf("\n");
	
	int del;
	scanf("%d",&del);
	memset(visit,0,sizeof(visit));
	visit[del]=1;
	flag=0;dfs(0);printf("\n");
	memset(visit,0,sizeof(visit));
	visit[del]=1;
	flag=0;bfs(0);printf("\n");
	
	return 0;
 } 

