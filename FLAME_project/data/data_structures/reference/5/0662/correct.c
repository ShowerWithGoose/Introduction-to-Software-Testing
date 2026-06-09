#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node {
	int coef;
	int exp;
}q1[1000], q2[1000], q[100000];
char s[100000];
int n1, n2, n;
void init(struct node l[], int *nn) 
{
	int i;
	int x = 0, t;
	for (i = 0; i < strlen(s); i++) {
		t = 0;
		while (s[i] >= '0' && s[i] <= '9') {
			t = t*10 + s[i++] -'0';
		}
		if (!x) x = t;
		else {
			l[++(*nn)].coef = x; l[(*nn)].exp = t; x = 0;
		}
	}
}
int cmp (const void *a, const void *b) {
	struct node *c = (struct node *)a;
	struct node *d = (struct node *)b;
	return d->exp - c->exp;
}
int main()
{
	int i, j;
	gets(s);
	init(q1, &n1);
	gets(s);
	init(q2, &n2);
	for (i = 1; i <= n1; i++)
		for (j = 1; j <= n2; j++)
			q[++n].coef = q1[i].coef*q2[j].coef, q[n].exp = q1[i].exp+q2[j].exp;
	qsort(q+1, n, sizeof(q[0]), cmp);
	int a1 = q[1].coef, a2 = q[1].exp;
	for (i = 2; i <= n; i++) {
		if (q[i].exp == a2) a1 += q[i].coef;
		else {
			printf("%d %d ", a1, a2);
			a1 = q[i].coef; a2 = q[i].exp;
		}
	}
	printf("%d %d", a1, a2);
	printf("\n");
	return 0;
}

