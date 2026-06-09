//基本思路，一共3个链表，2个存放原始数据，1个存放结果，用来乘的那个乘完一个销毁一个，再放到新的链表里，每回都检测一下是否该指数已经建立过了
#include <stdio.h>
#include <stdlib.h>
typedef struct point {
	int pow;
	int coe;
	struct point* next;
}node,*ptr;
ptr rethead=NULL,han;
void mul(ptr head1, ptr head2);

int main()
{
	int co, po ,len1=0 ,len2=0;
	char c;
	ptr head1=NULL, head2=NULL , p , q=NULL;
	do {
		scanf("%d%d%c", &co, &po, &c);
		if (len1 == 0)
		{
			head1 = p = q = (ptr)malloc(sizeof(node));
			head1->coe = co; head1->pow = po; head1->next = NULL;
		}
		else
		{
			p = (ptr)malloc(sizeof(node));
			q->next = p; q = p;
			p->coe = co; p->pow = po; p->next = NULL;
		}
		len1++;
	} while (c != '\n');
	do {
		scanf("%d%d%c", &co, &po, &c);
		if (len2 == 0)
		{
			head2 = p = q = (ptr)malloc(sizeof(node));
			head2->coe = co; head2->pow = po; head2->next = NULL;
		}
		else
		{
			p = (ptr)malloc(sizeof(node));
			q->next = p; q = p;
			p->coe = co; p->pow = po; p->next = NULL;
		}
		len2++;
	} while (c != '\n');//将两个链表建立完毕
	//开始进行运算
	mul(head1, head2);
	for (p = rethead; p != NULL; p = p->next)
		printf("%d %d ", p->coe, p->pow);
	return 0;
}
void mul(ptr head1, ptr head2)
{
	int coe, pow, flag=0;
	ptr p = head1, q = head2,check=rethead,new;
	han = rethead;
	while (q != NULL)
	{
		while (p != NULL)
		{
			coe = p->coe * q->coe;
			pow = p->pow + q->pow;
			if (rethead == NULL)//create a head node;
			{
				rethead = han = (ptr)malloc(sizeof(node));
				rethead->coe = coe; rethead->pow = pow; rethead->next = NULL;
			}
			else
			{
				check = rethead;
				while (check != NULL)//看看有没有次数相等的节点
				{
					if (check->pow == pow)
					{
						check->coe += coe;
						flag = 1;
						break;
					}
					check = check->next;
				}
				check = rethead;
				if (flag == 0)//如果没有次数相等的节点，看看在哪里插入；
				{
					while (check->next != NULL)//循环的结束条件是到最后一个节点，这样避免到了访问NULL的pow而出错
					{
						if (check->pow > pow && check->next->pow < pow)
						{
							new = (ptr)malloc(sizeof(node));
							new->pow = pow; new->coe = coe;
							new->next=check->next; check->next = new;//add a new node 
							break;
						}
						check = check->next;
					}
					if (check->next == NULL)
					{
						new = (ptr)malloc(sizeof(node));
						check->next=new; new->next = NULL;
						new->pow = pow; new->coe = coe;
					}
				}
			}
			p = p->next;
			flag = 0;
		}
		p = head1;//p在回到多项式的开头
		q = q->next;
	}
}
