#include <stdio.h>
#include <malloc.h>
typedef struct node {
	int data;
	int height;
	struct node * lChild;
	struct node * rChild;
}Treenode, *BSTNode;
int n;
Treenode Stack[10000];// = (BSTNode)malloc(sizeof(Treenode)*(n + 2));
BSTNode CreatNode(BSTNode parent, int da) {
	BSTNode t = (BSTNode)malloc(sizeof(Treenode));
	t->data = da;
	t->height = parent->height + 1;
	t->lChild = NULL;
	t->rChild = NULL;
	return t;
}
void insertT(BSTNode v, int da) {
	BSTNode hot = v;
	BSTNode s = v;
	while(1) {
		if (s == NULL) break;
//		printf("%d %d\n", da, s->data);
		hot = s;
		if (da < (s->data)) s = s->lChild;
		else s = s->rChild;
	}
	if (hot->data < da) hot->rChild = CreatNode(hot, da);
	else hot->lChild = CreatNode(hot, da);
	return;
}
int goLeftBranch(int k, BSTNode s) {
	while(1) {
		if (s == NULL) break;
		Stack[k++] = *s;
		s = s->lChild;
	}
	return k;
}
void visit(BSTNode s) {
	if (s->lChild == NULL && s->rChild == NULL) printf("%d %d\n", s->data, s->height);
	return;
}
void treaves(BSTNode v) {
	int k = 0;
	BSTNode start = v;
	while(1) {
		
		k = goLeftBranch(k, v);
		if (k == 0) break;
		v = &Stack[--k];
		visit(v);
		v = v->rChild;
	}
	return;
}
int main() {
	scanf("%d", &n);
	int a;
	if (n == 0) return 0;
	scanf("%d", &a);
	BSTNode root = (BSTNode)malloc(sizeof(Treenode));
	root->data = a;
	root->height = 1;
	root->lChild = NULL;
	root->rChild = NULL;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &a);
//		printf("%d\n", a);
		insertT(root, a);
	}
	treaves(root);
	return 0;
}



