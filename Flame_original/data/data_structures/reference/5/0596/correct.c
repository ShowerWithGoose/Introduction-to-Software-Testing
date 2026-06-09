#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1024

struct node{
	int an;
	int n;
	struct node* next;
};
struct node *p1, *p2, *r, *head1 = NULL, *head2 = NULL, *head = NULL;

void insert(struct node *item) {
	struct node *p = head, *q;
	if (head == NULL) {
		head = item;
	}
	else {
		while (1) {
			if (p == NULL) {
				q->next = item;
				return;
			}
			else if (item->n == p->n) {
				p->an += item->an;
				return;
			}
			else if (item->n < p->n) {
				q = p;
				p = p->next;
			}
			else if (item->n > p->n) {
				item->next = p;
				q->next = item;
				return;
			}
		}
	}
}

int main() {
	int a, b;
	char ch;
	while (scanf("%d%d%c", &a, &b, &ch)) {
		r = (struct node*)malloc(sizeof(struct node));
		r->an = a;
		r->n = b;
		r->next = NULL;
		if (head1 == NULL) {
			head1 = p1 = r;
		}
		else {
			p1->next = r;
		}
		p1 = r;
		if (ch =='\n') break;
	}
	while (scanf("%d%d%c", &a, &b, &ch)) {
		r = (struct node*)malloc(sizeof(struct node));
		r->an = a;
		r->n = b;
		r->next = NULL;
		if (head2 == NULL) {
			head2 = p2 = r; 
		}
		else {
			p2->next = r;
		}
		p2 = r;
		if (ch == '\n') break;
	}
	p1 = head1;
	while (p1) {
		p2 = head2;
		while (p2) {
			r = (struct node*)malloc(sizeof(struct node));
			r->an = p1->an * p2->an;
			r->n = p1->n + p2->n;
			r->next = NULL;
			insert(r);
			p2 = p2->next;
		}
		p1 = p1->next; 
	}
	
	struct node *tail;
	tail = head;
	while (tail) {
		printf("%d %d ", tail->an, tail->n);
		tail = tail->next;
	}
	return 0;
}

