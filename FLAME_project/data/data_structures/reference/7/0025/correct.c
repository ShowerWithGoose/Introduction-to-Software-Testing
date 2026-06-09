#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int date;
	int depth;
	struct node* left;
	struct node* right;	
}Node;

typedef struct 
{
	Node* root;
}Tree;

void insert(Tree* tree, int value)
{
	Node* node = malloc(sizeof(Node));
	node->date = value;
	node->depth = 1;
	node->left = NULL;
	node->right = NULL;
	
	if(tree->root == NULL)
	{
		tree->root = node;
	}
	else
	{
		Node* temp = tree->root; 
		while (temp != NULL)
		{
			node->depth++;
			if(value < temp->date)
			{
				if(temp->left == NULL)
				{
					temp->left = node;
					return;
				}
				else
				{
					temp = temp->left; 
				}
			}
			else
			{
				if(temp->right == NULL)
				{
					temp->right = node;
					return;
				}
				else
				{
					temp = temp->right; 	
				}
			}
		}
	}
}

void inorder(Node* node)
{
	if(node != NULL)
	{
		inorder(node->left);
		if(node->left == NULL && node->right == NULL)
		{
			printf("%d %d\n", node->date, node->depth);
		}
		inorder(node->right);
	}
}

int n, i, x;

int main()
{
	Tree tree;
	tree.root = NULL;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d", &x);
		insert(&tree, x);
	}
	
	inorder(tree.root);
	
	return 0;
}

