#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAX 100

struct Node
{
	int num;
	struct Node* link;
};

void push(struct Node** top, int num, int* count);
void pop(struct Node** top, int* count);
void freestack(struct Node** top, int count);

int main()
{
	int n = 0;

	struct Node* top = NULL;
	int count = 0;

	while (scanf("%d", &n), n != -1)
	{
		if (n == 1)
		{
			scanf("%d", &n);
			push(&top, n, &count);
		}
		else if (n == 0)
		{
			pop(&top, &count);
		}
	}

	freestack(&top, count);

	return 0;
}

void push(struct Node** top, int num, int* count)
{
	if ((*count) >= MAX)
	{
		printf("error ");
	}
	else
	{
		struct Node* ptmp = (struct Node*)malloc(sizeof(struct Node));
		ptmp->num = num;
		ptmp->link = NULL;
		if ((*top) == NULL)
		{
			(*top) = ptmp;
		}
		else
		{
			ptmp->link = (*top);
			*top = ptmp;
		}
		(*count)++;
	}
}

void pop(struct Node** top, int* count)
{
	if ((*count) <= 0)
	{
		printf("error ");
	}
	else
	{
		struct Node* ptmp = *top;
		printf("%d ", (*top)->num);
		*top = (*top)->link;
		free(ptmp);
		(*count)--;
	}
}

void freestack(struct Node** top, int count)
{
	for (int i = 0; i < count; i++)
	{
		struct Node* ptmp = *top;
		*top = (*top)->link;
		free(ptmp);
	}
}
