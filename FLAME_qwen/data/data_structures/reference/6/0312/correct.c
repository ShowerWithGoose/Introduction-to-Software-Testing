#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define MAXSIZE 100 //定义栈中元素的最大个数
typedef struct stack{
    int data[MAXSIZE];
    int top;    //用于栈顶指针
}Stack;
void InitStack(Stack *S);//初始化 
int Push(Stack *S, int e);
int Pop(Stack *S, int *e);

int main()
{
	int n,i;
    Stack s;
    InitStack(&s);
    while(scanf("%d",&n)!=EOF,n!=-1){
    	if(n==1){
    		scanf("%d ",&i);
    		if(!Push(&s,i))
    		printf("error ");
		}
		else{
			if(!Pop(&s,&i))
			printf("error ");
			else{
				printf("%d ",i);
			}
		}
	}
	return 0;
}

void InitStack(Stack *S){
    S->top = -1;    //初始化栈顶指针
}

//出栈 
int Pop(Stack *S, int *e){
    if(S->top==-1)//栈空返回0 
        return 0;
    *e=S->data[S->top];//将要删除的栈顶元素赋值给e
    S->top--;   //栈顶指针减一
    return 1;
}

//进栈 
int Push(Stack *S, int e){
    if(S->top == MAXSIZE-1)//栈满返回0 
        return 0;
    S->top++;   //栈顶指针增加一
    S->data[S->top]=e;//将新插入元素赋值给栈顶空间
    return 1;
}


