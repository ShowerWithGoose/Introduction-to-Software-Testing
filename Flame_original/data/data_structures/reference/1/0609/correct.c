#include<stdio.h>

typedef long long ll;

ll max(ll a,ll b){
   return a>b?a:b;
}
ll min(ll a,ll b){
   return a<b?a:b;
}
int a[100];
int vis[100];
int n;
void dfs (int x){
	if (x==n+1){
		for (int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			vis[i]=1;
			a[x]=i;
			dfs (x+1);
			vis[i]=0;
		}
	}
	return;
}

int main(){
	scanf ("%d",&n);
	dfs (1);
	return 0;
}

