#include <stdio.h>
#include <stdlib.h>

struct node {
	int c;
	int e;
} a[5], b[5], c[25];

char flag = ' '; //判断是否换行

int cmp(const void *p, const void *q) {
	struct node *x = (struct node *)p;
	struct node *y = (struct node *)q;
	return y->e - x->e;
}//按指数降序排列

int main() {
	int i = 0, j, k = 0, couta, coutb;
	while (flag != '\n') {
		scanf("%d%d%c", &a[i].c, &a[i].e, &flag);
		i++;
		couta = i;
	}
	i = 0;
	flag = ' ';
	while (flag != '\n') {
		scanf("%d%d%c", &b[i].c, &b[i].e, &flag);
		i++;
		coutb = i;
	}
	for (i = 0; i < couta; i++) {
		for (j = 0; j < coutb; j++) {
			c[k].c = a[i].c * b[j].c;
			c[k].e = a[i].e+b[j].e;
			k++;
		}
	}
	qsort(c, k, sizeof(c[0]), cmp);
	for (i = 0; i < k - 1; i++) {
		for (j = i + 1; j < k; j++) {
			if (c[i].e == c[j].e) {
				c[i].c += c[j].c;
				c[j].c = 0;
			}
		}
	}//合并相同指数项
	for (i = 0; i < k; i++) {
		if (c[i].c != 0) {
			printf("%d %d ", c[i].c, c[i].e);
		}
	}
	return 0;
}
