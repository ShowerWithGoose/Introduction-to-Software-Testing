#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define LL  long long
#define ULL  unsigned long long

void swap(int a[],int m,int n){
	int tmp=a[m];
	a[m]=a[n];
	a[n]=tmp;
	return;
}
int main(void){
	int n;
	scanf("%d",&n);
	int a[15]={0,1,2,3,4,5,6,7,8,9,10};
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");

	while(1){
		int i;
		for(i=n-1;i>0;i--){
			if(a[i]<a[i+1]){
				int min=20,mini;
				for(int j=i+1;j<=n;j++){
					if(a[j]>a[i]&&a[j]-a[i]<min){
						min=a[j]-a[i];
						mini=j;
					}
				}
				swap(a,i,mini);
				for(int j=i+1,k=n;j<k;j++,k--){
					swap(a,j,k);
				}
				for(int i=1;i<=n;i++){
					printf("%d ",a[i]);
				}
				printf("\n");
				break;
			}
		}
		if(!i)break;
	}
	return 0;
}
