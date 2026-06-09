#include<stdio.h>
int a[105];
int main(){
	int i=0,n,k;
	do{
		scanf("%d",&n);
		switch(n){
			case 1:
				scanf("%d",&k);
				if(i<99){
					i++;
					a[i]=k;
					break;
				}else{
					printf("error ");
					break;
				}
			case 0:
				if(i==0){
					printf("error ");
					break;
				}else{
					printf("%d ",a[i]);
					i--;
					break;
				}
		}
	}while(n!=-1);
	return 0;
} 

