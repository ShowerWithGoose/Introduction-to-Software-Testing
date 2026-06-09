#include<stdio.h>
int n, a[20], b[20];
int c = 1;
void dfs(int x)
{
	if (x > n)
	{
		for (int i = 1;i <= n;i++)
			printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for (int i = 1;i <= n;i++)
	{
		if (b[i] == 0)
		{
			b[i] = 1;
			a[c] = i;
			c++;
			dfs(x + 1);
			b[i] = 0;
			a[c] = 0;
			c--;
		}
	}
}
int main()
{
	scanf("%d", &n);
	dfs(1);
	return 0;
}




