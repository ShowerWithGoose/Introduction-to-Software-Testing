#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
	if(top==max-1){
		printf("error ");
		
	}else{
	
		stack[top]=number;
		
	}
    	
}
void pop(int stack[],int top){
	if(top==-1){
		printf("error ");
	}else{
	printf("%d ",stack[top]);
	
	
	}
	
}
int main(){
	int number;int stack[max]={0};
	while(scanf("%d",&number)){
		if(number==-1){
		break;
		}
		else if(number==1){
			scanf("%d",&number);
			top++;
			push(stack,top,number);
		} else if(number==0){
			pop(stack,top);
			top--;
		}
	}
	return 0;
}
