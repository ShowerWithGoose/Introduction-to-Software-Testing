#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define Max 100
int stack[Max];/*构造一个线性堆栈*/
int main(int argc,char *argv[])
{
	int op,item;/*op表示操作符,item表示入栈的元素*/
	int top=-1;/*初始化堆栈*/
	while(~scanf("%d",&op))
	{
		if(op==1)/*入栈*/
		{
			scanf("%d",&item);
			if(top==Max)/*栈满*/
				printf("error");
			else
				stack[++top]=item;
		}
		else if(op==0)/*出栈*/
			if(top==-1)/*栈为空*/
				printf("error ");
			else
				printf("%d ",stack[top--]);
		else if(op==-1)
			break;
	}
	return 0 ;
}

