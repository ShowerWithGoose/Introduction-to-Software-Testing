#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define eps 1e-6
int have[11], ans[11], b[11];
void list(int, int);
int main()
{
	int i, N;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		ans[i] = i;
	}
	int k = 0;
	list(N, k);
	return 0;
}
void list(int n, int k)
{
	int j, p;
	if (k == n)
	{
		for (p = 0; p < n; p++)
			printf("%d ", b[p]);
		printf("\n");
	}
	else
	{
		for (j = 1; j <= n; j++)
		{
			if (have[j] == 0)
			{
				b[k] = ans[j];
				have[j] = 1;
				list(n, k + 1);
				have[j] = 0;
			}
		}
	}
}
