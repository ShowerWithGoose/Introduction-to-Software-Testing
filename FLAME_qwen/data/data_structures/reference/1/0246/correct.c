#include<stdio.h>
int n,a[12];
void init(){
	scanf("%d",&n);
}
int vis[12];
void dfs(int now){
	if (now==n+1) {
		for (int i=1;i<=n;i++) printf("%d ",a[i]);
		puts("");
		return;
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]){
			vis[i]=1; a[now]=i; dfs(now+1); vis[i]=0;
		}
}
void solve(){
	dfs(1);
}
int main(){
	init(); solve();
}

