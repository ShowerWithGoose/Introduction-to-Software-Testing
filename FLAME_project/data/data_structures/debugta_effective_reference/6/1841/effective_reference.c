#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef struct stack{
	int n;
	struct stack *link;
} node;
node *top;
int count;
void push(int n);
int pop();
int main()
{
	int command,n;
	while(1)
	{
		scanf("%d",&command);
		if(command==1)
		{
			scanf("%d",&n);
			push(n);
		}
		else if(command==0)
		{
			n=pop();
			if(n==-1)
			{
				
			}
			else
			{
				printf("%d ",n);
			}
		}
		else if(command==-1)
		{
			return 0;
		}
	}
}
void push(int n)
{
	node *p;
	if(count==0)
	{
		top=(node *)malloc(sizeof(node));
		top->n=n;
		count++;
	}
	else if(count==MaxSize)
	{
		printf("error ");
	}
	else
	{
		p=(node *)malloc(sizeof(node));
		p->link=top;     //后一个连到前一个上 
		p->n=n;
		top=p;
		count++;
	}
}
int pop()
{
	if(count==0)
	{
		printf("error ");
		return(-1);
	}
	else
	{
		node *p;
		p=top;
		if(top->link!=NULL)
		{
			top=top->link;
		}
		count--;
		return(p->n);
		free(p);
	}
}

