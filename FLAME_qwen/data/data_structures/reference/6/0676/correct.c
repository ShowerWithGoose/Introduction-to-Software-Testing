#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 110

struct stack{
	int data[MAX];
	int top;
};
typedef struct stack Stack;
typedef struct stack* Stackptr;

Stack s;
int isempty_st(Stackptr s)
{
	return s->top==-1;
}
int isfull_st(Stackptr s)
{
	return s->top==MAX-1;
}
int push_st(Stackptr s,int a)
{
	if(isfull_st(s)!=0)
	{
		printf("error ");
		return 0;
	}
	s->data[++s->top]=a;//ÈëÕ»
	return 1; 
}
int pull_st(Stackptr s,int a)
{
	if(s->top ==-1)
	{
		printf("error ");
		return 0;
	}
	a=s->data[s->top--];
	printf("%d ",a);
	return 1;
}
int main()
{
	(&s)->top=-1;
	int flag=-1,op=0;
	
	while(1)
	{
		scanf("%d",&flag);
		if(flag==-1)
		    break;
		else if(flag==1)
		{
			scanf("%d",&op);
			push_st(&s,op);
		}
		else if(flag==0)
		{
			pull_st(&s,op);
		}
	}
	return 0;
}


 

