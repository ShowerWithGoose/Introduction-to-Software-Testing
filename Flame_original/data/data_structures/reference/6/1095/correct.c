#include <stdio.h>
#define MAXSIZE 150
int STACK[MAXSIZE];
int s[MAXSIZE];
int Top;
void initStack(){
	Top=-1;
}//初始化堆栈 
int isEmpty(){
	return Top==-1;
}//判断栈是否为空 
int isFull(){
	return Top==MAXSIZE-1;
}//测试栈堆是否已满 
void push(int s[],int item){
	if(isFull()){
		printf("error "); 
	}else{
		s[++Top]=item ;//入栈成功 
	}
}//进栈算法 
int pop(int s[]){
	if(isEmpty()){
		printf("error ");
	}else{
		printf("%d ",s[Top--]);
	}
}//出栈算法 
int main(){
	int label,input;
	initStack();
	do{
		scanf("%d",&label);
		if(label==1){
			scanf("%d",&input);
			push(STACK,input);
		}else if(label==0){
			pop(STACK);
		}
	}while(label!=-1);
	return 0;
}


