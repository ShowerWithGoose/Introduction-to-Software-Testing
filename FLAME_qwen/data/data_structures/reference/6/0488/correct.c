#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100
int STACK[MAX-1];
int top=-1;

int main(){
	int x;
	scanf("%d",&x);
	while(x!=-1){
		if(x==1){	/*--------入栈---------*/
			scanf("%d",&x);
			if(top==MAX){
				printf("error ");
			}else{
				STACK[++top]=x;
			}
		}else{		/*--------出栈---------*/
			if(top==-1){
				printf("error ");
			}else{
				printf("%d ",STACK[top--]);
			}
		}
		scanf("%d",&x);
	}
	
	return 0;
}

