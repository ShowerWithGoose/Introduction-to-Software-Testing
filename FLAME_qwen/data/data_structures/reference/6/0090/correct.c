#include<stdio.h> 
#define M 100 
int STACK[M];
int main()
{
	int x, num, top = -1;
	do
	{
		scanf("%d", &x);
		if(x == 1)
		{
			scanf("%d", &num);
			if(top == M-1)
			{
				printf("error ");
				continue;
			}
			else
				STACK[++top] = num;
		}
		if(x == 0)
		{
			if(top == -1)
			{
				printf("error ");
				continue;
			}
			else
				printf("%d ", STACK[top--]);
		}
	}while(x != -1);
	return 0;
}

