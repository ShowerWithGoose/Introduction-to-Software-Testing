#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
	int data;
	struct node *l, *r;
};
struct node *head = NULL;
int length = 1; //统计层数

int traverse(struct node *t) {
	if (t == NULL) {
		length--;
		return 0;
	}

	length++;
	traverse(t->l);
	if (t->l == NULL && t->r == NULL)
		printf("%d %d\n", t->data, length);
	length++;
	traverse(t->r);

	//length -= 2;
	length--;
	return 0;
}

int main() {
	int num;
	scanf("%d", &num);
	head = (struct node *)malloc(sizeof(struct node));
	scanf("%d", &head->data);
	head->l = head->r = NULL;
	num--;
	struct node *p, *q;
	//printf("finish creat head node.\n");
	while (num--) {
		q = head;
		p = (struct node *)malloc(sizeof (struct node));
		p->l = p->r = NULL;
		scanf("%d", &p->data);
		while (1) {
			if (p->data < q->data) {
				if (q->l == NULL) {
					q->l = p;
					break;
				}
				q = q->l;
			} else {
				if (q->r == NULL) {
					q->r = p;
					break;
				}
				q = q->r;
			}
		}
	}
	traverse(head);
	return 0;
}
//che清零
//fclose()

