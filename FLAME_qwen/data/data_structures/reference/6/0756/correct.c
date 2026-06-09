#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct sq{
	int data[MAX];
	int top;
}sqStack;
int arr[100]={0},i=0;
void initStack(sqStack *s)
{
	s->top=-1;
} 
void Empty(sqStack *s)
{
	s->top=-1;
}
int isEmpty(sqStack *s)
{
	return s->top==-1;
}
int isFull(sqStack *s)
{
	return s->top==MAX-1;
}
void push(sqStack *s,int item)
{
	if(isFull(s))  arr[i++]=-1;
	else s->data[++s->top]=item;
}
void pop(sqStack *s)
{
	if(isEmpty(s))  arr[i++]=-1;
	else arr[i++]=s->data[s->top--];
}
int main()
{
	int m,n;
	sqStack *stack;
	stack=(sqStack*)malloc(sizeof(sqStack));
	initStack(stack);
	while(1)
	{
		scanf("%d",&m);
		if(m==-1)  break;
		else if(m==1)
		{
			scanf("%d",&n);
			push(stack,n);
		}
		else if(m==0)
		{
			pop(stack);
		}
	}
	for(int k=0;k<i;k++)
	{
		if(arr[k]==-1)  printf("error ");
		else printf("%d ",arr[k]);
	}
	return 0;
}
/*#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
typedef struct {
	int *top;
	int *base;
	int stacksize;
}sqStack;
int initStack(sqStack *s)
{
	s->base=(int*)malloc(sizeof(int)*SIZE);
	if(!s->base)
	exit(0);
	s->top=s->base;
	s->stacksize=SIZE;
	return 1;
}
int wrong(sqStack *s)
{
	if(s->base==s->top)  return 1;
	if(s->base+s->stacksize==s->top)  return 1;
	else  return 0;
}
void push(sqStack *s,int num)
{
	if(wrong(s))  printf("error ");
	else 
	{
	*(s->top)=num;
	s->top++;
	}
}
void pop(sqStack *s)
{
	int x;
	if(wrong(s))  printf("error "); 
	else
	{
	x=*(s->top);
	s->top--;
	printf("%d",x); 
	}
}
int main()
{
 	int n,m;	
	sqStack *st;
	initStack(st);
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&m);
			push(st,m);
		}
		if(n==0)
		{
			pop(st);
		}
	}
	return 0;
 } 
 */

