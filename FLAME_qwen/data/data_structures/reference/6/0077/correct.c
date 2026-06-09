#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXSIZE 100
void initStack();
int isEmpty();
int isFull();
void push(int s[],int item);
int pop(int s[]);
int stack[MAXSIZE];
int Top;
int main()
{
	int i,x;
	int item;
	initStack();
	do{
		scanf("%d",&x);
		if(x==1){ //入栈 
			scanf("%d",&item);
			push(stack,item);
		}
		else if(x==0){
			pop(stack);
		}
	}while(x!=-1);
 return 0;
}
void initStack(){
	Top=-1;
}
int isEmpty(){  //判断栈空与否，栈空返回1，否则返回0 
	return Top==-1;
}
int isFull(){  //判断栈满与否，栈满返回1，否则返回0 
	return Top==MAXSIZE-1;
}
void push(int s[],int item){
	if(isFull()){
		printf("error ");
		exit -1;
	}
	else{
		Top++;
		s[Top]=item;
	}
		
}
int pop(int s[]){
	if(isEmpty()){
		printf("error ");
		return -1;
	}
	else{
		printf("%d ",stack[Top]);
		Top--;
		return 1;
	}
}
/*
创建一个数组，用来存入栈元素
依次读取输入的数据，根据op决定栈中元素变化
如果输入1，先判断栈是否满，满则error，不满则写入
如果输入0，先判断是否为空，空则erro，不空则改top，当作删除，下次直接覆盖 



*/

