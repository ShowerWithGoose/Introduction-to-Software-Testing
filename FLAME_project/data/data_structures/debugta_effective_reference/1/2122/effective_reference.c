#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10
int n, arr[20];
bool used[20];
void arrange(int a)
{
	if (a > n)
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			arr[a] = i;
			used[i] = true;
			arrange(a + 1);
			arr[a] = 0;
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
