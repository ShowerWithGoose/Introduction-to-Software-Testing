#include<stdio.h>

int jc=1,N,a[13],i,j;

void find(){
	for(i=N-1;a[i-1]>a[i]&&i-1>=0;i--){
	}
	int h_l=i,k=i-1;
	for(j=i;j<N;j++){
		if(a[k]<a[j]&&a[j]<a[h_l])
		h_l=j;
	}
	int tep;
	tep=a[h_l];
	a[h_l]=a[k];
	a[k]=tep;
	for(i=k+1,j=N-1;i<j;i++,j--){
		tep=a[j];
		a[j]=a[i];
		a[i]=tep;
	}
}

int main(){
	int o;
	scanf("%d",&N);
	
	for(i=1;i<=N;i++){
		a[i-1]=i;
		jc=jc*i;
	}
	for(j=0;j<N-1;j++)
		printf("%d ",a[j]);
		printf("%d\n",a[j]);
	for(o=0;o<jc-1;o++){
		find();
		for(j=0;j<N-1;j++)
		printf("%d ",a[j]);
		printf("%d\n",a[j]);
	}
	return 0;
}
 

