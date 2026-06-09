#include<stdio.h>
#include<stdlib.h>

int seq[15];
int vis[15];
int rest[5];
int n;

void Dfs(int dep){
	if(dep==n-5){
		int tot=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				rest[tot]=i;
				tot++;
			}
		}
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[1],rest[2],rest[3],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[1],rest[2],rest[4],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[1],rest[3],rest[2],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[1],rest[3],rest[4],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[1],rest[4],rest[2],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[1],rest[4],rest[3],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[2],rest[1],rest[3],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[2],rest[1],rest[4],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[2],rest[3],rest[1],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[2],rest[3],rest[4],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[2],rest[4],rest[1],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[2],rest[4],rest[3],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[3],rest[1],rest[2],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[3],rest[1],rest[4],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[3],rest[2],rest[1],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[3],rest[2],rest[4],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[3],rest[4],rest[1],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[3],rest[4],rest[2],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[4],rest[1],rest[2],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[4],rest[1],rest[3],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[4],rest[2],rest[1],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[4],rest[2],rest[3],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[4],rest[3],rest[1],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[0],rest[4],rest[3],rest[2],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[0],rest[2],rest[3],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[0],rest[2],rest[4],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[0],rest[3],rest[2],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[0],rest[3],rest[4],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[0],rest[4],rest[2],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[0],rest[4],rest[3],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[2],rest[0],rest[3],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[2],rest[0],rest[4],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[2],rest[3],rest[0],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[2],rest[3],rest[4],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[2],rest[4],rest[0],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[2],rest[4],rest[3],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[3],rest[0],rest[2],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[3],rest[0],rest[4],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[3],rest[2],rest[0],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[3],rest[2],rest[4],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[3],rest[4],rest[0],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[3],rest[4],rest[2],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[4],rest[0],rest[2],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[4],rest[0],rest[3],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[4],rest[2],rest[0],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[4],rest[2],rest[3],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[4],rest[3],rest[0],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[1],rest[4],rest[3],rest[2],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[0],rest[1],rest[3],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[0],rest[1],rest[4],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[0],rest[3],rest[1],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[0],rest[3],rest[4],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[0],rest[4],rest[1],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[0],rest[4],rest[3],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[1],rest[0],rest[3],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[1],rest[0],rest[4],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[1],rest[3],rest[0],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[1],rest[3],rest[4],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[1],rest[4],rest[0],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[1],rest[4],rest[3],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[3],rest[0],rest[1],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[3],rest[0],rest[4],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[3],rest[1],rest[0],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[3],rest[1],rest[4],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[3],rest[4],rest[0],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[3],rest[4],rest[1],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[4],rest[0],rest[1],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[4],rest[0],rest[3],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[4],rest[1],rest[0],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[4],rest[1],rest[3],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[4],rest[3],rest[0],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[2],rest[4],rest[3],rest[1],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[0],rest[1],rest[2],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[0],rest[1],rest[4],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[0],rest[2],rest[1],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[0],rest[2],rest[4],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[0],rest[4],rest[1],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[0],rest[4],rest[2],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[1],rest[0],rest[2],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[1],rest[0],rest[4],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[1],rest[2],rest[0],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[1],rest[2],rest[4],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[1],rest[4],rest[0],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[1],rest[4],rest[2],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[2],rest[0],rest[1],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[2],rest[0],rest[4],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[2],rest[1],rest[0],rest[4]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[2],rest[1],rest[4],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[2],rest[4],rest[0],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[2],rest[4],rest[1],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[4],rest[0],rest[1],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[4],rest[0],rest[2],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[4],rest[1],rest[0],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[4],rest[1],rest[2],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[4],rest[2],rest[0],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[3],rest[4],rest[2],rest[1],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[0],rest[1],rest[2],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[0],rest[1],rest[3],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[0],rest[2],rest[1],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[0],rest[2],rest[3],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[0],rest[3],rest[1],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[0],rest[3],rest[2],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[1],rest[0],rest[2],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[1],rest[0],rest[3],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[1],rest[2],rest[0],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[1],rest[2],rest[3],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[1],rest[3],rest[0],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[1],rest[3],rest[2],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[2],rest[0],rest[1],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[2],rest[0],rest[3],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[2],rest[1],rest[0],rest[3]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[2],rest[1],rest[3],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[2],rest[3],rest[0],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[2],rest[3],rest[1],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[3],rest[0],rest[1],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[3],rest[0],rest[2],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[3],rest[1],rest[0],rest[2]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[3],rest[1],rest[2],rest[0]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[3],rest[2],rest[0],rest[1]);
		for(int i=0;i<n-5;i++){printf("%d ",seq[i]);}printf("%d %d %d %d %d \n",rest[4],rest[3],rest[2],rest[1],rest[0]);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			seq[dep]=i;
			Dfs(dep+1);
			vis[i]=0;
		}
	}
}

void NormalDfs(int dep){
	if(dep==n){
		for(int i=0;i<n;i++){
			printf("%d ",seq[i]);
		}printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			seq[dep]=i;
			NormalDfs(dep+1);
			vis[i]=0;
		}
	}
}


int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	
	scanf("%d",&n);
	if(n<5)NormalDfs(0);
	else Dfs(0);
	return 0;
}


