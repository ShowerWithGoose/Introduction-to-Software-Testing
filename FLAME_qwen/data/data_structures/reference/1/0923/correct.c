#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
int n,num[20];
bool used[20];
void dfs(int x){
	if(x>n){
		for(int i=1;i<=n;i++){
		    printf("%d ",num[i]);
		}
    printf("\n");
	return;	
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			num[x]=i;
			used[i]=true;
			dfs(x+1);
			num[x]=0;
			used[i]=false;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)used[i]=false;
	dfs(1);
	return 0;
}


