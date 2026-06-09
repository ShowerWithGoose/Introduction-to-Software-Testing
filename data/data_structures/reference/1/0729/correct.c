#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
	int n;
	int a[11]={0};
	int jud[11]={0};
int main()
{
	
	scanf("%d",&n);
	deepsear(1);
	return 0;
}

void deepsear(int l){
	//l = layer
	if(l==n+1) {
		for(int i = 1; i <= n; i++){
		printf("%d ",a[i]);
//		jud[i]==0;
		}
		printf("\n");
	}
	
	else{
		for(int i = 1;i<=n;i++){
			if(judge(i)==1) {
				a[l]=i;
				jud[i]=1;
				deepsear(l+1);
				jud[i]=0;
			}
		}
	}
	
}
int judge(int j){
	int flag=1;
	if(jud[j]==1) {
		flag=0;
	}
	return flag;
}

