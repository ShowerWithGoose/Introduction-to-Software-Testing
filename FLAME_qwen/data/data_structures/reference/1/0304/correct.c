#include <stdio.h>
void f(int n,int k,int *a){
	int i,j;
	for(i=n;i<=k;i++){
		if(n==k){
			for(i=1;i<=k;i++){
				printf("%d ",a[i]);
			}
			printf("\n");
		}
		else{
			int temp;
			for(i=n;i<=k;i++){
				temp=a[i];
				for(j=i;j>n;j--){
					a[j]=a[j-1];
				}
				a[n]=temp;
				f(n+1,k,a);
				temp=a[n];
				for(j=n;j<i;j++){
					a[j]=a[j+1];
				}
				a[i]=temp;
			}
		}
	}
} 
int main(){
	int n,k,a[11];
	scanf("%d",&k);
	n=1;
	int i;
	for(i=1;i<=k;i++){
		a[i]=i;
	}
	f(n,k,a);
	return 0;
}

