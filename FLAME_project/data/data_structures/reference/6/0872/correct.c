#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int stack[105];
int *top=stack;
void enstack()
{
	int tmp;
	scanf("%d",&tmp);
	if(top==stack+100)
	printf("error ");
	else
	*(++top)=tmp;
}
void pop()
{
	if(top==stack)
	printf("error ");
	else
	printf("%d ",*top--);
}
int main()
{
	int opt;
	while(scanf("%d",&opt)!=-1)
	{
		if(opt)
		{
			enstack();
		}
		else
		pop();
	}
	return 0;
}

