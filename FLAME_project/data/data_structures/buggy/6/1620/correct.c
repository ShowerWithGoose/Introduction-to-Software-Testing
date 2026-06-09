#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top = -1;
void push(int s[], int num)
{
	if (top == 99)
	{
		printf("error ");
	}
	else 
	{
		s[++top] = num;
	}
}
int main()
{
	int x;
	scanf("%d", &x);
	while(x!=-1)
	{
		if(x) 
		{
			int num;
			scanf("%d", &num);
			push(stack, num);
		}
		else 
		{
			if (top == -1)
			{
				printf("error ");
			}
			else 
			{
				printf("%d ", stack[top--]);
			}
		}
		scanf("%d", &x);
	}
	return 0;
}
