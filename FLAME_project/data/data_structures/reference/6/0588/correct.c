#include <stdio.h>
#define MAX_SIZE 100
int STACK[MAX_SIZE];
int TOP = -1;
int isEmpty();
int isFull();
int op;
int item;
void pop();
void push(int item);

int main()
{
	while(scanf("%d",&op)!=EOF)
	{
		if(op==1)
		{
			scanf("%d",&item);
			push(item);
		}
		if(op==0)
			pop();
	}
	return 0;
} 

void pop()
{
	if(isEmpty() == 1)
		printf("error ");
	else
		printf("%d ",STACK[TOP--]);
	return;
}

void push(int item)
{
	if(isFull() == 1)
		printf("error ");
	else
		STACK[++TOP]=item;
	return;
}

int isEmpty()
{
	return TOP == -1;
}

int isFull()
{
	return TOP == MAX_SIZE-1;
}


