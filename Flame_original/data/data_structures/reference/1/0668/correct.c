#include<stdio.h>
int k;
int tmp[10];
int done[10];
void digui(int a[],int n){
	if(n>k-1){
		int i;
		for(i=0;i<k;i++)
			printf("%d ",tmp[i]);
		printf("\n");
	}else{
		int i; 
		for(i=0;i<k;i++){
			tmp[n]=a[i];
			if(done[i]==0){
				done[i]=1;
				digui(a,n+1);
				done[i]=0;
			}
		}
	}
}
int main(){
	scanf("%d",&k);
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int i;
	for(i=0;i<k;i++){
		tmp[i]=0;
		done[i]=0;
	}
	digui(a,0);
	return 0;
}



