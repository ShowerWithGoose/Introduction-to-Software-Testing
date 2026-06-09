#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct node {
	int data;
	struct node *lchild, *rchild;
	int flag;
	int high;
};
typedef struct node BTNode, *BTNodeptr;
BTNode quene[1000];
int qfront = 0;
int qrear = -1;
int qnum = 0;
BTNodeptr insertBST(BTNodeptr p, int item, int hi) {
	if (p == NULL) {
		p = (BTNodeptr)malloc(sizeof(BTNode));
		p->data = item;
		p->lchild = p->rchild = NULL;
		p->flag = 0;
		p->high = hi;
	} else if (item < p->data) {
		hi++;
		p->flag = 1;
		p->lchild = insertBST(p->lchild, item, hi);
		p->lchild->high = hi;
	} else if (item >= p->data) {
		hi++;
		p->flag = 1;
		p->rchild = insertBST(p->rchild, item, hi);
		p->rchild->high = hi;
	}
	return p;
}
int isEmpty() {
	return qnum == 0;
}
int isFull() {
	return qnum == 1000;
}
void enquene(BTNodeptr p) {
	if (isFull()) {
		exit(-1);
	} else {
		qrear = (qrear + 1) % 1000;
		quene[qrear] = *p;
		qnum++;
	}
}
BTNodeptr dequene() {
	static BTNode c;
	if (isEmpty()) {
		exit(-1);
	} else {                         /* 队非空，删除成功 */
		c = quene[qfront];
		qnum--;
		qfront = (qfront + 1) % 1000;
		return &c;
	}
}
void inorder(BTNodeptr t) {
	if (t != NULL) {
		inorder(t->lchild);
		if (t->flag == 0) {
			printf("%d %d\n", t->data, t->high);
		}
		inorder(t->rchild);
	}
}
int main() {
	int n, s;
	BTNodeptr root = NULL;
//	BTNodeptr p;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s);
		root = insertBST(root, s, 1);
	}
//	if (root != NULL) {
//		enquene(root);
//		while (!isEmpty()) {
//			p = dequene();
//			if (p->flag == 0) {
//				printf("%d %d\n", p->data, p->high);
//			}
//			if (p->lchild != NULL) {
//				enquene(p->lchild);
//			}
//			if (p->rchild != NULL) {
//				enquene(p->rchild);
//			}
//		}
//	}
	inorder(root);
	return 0;
}



