#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
struct tree {
	int hight;
	int num;
	struct tree*left;
	struct tree*right;
} *first, *k;
void pp(struct tree *p) {
	if (p->left != NULL) {
		pp(p->left);
	}
	if (p->right != NULL) {
		pp(p->right);
	}
	if (p->right == NULL && p->left == NULL) {
		printf("%d %d\n", p->num, p->hight);
	}
	free(p);
	return;
}
struct tree* f(struct tree* k, int x,int v) {
	struct tree *q;
	if (k == NULL) {
		q = (struct tree*)malloc(sizeof(struct tree));
		q->num = x;
		q->hight = v;
		q->left = q->right = NULL;
		return q;
	} else {
		if (x >= k->num) {
			k->right = f(k->right, x,v+1);
		} else {
			k->left = f(k->left, x,v+1);
		}
	}
	return k;
}
int main() {
	int n, a, j;
	scanf("%d", &n);
	first = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
first=f(first,a,1); 
	}
	pp(first);
	return 0;
}

