//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define eps 1e-6
int N;
int qu[15],shu[15];
void dfs(int a){
	int i;
	if(a==N+1){
		for(i=1;i<a;i++) printf("%d ",qu[i]);
		printf("\n");
		return;
	}
	
	for(i=1;i<=N;i++){
		if(shu[i]==0){
			shu[i]=1;
			qu[a]=i;
			dfs(a+1);
			shu[i]=0;
		}
	}
}
int main(){
	
	scanf("%d",&N);
	dfs(1); 
	return 0;
}



