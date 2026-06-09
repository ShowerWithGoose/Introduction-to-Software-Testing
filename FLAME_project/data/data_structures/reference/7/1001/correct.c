#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct MyTree
{
	int data;
	int height;
	struct MyTree* left;
	struct MyTree* right;
}tree;

tree* tree_init(int n);
void inorder(tree* t);

int main()
{
	int n, data;
	tree* head = NULL;
	scanf("%d", &n);
	head = tree_init(n);
	inorder(head);
	return 0;
}

tree* tree_init(int n)
{
	int stop = 0, h = 1;
	tree* T = NULL, * p = NULL, * q = NULL;
	while (n--) {
		p = (tree*)malloc(sizeof(tree));
		p->left = NULL;
		p->right = NULL;
		if (T == NULL) {
			T = p;
			p->height = 1;
		}
		scanf("%d", &p->data);
		if (T == p) {
			continue;
		}
		else {
			q = T;
			stop = 0;
			while (stop == 0) {
				if (p->data >= q->data) {
					if (q->right == NULL) {
						q->right = p;
						p->height = q->height + 1;
						stop = 1;
					}
					else {
						q = q->right;
					}
				}
				else {
					if (q->left == NULL) {
						q->left = p;
						stop = 1;
						p->height = q->height + 1;
					}
					else {
						q = q->left;
					}
				}
			}
		}
	}
	return T;
}

void inorder(tree* t)
{
	if (t != NULL) {
		inorder(t->left);
		if (t->left == NULL && t->right == NULL) {
			printf("%d %d\n", t->data, t->height);
		}
		inorder(t->right);
	}
	return;
}
