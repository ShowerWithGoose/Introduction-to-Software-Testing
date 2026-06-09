#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXLEN 100
int stack[MAXLEN];
void push(int data);
void pop();
int top,bot;
int top=-1;
int bot=-1;
int main(){
	int a,data;
	char c;
	while(scanf("%d",&a)){
	//	printf("zh%d",a);
		
		
		if(a==1)
		{
			scanf("%d",&data);
			push(data);
		}
		else if(a==0)
		{
			pop();
		}else break;
	}
	return 0;
} 
void push(data)
{
	if(top>=bot)
	{
		stack[++top]=data;
	//	printf("jin%d ",data);
	}
	else
	{
		printf("error ");
	}
	return;
}
void pop()
{
	if(top>bot)
	{
		printf("%d ",stack[top--]);
	}
	else
	{
		printf("error ");
	}
	return;
}

