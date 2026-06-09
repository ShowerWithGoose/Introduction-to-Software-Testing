#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int top;
void initstack(){
	top=-1;
}
int isempty(){
	return top==-1;
}
int isfull(){
	return top==99;
}
void push(int s[],int item){
	if(isfull()){
		printf("error ");
	}else{
		s[++top]=item;
	}
}
int pop(int s[]){
	if(top==0){
		printf("error ");
	}else{
		printf("%d ",s[top--]) ;
	}
}
int main(){
	int stack[100];
	int s;int i=0,cnt=0;
	while(1){
		scanf("%d",&s);
		if(s==-1){
			break;
		}else if(s==0){
			pop(stack);
		}else if(s==1){
			scanf("%d",&s);
			push(stack,s);
		}
	}
	return 0;
}

