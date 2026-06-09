#include<stdio.h>
#include<string.h>
int N;
void print(int a[],int n,int order){
	int i=0,j=0;
	if(n==0){
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				if(a[j]==i){
					printf("%d ",j);
				}
			}
		}
		printf("\n");
		return;
	}else{
		for(i=1;i<=N;i++){
			if(a[i]==0){
				a[i]=order;
				print(a,n-1,order+1);
				a[i]=0;
			}
		}
		return;
	}
}
int main(){
	int a[100],i=0;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		a[i]=0;
	}
	print(a,N,1);
	return 0;
}



