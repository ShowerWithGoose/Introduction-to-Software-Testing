#include<stdio.h>
#include<string.h>

int n;
int a[11]={};

void print_();
void func(int*,int);
void change(int*,int);
void fchange(int*,int);

int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		a[i]=i+1;
	}
	func(a,n);
	return 0;
}
void func(int *a,int n1){
	if(n1==1){
		print_();
	}
	
	for(int j=0;j<n1;j++){
		change(a,j);
		func(a+1,n1-1);
		fchange(a,j);
	}
}
void print_(){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
void change(int *a,int i){
	for(int j=0;j<=i;j++){
		int temp=*a;
		*a=*(a+j);
		*(a+j)=temp;
	}
	
}
void fchange(int *a,int i){
	for(int j=i;j>=0;j--){
		int temp=*a;
		*a=*(a+j);
		*(a+j)=temp;
	}
}



