#include <stdio.h>
#include <stdlib.h>
int stack[1000] = { 0 };
int top = -1,flag=0;
void pushnum(int num);
int pop();

int main()
{
	char c,a;
	int op, num ,ret;
	while (scanf("%d",&op))
	{
		if (op == -1)
			break;
		else
		{
			if (op == 1)
			{
				c = getchar();
				scanf("%d", &num);
				pushnum(num);
			}
			else
			{
				ret=pop();
				if (flag == -1)
					printf("error ");
				else
					printf("%d ", ret);
			}
		}
		c = getchar();
	}
	return 0;
}

void pushnum(int num)
{
	stack[++top] = num;
	if (top >= 0)
		flag = 0;
}
int pop()
{
	int tmp;
	if (top == -1)
	{
		flag = -1;
		return -1;
	}
	else
	{
		tmp = stack[top--];
		return tmp;
	}
}
