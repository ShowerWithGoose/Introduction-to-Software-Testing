#include <stdio.h>
int arry[15];
void rank(int arry[],int,int);
void swap(int arry[],int,int);
void swapback(int arry[],int,int);
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		arry[i]=i+1;
	}
	rank(arry,0,N-1);
	return 0;
}
rank(int arry[],int p,int q)
{
	if(p==q){
		for(int i=0;i<=q;i++){
			printf("%d ",arry[i]);
		}
		printf("\n");
	}else{
		for(int i=p;i<=q;i++){
			swap(arry,p,i);
	    	rank(arry,p+1,q );
	    	swapback(arry,p,i);
		}
	}
}
swap(int arry[],int m,int n)
{
	int temp=arry[n];
	for(int i=n;i>=m+1;i--){
		arry[i]=arry[i-1];
	}
	arry[m]=temp;
}
swapback(int arry[],int m,int n)
{
	int temp=arry[m];
	for(int i=m;i<=n-1;i++){
		arry[i]=arry[i+1];
	}
	arry[n]=temp;
}



