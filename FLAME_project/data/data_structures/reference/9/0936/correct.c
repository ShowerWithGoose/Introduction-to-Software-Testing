#include<stdio.h>
#include <stdlib.h>
struct Zuobiao {
	int x1;
	int y1;
	int x2;
	int y2;
	struct Zuobiao *next;
};
int biao[101];
int x[101];
int y[101];
int max(int B) {
	int M = biao[0];
	int f = 0;
	for (int i = 1; i < B; i++) {
		if (M < biao[i]) {
			f = i;
			M = biao[i];
		}
	}
	return f;
}
int main() {
	struct Zuobiao *first = NULL, *p, *q, *t, *tm, *tx;
	int n, sum = 1;
	int B = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		q = (struct Zuobiao *)malloc(sizeof(struct Zuobiao));
		scanf("%d%d%d%d", &q->x1, &q->y1, &q->x2, &q->y2);
		q->next = NULL;
		if (first == NULL) {
			first = p = q;
		} else {
			p->next = q;
			p = p->next;
		}
	}
	tx = first;
	while (tx!= NULL) {
			x[B] = tx->x1;
			y[B] = tx->y1;
		tm = tx;
		t = first;
		while (t!= NULL) {
			if (tm->x2 == t->x1 && tm->y2 == t->y1) {
				sum++;
				tm = t;
				t = first;
			} else {
				t = t->next;
			}
		}
		biao[B] = sum;
		B++;
		sum = 1;
		tx = tx->next;
	}
	printf("%d %d %d", biao[max(B)], x[max(B)], y[max(B)]);
	return 0;
}
/*
10

80 75 125 75

60 40 80 55

80 55 90 20

140 120 195 205

10 111 70 165

22 35 43 43

22 175 80 205

43 43 60 40

90 20 125 60

70 165 140 120

1
43 43 60 40
*/

