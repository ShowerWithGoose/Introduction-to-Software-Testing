#include<stdio.h>
int a[20]={};

void putin(int x,int y){
	int i;
	int tem=a[x];
	for(i=x;i>y;i--)  a[i]=a[i-1];
	a[y]=tem;
}

void putout(int x,int y){
	int i;
	int tem=a[x];
	for(i=x;i<y;i++)  a[i]=a[i+1];
	a[y]=tem;
}	

void arrange(int N,int n){
	int i,j;
	if(n<N){
		for(i=n;i<=N;i++){
			if(i!=n)  putin(i,n);
			arrange(N,n+1);
			if(i!=n)  putout(n,i);
		}
	}	
	else{
		for(j=1;j<=N;j++)
			printf("%d ",a[j]);
		printf("\n");
	}	
}

int main(){
	int N;
	int i;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		a[i]=i;
	arrange(N,1);
	return 0;
}

