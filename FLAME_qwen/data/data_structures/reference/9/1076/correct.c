#include<stdio.h>
#include<string.h>
typedef struct rop1
{
	int s_x;
	int s_y;
	int f_x;
	int f_y;
}rope;
rope rop[200];
int a[100] = { 0 };
int n;
void multi(int a[], rope p[]);
void find(int a[], rope p[], int now, int m);
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &rop[i].s_x, &rop[i].s_y, &rop[i].f_x, &rop[i].f_y);
	}
	multi(a, rop);
	int max = 0;
	int j = 0;
	for (int i = 1; i <= n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			j = i;
		}
	}
	printf("%d %d %d\n", max+1, rop[j].s_x, rop[j].s_y);
}
void multi(int a[], rope p[])
{
	for (int i = 1; i <= n; i++)
	{
		find(a, p, i, i);
	}
}
void find(int a[], rope p[], int now, int m)
{
	int q = 0;
	for (int i = 1; i <= n; i++)
	{
		if (p[now].f_x == p[i].s_x && p[now].f_y == p[i].s_y)
		{
			a[m]++;
			now = i;
			q = 1;
			break;
		}
	}
	if(q==1)find(a, p, now, m);
	else
	{
		return;
	}
}
