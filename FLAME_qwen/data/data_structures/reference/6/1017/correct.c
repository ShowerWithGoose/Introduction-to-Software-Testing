#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
 int s[100];
 int top;
typedef  int  Stack ;

void initStack(){
	top=-1;
}
void push(Stack s[], int e); //压一个元素进栈
int pop(Stack s[]); //从栈中弹出一个元素
int  isEmpty() ;//判断栈是否为空
int isFull() ;//判断栈是否已满
int getTop(Stack s[]); //获取栈顶元素

int main(){
	int n,t;
	initStack();
  while(scanf("%d",&n)!=-1){
  	
  	if(n==1){
	  	scanf("%d",&t);
	  	push(s,t);
	  }
	  else if(n==0){
	  	if(isEmpty()){
		  		printf("error ");}
		  		else
	  	printf("%d ",pop(s));
	  }
  }
  return 0;
}
void push(Stack s[],int e){
	if(isFull()){
	printf("error ");
	 
	}
	else
	s[++top]=e;
}
int isEmpty(){
	return top==-1;
}
int isFull(){
  return top==100-1;	
}
int pop(int s[]){

	return s[top--];
}











