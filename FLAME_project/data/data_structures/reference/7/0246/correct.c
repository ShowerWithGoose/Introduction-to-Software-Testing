#include<stdio.h>
#define N 505
int n,b[N],root,cnt;
void init(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
}
struct node{
	int son[2],val;
}a[N];
int insert(int k,int v){
	if (!k) {
		k=++cnt; a[k].val=v; return k;
	}
	if (a[k].val>v) a[k].son[0]=insert(a[k].son[0],v);
		else a[k].son[1]=insert(a[k].son[1],v);
	return k; 
}
void dfs(int k,int dep){
	if (!k) return;
	dfs(a[k].son[0],dep+1);
//	write(a[k].val); putchar(' '); writeln(dep);
	if (!(a[k].son[0]+a[k].son[1]))	printf("%d %d\n",a[k].val,dep);
	dfs(a[k].son[1],dep+1);
}
void solve(){
	for (int i=1;i<=n;i++){
		root=insert(root,b[i]);
	}
	dfs(root,1);
}
int main(){
	init(); solve();
	return 0;
}

