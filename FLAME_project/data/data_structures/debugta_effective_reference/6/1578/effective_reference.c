#include <stdio.h>
#define MAXSIZE 150
int STACK[MAXSIZE];
int s[MAXSIZE];
int top;
void initStack(){
	top=-1;
}//初始化堆栈 
int isEmpty(){
	return top==-1;
}//判断栈是否为空 
int isFull(){
	return top==MAXSIZE-1;
}//测试栈堆是否已满 
void push(int s[],int item){
	if(isFull()){
		printf("error "); 
	}else{
		s[++top]=item ;//入栈成功 
	}
}//进栈算法 
int pop(int s[]){
	if(isEmpty()){
		printf("error ");
	}else{
		printf("%d ",s[top--]);
	}
}//出栈算法 
int main(){
	int op,input;
	initStack();
	do{
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&input);
			push(STACK,input);
		}else if(op==0){
			pop(STACK);
		}
	}while(op!=-1);
	return 0;
}


