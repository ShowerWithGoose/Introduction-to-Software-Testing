#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int b[11];
int a[15];
int n,i,j;
void temp(){
	int m,min=11,k,i=0,p;
	for(i=n-1;i>0;i--){
		if(a[i]>a[i-1]){
		break;
	}
	}
	m=i-1;
	for(i=m+1;i<n;i++){
		if(a[i]<min&&a[i]>a[m]){
			min=a[i];
			k=i;
		}
	}
	int tempp;
	tempp=a[m];
	a[m]=a[k];
	a[k]=tempp;
	for(int l=m+1,p=n-1;p>l;l++,p--){
		tempp=a[p];
		a[p]=a[l];
		a[l]=tempp;
	}
}
void print(){
    int i=0;
    for(i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[i]);
}
int main(){
	int i;
	b[0]=1;
	for(i=1;i<10;i++){
		b[i]=i*b[i-1];
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		a[i]=i+1;
	}
	print();
	for(int r=1;r<b[n];r++)
	{
		temp();
		print();
	}
	return 0;
}

