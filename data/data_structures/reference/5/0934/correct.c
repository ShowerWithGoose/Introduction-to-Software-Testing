#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
long long s1[1005][2],s2[1005][2],sm[10000005][2];
int l1 = 0, l2 = 0, lm = 0, c;
int cmp(const void* a, const void* b)
{
	return ((long long*)b)[1] - ((long long*)a)[1];
}
void mul()
{
	for(int i=0;i<l1;i++)
		for (int j = 0; j < l2; j++)
		{
			sm[lm][0] = s1[i][0] * s2[j][0];
			sm[lm][1] = s1[i][1] + s2[j][1];
			lm++;
		}
}
void sel()
{
	for (int i = 0; i < lm-1; i++)
	{
		if (sm[i][1] == sm[i + 1][1])
		{
			sm[i][0] += sm[i + 1][0];
			for (int j = i + 1; j < lm - 1; j++)
			{
				sm[j][0] = sm[j + 1][0];
				sm[j][1] = sm[j + 1][1];
			}
			lm--;
			i--;
		}
	}
}
int main() {
	
	do{
		scanf("%lld %lld", &s1[l1][0], &s1[l1][1]);
		l1++;
	} while ((c = getchar()) != '\n');
	//putchar('\n');
	do {
		scanf("%lld %lld", &s2[l2][0], &s2[l2][1]);
		l2++;
	} while ((c = getchar()) != '\n');
	//for (int i = 0; i < l1; i++)printf("%d %d ", s1[i][0], s1[i][1]);
	//for (int i = 0; i < l2; i++)printf("%d %d ", s2[i][0], s2[i][1]);
	mul();
	qsort(sm, lm, sizeof(sm[0]), cmp);
	sel();
	for (int i = 0; i < lm; i++)
		if(sm[i][0]!=0)printf("%lld %lld ", sm[i][0], sm[i][1]);
	return 0;
}





