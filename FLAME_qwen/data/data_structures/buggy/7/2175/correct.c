#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<ctype.h>
#include <alloca.h>
#define ma(a,b) (a)>(b)?(a):(b);
#define mi(a,b) (a)<(b)?(a):(b);

#define M 1005

typedef struct tree {
	int data;
	struct tree* lchild, *rchild;
} bn, *btree;
btree insert(int data, btree p) {
	if (p == NULL) {
		p = (btree)malloc(sizeof(bn));
		p->data = data;
		p->lchild = p->rchild = NULL;
	} else if (data < p->data) {
		p->lchild = insert(data, p->lchild);
	} else {
		p->rchild = insert(data, p->rchild);
	}
	return p;
}
void inorder(btree t, int dep) {
	if (t != NULL) {
		inorder(t->lchild, dep + 1);
		if (t->lchild == NULL && t->rchild == NULL) {
			printf("%d %d\n", t->data, dep);
		}
		inorder(t->rchild, dep + 1);
	}
}
int main() {
	int n, a;
	scanf("%d", &n);
	btree p = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		p = insert(a, p);
	}
	inorder(p, 1);
	return 0;
}

