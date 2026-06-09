#include<stdio.h>
#define MAXSIZE 100
int main(){
	int command,a,top=-1,stack[MAXSIZE];
	while(scanf("%d",&command)!=EOF){
		switch(command){
			case -1:
				return 0;
			case 0:
				if(top!=-1){
					printf("%d ",stack[top--]);
				}
				else{
					printf("error ");
				}
				break;
			case 1:
				if(top!=MAXSIZE-1){
					scanf("%d",&a);
					stack[++top]=a;
				}
				else{
					printf("error ");
				}
				break;
		}
	}
	return 0;
} 

