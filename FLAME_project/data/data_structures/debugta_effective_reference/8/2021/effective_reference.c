#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n, num;
int flag, ju[101][101];
int visit[101], s[101];

void dfs(int v){
	if(!flag){
		printf("%d",v);
		flag=1;
	}
	else printf(" %d",v);
	visit[v]=1;
	int i;
	for(i=0;i<n;i++){
		if(ju[v][i]){
			if(!visit[i]) dfs(i);
		}
	}
}

void bfs(int t){
	s[1]=t;
	int head=1,rear=1,i;
	while(head<=rear)
	{
		int v=s[head];head++;
		if(visit[v])continue;
		
		if(!flag)printf("%d",v),flag=1;
		else printf(" %d",v);
		visit[v]=1;
		for(i=1;i<=n;i++)
		    if(ju[v][i]){
			    if(!visit[i]) s[++rear]=i;
		    }
	}
	memset(visit,0,sizeof(visit));
}

int main()
{
	scanf("%d%d",&n,&num);
	int i, v, y;
	for(i=0;i<num;i++)
	{
		scanf("%d %d",&v,&y);
		ju[v][y]=1;
		ju[y][v]=1;
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

