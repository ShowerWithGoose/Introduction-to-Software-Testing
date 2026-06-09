#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,map[105][105],p[105],k,q[105];
void DFS(int x);
void BFS(int t);
int main()
{
	scanf("%d%d",&n,&m);
	int i,x,y;
	for(i=1;i<=m;i++)
	{	
		scanf("%d%d",&x,&y);
		map[x][y]=1;
		map[y][x]=1;
	}
	k=0;DFS(0);printf("\n");
	memset(p,0,sizeof(p));
	k=0;BFS(0);printf("\n");
	scanf("%d",&i);
	p[i]=1;
	k=0;DFS(0);printf("\n");
	memset(p,0,sizeof(p));p[i]=1;
	k=0;BFS(0);printf("\n");
	return 0;
}
void DFS(int x){
	if(!k)printf("%d",x),k=1;
	else printf(" %d",x);
	p[x]=1;
	int i;
	for(i=1;i<=n;i++)if(map[x][i])
	{
		if(!p[i])
		{
			DFS(i);
		}
	}
}
void BFS(int t){
	q[1]=t;

	int y=1,r=1,i;
	while(y<=r){
		int x=q[y];y++;if(p[x])continue;
		if(!k)printf("%d",x),k=1;
		else printf(" %d",x);
		
		p[x]=1;
		for(i=1;i<=n;i++)if(map[x][i])
		{
			if(!p[i])q[++r]=i;
		}
	}
	memset(p,0,sizeof(p));
}

