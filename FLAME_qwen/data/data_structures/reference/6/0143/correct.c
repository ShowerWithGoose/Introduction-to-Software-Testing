#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

typedef struct S
{
	int *base;//栈底指针
	int *top;//栈顶指针
	int size;//当前已经分配的存储空间，以元素个数为单位
}Stack;

int IntiStack(Stack *S);
int Push(Stack *S,int data);
int *Pop(Stack *S,int *data);

int main(int argc, const char * argv[])
{
	Stack *S=(Stack *)malloc(sizeof(Stack));
	IntiStack(S);
	int x,n;
	int *a;
	while(1)
	{
		scanf("%d",&x);
		if(x==-1)
		{
			break;
		}
		else if(x==0)
		{
			Pop(S,a);
		}
		else if(x==1)
		{
			scanf("%d", &n);
			Push(S,n);
		}
	}
	return 0;
}

int IntiStack(Stack *S)
{
	S->base=(int *)malloc(100*sizeof(int));//num是初始定义的元素个数
	if(S->base==NULL)
	{
		return 0;
	}
	S->top=S->base;
	S->size=100;
	return 1;
}
int Push(Stack *S,int data)
{
	if((S->top-S->base)==S->size)
	{
		printf("error ");
		return 0;
		
	}//先插入元素，再移动栈顶指针
	*(S->top)=data;
	S->top++;
	return 1;
}
int *Pop(Stack *S,int *data)
{
	if(S->base==S->top)
	{
		printf("error ");
		return NULL;
	}
	else
	{
		S->top--;
		data=S->top;
		printf("%d ",*data);
		return data;
	}
}

