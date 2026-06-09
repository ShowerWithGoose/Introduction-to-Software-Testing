#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define eps 1e-10
#define MAX(a,b) ((a)>(b)?(a) : (b))
#define MIN(a,b) ((a)>(b)?(a) : (b))
typedef struct bst {
	int data;
	struct bst *left, *right;
	int h;
} tree, *ptr;
int h = 1;
ptr insert(ptr p, int data) {
	if (p == NULL) {
		p = (ptr)malloc(sizeof(tree));
		p->data = data;
		p->h = h;
		h = 1;
		p->left = p->right = NULL;
	} else if (data < p->data) {
		h++;
		p->left = insert(p->left, data);
	} else {
		h++;
		p->right = insert(p->right, data);
	}
	return p;
}
void in(ptr p) {
	if (p != NULL) {
		in(p->left);
		if (p->left == NULL && p->right == NULL) {
			pf("%d %d\n", p->data, p->h);
		}
		in(p->right);
	}
}
int main() {
	int n;
	sf("%d", &n);
	int i, num;
	ptr head = NULL;
	for (i = 0; i < n; i++) {
		sf("%d", &num);
		head = insert(head, num);
	}
	in(head);
	return 0;
}


