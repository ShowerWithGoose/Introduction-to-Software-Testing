#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node{
	int coef;
	int expo;
	struct node *link;
};
typedef struct node* Nodeptr;

Nodeptr creatlist();
Nodeptr insertlist(Nodeptr list, Nodeptr elem);
Nodeptr deletelist(Nodeptr list, Nodeptr elem); 
Nodeptr multiplelist(Nodeptr lista, Nodeptr listb);
void Printlist(Nodeptr list);

int main()
{
	Nodeptr lista = NULL, listb = NULL;
	Nodeptr multi_list;
	lista = creatlist();
	listb = creatlist();
	multi_list = multiplelist(lista, listb);
	Printlist(multi_list);
	return 0;
}

Nodeptr creatlist()
{
	Nodeptr head = NULL, p = NULL, q;
	int xishu, zhishu;
	char ch;
	while(1)
	{
		scanf("%d%d", &xishu, &zhishu);
		p = (Nodeptr)malloc(sizeof(struct node));
		p->coef = xishu;
		p->expo = zhishu;
		p->link = NULL;
		if(head == NULL)
		{
			head = p;
			q = p;
		}
		else
		{
			q->link = p;
			q = q->link;
		}
		ch = getchar();
		if(ch == '\n')
			break;
	}
	p->link = NULL;
	return head;
}

Nodeptr multiplelist(Nodeptr lista, Nodeptr listb)
{
	Nodeptr p = lista;
	Nodeptr q = listb;
	Nodeptr elem;
	Nodeptr head = NULL;
	int xishu;
	int zhishu;
	while(p != NULL)
	{
		while(q != NULL)
		{
			elem = (Nodeptr)malloc(sizeof(struct node));//每次有新的值输入都要申请空间才行，否则会不停地覆盖掉原先的值 
			xishu = p->coef * q->coef;
			zhishu = p->expo + q->expo;
			elem->coef = xishu;
			elem->expo = zhishu;
			head = insertlist(head, elem);
			q = q->link;
		}
		q = listb;
		p = p->link;
	} 
	return head;
}

Nodeptr insertlist(Nodeptr list, Nodeptr elem)
{
	Nodeptr head = list, p = NULL, q = NULL, r = NULL;
	p = (Nodeptr)malloc(sizeof(struct node));
	p = elem;
	p->link = NULL;
	if(head == NULL)
	{
		head = elem;
		head->link = NULL;
		return head;
	}
	else
	{
		q = head;
		//此处用双向链表更佳 ， 
		while(q != NULL)
		{
			if(elem->expo < q->expo)
			{
				r = q;   // r要慢q一步，便于后面删除，因为此处我们用的是单向链表，elem会插入到q的前面，必须有一个在q之前的地址 
				q = q->link;				
			}
			else
			{
				if(elem->expo == q->expo)
				{
					if(elem->coef + q->coef == 0)
					{
						head = deletelist(head, q);//删去指数为zhishu的项
						return head;
					}
					else
					{
						q->coef = elem->coef + q->coef;
						return head;
					}
				}
				else
				{
					r->link = p;
					p->link = q;
					return head;
				}
			}
		}
		r->link = p;
		p->link = NULL;
		return head;
	}
}

Nodeptr deletelist(Nodeptr list, Nodeptr elem)
{
	Nodeptr head = list;
	Nodeptr p = list, q;
	if(p->expo == elem->expo)
	{
		head = p->link;
		return head;
	}
	q = p->link;//q比p快一步，便于删除
	while(q != NULL)
	{
		if(q->expo == elem->expo)
		{
			p->link = q->link;
			free(q);
			return head;
		}
		else
		{
			p = p->link;
			q = q->link;
		}
	}
	return head; 
}

void Printlist(Nodeptr list)
{
	Nodeptr p = list;
	while(p != NULL)
	{
		printf("%d %d ", p->coef, p->expo);
		p = p->link;
	}
}


