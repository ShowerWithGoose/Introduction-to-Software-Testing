#include <stdio.h>
#include <stdlib.h>
typedef struct _bst_node
{
	int data;
	struct _bst_node *parent;
	struct _bst_node *left_child;
	struct _bst_node *right_child;
}BST_NODE, *PBST_NODE;
PBST_NODE insert(int data, PBST_NODE root);
void DFS(PBST_NODE root, int depth);
void free_tree(PBST_NODE root);

PBST_NODE root = NULL;

int main()
{
	int n, i, x;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &x), root = insert(x, root);
	DFS(root, 1);
	free_tree(root);
	return 0;
}

PBST_NODE insert(int data, PBST_NODE root)
{
	if (root == NULL)
	{
		root = (PBST_NODE)malloc(sizeof(BST_NODE));
		root->data = data;
		root->left_child = NULL;
		root->right_child = NULL;	
	}
	else if(data < root->data) root->left_child = insert(data, root->left_child), root->left_child->parent = root;
	else root->right_child = insert(data, root->right_child), root->right_child->parent = root;
	return root;
}
void DFS(PBST_NODE root, int depth)
{
	if (root->left_child == NULL && root->right_child == NULL)
	{
		printf("%d %d\n", root->data, depth);
		return;
	}
	if (root->left_child != NULL) DFS(root->left_child, depth + 1);
	if (root->right_child != NULL) DFS(root->right_child, depth + 1);
}
void free_tree(PBST_NODE root)
{
	if (root == NULL) return;
	free_tree(root->left_child);
	free_tree(root->right_child);
	free(root);
}

