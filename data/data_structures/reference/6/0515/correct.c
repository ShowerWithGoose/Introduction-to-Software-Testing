#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef struct stack{
	int num;
	struct stack *link;
} node;
node *top;
int count;
void push(int num);
int pop();
int main()
{
	int n,num;
	while(1)
	{
		scanf("%d",&n);
		if(n==1)
		{
			scanf("%d",&num);
			push(num);
		}
		else if(n==0)
		{
			num=pop();
			if(num==-1)
			{
				
			}
			else
			{
				printf("%d ",num);
			}
		}
		else if(n==-1)
		{
			return 0;
		}
	}
}
void push(int num)
{
	node *p;
	if(count==0)
	{
		top=(node *)malloc(sizeof(node));
		top->num=num;
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
		p->num=num;
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
		return(p->num);
		free(p);
	}
}

