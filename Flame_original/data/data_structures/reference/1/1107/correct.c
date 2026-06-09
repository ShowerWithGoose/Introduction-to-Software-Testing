#include<stdio.h>
int a[12],b[12];
int n;
void travel(int i){
	
	if(i>0)dfs(i);
}
void t(int c){
	printf("%d ",c);
}
void dfs(int x){
	int i;
	if(x==n+1){
		for(int j=1;j<=n;j++){
			t(a[j]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++){
		if(b[i]==0){
		a[x]=i;
		b[i]=1;
		travel(x+1);
		b[i]=0;        }
		
	}
	return;
}
int main(){
    scanf("%d",&n);
	travel(1);
	return 0;
}

