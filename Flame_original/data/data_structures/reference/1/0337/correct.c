#include <stdio.h>

#define MAX 11

int a[MAX],book[MAX] = {0};

int N = 0;

void dfs(int step){
	
	int i = 1;
	if(step==N+1){
		for(i=1;i<=N;i++)	
			printf("%d ",a[i]);
		printf("\n");
		return;
	} 
	
	for(;i<=N;i++){
		if(book[i]==0){
			a[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;//²»Àí½â£¬ 
		}	
	}
	
}




int main(){
	
	scanf("%d",&N);
	dfs(1);
	
	return 0;	
}	

