#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
ElemType STACK[MAXSIZE];
int Top;
void initStack()
{
	Top = -1;
}//³õÊ¼»¯Õ»
int isEmpty()
{
	return Top == -1;	
}//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ 
int isFull()
{
	return Top == MAXSIZE - 1;
}//ÅÐ¶ÏÊÇ·ñÕ»Âú 
void Error(char s[])
{
	printf("%s ", s);
}
void push(ElemType n)
{
	if(isFull())
	Error("error");
	else STACK[++Top] = n;
}//½øÕ»
 ElemType pop()
 {
 	if(isEmpty())
 	{
 		Error("error");
 		return 0;
	 }
 	else 
 	return STACK[Top--];
 }//³öÕ» 
int main()
{
	initStack();
	int order;
	scanf("%d", &order);
	while(order != -1)
	{
		if(order == 1)
		{
			ElemType num;
			scanf("%d", &num);
			push(num);
		}
		else if(order == 0)
		{
			ElemType x = pop();
			if(x != 0 )
			printf("%d ", x); 
		}
		scanf("%d", &order);
	} 
	return 0;
 } 

