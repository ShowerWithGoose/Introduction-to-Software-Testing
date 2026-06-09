#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define ERROR -1
#define OK 1
typedef int Elemtype;
typedef int Status;
typedef struct Stack{
	Elemtype data[100];
	int top;//top是索引，-1代表空栈 
}Stack;
Stack num;
Status Push(Stack*,Elemtype);
Status Pop(Stack*,Elemtype*);
int main(){
	num.top=-1;
	int mood,dat;
	while(1){
		scanf("%d",&mood);
		if(mood==-1)break;
		if(mood==1){
			scanf("%d",&dat);
			if(Push(&num,dat)==ERROR)printf("error ");
		}
		if(mood==0){
			if(Pop(&num,&dat)==ERROR)printf("error ");
			else printf("%d ",dat);
		}
	}
	return 0;
}
Status Push(Stack* L,Elemtype e){
	if(L->top==99)return ERROR;
	L->data[++(L->top)]=e;
	return OK;
}
Status Pop(Stack* L,Elemtype*e){
	if(L->top==-1)return ERROR;
	*e=L->data[L->top--];
	return OK;
}

