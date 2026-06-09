#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define maxn 105
int n;
bool d[maxn][maxn];
int m;
bool f[maxn];
int i;
int qu[maxn],head,tail;
void init(){
	head=tail=0;
	int k;
	for(k=0;k<n;k++){
		f[k]=0;
	}
}
void dfs(int p,int del){
	f[p]=1;
	if(p==del)return;
	printf("%d ",p);
	int k;
	for(k=0;k<n;k++){
		if(!f[k]&&d[p][k]){
			dfs(k,del);
		}
	}
	if(p==0)printf("\n");
}
void bfs(int s,int del){
	init();
	qu[head++]=s;
	int k;
	f[0]=1;
	for(k=0;k<n;k++){
		if(!f[k]&&d[s][k]){
			qu[head++]=k;
			f[k]=1;
		}
	}
	while(head!=tail){
		int fr=qu[tail++];
		if(fr==m)continue;
		printf("%d ",fr);
		for(k=0;k<n;k++){
			if(!f[k]&&d[fr][k]){
				f[k]=1;
				qu[head++]=k;
			}
		}
	}
	printf("\n");
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		d[a][b]=d[b][a]=1;
	}
	init();
	dfs(0,-1);
	bfs(0,-1);
	scanf("%d",&m);
	init();
	dfs(0,m);
	bfs(0,m);
	return 0;
}
