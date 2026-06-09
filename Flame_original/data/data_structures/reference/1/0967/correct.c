#include <stdio.h>
int main()
{
	int num[10]={0},i,m,n,j=0,k=1,sum=0,cj=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){ 
		num[i]=i;
		j+=num[i];
		k*=(num[i]+1);
	}
	while(num[0]!=10){
		sum=0,cj=1;
		for(i=0;i<n;i++){ 
			sum+=num[i];
			cj*=(num[i]+1);
		}
		if(sum==j&&cj==k){
			for(i=0;i<n;i++){ 
				printf("%d ",num[i]+1);
			}
			printf("\n");
		}
		num[n-1]++;
		for(i=n-1;i>0;i--){
			if(num[i]==10){
				num[i]=0;
				num[i-1]++;
			}
		}
	}
	return 0;
}



