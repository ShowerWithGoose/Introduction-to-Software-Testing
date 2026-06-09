#include<stdio.h>
int a[101],b[101],n=0,m=0,i=0;
int main(){
	for(;;){
		scanf("%d",&a[n]);
		if(a[n]==-1){
			break;
		}
		if(a[n]==0){
			if(n==0) printf("error ");
			else{
				n--;
				printf("%d ",a[n]);
				
			}
		}
		if(a[n]==1){
			if(n==100) printf("error");
			
			else{
			scanf("%d ",&a[n]);n++;
			}
			
		}
	}

	return 0;
}

