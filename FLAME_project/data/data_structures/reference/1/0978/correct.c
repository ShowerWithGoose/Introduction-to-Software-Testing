#include<stdio.h>
#include<string.h>
void arrange(int m, int n, int a[], int temp[]){
	int j;
	if(m>=n){
		for(j=0;j<n-1;j++){
			printf("%d ",a[j]);
		}
		printf("%d\n",a[j]);
	}
	else{
		for(j=0;j<n;j++){
			if(temp[j]==0){
				temp[j]=1;
				a[m]=j+1;
				arrange(m+1,n,a,temp);
				temp[j]=0;
			}
		}
	}
}
int main(){
	int n,i,a[15],temp[15];
	scanf("%d",&n);
	for (i=0;i<n;i++){
		temp[i]=0;
	} 
	arrange(0,n,a,temp);
	return 0;
}



