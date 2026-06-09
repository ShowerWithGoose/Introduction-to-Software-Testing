#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef long long ll;
const int maxn = 110;
ll max(ll a,ll b){
   return a>b?a:b;
}
ll min(ll a,ll b){
   return a<b?a:b;
}
int n,m,head;
int ma[105][105];
int vis[105];
int ans[105];
void dfs(int u,int fa){
	vis[u]=1;
	for (int i=1;i<=n;i++){
		if (i==fa) continue;
		if (ma[u][i]&&!vis[i]) {
			ans[++ans[0]]=i;
			dfs(i,fa);
		}
	}
}
void bfs(int u,int fa){
	
	for (int i=1;i<=n;i++){
		if (i==fa) continue;
		if (ma[u][i]&&!vis[i]){
			vis[i]=1;
			ans[++ans[0]]=i;
		}
	}
	if (head<=ans[0])
	bfs(ans[head++],fa);
}
void print(){
	for (int i=1;i<=ans[0];i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
}
int main(){
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v;
		scanf ("%d%d",&u,&v);
		ma[u][v]=ma[v][u]=1;
	}
	int now;
	
	scanf ("%d",&now);
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	ans[++ans[0]]=0;
	dfs(0,-1);
	print();
	
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	ans[++ans[0]]=0;
	head=1;
	bfs(0,-1);
	print();
	

	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
		vis[0]=1;
	ans[++ans[0]]=0;
	dfs(0,now);
	print();
	

	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
		vis[0]=1;
	ans[++ans[0]]=0;
	head=1;
	bfs(0,now);
	print();
	return 0;
}

