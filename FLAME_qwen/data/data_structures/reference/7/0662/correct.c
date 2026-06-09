#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int n, x;
struct BstNode {
	int date;
	struct BstNode *l, *r;
};
struct BstNode *insertBST(struct BstNode *root, int date) {
	if (root == NULL) {
		struct BstNode *p;
		p = (struct BstNode*)malloc(sizeof(struct BstNode)); 
		p->date = date;
		p->l = NULL; p->r = NULL;
		return p;
	}
	if (date < root->date) 
		root->l = insertBST(root->l, date);
	else
		root->r = insertBST(root->r, date);
	return root;

}
void printLeaf(struct BstNode *root, int high) {
	if (root->l != NULL) printLeaf(root->l, high+1);
	if (root->r != NULL) printLeaf(root->r, high+1);
	if (root->l == NULL && root->r == NULL) 
		printf("%d %d\n", root->date, high);
}
int main()
{
	struct BstNode *root=NULL;
	
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &x);
		root = insertBST(root, x);
	}
	printLeaf(root, 1);
	return 0;
} 

