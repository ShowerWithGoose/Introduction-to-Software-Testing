#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bts {
	int num;
	int height;
	struct bts* left;
	struct bts* right;
}*p, * q, * base;

void insert(int a) {
	int h = 2;
	p = base;
	while ((a >= p->num && p->right != NULL) || (a < p->num && p->left != NULL)) {
		if (a < p->num)
			p = p->left;
		else if (a >= p->num)
			p = p->right;
		h++;
	}
	q->height = h;
	if (a < p->num)
		p->left = q;
	if (a >= p->num)
		p->right = q;
}

void search(struct bts* p) {
	if (p->left == NULL && p->right == NULL) {
		printf("%d %d\n", p->num, p->height);
		return;
	}
	if (p->left != NULL)
		search(p->left);
	if (p->right != NULL)
		search(p->right);
}

int main() {
	int n, a;
	base = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		q = (struct bts*)malloc(sizeof(struct bts));
		q->num = a;
		q->left = NULL, q->right = NULL;
		if (base == NULL) {
			q->height = 1;
			base = q, p = q;
		}
		else
			insert(a);
	}
	search(base);
	return 0;
}
