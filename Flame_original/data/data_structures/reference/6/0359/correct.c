#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct stack
{
	int data[102];
	int top;
}s;
typedef struct stack stack;
void initstack(stack *s){s->top=-1;}
int isfull(stack *s){return s->top==101;}
void push(stack *s, int a)
{
	if(isfull(s)!=0)
	{
		printf("error ");
		return ; 
	}
	s->data[++s->top]=a;
}
void pop(stack *s)
{
	if(s->top==-1)
	{
		printf("error ");
		return ;
	}
	printf("%d ",s->data[s->top--]);
	return ;
}
int main()
{
	initstack(&s);
	int mode;
	while(1)
	{
		scanf("%d",&mode);
		if(mode==-1)break;
		if(mode==0)pop(&s);
		if(mode==1)
		{
			int tmp;
			scanf("%d",&tmp);
			push(&s,tmp);
		}
	}
	return 0;
}

