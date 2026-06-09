#include<stdio.h>

int used[15]={};
int stk[15]={0};
int a[15]={0};
int n;
int top=1;

void dfs(int);

int main(){
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a[i]=i;
//		printf("%d",a[i]);
	}
	dfs(1);
	
	return 0;
}

void dfs(int dph){
	int i,j;
	if(dph==n+1){
		for(j=1;j<=n;j++){
			printf("%d ",stk[j]);
					
		}
		printf("\n");	
		return;
	}
	else{
		for(i=1;i<=n;i++){
			if(used[i]==0){
				used[i]=1;
				stk[top++]=a[i];
				dfs(dph+1);
				top--;
				used[i]=0;	
			}
		}
	}
}



