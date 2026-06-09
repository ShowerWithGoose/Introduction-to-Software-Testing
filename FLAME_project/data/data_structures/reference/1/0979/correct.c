#include <stdio.h>
void prt();
void dfs(int);
int n, used[10]={'0'}, result[20];
int main(){
	scanf("%d", &n);
	dfs(1);
	return 0;
}
void prt(){
	int i;
	for(i=0; i<n; i++){
		printf("%d",result[i+1]);
		if((i+1)%n!=0){
			printf(" ");
		}
		else printf("\n");
	}
}
void dfs(int m){
	if(m==n+1){
		prt();
	}
	else {
		int i;
		for(i=1; i<=n; i++){
		if (used[i]==0){
			result[m]=i;
			used[i]=1;
			dfs(m+1);
			used[i]=0;
			}
		}
	}
}

