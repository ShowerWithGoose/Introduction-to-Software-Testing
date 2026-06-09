#include<stdio.h>
typedef struct stack
{
	int data[100];
	int top;
}sqStack;
void init(sqStack *S)
{
	S->top = -1;
}
void push(sqStack *S, int e)
{
	S->top++;
	S->data[S->top] = e; 
}
void pop(sqStack *S, int *e)
{
	*e = S->data[S->top];
	S->top--;
}
int n, m, val;
int main()
{
	sqStack S;
	init(&S);
	while(~scanf("%d", &n))
	{
		if(n == 1)
		{
			scanf("%d", &m);
			if(S.top >= 100)
			{
				printf("error ");
			}
			else
			{
				push(&S, m);
			}
		}
		else if(n == 0)
		{
			if(S.top == -1)
			{
				printf("error ");
			}
			else
			{
				pop(&S, &val);
				printf("%d ", val);
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}

