#include<stdio.h>
#define Max 1000
int Stack[Max];
int top=-1;
int op;
int main()
{
	scanf("%d",&op);
	while(op!=-1)
	{
	if(op==1)
	{
		int item;
		scanf("%d",&item);
		Stack[++top]=item;
	}	
	if(op==0)
	{
		if(top==-1)
		printf("error ");
		else
		{
		printf("%d ",Stack[top]);
		top--;	
		}
	}
	scanf("%d",&op);
	}
}

