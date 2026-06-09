#include<stdio.h> 

int map[150];
int top = 0;

void add(int a)
{
	map[top++] = a;
}

void del(int a)
{
	printf("%d ", map[--top]);
}

int main()
{
	int op;
	while (1)
	{
		scanf("%d", &op);
		if (op == -1)
		{
			break;
		}
		if (op == 1)
		{
			scanf("%d", &op);
			if (top == 100)
			{
				printf("error ");
			}
			else
			{
				add(op);
			}
		}
		if (op == 0)
		{
			if (top == 0)
			{
				printf("error ");
			}
			else
			{
				del(op);
			}
		}
	}
	return 0;
}

