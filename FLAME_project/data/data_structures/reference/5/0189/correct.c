#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include <string.h>
#include <stdlib.h>
struct mulit {
	int xi;
	int pow;
};
struct mulit  mutl1[666], mutl2[666],ji[66666];

int cmp(const void* p1, const void* p2)
{
	struct mulit c = *(struct mulit*)p1;
	struct mulit d = *(struct mulit*)p2;
	return d.pow - c.pow;
}

int main()
{   
	int i=0, j=0, k=0;
	int m, n;
	char ch;
		while(1)
		{
			scanf("%d%d%c", &mutl1[i].xi, &mutl1[i].pow, &ch);
				if (ch != '\n')
				{
					i++;
					n = i;
					continue;
				}
				else break;
		}
		i = 0;
		while (1)
		{
			scanf("%d%d%c", &mutl2[i].xi, &mutl2[i].pow, &ch);
				if (ch != '\n')
				{
					i++;
					m = i;
					continue;
				}
				else break;
		}
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			ji[k].xi=mutl1[i].xi* mutl2[j].xi;//算X的系数
			ji[k].pow= mutl1[i].pow + mutl2[j].pow;//算X的次数
			k++;
		}
	}
	
	for (i = 0; i <= (m+1) *(n+1); i++)
	{
		for (j = i + 1; j <= (m + 1) * (n + 1); j++)
		{
			if (ji[i].pow== ji[j].pow)//X的次数相同的系数合并
			{
				ji[i].xi = ji[i].xi + ji[j].xi;
				ji[j].pow = 0;
				ji[j].xi = 0;
			}
		}
	}
	qsort(ji, (m + 1) * (n + 1), sizeof(ji[0]), cmp);
	for (i = 0; i <= (m+1)*(n+1); i++)
	{
		if ( ji[i].xi != 0)
		{
			printf("%d %d ", ji[i].xi, ji[i].pow);
		}
	}
	return 0;
}

