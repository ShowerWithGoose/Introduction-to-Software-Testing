#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define S scanf
#define P printf
#define L long long
int n,m,ok,q[105],vis[105],a[105][105];
void dfs(int x){
	int i;
	if(ok==0){
		P("%d",x);
		ok=1;
	}
	else P(" %d", x);
	vis[x]=1;
	for (i=1;i<= n;i++){
		if (a[x][i]!=0){
			if (vis[i]==0) dfs(i);
		}
	}
}
void bfs(int t){
	int l = 1, r = 1, i;
	q[1]=t;
	while (l <= r){
		int x = q[l];
		l++;
		if (vis[x]!=0) continue;
		if (ok==0){
			P("%d",x);
			ok=1;
		}
		else P(" %d",x);
		vis[x] = 1;
		for (i = 1; i <= n; i++) if (a[x][i]&&vis[i]==0) q[++r] = i;
	}
	memset(vis, 0, sizeof(vis));
}
int main(){
	int i;
	S("%d%d", &n, &m);
	for(i=1;i<=m;i++){
		int x, y;
		S("%d%d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	ok = 0;
	dfs(0);
	P("\n");
	memset(vis, 0, sizeof(vis));
	ok = 0;
	bfs(0);
	P("\n");
	S("%d", &i);
	vis[i] = 1;
	ok = 0;
	dfs(0);
	P("\n");
	memset(vis, 0, sizeof(vis));
	vis[i] = 1;
	ok = 0;
	bfs(0);
	P("\n");
	return 0;
}



