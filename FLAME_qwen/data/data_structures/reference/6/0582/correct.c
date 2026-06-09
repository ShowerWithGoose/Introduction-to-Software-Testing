
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct stack{
			int data;
			struct stack* link;
		};
struct stack* TOP = NULL;
void push(int item)
{
	struct stack* p;
	p = (struct stack*)malloc(sizeof(struct stack));
	p->data = item;
	p->link = TOP;
	TOP = p;
}
int isempty()
{

	return TOP == NULL;
}
void pop()
{
	struct stack* p;
	int item;
	if (isempty())
		printf("error ");
	else {
		p = TOP;
		item = TOP->data;
		TOP = TOP->link;
		free(p);
		printf("%d ", item);

	}


}
int main()
{
			int a, b;
			while (scanf("%d ", &a) != EOF)
			{
				if (a == 1)
				{
					scanf("%d ", &b);
					push(b);
				}
				else if (a == 0)
					pop();
				else
					break;
			}
				return 0;
}




