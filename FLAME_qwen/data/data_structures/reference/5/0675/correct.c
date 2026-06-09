#include <stdio.h>
#include <stdlib.h>

struct link {
	int long long m;
	int long long n;
	struct link *next;
};

int main() {
	int num1 = 0, num2 = 0;
	char hc;
	struct link a[1000], b[1000];
	while (1) {
		scanf("%lld%lld", &a[num1].m, &a[num1].n);
		num1++;
		scanf("%c", &hc);
		if (hc == '\n')
			break;
	}
	while (1) {
		scanf("%lld%lld", &b[num2].m, &b[num2].n);
		num2++;
		scanf("%c", &hc);
		if (hc == '\n')
			break;
	}
	struct link *first = NULL, *p, *q, *r;
	for (int i = 0; i < num1; i++) {
		for (int j = 0; j < num2; j++) {
			q = (struct link *)malloc(sizeof(struct link));
			q->m = a[i].m * b[j].m;
			q->n = a[i].n + b[j].n;
			q->next = NULL;
			p = first;
			while (1) {
				if (first == NULL) {
					first = q;
					break;
				} else if (p == NULL) {
					r->next = q;//为什么把r->next换成p就不对了呢
					break;
				} else if (p->n > q->n) {
					r = p;
					p = p->next;
				} else if (p->n == q->n) {
					p->m += q->m;
					break;
				} else if (p->n < q->n) {
					q->next = p;
					r->next = q;
					break;
				}

			}
		}

	}
	p = first;
	while (p != NULL) {
		printf("%lld %lld ", p->m, p->n);
		p = p->next;
	}
	return 0;
}
