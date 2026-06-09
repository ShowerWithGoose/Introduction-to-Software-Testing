#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
#define N 100010

int v[N],e[N],ne[N],idx;
int st[N];
int q[N];
int ver,edg,cnt;
int ans[N];
void insert(int a,int b)
{
	int i=v[a],q;
	e[idx]=b;
	if(v[a]==-1) v[a]=idx;
	else{
		if(e[i]>b){
			ne[idx]=v[a];
			v[a]=idx;
		} 
		else{
			while(ne[i]!=-1&&e[ne[i]]<b) i=ne[i];
			ne[idx]=ne[i];
			ne[i]=idx;
		}
	}
	idx++;
}
void dfs(int x)
{
	st[x]=1;
	ans[cnt]=x;
	cnt++;
	int i;
	for(i=v[x];i!=-1;i=ne[i]){
		int j=e[i];
		if(!st[j]) dfs(j);
	}
}
void bfs(int x)
{
	int hh=0,tt=-1;
	int f,i,j;
	
	st[0]=1;
	tt++;
	q[tt]=0;
	
	while(hh<=tt){
		f=q[hh];
		printf("%d ",f);
		hh++;
		
		for(i=v[f];i!=-1;i=ne[i]){
			j=e[i];
			if(!st[j]){
				st[j]=1;
				tt++;
				q[tt]=j;
			}
		}
	}
	putchar('\n');
}

int main(){
	memset(v,-1,sizeof(v));
	memset(ne,-1,sizeof(ne));
	scanf("%d%d",&ver,&edg);
	int i,a,b,dele;
	for(i=0;i<edg;i++){
		scanf("%d%d",&a,&b);
		insert(a,b);
		insert(b,a);
	}
	scanf("%d",&dele);
	
	dfs(0);
	for(i=0;i<ver;i++) printf("%d ",ans[i]);
	putchar('\n');
	memset(st,0,sizeof(st));
	memset(ans,0,sizeof(ans));
	cnt=0;
	
	bfs(0);
	memset(st,0,sizeof(st));
	
	
	st[dele]=1;
	dfs(0);
	for(i=0;i<ver-1;i++) printf("%d ",ans[i]);
	putchar('\n');
	memset(st,0,sizeof(st));
	
	st[dele]=1;
	bfs(0);
	
	return 0;
}

