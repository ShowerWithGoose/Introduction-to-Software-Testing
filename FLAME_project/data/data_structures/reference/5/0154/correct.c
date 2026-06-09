#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//多项式乘法，用一个多项式遍历，每一个与另一个相乘，然后用链表存储结果，再将链表整合成一个合适的链表
typedef struct node {
	int coeff;
	int index;
}nd;
nd a[10000],b[10000];
int compare(const void* a, const void* b)
{
	nd* pa = (nd*)a;
	nd* pb = (nd*)b;
	return pb->index-pa->index;
}
int main()
{

	int i = 0;
	char c;
	scanf("%d%d", &a[i].coeff, &a[i].index);
	i++;
	c = getchar();
	while (c != '\n')
	{
		scanf("%d%d", &a[i].coeff, &a[i].index);
		i++;
		c = getchar();
	}
	int numa = i;
	i = 0;
	scanf("%d%d", &b[i].coeff, &b[i].index);
	i++;
	c = getchar();
	while (c != '\n')
	{
		scanf("%d%d", &b[i].coeff, &b[i].index);
		i++;
		c = getchar();
	}
	int numb = i;
	nd d[100000];
	int  k = 0;
	for (int i = 0; i < numa; i++)
		for (int j = 0; j < numb; j++)
		{
			d[k].coeff = a[i].coeff * b[j].coeff;
			d[k].index = a[i].index + b[j].index;
			k++;
		}
	int numd = k;
	qsort(d, numd, sizeof(nd),compare);
	for (int i = 0; i < numd-1; i++)
	{
		if (d[i].index != d[i + 1].index)
			printf("%d %d ", d[i].coeff, d[i].index);
		else 
			d[i + 1].coeff += d[i].coeff;
	}
	printf("%d %d ", d[numd - 1].coeff, d[numd - 1].index);
	return 0;
}
