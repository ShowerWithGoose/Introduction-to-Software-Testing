#include<stdio.h>
int i,j,k,l,op,n,a[11],min,temp;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a[i]=i;
		printf("%d ",i);
	}
	printf("\n");
	while(1){
		for(i=1,op=0;i<n;i++){
			if(a[i]<a[i+1]){
				op=1;
				k=i;
			}
		}
		if(op==0)break;
		for(i=k+1;i<=n;i++){
			min=10;
			if(a[i]>a[k]&&a[i]<min){
				min=a[i];
				l=i;
			}
		}
		temp=a[l];
		a[l]=a[k];
		a[k]=temp;
		for(i=k+1,j=n;i<=j;i++,j--){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		for(i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
	}
	printf("\n");
	for(i=10;i<=n;i++)printf("%d ",a[i]);
	return 0;
}
