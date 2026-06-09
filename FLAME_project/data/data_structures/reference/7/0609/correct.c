#include<stdio.h>
typedef long long ll;
ll max(ll a,ll b){
   return a>b?a:b;
}
ll min(ll a,ll b){
   return a<b?a:b;
}
int tr[100010],lc[100010],rc[100010];
int n,cnt;
void insert(int u,int a){
	if (cnt==0){
		tr[++cnt]=a;
		return;
	}
	if (tr[u]>a){
		if (lc[u]==0){
			lc[u]=++cnt;
			tr[cnt]=a;
		}else{
			insert(lc[u],a);
		}
		return;
	}else{
		if (rc[u]==0){
			rc[u]=++cnt;
			tr[cnt]=a;
		}else{
			insert(rc[u],a);
		}
		return;
	}
}
void dfs(int u,int h){
	int flag=0;
	if (lc[u]!=0){
		flag=1;
		dfs(lc[u],h+1);
	}
	if (rc[u]!=0){
		flag=1;
		dfs(rc[u],h+1);
	}
	if (!flag){
		printf("%d %d\n",tr[u],h);
	}
	return;
}
int main(){
	scanf ("%d",&n);
	for (int i=1;i<=n;i++){
		int a;
		scanf ("%d",&a);
		insert(1,a);
	}
	dfs(1,1);
	return 0;
}

