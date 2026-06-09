#include<stdio.h>
void sift(int a[],int low,int high){
	int temp;
	int i,j;
	i=low,j=high;
	if(low<high){
		temp=a[i];
		while(i!=j){
		while(i<j&&a[j]>temp) j--;
		a[i]=a[j];
		while(i<j&&a[i]<temp) i++;
		a[j]=a[i];
	}
	a[i]=temp;
	sift(a,low,i-1);
	sift(a,i+1,high);
	}
} 
void P(int L[],int k,int m){
	if(k==m){ 
		for(int i=0;i<=m;i++){
			printf("%d ",L[i]);
		}
		printf("\n");
	}
	else{
		for(int i=k;i<=m;i++){
			int temp;
			temp=L[i];
			L[i]=L[k];
			L[k]=temp;
			sift(L,k+1,m); 
			P(L,k+1,m);
			sift(L,k,m);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	P(a,0,n-1);
}

