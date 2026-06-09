#include <stdio.h>
#include <string.h>

#define MAX_N 10010

struct Line {
	int x1,y1;
	int x2,y2;
}p[MAX_N];
int ans,id,maxn;
int vis[MAX_N];
int n;
void dfs(int i,int dep) {
	int j;
	maxn=maxn<dep?dep:maxn;
	vis[i]=1;
	for(j=1;j<=n;j++) {
		if(vis[j]) continue;
		if(p[i].x2!=p[j].x1 || p[i].y2!=p[j].y1) continue;
		dfs(j,dep+1);
	}
	vis[i]=0;
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d%d%d%d",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
	for(i=1;i<=n;i++) {
		maxn=0;
		dfs(i,1);
		if(maxn>ans) {
			ans=maxn;
			id=i;
		}
	}
	printf("%d %d %d",ans,p[id].x1,p[id].y1);
	return 0;
}

