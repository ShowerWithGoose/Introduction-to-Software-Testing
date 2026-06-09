#include<stdio.h>

int gd[15],a[15],n;//gd判断该数是否用过
void pt(){
	for(int i=1;i<=n;i++) printf("%d ",a[i]);//
	printf("\n"); 
}
void dfs(int dee){//Depth First Search
	if(dee>n){
		pt();return;
	}
	for(int i=1;i<=n;i++){
		if(!gd[i]){
			gd[i]=1;
			a[dee]=i;
			dfs(dee+1);
			gd[i]=0;
		}
	}
	return;
}
int main(){
	scanf("%d",&n);
	dfs(1);
	return 0;
}



