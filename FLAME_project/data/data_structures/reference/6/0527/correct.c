#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100
int STACK[maxsize];
int top=-1;
int isfull(int top);
int isempty(int top);
void push(int s[],int item);
void shuchu(int s[]);
int main()
{
	int flag;
	int item;
	while(1)
	{
		scanf("%d",&flag);
		if(flag==1)
		{
			scanf("%d",&item);
			push(STACK,item);
		}
		else if(flag==0)
		{
			shuchu(STACK);
		}
		else if(flag==-1)
		break;
	}
	return 0;
}
void push(int s[],int item)
{
	if(isfull(top))
	printf("error ");
	else s[++top]=item;
}
void shuchu(int s[])
{
	if(isempty(top))
	printf("error ");
	else printf("%d ",s[top--]);
}
int isfull(top)
{
	return top==maxsize-1;
}
int isempty(top)
{
	return top==-1;
}

