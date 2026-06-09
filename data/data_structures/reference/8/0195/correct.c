#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<malloc.h>
#define ULL unsigned long long 
#define LL long long
#define fep(i,l,r) for(int i=(l);i<=r;i++)
#define ffep(i,r,l) for(int i=(r);i>=l;i--)
int rd(){
	char ch;int f=0,w=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=f*10+ch-'0';ch=getchar();}
	return f*w;
}
int e[102][102];
int n,e1;
bool vis[102];
int ans[102],tot;
void dfs(int x){
	vis[x]=true;ans[++tot]=x;if(tot==n)return;
	fep(i,0,n-1){
		if(i==x)continue;
		if(e[x][i]&&!vis[i])dfs(i);
	}
}
int q[102],l=-1,r=0;
void bfs(){
	int x;q[0]=0;
	while(l<r){
		x=q[++l];vis[x]=true;ans[++tot]=x;
		fep(i,0,n-1){
			if(i==x)continue;
			if(e[x][i]&&!vis[i]){
				vis[i]=true;q[++r]=i;
			}
		}
		
	}
}
void del(int x){
	fep(i,0,n-1){
		e[x][i]=0;e[i][x]=0;
	}
}
int main(){
	n=rd();e1=rd();
	int x,y;
	fep(i,1,e1){
		x=rd();y=rd();
		e[x][y]=e[y][x]=1;
	}
	dfs(0);memset(vis,0,sizeof(vis));
	fep(i,1,tot-1)printf("%d ",ans[i]);printf("%d\n",ans[tot]);tot=0;
	bfs();memset(vis,0,sizeof(vis));
	fep(i,1,tot-1)printf("%d ",ans[i]);printf("%d\n",ans[tot]);tot=0;
	int d=rd();
	del(d);
	dfs(0);memset(vis,0,sizeof(vis));
	fep(i,1,tot-1)printf("%d ",ans[i]);printf("%d\n",ans[tot]);tot=0;
	l=-1;r=0;
	bfs();memset(vis,0,sizeof(vis));
	fep(i,1,tot-1)printf("%d ",ans[i]);printf("%d\n",ans[tot]);
} 

