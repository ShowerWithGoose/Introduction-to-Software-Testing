#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int output[12],judge[12];
void dfsA(int a[],int b[],int n,int depth){
	int i;
	if(depth==n+1){
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	else{
		for(i=1;i<=n;i++){
			if(b[i]==0){
				b[i]=1;
				a[depth]=i;
				dfsA(a,b,n,depth+1);
				b[i]=0;
			}
		}
	}
} 
int main()
{
	int num;
	scanf("%d",&num);
	dfsA(output,judge,num,1);
	return 0;
}



