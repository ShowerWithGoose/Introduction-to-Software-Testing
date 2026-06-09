#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct treenode {
	int num;
	int depth;
	struct treenode* lchild, * rchild;
};
struct treenode* create(struct treenode* root, int temp, int high) {
	high++;
	if (root == NULL) {
		root = (struct treenode*)malloc(sizeof(struct treenode));
		root->num = temp;
		root->depth = high;
		root->lchild=root->rchild = NULL;
	}
	else if (temp >= root->num)
		root->rchild = create(root->rchild, temp, high);
	else if (temp < root->num)
		root->lchild = create(root->lchild, temp, high);
	return root;
}
void fin(struct treenode* root) {
	if (root != NULL) {
		if (root->lchild == NULL && root->rchild == NULL){
			printf("%d %d\n", root->num, root->depth);
		}
			fin(root->lchild);
			fin(root->rchild);
	}
	
}
int main() {
	struct treenode* root = NULL;
	int n, a, i, h = 0;
	scanf("%d", &n);
	for (i = 1;i <= n;i++) {
		h = 0;
		scanf("%d", &a);
		root = create(root, a, h);
	}
	fin(root);
	return 0;
}

