#include<stdio.h>
#include<string.h>

int flag[100],a[11],m;

void dfs(int n){
	if(n>m){
		for(int i=1;i<=m;i++)
			printf("%d ",a[i]);
		puts("");
		return ;
	}
	else{
		for(int i=1;i<=m;i++){
			if(flag[i]==0){
				flag[i]=1;
				a[n]=i;
				dfs(n+1);
				flag[i]=0;
			}
		}
	}
} 
int main(){
	scanf("%d",&m);
	dfs(1);
	return 0;
}



