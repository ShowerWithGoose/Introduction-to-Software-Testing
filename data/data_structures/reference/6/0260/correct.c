#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
void initStack();
int Top=-1;
void push(int s[],int e);
int pop(int s[]);
int isEmpty();
int getTop(int s[]);
int main()
{
	int op[1000],da,i;
	op[0]=3;
	char s[5]="error";
	initStack(STACK);
	while(scanf("%d",&op[i])!=-1)
	{
		if(op[i])
		{
			scanf("%d ",&da);
			if(Top==MAXSIZE-1)
			printf("%s ",s);
			else
			push(STACK,da);
		}
		else 
		{
			if(Top==-1)
			printf("%s ",s);
			else
			printf("%d ",pop(STACK));			
		}
	}
	return 0;
}
//初始化堆栈
void initStack()
{
	Top=-1;
}
//进栈
void push(int  s[],int item)
{

		s[++Top]=item;
}
//出栈
int pop(int s[])
{
	return s[Top--];
} 

