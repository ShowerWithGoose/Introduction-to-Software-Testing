#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int comp(const void* a, const void* b)
{
	if (((int*)b)[0] >= ((int*)a)[0])
		return 1;
	else
		return -1;
}
int main()
{
	int cnm[105][5] = { 0 }, n, i, j, k, m = 0, flg = 0, lo;
	int lin[105][5] = { 0 };
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &lin[i][1], &lin[i][2], &lin[i][3], &lin[i][4]);
		cnm[i][0] = 1;
		lin[i][0] = i * i;
		qsort(lin+5, n, 5 * sizeof(int), comp);
		for (j = 1; j <= 4; j++)
		{
			cnm[i][j] = lin[i][j];
		}
	}
	memset(cnm, 0, sizeof(cnm));
	k = 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n && j != i; j++)
		{
			if ((cnm[i][1] == lin[j][3]) && (cnm[i][2] == lin[j][4]))
			{
				flg = 1;
				break;
			}
		}
		if (!flg)
		{
			k++;
			for (lo = 1; lo <= 4; lo++)
			{
				cnm[k][lo] = lin[i][lo];
			}
		}
		flg -= flg;
	}
	for (i = 1; i < k; i++)
	{
		cnm[i][0] = 1;
		for (j = 1; j <= n; j++)
		{
			if ((cnm[i][3] == lin[j][1]) && (cnm[i][4] == lin[j][2]))
			{
				cnm[i][3] = lin[j][3];
				cnm[i][4] = lin[j][4];
				cnm[i][0] += 1;
				j = 0;
				j--;
			}
		}
	}
	if (1)
		qsort(cnm+1, k, 5 * sizeof(int), comp);
	lo = 0;
	for (i = 1; i < k; i++)
	{
		if (cnm[i][0] >= lo)
		{
			lo = cnm[i][0];
			m = i;
		}
	}
	printf("%d %d %d\n", cnm[m][0], cnm[m][1], cnm[m][2]);
	return 0;
}




