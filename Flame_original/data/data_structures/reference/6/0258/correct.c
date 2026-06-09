#include<stdio.h>
#include<stdlib.h>
int main(){
	int STACK[100];
	int order,i=0;
	while(scanf("%d",&order)!=EOF){
		switch(order){
			case 0:
				if(i<=0) printf("error ");
				else{
					printf("%d ",STACK[i-1]);
					i--;
				}
				break;
			case 1:
				if(i>=100) printf("error ");
				else{
					scanf("%d ",&STACK[i]);
					i++;
				}
			break;
			default:
				return 0;
		}
	}
} 

