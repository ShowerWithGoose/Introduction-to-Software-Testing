#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100
struct opstack{
	int data[maxsize] ;
	int top;
}s;
typedef struct opstack stack;
int a,i;
void initstack(stack *s){
	s->top = -1;
}//³õÊ¼»¯Äó 
/*
int isempty(stack *s)//ÅÐ¶ÏÕ»¿Õ²»¿Õ£¬¿Õ·µ»Ø1£¬²»¿Õ·µ»Ø0 
{
	return s->top==-1;
}
int isfull(stack *s)//ÅÐ¶ÏÕ»Âú·µ»Ø1£¬²»Âú·µ»Ø0 
{
	return s->top==maxsize-1;
 } */
int push(stack *s,int a)//ÈëÕ»²Ù×÷ 
{
	if(s->top==maxsize-1)
	{
		printf("error ");
		return 0;
	}
	s->data[++s->top] = a;
	return 1;
}
int pop(stack *s,int a)//³öÕ» 
{
	if(s->top==-1)
	{
		printf("error ");
		return 0; 
	}
	a=s->data[s->top--];
	printf("%d ",a) ;
	return 1;
}
main()
{
	//stack *s;
	//s->top = -1;
	initstack(&s);
	int type;
	while(1)
	{
		scanf("%d",&type) ;
		if(type==-1)
		break;
		else if(type==0)
		pop(&s,a) ;
		else if(type==1)
		{
			scanf("%d",&i);
			push(&s,i);
		}
	}
	return 0;
}

