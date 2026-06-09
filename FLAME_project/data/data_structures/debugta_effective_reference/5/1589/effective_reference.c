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
Nodeptr insertlist(Nodeptr list, Nodeptr x);
Nodeptr deletelist(Nodeptr list, Nodeptr x); 
Nodeptr multiplelist(Nodeptr a, Nodeptr b);
void Printlist(Nodeptr list);

int main()
{
	Nodeptr a = NULL, b = NULL;
	Nodeptr list;
	a = creatlist();
	b = creatlist();
	list = multiplelist(a, b);
	Printlist(list);
	return 0;
}

Nodeptr creatlist()
{
	Nodeptr head = NULL, k = NULL, m;
	int xishu, zhishu;
	char ch;
	while(1)
	{
		scanf("%d%d", &xishu, &zhishu);
		k = (Nodeptr)malloc(sizeof(struct node));
		k->coef = xishu;
		k->expo = zhishu;
		k->link = NULL;
		if(head == NULL)
		{
			head = k;
			m = k;
		}
		else
		{
			m->link = k;
			m = m->link;
		}
		ch = getchar();
		if(ch == '\n')
			break;
	}
	k->link = NULL;
	return head;
}

Nodeptr multiplelist(Nodeptr a, Nodeptr b)
{
	Nodeptr k = a;
	Nodeptr m = b;
	Nodeptr x;
	Nodeptr head = NULL;
	int xishu;
	int zhishu;
	while(k != NULL)
	{
		while(m != NULL)
		{
			x = (Nodeptr)malloc(sizeof(struct node));//每次有新的值输入都要申请空间才行，否则会不停地覆盖掉原先的值 
			xishu = k->coef * m->coef;
			zhishu = k->expo + m->expo;
			x->coef = xishu;
			x->expo = zhishu;
			head = insertlist(head, x);
			m = m->link;
		}
		m = b;
		k = k->link;
	} 
	return head;
}

Nodeptr insertlist(Nodeptr list, Nodeptr x)
{
	Nodeptr head = list, k = NULL, m = NULL, r = NULL;
	k = (Nodeptr)malloc(sizeof(struct node));
	k = x;
	k->link = NULL;
	if(head == NULL)
	{
		head = x;
		head->link = NULL;
		return head;
	}
	else
	{
		m = head;
		//此处用双向链表更佳 ， 
		while(m != NULL)
		{
			if(x->expo < m->expo)
			{
				r = m;   // r要慢q一步，便于后面删除，因为此处我们用的是单向链表，elem会插入到q的前面，必须有一个在q之前的地址 
				m = m->link;				
			}
			else
			{
				if(x->expo == m->expo)
				{
					if(x->coef + m->coef == 0)
					{
						head = deletelist(head, m);//删去指数为zhishu的项
						return head;
					}
					else
					{
						m->coef = x->coef + m->coef;
						return head;
					}
				}
				else
				{
					r->link = k;
					k->link = m;
					return head;
				}
			}
		}
		r->link = k;
		k->link = NULL;
		return head;
	}
}

Nodeptr deletelist(Nodeptr list, Nodeptr x)
{
	Nodeptr head = list;
	Nodeptr k = list, m;
	if(k->expo == x->expo)
	{
		head = k->link;
		return head;
	}
	m = k->link;//q比p快一步，便于删除
	while(m != NULL)
	{
		if(m->expo == x->expo)
		{
			k->link = m->link;
			free(m);
			return head;
		}
		else
		{
			k = k->link;
			m = m->link;
		}
	}
	return head; 
}

void Printlist(Nodeptr list)
{
	Nodeptr k = list;
	while(k != NULL)
	{
		printf("%d %d ", k->coef, k->expo);
		k = k->link;
	}
}


