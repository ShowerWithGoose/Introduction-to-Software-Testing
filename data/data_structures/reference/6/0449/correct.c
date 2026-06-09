#include <stdio.h>

int STACK[100];

int top=-1;

int isEmpty()
{
	return top==-1;
}
int isFull()
{
	return top==99;
}

int main()
{
	int act=0,num=0;
	
	while(1)
	{
		scanf("%d",&act);
		if(act==1)
		{
			scanf("%d",&num);
			if(isFull())
			{
				printf("error ");
				}	
			else STACK[++top]=num;
		}
		else if(act==0)
		{
			if(isEmpty())
			{
				printf("error ");
			}
			else 
			{
				printf("%d ",STACK[top]);
				top--;
			}
		}
		else if(act==-1)
		{
			break;
		}
	}
	return 0;
 } 

