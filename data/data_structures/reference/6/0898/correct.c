#include<stdio.h>
#include<string.h>
int stack[5000];
int now = -1;
int main()
{
	int n;
	while (1)
	{
		scanf("%d", &n);
		if (n == -1) break;
		if (n == 1)
		{
			int a;
			scanf("%d", &a);
			now++;
			stack[now] = a;
		}
		else if (n == 0)
		{
			if (now >= 0)
			{
				printf("%d ", stack[now]);
				now--;
			}
			else
			{
				printf("error ");
			}
		}
	}
	return 0;
}

