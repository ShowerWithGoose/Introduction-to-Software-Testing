#include <stdio.h>
#include <stdlib.h>
int op[1000], out[1000], stack[105];
int top = -1;//return huiduo 1ge 6 
void push(int item)
{
	if (top == 99)
	printf("error ");
	else
	{
		stack[++top] = item;
	}
}
void pop()
{
	if (top == -1)
	printf("error ");
	else
	{
		
		printf("%d ", stack[top--]);
	}
}
int main()
{
	int i = 0, hold;
	while (~scanf("%d", &op[i]))
	{
		if (op[i] == 1)
		{
			scanf("%d", &hold);
			push(hold);
		}
		else if (op[i] == 0)
		{
			//printf("%d ", pop());
			pop();
		}
		else
		{
			break;
		}
		i++;
	}
	return 0;
} 

