#include <stdio.h>
#include <string.h>
int a[1001];
int top = 0;

int main ()
{
	int op;
	while(scanf("%d",&op))
	{
		if(op == -1) break;
		if(op == 0)
		{
			if(top == 0)
			printf("error ");
			else
			printf("%d ",a[--top]);
		}
		else
		{
			int n;
			scanf("%d",&n);
			a[top++] = n;
		}
	}
	return 0;
}

