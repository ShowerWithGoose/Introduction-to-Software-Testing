#include<stdio.h>
#define isfull top==99
#define isempty top==-1

void push();
int pop();

int stack[105],top=-1,key,ele;

int main()
{
	scanf("%d",&key);
	while(key!=-1)
	{
		if(key==1)
		{
			if(isfull)
			printf("error ");
			else
			{
				scanf("%d",&ele);
				push();
			}
		}
		else
		{
			if(isempty)
			printf("error ");
			else
			{
				printf("%d ",pop() );
			}
		}
		scanf("%d",&key);
	}
	return 0;
}

void push()
{
	stack[++top]=ele;
	return;
}

int pop()
{
	return stack[top--];
}

