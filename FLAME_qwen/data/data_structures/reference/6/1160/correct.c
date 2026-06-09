#include <stdio.h>
#include <stdlib.h>
#define ElemType int

typedef struct node{
	ElemType data;
	struct node *link;
} SNode;

SNode *top;

void initStack()
{
	top = NULL;
}

int isEmpty()
{
	return top == NULL;
}

void push(ElemType item)
{
	SNode *p;
	if ((p = (SNode*)malloc(sizeof(SNode))) == NULL)
	{
		printf("No memory!");
	}
	else
	{
		p->data = item;
		p->link = top;
		top = p;
	}
}

ElemType pop()
{
	SNode *p;
	ElemType item;
	if (isEmpty())
	{
		printf("Empty Stack!");
	}
	else
	{
		p = top;
		item = top->data;
		top = top->link;
		free(p);
		return item;
	}
}

int main()
{
	initStack();
	int op;
	while (scanf("%d",&op))
	{
		if (op == -1)
		{
			break;
		}
		switch (op)
		{
			case 1:
			{
				int a;
				scanf("%d",&a);
				push(a);
				break;
			}
			case 0:
			{
				if (isEmpty())
				{
					printf("error ");
					break;
				}
				int b = pop();
				printf("%d ",b);
				break;
			}
			default:
				break;
		}
	}

	return 0;
}
