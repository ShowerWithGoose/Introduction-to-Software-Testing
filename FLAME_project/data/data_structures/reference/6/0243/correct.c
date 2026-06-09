#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef int ElemType;
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}sqStack;

void initstack(sqStack *s)
{
	s->base=(ElemType *)malloc(100*sizeof(ElemType));
	if(!s->base)
	{
		exit(0);
	}
	s->top=s->base;
	s->stacksize=100;//栈的最大可用空间 
}

void push(sqStack *s,ElemType e)
{
//	if(s->top-s->base==s->stacksize)
//	{
//		s->base=(ElemType *)realloc(s->base,100*sizeof(ElemType));
//		if(!s->base)
//		{
//			exit(0);
//		}
//		s->top=s->base+100;
//		s->stacksize=s->stacksize+100;
//	}
	*(s->top)=e;
	s->top++;
}

void pop(sqStack *s,ElemType *e)
{
	if(s->base==s->top)
	{
		return ;
	}
	*e=*--(s->top);
}

int stacklen(sqStack *s)
{
	return s->top-s->base;
}

int main()
{
	int a,op;
	sqStack s;
	int len;
	int e;
	initstack(&s);//初始化栈 
	while(scanf("%d",&op)!=EOF) 
	{
		if(op==-1)
		{
			break;
		}
		else if(op==1)
		{
			scanf("%d",&a);
			len=stacklen(&s);
			if(len>=100)
			{
				printf("error ");
			}
			else
			{
				push(&s,a);
			}
		}
		else if(op==0)
		{
			len=stacklen(&s);
			if(len<=0)
			{
				printf("error ");
			}
			else
			{
				pop(&s,&e);
				printf("%d ",e);
			}
		}
	}
	return 0;
}

