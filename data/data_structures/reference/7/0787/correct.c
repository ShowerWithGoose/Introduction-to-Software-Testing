#include<stdio.h>
#include<stdlib.h>
int count;
struct node {
	int data;
	struct node* left;
	struct node* right;
	int height;
};
struct node* inserttree(struct node* p, int x)
{
	count++;
	if (p == NULL) {
		struct node* q = (struct node*)malloc(sizeof(struct node));
		q->data = x;
		q->left = q->right = NULL;
		q->height = count;
		p = q;
	}
	else if (x >= p->data)
		p->right=inserttree(p->right, x);
	else
		p->left=inserttree(p->left, x);
	count = 0;
	return p;
}
void postorder(struct node* root)
{
	if (root) {
		postorder(root->left);
		postorder(root->right);
		if (root->left == NULL && root->right == NULL)
			printf("%d %d\n", root->data, root->height);
	}
	return;
}
int main()
{
	struct node* root = NULL;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		root=inserttree(root, x);
	}
	postorder(root);
	return 0;
}

