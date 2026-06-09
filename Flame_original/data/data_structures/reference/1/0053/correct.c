#include<stdio.h>
int a[10][10]={1,2,3,4,5,6,7,8,9,10};
int N;
int b[10];
void arr(int l){
	int i,j,k;
	if(l>1){
		for(i=0;i<l;i++){
			b[N-l]=a[N-l][i];
			for(j=0,k=0;j<l;j++){
				if(j!=i){
					a[N-l+1][k]=a[N-l][j];
					k++;
				}
			}
			arr(l-1);
		}
	}else{
		b[N-l]=a[N-l][0];
		for(i=0;i<N;i++){
			printf("%d ",b[i]);
		}
		printf("\n");
	}
}
int main(){
	scanf("%d",&N);
	arr(N);
}



