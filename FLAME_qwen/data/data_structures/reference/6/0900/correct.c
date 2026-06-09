#include<stdio.h>
#include<string.h>
int Stack[100];
int main()
{
	int top = -1, n, m;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 1)
		{
			if(top == 99)
			{
				printf("error ");
			}else
			{
				scanf("%d",  &m);
				Stack[++top] = m;
			}
		}else
		if(n == 0)
		{
			if(-1 == top)
			{
				printf("error ");
			}else
			{
				printf("%d ", Stack[top--]);
			}
		}else
		if(n == -1)
		{
			break;
		}
	}
	return 0;
}

