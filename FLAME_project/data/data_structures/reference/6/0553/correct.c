#include<stdio.h>
#include<string.h>
#define MAX 99
int put_in(int top,int stack[],int x)
{
	top++;
	stack[top]=x;
	return top;
}
int pop(int top,int stack[])
{
	stack[top]=0;
	top--;
	return top;
}
int isempty(int top)
{
	return (top==-1)?1:0;
}
int isfull(int top)
{
	return (top==MAX)?1:0;
}
int main()
{
	int op,x;
	int stack[105],top=-1;
	while(1)
	{
		scanf("%d",&op);
		if(op==-1)
			break;
		else if(op==1)
		{
			scanf("%d",&x);
			if(isfull(top))
				printf("error ");
			else
				top=put_in(top,stack,x);
		}
		else if(op==0)
		{
			if(isempty(top))
				printf("error ");
			else{
				printf("%d ",stack[top]);
				top=pop(top,stack);
			}	
		}
	}
	return 0;
}

