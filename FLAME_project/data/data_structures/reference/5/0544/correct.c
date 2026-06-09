#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int co;
	int index;
	struct node* link;
}Item,*LinkList;

LinkList CREAT()
{
	LinkList p = NULL, r = NULL, list = NULL;
	char c=' ';
	while (1)
	{
		p = (LinkList)malloc(sizeof(Item));
		scanf("%d %d%c", &p->co, &p->index, &c);
		p->link = NULL;
		if (list == NULL)
			list = p;
		else
			r->link = p;
		r = p;
		if (c == '\n')
			break;
	}
	return list;
}

LinkList Multi(LinkList list1, LinkList list2)
{
	LinkList ansList=NULL,p=list1,q=list2;
	LinkList r =NULL,s=NULL;
	for (p = list1; p!= NULL; p=p->link)
	{
		for (q = list2; q!= NULL; q=q->link)
		{
			s = (LinkList)malloc(sizeof(Item));
			s->co = p->co * q->co;
			s->index = p->index + q->index;
			s->link = NULL;
			if (ansList == NULL)
				ansList = s;
			else
				r->link = s;
			r = s;
		}
	}
	return ansList;
}

void BubbleSort(LinkList list)
{
	LinkList p=NULL, q=NULL, end=NULL;
	end = NULL;
	if (list->link == NULL)//只有一项
		return;
	else if (list->link->link == NULL)//只有两项（第一项一定更大）
		return;
	while ((list->link->link) != end)//三项及以上
	{
		p = list;
		q = list->link;
		while (q->link != end)
		{
			if ((q->index) < (q->link->index))
			{
				p->link = q->link;
				q->link = q->link->link;
				p->link->link = q;
				q = p->link;
			}
			else if ((q->index) == (q->link->index))
			{
				q->co = q->co + q->link->co;
				LinkList temp = q->link;
				q->link = q->link->link;
				free(temp);
			}
			q = q->link;
			p = p->link;
		}
		end = q;
	}
}
void PRINT(LinkList list)
{
	LinkList p = list;
	for (; p != NULL; p = p->link)
		printf("%d %d ", p->co, p->index);
}

int main()
{
	LinkList list1,list2,list3;
	list1=CREAT();
	list2 = CREAT();//此时已读入两个多项式的系数和指数
	list3 = Multi(list1, list2);//此时已得到结果多项式，但未合并与排序
	BubbleSort(list3);//排序与合并
	PRINT(list3);
	return 0;
}
