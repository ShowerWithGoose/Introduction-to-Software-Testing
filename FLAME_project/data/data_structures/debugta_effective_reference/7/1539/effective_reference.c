#include <stdio.h>
#include <stdlib.h>

struct tree{
	int num;
	int high;
	struct tree *lchild, *rchild;
};
typedef struct tree Tree, *Treeptr;
Treeptr head, move, wood;

void visit(Treeptr t) {
	if (t->lchild == NULL && t->rchild == NULL)
		printf("%d %d\n", t->num, t->high);
}

void inorder(Treeptr t) {
	if (t != NULL) {
		inorder(t->lchild);	
		visit(t);
		inorder(t->rchild);
	}
}

int main() {
	int n, in, i, high, rea;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &in);
		if (head == NULL) {
			head = (Treeptr)malloc(sizeof(Tree));
			head->high = 1;
			head->num = in;
			head->lchild = NULL;
			head->rchild = NULL;
		}
		else {
			high = 1;
			wood = head;
			while (wood != NULL) {
				move = wood;
				if (wood->num > in) {
					rea = 1;
					wood = wood->lchild;
				}
				else {
					rea = 0;
					wood = wood->rchild;
				}
				high++;
			}
			if (rea) 
				move = move->lchild = (Treeptr)malloc(sizeof(Tree));
			else 
				move = move->rchild = (Treeptr)malloc(sizeof(Tree));
			move->high = high;
			move->num = in;
			move->lchild = NULL;
			move->rchild = NULL;
		}
	}
	
	inorder(head);
	
	return 0;
}

