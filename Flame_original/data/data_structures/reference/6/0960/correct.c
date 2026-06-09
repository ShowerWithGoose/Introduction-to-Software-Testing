#include<stdio.h>
#include<string.h> 
int l=0;
int push(int a[], int n){
	int i;

	if(l==100){
		printf("error ");return 0;
	}
	for(i=l;i>0;i--){
		a[i]=a[i-1];
	}
  a[0]=n;	
  l++;
  return 0;
}
int pop(int a[]){
	int i;

	if(l==0){
		printf("error ");return 0;
	}
	printf("%d ",a[0]);
	for(i=0;i<l;i++){
		a[i]=a[i+1];
	}
	a[i]=0;
	l--;
	return 0;
}
int main(){
	int a[100]={0};
	int k=0;
	int n;
	while(scanf("%d",&k)!=EOF){
		
		if(k==1){
			scanf("%d",&n);push(a,n);
		}
		else if(k==0) pop(a);
	}
	return 0;
}

