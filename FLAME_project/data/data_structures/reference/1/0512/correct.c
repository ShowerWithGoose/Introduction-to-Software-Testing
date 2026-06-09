#include<stdio.h>
int main(){
	int n,N,i,j,k,low,temp,keep,L;
	int a[10]; 
	scanf("%d",&n);
	for(i=0;i<n;i++){
		a[i]=i+1;
	}
	for(N=1,i=1;i<=n;i++){
		N*=i;
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=1;i<N;i++){
		for(j=n-2;j>=0;j--){
			if(a[j]<a[j+1])
			break;
		}
		k=j;
		low=j+1;
		for(j=k+1;j<n;j++){
			if(a[j]<a[low]&&a[j]>a[k])
			low=j;
		}
		keep=a[low];
		a[low]=a[k];
		a[k]=keep;
		for(j=k+1,L=n-1;j<L;j++,L--){
			keep=a[j];
			a[j]=a[L];
			a[L]=keep;
		}
		for(j=0;j<n;j++){
			printf("%d ",a[j]);
		}
		printf("\n");
	}
	return 0;
}

