#include<stdio.h>

int read(){
	int s=0,f=1;char t=getchar();
	while('0'>t||t>'9'){
		if(t=='-')f=-1;
		t=getchar();
	}
	while('0'<=t&&t<='9'){
		s=(s<<1)+(s<<3)+(t-'0');
		t=getchar();
	}
	return s*f;
}

typedef struct{
	int lc,rc,val;
} tree;
tree t[1000];
int tot;

void Ins(int* x,int v){
	if((*x)==0){(*x)=++tot;t[*x].val=v;return;}
	if(t[*x].val>v)Ins(&t[*x].lc,v);
	else Ins(&t[*x].rc,v);
} 

int rt;

void Dfs(int u,int d){
	if(t[u].lc|t[u].rc){
		if(t[u].lc)Dfs(t[u].lc,d+1);
		if(t[u].rc)Dfs(t[u].rc,d+1);
	}else{
		printf("%d %d\n",t[u].val,d);
	}
}

int main(){
	int n=read();
	for(int i=1;i<=n;i++)
		Ins(&rt,read());
	Dfs(rt,1);
	return 0;
}
/*
13
50 38 30 64 58 40 10 73 70 50 60 100 35
*/

