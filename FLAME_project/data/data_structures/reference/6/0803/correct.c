#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define M 1000
int PUSH(int STACK[],int item);
int POP(int STACK[]);
int STACK[M];
int top=-1;
int main(){
	while(1){
		int op,s;
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&s);
			PUSH(STACK,s);		   	
		}
		else if(op==0){
			POP(STACK);
		}
		else if(op==-1){
			break;
		}
	} 
	return 0;
}
int PUSH(int STACK[],int item){
	if(top==M-1){
		printf("error ");
	}
	else{
		STACK[++top]=item;
	}	
}
int POP(int STACK[]){
	if(top==-1){
		printf("error ");
	}
	else{
		printf("%d ",STACK[top--]);
	} 	
}  

