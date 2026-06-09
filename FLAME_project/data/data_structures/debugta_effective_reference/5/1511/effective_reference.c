#include <stdio.h>
#include <stdlib.h>
struct Node { //一个多项式结点结构
	int coe; //系数
	int pow; //幂
	struct Node *next;
};
void print(struct Node *h) {
	struct Node *p = h;
	while (p != NULL) {
		printf("%d %d ", p->coe, p->pow);
		p = p->next;
	}
}
void BubbleSort(struct Node* List) { //链表冒泡排序
	struct Node * p, * q, * tail;
	tail = NULL;
	while ((List->next->next) != tail) {
		p = List;
		q = List->next;
		while (q->next != tail) {
			if ((q->pow) < (q->next->pow)) {
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
				q = p->next;
			}
			q = q->next;
			p = p->next;
		}
		tail = q;
	}
}
int main() {
	int a, n;
	char c;
	struct Node *head1, *p1, *q1;
	struct Node *head2, *p2, *q2;
	struct Node *head, *p, *q, *r;
	head1 = p1 = NULL;
	do { //创建一个链表存放第1个多项式
		scanf("%d%d%c", &a, &n, &c);
		q1 = (struct Node *)malloc(sizeof(struct Node));
		q1->coe = a;
		q1->pow = n;
		q1->next = NULL;
		if ( head1 == NULL)
			head1 = p1 = q1;
		else {
			p1->next = q1;
			p1 = p1->next;
		}
	} while ( c != '\n');
//	print(head1);
	head2 = p2 = NULL;
	do { //创建一个链表存放第2个多项式
		scanf("%d%d%c", &a, &n, &c);
		q2 = (struct Node *)malloc(sizeof(struct Node));
		q2->coe = a;
		q2->pow = n;
		q2->next = NULL;
		if ( head2 == NULL)
			head2 = p2 = q2;
		else {
			p2->next = q2;
			p2 = p2->next;
		}
	} while ( c != '\n');
//	print(head2);
	head = p = NULL;
	p1 = head1;
	p2 = head2;
	while (p1 != NULL) {
		while (p2 != NULL) {
			//将第1,2个多项式的每个项循环相乘写加到第3个多项式链表中
			q = (struct Node *)malloc(sizeof(struct Node));
			q->coe = (p1->coe) * (p2->coe);
			q->pow = (p1->pow) + (p2->pow);
			q->next = NULL;
			if (head == NULL)
				head = p = q;
			else {
				p->next = q;
				p = p->next;
			}
			p2 = p2->next;
		}
		p2 = head2;
		p1 = p1->next;
	}
//	print(head);
	r = p = q = head; //合并同类项
	for (p = head; p != NULL; p = p->next) {
		r = p;
		for (q = p->next; q != NULL; r = q, q = q->next) {
			if (p->pow == q->pow) {
				p->coe += q->coe;
				r->next = q->next;
				free(q);
				q = r->next;
			}
		}
	}
	if(head->next!=NULL)
	BubbleSort(head);
	print(head);
}

