#include <stdio.h>
#include <stdlib.h>

struct tree{
	int num;
	int layer;
	struct tree *lchild, *rchild;
};
typedef struct tree Tree, *Treeptr;
Treeptr head, in, put;

void visit(Treeptr t) {
	if (t->lchild == NULL && t->rchild == NULL)
		printf("%d %d\n", t->num, t->layer);
}

void inorder(Treeptr t) {
	if (t != NULL) {
		inorder(t->lchild);	
		visit(t);
		inorder(t->rchild);
	}
}

int main() {
	int m, n, i, high, flag;
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &n);
		if (head == NULL) {
			head = (Treeptr)malloc(sizeof(Tree));
			head->layer = 1;
			head->num = n;
			head->lchild = NULL;
			head->rchild = NULL;
		}
		else {
			high = 1;
			put = head;
			while (put != NULL) {
				in = put;
				if (put->num > n) {
					flag = 1;
					put = put->lchild;
				}
				else {
					flag = 0;
					put = put->rchild;
				}
				high++;
			}
			if (flag) 
				in = in->lchild = (Treeptr)malloc(sizeof(Tree));
			else 
				in = in->rchild = (Treeptr)malloc(sizeof(Tree));
			in->layer = high;
			in->num = n;
			in->lchild = NULL;
			in->rchild = NULL;
		}
	}
	
	inorder(head);
	
	return 0;
}

