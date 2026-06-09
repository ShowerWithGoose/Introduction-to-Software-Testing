#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<ctype.h>
typedef struct name
{
	int x;
	int y;
	struct name* next;
}*poi;
poi create()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	poi link = (poi)malloc(sizeof(struct name));
	poi ano = (poi)malloc(sizeof(struct name));
	link->x = a;
	link->y = b;
	link->next = ano;
	ano->x = c;
	ano->y = d;
	ano->next = 0;
	return link;
}
int linkfree(poi a)
{
	if (a == 0)
		return 0;
	else
	{
		poi b = a->next;
		while (b)
		{
			free(a);
			a = b;
			b = b->next;
		}
		return 0;
	}
}
int linkcmp(poi a, poi b)
{
	if (a == NULL || b == NULL)
		return 0;
	while (a->next)
		a = a->next;
	if (a->x == b->x && a->y == b->y)
		return 1;
	else
		return 0;
}
int link(poi a, poi b)
{
	while (a->next)
		a = a->next;
	a->next = b->next;
	free(b);
	b = 0;
	return 0;
}
int count(poi a)
{
	if (a == 0)
		return 0;
	else
	{
		int n = -1;
		while (a)
		{
			n++;
			a = a->next;
		}
		return n;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	poi C[100];
	for (int i = 0; i < n; i++)
	{
		C[i] = create();
	} 
	int flag = 1;
	while (flag)
	{
		flag = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (C[j] == 0)
					continue;
				else
				{
					if (linkcmp(C[i], C[j]))
					{
						link(C[i], C[j]);
						C[j] = 0;
						flag = 1;
					}
				}
			}
		}
	}
	int num[100];
	for (int i = 0; i < n; i++)
	{
		num[i] = count(C[i]);
	}
	int max = 0;
	poi maxlink = 0;
	for (int i = 0; i < n; i++)
	{
		if (num[i] > max)
		{
			max = num[i];
			maxlink = C[i];
		}
	}
	printf("%d %d %d", max, maxlink->x, maxlink->y);
	for (int i = 0; i < n; i++)
		linkfree(C[i]);
	return 86;
}























