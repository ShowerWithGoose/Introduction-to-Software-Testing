#include <stdio.h>
#include <stdlib.h>

struct node {
	int xishu;
	int pow;
	struct node *next;
};
typedef struct node Node;
typedef struct node *Nodep;

int main(void) {
	int a, n, aa, nn;
	char c;
	Nodep head1, head2 = NULL, p1, q1, p2, q2, r = NULL;
	head1 = p1 = NULL;
	c = '1';
	while (c != '\n') {
		scanf("%d%d%c", &a, &n, &c);
		q1 = (Nodep)malloc(sizeof(Node));
		q1->xishu = a;
		q1->pow = n;
		q1->next = NULL;
		if (head1 == NULL) {
			head1 = p1 = q1;
		} else {
			p1->next = q1;
			p1 = p1->next;
		}
	}
	c = '1';
	while (c != '\n') {
		scanf("%d%d%c", &a, &n, &c);
		for (p1 = head1; p1 != NULL; p1 = p1->next) {
			aa = a * p1->xishu;
			nn = n + p1->pow;
			q2 = (Nodep)malloc(sizeof(Node));
			q2->xishu = aa;
			q2->pow = nn;
			q2->next = NULL;
			if (head2 == NULL) {
				head2 = p2 = q2;
			} else {
				for (p2 = head2; p2 != NULL; p2 = p2->next) {

					if (q2->pow > p2->pow) {
						q2->next = p2;
						r->next = q2;
						break;

					} else if (q2->pow == p2->pow) {
						p2->xishu += q2->xishu;
						break;
					}
					r = p2;
				}

			}
			if (p2 == NULL) {
				r->next = q2;
			}
		}
	}
	for (p2 = head2; p2 != NULL; p2 = p2->next) {
		printf("%d %d ", p2->xishu, p2->pow);
	}
	return 0;
}


