#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10
int n, num[20];
bool used[20];
void arrange(int x)
{
	if (x > n)
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", num[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			num[x] = i;
			used[i] = true;
			arrange(x + 1);
			num[x] = 0;
			used[i] = false;
		}
	}
}

int main()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		used[i] = false;
	}
	arrange(1);
	return 0;
}
