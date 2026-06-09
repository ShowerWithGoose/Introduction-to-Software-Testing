#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct num {
	int idx;
	int exp;
} node;
int l1, l2, l3;

int cmp(const void *_a, const void *_b) {
	node *a = (node *)_a;
	node *b = (node *)_b;
	if (a->exp >= b->exp)
		return -1;
	return 1;
}
int a1, a2;
int cnt;

int main(void) {
	char *s = (char *)malloc(300);
	node a[100], b[100], c[10000];
	fgets(s, 200, stdin);
	while (sscanf(s, "%d%d", &a[l1].idx, &a[l1].exp) != EOF) {
		l1++;
		cnt = 0;
		while (1) {
			if (cnt == 2)
				break;
			s++;
			if ( *s == '\n' || *s == ' ' )
				cnt++;
		}
	}
	fgets(s, 200, stdin);
	while (sscanf(s, "%d%d", &b[l2].idx, &b[l2].exp) != EOF) {
		l2++;
		cnt = 0;
		while (1) {
			if (cnt == 2)
				break;
			s++;
			if ( *s == '\n' || *s == ' ' )
				cnt++;
		}
	}
	for (int i = 0; i < l1; i++)
		for (int j = 0; j < l2; j++) {
			a1 = a[i].idx * b[j].idx;
			a2 = a[i].exp + b[j].exp;
			for (int i = 0; i <= l3; i++) {
				if (i == l3) {
					c[l3].idx = a1;
					c[l3].exp = a2;
					l3++;
					break;
				} else if (c[i].exp == a2) {
					c[i].idx += a1;
					break;
				}
			}
		}
	qsort(c, l3 - 1, sizeof(node), cmp);
	for (int i = 0; i < l3; i++)
		printf("%d %d ", c[i].idx, c[i].exp);
	return 0;
}

