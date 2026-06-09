#include <stdio.h>
#define M 100

int stack[M];
int process[M*2];
int result[M*2];
int top = -1;
int main(int argc, char const *argv[])
{
	int a = 0;
	int sum = 0;
	scanf("%d", &a);
	while( a!=-1 )
	{
		process[sum++] = a;
		scanf("%d", &a);		
	}
	for (int i = 0; i < sum; ++i)
	{
		if (process[i] == 1)
		{
			stack[++top] = process[++i];
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
	}
	return 0;
}
