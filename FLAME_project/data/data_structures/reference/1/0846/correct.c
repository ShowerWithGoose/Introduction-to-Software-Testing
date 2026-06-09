#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
int a[20]={0},N;
void p(   void     );//按格式打印 
void f(   int n     );//递归 
void swap(int a,int b);
int main(int argc, char *argv[]) {
	int k;
	scanf("%d",&N);
	for(k=1;k<=N;k++)a[k-1]=k;
	f(1);
	return 0;
}
void p(){
	int j;
	for(j=0;j<=N-1;j++){
		if(j==N-1)printf("%d\n",a[j]);
		else printf("%d ",a[j]);		
	}
}
void f(int n){
	int i;
	if(N==1){
	printf("1\n");return;}
	if(n==N-1){
		p();  
		swap(n,N);
		p();
		swap(n,N);
		return;
	}
	else {
			f(n+1);	
		for(i=n+1;i<=N;i++){
			swap(n,i);
			f(n+1);	
		}
		for(i--;i>=n+1;i--)swap(n,i);
	}	
}
void swap(int p,int q){
	int w;
	w=a[p-1];
	a[p-1]=a[q-1];
	a[q-1]=w;
}


