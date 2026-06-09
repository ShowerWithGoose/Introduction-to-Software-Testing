#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable:6031)

#define MAXSIZE 100

typedef struct {
	int data[MAXSIZE];
	int top;//Õ»¶¥Ö¸Õë
}stack;

void initStack(stack* s);
void push(stack* s, int n);
void pop(stack* s);

void initStack(stack *s)
{
	s->top = -1;
}

void push(stack* s,int n)
{
	if (s->top == MAXSIZE - 1)
		printf("error ");
	else
	{
		s->top++;
		s->data[s->top] = n;
	}
}

void pop(stack* s)
{
	if (s->top == -1)
		printf("error ");
	else
	{
		printf("%d ", s->data[s->top]);
		s->top--;
	}
}

int main()
{
	stack s;
	initStack(&s);
	int op, n;
	scanf("%d", &op);
	while (op != -1)
	{
		if (op)
		{
			scanf("%d", &n);
			push(&s, n);
		}			
		else
			pop(&s);
		scanf("%d", &op);
	}
	return 0;
}
