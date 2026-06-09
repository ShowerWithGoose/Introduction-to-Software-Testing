#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int a[15],b[15],n;
void dfs(int m){
	int i;
	if(m==n+1){
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++){
		if(b[i]==0){
			a[m]=i;
			b[i]=1;
			dfs(m+1);
			b[i]=0;
		}
	}
	return ;
}
int main(){
	scanf("%d",&n);
	dfs(1);
	return 0;
}




