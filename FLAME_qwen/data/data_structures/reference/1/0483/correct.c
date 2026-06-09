#include<stdio.h>

int n, a[105];
int digui[105];

void find(int x)
{
	int i;
	if (x == n + 1)
	{
		for (i = 1; i <= n; i ++ )
			printf("%d ", a[i]);
		printf("\n");
		return ;
	}
	for (i = 1; i <= n; i ++ )
	{
		if (digui[i]!=1)
		{
			a[x] = i;
			digui[i] = 1;
			find(x + 1);
			digui[i] = 0;
		}
	}
}

int main()
{
	scanf("%d", &n);
	find(1);
	return 0; 
}

