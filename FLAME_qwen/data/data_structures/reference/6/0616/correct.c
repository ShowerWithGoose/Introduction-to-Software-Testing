#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int stack[99];
int top=-1;
int main(){
	int a,n;
	while(scanf("%d",&n)!=EOF){
		if(n==1){
			scanf("%d",&a);
			if(top==99){
				printf("error ");
			}
			else top++,stack[top]=a;
			
		}
		else if(n==0){
			if(top==-1){
				printf("error ");
			}
			else 
			printf("%d ",stack[top]),top--; 
		}
		else if(n==-1)
		break;
	}
	
	return 0;
} 

