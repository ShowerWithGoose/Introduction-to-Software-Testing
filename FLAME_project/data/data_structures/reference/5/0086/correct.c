#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct st {
	int xi;
	int ci;
	struct st* next;
}*head1,*head2, *q,*link;
struct st* listsearch(struct st* top, struct st content);/*返回指针（相同的返回相同的指针，不同的返回内容小于它的指针）,没找到返回尾结点*/
void add(struct st** jie, struct st cont);/*在jie所指的链表节点之后添加一个新的节点，内容是i。只能加在head之后，如果要加在head之前，需要特判*/
int main()
{
	head1 = (struct st*)malloc(sizeof(struct st));
	head2 = (struct st*)malloc(sizeof(struct st));
	head1->next = head2->next = NULL;
	head2->ci = 1000000;
	char e='.';
	int date1, date2;
	q = head1;
	while (e != '\n')/*输入第一行*/
	{
		scanf("%d%d%c", &(q->xi),&(q->ci), &e);
		struct st *zan;
		zan= (struct st*)malloc(sizeof(struct st));
		q->next = zan;
		zan->next = NULL;
		q = q->next;
	}
	q = head2,e='.';
	while (e != '\n')/*相乘*/
	{
		scanf("%d%d%c", &date1, &date2, &e);
		q = head1;
		while (q->next != NULL)
		{
			struct st zan;
			zan.xi = date1 * (q->xi);
			zan.ci = date2 + (q->ci);
			link=listsearch(head2, zan);
			if (link->ci == zan.ci)
				link->xi += zan.xi;
			else
				add(&link, zan);
			q = q->next;
		}	
	}
	q = head2->next;
	free(head2);
	while (q != NULL)/*输出*/
	{
		printf("%d %d ", q->xi, q->ci);
		link = q;
		q = q->next;
		free(link);
	}
	q = head1;
	while (q != NULL)
	{
		link = q;
		q = q->next;
		free(link);
	}
	return 0;
}
struct st* listsearch(struct st* top, struct st content)/*返回指针（相同的返回相同的指针，不同的返回内容小于它的指针）,没找到返回尾结点*/
{
	struct st* jian = top;
	while (jian->next != NULL)
	{
		if (jian->next->ci < content.ci)
			return jian;
		else if (jian->next->ci == content.ci)
			return jian->next;
		else
			jian = jian->next;
	}
	return jian;
}
void add(struct st** jie, struct st cont)/*在jie所指的链表节点之后添加一个新的节点，内容是i。只能加在head之后，如果要加在head之前，需要特判*/
{
	struct st* content;
	content = (struct st*)malloc(sizeof(struct st));
	struct st* jian;
	jian = (*jie)->next;
	(*jie)->next = content;
	*content = cont;/*输入添加的结构体内容*/
	content->next = jian;
}
