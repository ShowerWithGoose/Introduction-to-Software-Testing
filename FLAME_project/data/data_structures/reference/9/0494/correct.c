#include<stdio.h>
#include<stdbool.h>
#define MAX 105
int head[MAX*MAX],nxt[MAX*MAX],to[MAX*MAX],cnt,res,tmp,tmp2,tmp1;
int x1[MAX],x2[MAX],y1[MAX],y2[MAX],n,p;
int i,j;
bool f[MAX];
bool is_con(int a,int b){
	if(x1[a]==x1[b]&&y1[a]==y1[b])return 1;
	if(x1[a]==x2[b]&&y1[a]==y2[b])return 1;
	if(x2[a]==x1[b]&&y2[a]==y1[b])return 1;
	if(x2[a]==x2[b]&&y2[a]==y2[b])return 1;
	return 0;
}
void add_edge(int u,int v){
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
void dfs(int s){
	int k;
	for(k=head[s];k;k=nxt[k]){
		if(f[to[k]])continue;
		f[to[k]]=1;
		tmp++;
		if(x1[tmp2]>x1[to[k]]){
			tmp2=to[k];
		}
		dfs(to[k]);
	}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);
		for(j=1;j<i;j++){
			if(is_con(i,j)){
				add_edge(i,j);
				add_edge(j,i);
			}
		}
	}
	for(i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			tmp=1;
			tmp2=i;
			dfs(i);
			if(res<tmp){
				res=tmp;
				p=tmp2;
			}
		}
		
	}
	printf("%d %d %d\n",res,x1[p],y1[p]);
	return 0;
}
