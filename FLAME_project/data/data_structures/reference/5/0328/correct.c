#include <stdio.h>
#include <stdlib.h>

struct node {
	int coe;
	int pow;
	struct node *next;
};

int main() {
	int num1, num2, cnt = 0;
	char c;
	struct node *head, *p, *q, *t, *q0, *re, *head_re = NULL;
	head = NULL;
	do {
		scanf("%d%d%c", &num1, &num2, &c);
		p = (struct node *)malloc(sizeof(struct node));
		p->coe = num1;
		p->pow = num2;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			q->next = p;
		q = p;
	} while (c != '\n');
	do {
		scanf("%d%d%c", &num1, &num2, &c);
		p = (struct node *)malloc(sizeof(struct node));
		p->coe = num1;
		p->pow = num2;
		t = head;
		while (t != NULL && cnt == 0) {
			re = (struct node *)malloc(sizeof(struct node));
			re->coe = t->coe * p->coe;
			re->pow = t->pow + p->pow;
			re->next = NULL;
			if (head_re == NULL)
				head_re = re;
			else
				q->next = re;
			q = re;
			t = t->next;
		}
		while (t != NULL && cnt == 1) {
			re = (struct node *)malloc(sizeof(struct node));
			re->coe = t->coe * p->coe;
			re->pow = t->pow + p->pow;
			for (q = head_re; q != NULL; q0 = q, q = q->next) {
				if (re->pow > q->pow) {
					if (q == head) {
						re->next = q;
						head = re;
						break;
					} else {
						re->next = q;
						q0->next = re;
						break;
					}
				} else if (re->pow == q->pow) {
					q->coe += re->coe;
					free(re);
					break;
				}
			}
			if (q == NULL)
				q0->next = re;
			t = t->next;
		}
		cnt = 1;
		free(p);
	} while (c != '\n');
	t = head_re;
	while (t != NULL) {
		printf("%d %d ", t->coe, t->pow);
		t = t->next;
	}
	return 0;
}
