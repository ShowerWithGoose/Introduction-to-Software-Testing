#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top = 0;
int a, b;
int main()
{
	while (1)
	{
		scanf("%d", &a);
		if (-1==a)	break;
		if (1 == a)
		{
			scanf("%d", &b);
			if (top == 99)		printf("error ");
			else
			{
				stack[top++] = b;
			}
		}
		if (0 == a)
		{
			if (top == 0)		printf("error ");
			else
			{
				printf("%d ",stack[--top]);
			}
		}
	}
	return 0;
}
