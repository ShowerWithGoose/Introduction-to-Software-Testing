#include <string.h>
#include <stdio.h>
int n;
int a[100],vis[100];
int i;
void dfs(int dep) {
	if(dep==n+1) {
		for(i=1;i<=n;i++) printf("%d ",a[i]);
		puts("");
	}
	int j;
	for(j=1;j<=n;j++) {
		if(vis[j]) continue;
		a[dep]=j;
		vis[j]=1;
		dfs(dep+1);
		vis[j]=0;
	}
}
int main() {
	scanf("%d",&n);
	dfs(1);
	return 0;
}

