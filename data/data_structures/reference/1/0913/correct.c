#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(){
	int n;
	scanf("%d",&n);
	int a[12]={1,2,3,4,5,6,7,8,9,10},key=1,i,l,j,k,m;
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	while(key==1){
		for(j=n-2;j>=0;j--){
			if(a[j]<a[j+1]){
				break;
			}
		}
		if(j==-1){
			key=0;
			break;
		}
		for(i=n-1;i>j;i--){
			if(a[i]>a[j]){
				m=a[i];
				k=i;
				break;
			}
		}
		for(;i>j;i--){
			if(a[i]<m&&a[i]>a[j]){
				m=a[i];
				k=i;
			}
		}
		m=a[j];
		a[j]=a[k];
		a[k]=m;
		for(i=j+1,l=n-1;i<l;i++,l--){
			m=a[i];
			a[i]=a[l];
			a[l]=m;
		}
		for(i=0;i<=n-1;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	
	return 0;
}


