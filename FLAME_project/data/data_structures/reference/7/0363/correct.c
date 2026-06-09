#include <stdio.h>
#include <string.h>

#define MAX_N 1000010

int n;
int a[MAX_N];
int tr[MAX_N],vis[MAX_N];
void insert(int x,int val) {
	if(!vis[x]) {
		tr[x]=val;
		vis[x]=1;
//		printf("%d %d\n",val,x);
		return ;
	}
//	if(tr[x]==val) return;
	if(tr[x]<=val) insert(x*2+1,val);
	if(tr[x]>val) insert(x*2,val);
}
void dfs(int x,int dep) {
	if(!vis[x]) return ;
	if(!vis[x*2] && !vis[x*2+1]) {
		printf("%d %d\n",tr[x],dep);
		return ;
	}
	dfs(x*2,dep+1);
	dfs(x*2+1,dep+1);
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]),insert(1,a[i]);
//	puts("");
	dfs(1,1);
	return 0;
}

