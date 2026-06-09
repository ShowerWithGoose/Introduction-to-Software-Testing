#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct BST_TREE_
{
	int data;
	struct BST_TREE_* left;
	struct BST_TREE_* right;
}BST_TREE;

void add_node_(BST_TREE* root, BST_TREE* node)
{
	if (root->data > node->data)
	{
		if (root->left == NULL) root->left = node;
		else add_node_(root->left, node);
	}
	else
	{
		if (root->right == NULL) root->right = node;
		else add_node_(root->right, node);
	}
}

void add_node(BST_TREE** root, int data)
{
	BST_TREE* tmp = (BST_TREE*)malloc(sizeof(BST_TREE));
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	if (*root == NULL) *root = tmp;
	else add_node_(*root, tmp);
}

void search(BST_TREE* root, int level)
{
	if (root->left == NULL && root->right == NULL)
	{
		printf("%d %d\n", root->data, level);
		return;
	}
	if (root->left != NULL)
	{
		search(root->left, level + 1);
	}
	if (root->right != NULL)
	{
		search(root->right, level + 1);
	}
}

int main()
{
	BST_TREE* bts_tree = NULL;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		scanf("%d", &t);
		add_node(&bts_tree, t);
	}
	search(bts_tree, 1);
	system("pause");
	return 0;
}


