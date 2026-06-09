#include<stdio.h>
int vis[110],ans[15];

void dfs(int now, int tot){
	//printf("now=%d\n",now);
	if(now==tot){
		int i;
		for(i=1; i<=tot; i++)
			printf("%d ",ans[i]);
		puts("");
		return;
	}
	int i;
	for(i=1; i<=tot; i++){
		if(!vis[i]){
			vis[i]=1;
			ans[now+1]=i;
			dfs(now+1,tot);
			vis[i]=0;
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	dfs(0,n);
	return 0;
}


