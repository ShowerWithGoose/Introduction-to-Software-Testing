#include<stdio.h>
//#include<string.h>#include<stdlib.h>
void dfs(int f);
int n;
int flag[15]={0},list[15];
int main(){
scanf("%d",&n);
dfs(0);
return 0;
}
void dfs(int f){
	if(f == n){
		for(int i=0;i<n;i++){
			printf("%d ",list[i]);
		}
		printf("\n");
	}
	else{
		for(int i = 1;i<=n;i++){
			if(flag[i] == 0){
				flag[i] = 1;
				list[f] = i;
				dfs(f+1);
				flag[i] = 0;
			}
		}
	}
}



