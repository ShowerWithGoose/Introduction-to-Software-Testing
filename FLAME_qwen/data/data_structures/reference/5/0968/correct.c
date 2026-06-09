#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <malloc.h>
struct xiang
{
	int xishu;
	int cishu;
	struct xiang *link;
} * list, list1[100], list2[100], lnode;
struct xiang *find_place(struct xiang *list, int cishu, int xishu)
{
	struct xiang *p = NULL, *r = NULL, *q = NULL;
	p = list;
	// p->link=NULL;
	while (p != NULL)
	{
		if (cishu == p->cishu)
		{
			p->xishu += xishu;
			return list;
		}
		else if (p->cishu > cishu)
		{
			r = p;
			p = p->link;
		}
		else
		{
			q = (struct xiang *)malloc(sizeof(lnode));
			q->cishu = cishu;
			q->xishu = xishu;
			if (r != NULL)
				r->link = q;
			else
				list = q;
			q->link = p;
			return list;
		}
	}
	if (p == NULL)
	{
		q = (struct xiang *)malloc(sizeof(lnode));
		q->cishu = cishu;
		q->xishu = xishu;
		r->link = q;
		q->link = NULL;
	}
	return list;
}
int main()
{
	int xishu, cishu, num1 = 0, num2 = 0;
	char mark;
	while (scanf("%d%d%c", &xishu, &cishu, &mark) && mark != '\n')
	{
		list1[num1].xishu = xishu;
		list1[num1].cishu = cishu;
		num1++;
	}
	list1[num1].cishu = cishu;
	list1[num1].xishu = xishu;
	num1++;
	while (scanf("%d%d%c", &xishu, &cishu, &mark) && mark != '\n')
	{
		list2[num2].xishu = xishu;
		list2[num2].cishu = cishu;
		num2++;
	}
	list2[num2].cishu = cishu;
	list2[num2].xishu = xishu;
	num2++;
	struct xiang *p;
	p = (struct xiang *)malloc(sizeof(lnode));
	list = p;
	//	r=p;
	p->cishu = 0;
	p->xishu = 0;
	p->link = NULL;
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			long long temp_cishu = 0, temp_xishu = 0;
			temp_cishu = list1[i].cishu + list2[j].cishu;
			temp_xishu = list1[i].xishu * list2[j].xishu;
			list = find_place(list, temp_cishu, temp_xishu);
		}
	}
	while (list != NULL)
	{
		if (list->xishu != 0)
		printf("%d %d ", list->xishu, list->cishu);
		p = list;
		list = list->link;
		free(p);
	}
	return 0;
}



