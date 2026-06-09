#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Stack{
	int top;
	int ans[150];
}S; 
int push(S *stack,int x)
{
	if(stack -> top >= 100)
	{
		printf("error ");
	}
	else
	{
		stack -> ans[stack -> top] = x;
		stack -> top++;
	}
}
int pop(S *stack)
{
	stack -> top--;
	if(stack -> top < 0)
	{
		printf("error ");
		stack -> top = 0;
	}
	else
	{
		printf("%d ",stack -> ans[stack -> top]);
	}
	 
	
}
int main()
{
	S *stack;
	stack = (S*)malloc(sizeof(S));
	stack -> top = 0;
	int i,j;
	int a[1000];
	do
	{
		scanf("%d",&a[i]);
		i++;
	}while(getchar() != '\n');
	for (j = 0;j < i;j++)
	{
		if(a[j] == 1)
		{
			push(stack,a[j+1]);
		}
		else if (a[j] == 0)
		{
			pop(stack);
		}
		else if (a[j] == -1)
		{
			break;
		}
	}
	return 0;
}


