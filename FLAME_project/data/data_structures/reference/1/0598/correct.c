#include <stdio.h>

int cur[10];
int hash[10];

void arrange(int* cur, int* hash, int n, int depth)
{
	if (depth == n)
	{
		int i;
		for (i = 0; i < n; i++)
		{
			if (i) printf(" ");
			printf("%d", cur[i] + 1);
		}
		printf("\n");
		return;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		if (!hash[i])
		{
			hash[i] = 1;
			cur[depth] = i;
			arrange(cur, hash, n, depth + 1);
			hash[i] = 0;
			cur[depth] = 0;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		cur[i] = 0;
		hash[i] = 0;
	}
	arrange(cur, hash, n, 0);
}
