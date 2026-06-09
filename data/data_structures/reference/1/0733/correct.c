#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int arr[15],vis[15],stc[15];
int top,n;
void init(){
	int i;
	for(i=0;i<15;i++) vis[i]=1;
}
void dfs(int itn){
	int i;
	if(itn==n){
		for(i=0;i<n;i++){
			printf("%d ",stc[i]);
		}
		printf("\n");
		return;
	}
	for(i=0;i<n;i++){
		if(vis[i]==1){
			vis[i]=0;
			stc[top++]=arr[i];
			dfs(itn+1);
			top--;
			vis[i]=1;
		}
	}
}
int main() {
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++) arr[i]=i+1;
	init();
	top=0;
	dfs(0);
	return 0;
}




