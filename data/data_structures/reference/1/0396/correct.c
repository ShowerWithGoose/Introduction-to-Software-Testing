#include<stdio.h>

void A(int ,int ,int [],int []);

int a[100],b[100];

int main(){
	int n;
	scanf("%d",&n);
	A(0,n,a,b);
	return 0;
}

void A(int m,int n,int a[],int b[])
{
	int i;
	if(m==n){
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	else{
		for(i=0;i<n;i++){
			if(b[i]==0){
				b[i]=1;
				a[m]=i+1;
				A(m+1,n,a,b);
				b[i]=0;
			}
		}
	}
}



