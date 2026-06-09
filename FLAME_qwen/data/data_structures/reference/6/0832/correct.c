#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define eps 1e-6
int stack[101];
int main()
{
	int op, top = 0;
	while ((scanf("%d", &op)) != EOF)
	{
		if (op == 1)
		{
			scanf("%d", &stack[top++]);
		}
		else if (op == 0)
		{
			if (top >= 100 || top == 0)
			{
				printf("error ");
			}
			else
			{
				stack[top] = '\0';
				printf("%d ", stack[--top]);
			}
		}
		else if (op == -1)
			break;
	}
	return 0;
}
