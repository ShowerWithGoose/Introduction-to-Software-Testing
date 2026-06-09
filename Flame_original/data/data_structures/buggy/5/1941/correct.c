#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int a;
	int b;
}yuansu;
yuansu k1[100], k2[100], jie[10000];
char scan_k1[1000], scan_k2[1000];
int my_scanf(char* s, yuansu* k)
{
	int qt = 0;
	while ((s[0] >= '0' && s[0] <= '9') || s[0] == '-')
	{
		sscanf(s, "%d", &k[qt].a);
		while (s[0] != ' ')
			s++;
		sscanf(++s, "%d", &k[qt].b);
		while (s[0] != ' ' && s[0])
			s++;
		qt++, s++;
	}
	return qt;
}
int cmp(const void* x, const void* y)
{
	int p = *(int*)x;
	int q = *(int*)y;
	return -jie[p].b + jie[q].b;
}
int main()
{
	fgets(scan_k1, 1000, stdin);
	fgets(scan_k2, 1000, stdin);
	char* sk1 = scan_k1, * sk2 = scan_k2;
	int s1 = my_scanf(sk1, k1);
	int s2 = my_scanf(sk2, k2);
	int qt = 0;
	int a[10000];
	a[0] = 0;
	for (int i = 0; i < s1; i++)
		for (int j = 0; j < s2; j++)
		{
			jie[qt].a = k1[i].a * k2[j].a;
			jie[qt].b = k1[i].b + k2[j].b;
			qt++;
			a[qt] = qt;
		}
	qsort(a, qt, sizeof(int), cmp);
	for (int i = 0; i < qt - 1; i++)
		while (jie[a[i]].b == jie[a[i + 1]].b && i < qt)
		{
			jie[a[i + 1]].a += jie[a[i]].a;//重要错误！不能保存到jie[a[i]]内，而要保存到jie[a[i+1]]内1
			jie[a[i]].a = 0;
			i++;
		}
	for (int i = 0; i < qt; i++)
		if (jie[a[i]].a)
			printf("%d %d ", jie[a[i]].a, jie[a[i]].b);
	return 0;
}


