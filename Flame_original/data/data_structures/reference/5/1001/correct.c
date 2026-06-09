#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct number {
	int base;
	int exp;
	struct number* next;
}num;
void linksort(num** head);

int main()
{
	char c;
	int b, e, m1 = 0, m2 = 0;
	num* head1 = NULL, * head2 = NULL, * p = NULL, * q = NULL, * result = NULL, * ah = NULL;
	while (scanf("%d%d%c", &b, &e,&c) != EOF) {
		p = (num*)malloc(sizeof(num));
		m1++;
		if (head1 == NULL) {
			head1 = q = p;
		}
		else {
			q->next = p;
			q = p;
		}
		p->base = b;
		p->exp = e;
		if (c == '\n') {
			p->next = NULL;
			break;
		}
	}//输入第一个多项式
	while (scanf("%d%d%c", &b, &e,&c) != EOF) {
		p = (num*)malloc(sizeof(num));
		m2++;
		if (head2 == NULL) {
			head2 = q = p;
		}
		else {
			q->next = p;
			q = p;
		}
		p->base = b;
		p->exp = e;
		if (c == '\n') {
			p->next = NULL;
			break;
		}
	}//输入第二个多项式
	for (int i = 0; i < m1 * m2; i++) {
		p = (num*)malloc(sizeof(num));
		if (result == NULL) {
			result = q = p;
			ah = result;
		}
		else {
			q->next = p;
			q = p;
		}
		if (i == m1 * m2 - 1) {
			q->next = NULL;
			p = head1;
			q = head2;
		}
	}//创建result链表
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < m2; j++) {
			ah->base = q->base * p->base;
			ah->exp = p->exp + q->exp;
			q = q->next;
			ah = ah->next;
		}
		p = p->next;
		q = head2;
	}
	linksort(&result);
	p = result;
	while (p != NULL) {
		if(p->base!=0)
		printf("%d %d ", p->base, p->exp);
		p = p->next;
	}
	return 0;
}

void linksort(num** head)
{
	num* list = *head, * r = list, * q = r->next, * p = NULL, * m = list->next;
	if (m == NULL) {
		return;
	}
	p = m->next;
	while (p != NULL) {
		while (p != q) {
			if (p->exp > q->exp) {
				m->next = p->next;
				r->next = p;
				p->next = q;
				p = m->next;
				r = list;
				q = r->next;
				break;
			}
			else if (p->exp == q->exp) {
				q->base += p->base;
				m->next = p->next;
				free(p);
				p = m->next;
			}
			else {
				q = q->next;
				r = r->next;
			}

		}
		if (p == q) {
			r = list;
			q = r->next;
			m = m->next;
			p = p->next;
		}
	}
	return;
}

