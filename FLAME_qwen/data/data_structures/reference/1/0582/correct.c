#include<stdio.h>
int a[1000];
int visited[1000] = { 0 };
void num(int n, int deep)
{
	
	for (int i = 1;i <=n;i++)
	{
		if (visited[i] == 0)
		{
			a[deep++] = i;
			visited[i] = 1;
			num(n, deep);
			deep -= 1;
			visited[i] = 0;
		}
	}
	if (deep == n)
	{
		for (int i = 0;i < n;i++)
			printf("%d ", a[i]);
		printf("\n");
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	num(n, 0);
	return 0;
}


