#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int main()
{
	int top = -1;
	int op=0, shu=0;
	int cnt = 0;
	while (scanf("%d", &op) )
	{
		if (op == -1) break;

		if (op == 1)
		{
			if (top == 99)
			{
				printf("error ");
			}
			else
			{
				scanf("%d", &shu);
				stack[++top] = shu;
				
			}
		}
		else 
		{
			if (top == -1)
			{
				printf("error ");
			}
			else
			{
				printf("%d ", stack[top]);
				stack[top] = 0;
				top--;
			}
		}
	}

	return 0;
}
