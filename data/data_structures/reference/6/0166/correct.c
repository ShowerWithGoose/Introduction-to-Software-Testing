#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	int a[100] = { 0 };
	int n, top, i, m;
	top = -1;
	while (1)
	{
		scanf("%d", &i);
		if (i == -1)
		{
			return 0;
		}
		else if (i == 1)
		{
			scanf("%d", &m);
			a[++top] = m;
		}
		else if (i == 0)
		{
			if (top == -1)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",a[top--]);
			}
		}
	}
	return 0;
}


