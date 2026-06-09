#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//相乘：系数相乘，指数相加
//相加：指数相同的系数相加，指数不同则插入

struct multinomial
{
	int a;
	int n;
	struct multinomial* link;
};

typedef struct multinomial Node;
typedef struct multinomial* Nodeptr;

int compare(const void* _a, const void* _b) {
	Nodeptr a = (Nodeptr)_a;
	Nodeptr b = (Nodeptr)_b;
	return a->n - b->n;
}

int main()
{
	int x, y, num = 0, temp;
	char c;
	Nodeptr p, q, r, s, list1, list2;
	list1 = NULL;
	p = (Nodeptr)malloc(sizeof(Node));
	while (scanf("%d%d%c", &x, &y, &c) != NULL) {
		q = (Nodeptr)malloc(sizeof(Node));
		q->a = x, q->n = y;
		if (list1 == NULL)
			p = q, list1 = q;
		else {
			p->link = q;
			p = q;
		}
		q->link = NULL;
		if (c == '\n')
			break;
	}
	//首先先把第一个多项式以链表的形式存储
	//接着开始下一个多项式的操作
	//每读入一对数，就对链表进行相应的操作
	//再创建一个列表
	list2 = NULL;
	q = (Nodeptr)malloc(sizeof(Node));
	while (scanf("%d%d%c", &x, &y, &c) != NULL) {
		//读入了x和y
		for (p = list1; p != NULL; p = p->link) {
			r = (Nodeptr)malloc(sizeof(Node));
			r->a = p->a * x;
			r->n = p->n + y;
			r->link = NULL;
			if (list2 == NULL)
				list2 = r, q = r, num++;
			else {
				for (s = list2; s != NULL; s = s->link) {
					if (s->n == r->n) {
						s->a += r->a;
						break;
					}
					//如果指数一致，则系数相加
				}
				if (s == NULL) {
					q->link = r;
					q = r;
					num++;
				}
			}
		}
		if (c == '\n')
			break;
	}
	for (s = list2; s != NULL; s = s->link) {
		for (r = list2; r->link != NULL; r = r->link) {
			if (r->n < r->link->n) {
				temp = r->n;
				r->n = r->link->n;
				r->link->n = temp;
				temp = r->a;
				r->a = r->link->a;
				r->link->a = temp;
			}
		}
	}
	for (s = list2; s != NULL; s = s->link)
		printf("%d %d ", s->a, s->n);
	return 0;
}
