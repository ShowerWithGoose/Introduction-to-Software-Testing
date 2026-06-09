#include<stdio.h>
#include<stdlib.h>
typedef struct date{
	int num1, num2;
}Ldate;
typedef struct node{
	Ldate date;
	struct node *link;	
}LNode, *LinkList;
int main()
{
	LinkList list1 = NULL, list2 = NULL, list3 = NULL, p, q, r, k, m;
	int x, y;
	char ch;
	do{
		scanf("%d %d%c", &x, &y, &ch);
		p = (LinkList)malloc(sizeof(LNode));
		p->date.num1 = x;
		p->date.num2 = y;
		if(list1 == NULL)
			list1 = p;
		else
			r->link = p;
		r = p;
	}while(ch != '\n');	//读入第一个多项式 
	p->link = NULL;
	do{
		scanf("%d %d%c", &x, &y, &ch);
		p = (LinkList)malloc(sizeof(LNode));
		p->date.num1 = x;
		p->date.num2 = y;
		if(list2 == NULL)
			list2 = p;
		else
			r->link = p;
		r = p;
	}while(ch != '\n');	//读入第二个多项式 
	p->link = NULL;
	for(p = list1; p != NULL; p = p->link)	//多项式相乘并排序 
	{
		for(q = list2; q != NULL; q = q->link)
		{
			k = (LinkList)malloc(sizeof(LNode));
			k->date.num1 = p->date.num1*q->date.num1;
			k->date.num2 = p->date.num2+q->date.num2;
			k->link = NULL;
			if(list3 == NULL || k->date.num2 > list3->date.num2)
			{
				k->link = list3;
				list3 = k;
			}
			else
			{
				m = list3;
				while(m != NULL && k->date.num2 < m->date.num2)
				{
					r = m;
					m = m->link;
				}
				if(m != NULL && k->date.num2 == m->date.num2)
					m->date.num1 += k->date.num1;
				else
				{
					k->link = m;
					r->link = k;
				}
			}
		}
	}
	for(p = list3; p != NULL; p = p->link)	//输出多项式 
		printf("%d %d ", p->date.num1, p->date.num2);
	return 0;
}

