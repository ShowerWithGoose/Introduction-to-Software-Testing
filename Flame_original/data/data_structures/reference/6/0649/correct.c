#include<stdio.h>
int stack[100];
int topIndex = 0;

int main(void)
{
	int op, element;
	while (1)
	{
		scanf("%d", &op);
		if (op == -1)
		{
			return 0;
		}
		else if (op == 1)
		{
			scanf("%d", &element);
			stack[topIndex++] = element;
		}
		else if (op == 0)
		{
			if(topIndex)
			{
				printf("%d ", stack[--topIndex]);
			}
			else 
			{
				printf("error ");
			}
		}
	}
	return 0;
}
