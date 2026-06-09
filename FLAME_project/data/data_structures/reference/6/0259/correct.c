#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100 
typedef int ElemType;
typedef struct{
	ElemType data[MAX];
	int top;
}stack;

void InitStack(stack *S)//初始化 
{
	S->top=-1;
}
int isEmpty(stack *S)//判断是否为空 
{
   if(S->top==-1)
   return 0;
   else
   return 1;
} //空返回0，不空返回1 
int isFull(stack *S)//判断是否栈满 
{
   if(S->top==MAX-1)
   return 0;
   else
   return 1;
} //满返回0， 不满返回1 
int push(stack *S,ElemType n)//入栈操作 
{
   if(isFull(S)==0)
   return 0;
   else{
   S->top++;
   S->data[S->top]=n;
   return 1;	
   }
} 
int pop(stack *S,ElemType e)//出栈操作 
{
    if(isEmpty(S)==0)
    return 0;
    else{
    e=S->data[S->top];
    S->top--;
    return e;
}
} 

int main()
{
	int cz,num,k;
	int e;
	stack a[MAX];
	InitStack(a);
	scanf("%d",&cz);
	while(cz!=-1)
	{
		if(cz==1)
		{
			scanf("%d",&num);
			if(push(a,num)==0)
			printf("error "); 
		}
		else{
			k=pop(a,e);
			if(k!=0)
			printf("%d ",k);
			else 
			printf("error "); 
		}
	scanf("%d",&cz);
	}
	return 0;
}

