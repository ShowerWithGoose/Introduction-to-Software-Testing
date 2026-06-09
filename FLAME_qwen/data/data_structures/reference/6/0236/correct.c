#include<stdio.h>
int stack[100], top=-1;

void push()
{ 	int item;
	if(top==99) 
	{
		printf("error ");
		return;
	}
	top++;
	scanf("%d", &item);
	stack[top]=item;
}

void pop()
{
	if(top==-1)
	{
		printf("error ");
		return;
	}
	printf("%d ", stack[top]);
	top--;
}

int main()
{
	int op;
	do
	{
		scanf("%d", &op);
		if(op==1)
		push();
		else if(op==0)
		pop();
	}while(op!=-1);
 } 

