#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <ctype.h>

void dfs(int a[1000],int yong[1000],int n,int depth) 
{
	int i;
	
	if(depth==n){
		for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	
	for(i=1;i<=n;i++){
		if(yong[i]==0){
			yong[i]=1;  
			a[depth]=i;
			dfs(a,yong,n,depth+1);
			yong[i]=0;
		}
	}
}

int main(){	
	int n;
	scanf("%d",&n);
	
	int a[1000]={0};
	int yong[1000]={0};

	dfs(a,yong,n,0);
	return 0;
}




