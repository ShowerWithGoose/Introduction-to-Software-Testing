#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int stack[100], top;
int main()
{
	int mark, date;
	scanf("%d", &mark);
	while (mark != -1)
	{
		if (mark == 1)
		{
			scanf("%d", &date);
			stack[top++] = date;
		}
		else if (mark == 0)
		{
			if (top != 0)
			{
				printf("%d ", stack[top - 1]);
				top--;
			}
			else
				printf("error ");
		}
		scanf("%d", &mark);
	}
	return 0;
}
