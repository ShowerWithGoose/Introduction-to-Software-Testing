#include<stdio.h>
#include<string.h>

int bet[110][110];
int n,m,del;
int prt[110];
int vis[110];
int dui[110];
int head,tail;
int num;

void dfs(int s)
{	
	int i;
	vis[s]=1;
	for(i=1;i<n;i++){
		if(!vis[i]&&bet[s][i]){
			printf("%d ",i);
			dfs(i);
		}
	}
}

void bfs(int d)
{
	int i;
	head=1,tail=1;
	dui[head]=0;
	vis[0]=1;
	while(head<=tail){
		for(i=1;i<n;i++)
			if(!vis[i]&&bet[dui[head]][i]){
				vis[i]=1;
				dui[++tail]=i;
			}
		head++;
	}
	for(i=1;i<=n-d;i++)printf("%d ",dui[i]);
}
	
	
int main()
{
	int i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)scanf("%d%d",&a,&b),bet[a][b]=1,bet[b][a]=1;
	scanf("%d",&del);
	memset(vis,0,sizeof(vis));
	printf("0 ");
	num=1;
	dfs(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	bfs(0);
	printf("\n");
	
	for(i=0;i<n;i++)
		bet[i][del]=0,bet[del][i]=0;
	
	memset(vis,0,sizeof(vis));
	printf("0 ");
	num=1;
	dfs(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	bfs(1);
	
	return 0;
}
			
	

