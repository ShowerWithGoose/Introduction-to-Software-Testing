#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define maxn 105
int n;
bool form[maxn][maxn];
int m;
bool footprint[maxn];
int i;
int team[maxn],head,tail;
void init(){
	head=tail=0;
	int i;
	for(i=0;i<n;i++){
		footprint[i]=0;
	}
}
void dfs(int b,int d){
	footprint[b]=1;
	if(b==d)return;
	printf("%d ",b);
	int i;
	for(i=0;i<n;i++){
		if(!footprint[i]&&form[b][i]){
			dfs(i,d);
		}
	}
	if(b==0)printf("\n");
}
void bfs(int s,int d){
	init();
	team[head++]=s;
	int i;
	footprint[0]=1;
	for(i=0;i<n;i++){
		if(!footprint[i]&&form[s][i]){
			team[head++]=i;
			footprint[i]=1;
		}
	}
	while(head!=tail){
		int fr=team[tail++];
		if(fr==m)continue;
		printf("%d ",fr);
		for(i=0;i<n;i++){
			if(!footprint[i]&&form[fr][i]){
				footprint[i]=1;
				team[head++]=i;
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
		form[a][b]=form[b][a]=1;
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
