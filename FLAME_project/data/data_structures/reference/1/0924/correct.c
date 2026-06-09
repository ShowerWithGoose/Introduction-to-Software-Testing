#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#include<math.h>
int n,  num[20];
bool used[20];
void dfs(int x){
	int i; 
	if(x>n){
		for(i=1;i<=n;i++)printf("%d ", num[i]);
		printf("\n");
	return;
	}
	for(i=1;i<=n;i++)if(!used[i]){
		num[x]=i;
		used[i]=true;
		dfs(x+1);
		num[x]=0;
		used[i]=false;
	}	
	
}
int main(){
	int i;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	used[i]=false;
	dfs(1);
	return 0;
}

