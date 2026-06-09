#include <stdio.h>
#include <string.h>

// #define INTERNAL

#ifdef INTERNAL
#pragma warning(disable: 4996)
#endif

#define TREE_SIZE 256

// Binary tree
typedef struct tagBTNode
{
	int data;
	int depth;
	struct tagBTNode* left;
	struct tagBTNode* right;
} BTNode, * BTree;

BTNode BTNodePool[256];

BTNode* _BTNode_Create(void);
BTNode* BTNode_Init(BTNode* node);
int BTNode_IsLeaf(BTNode* node);

BTree* BTree_Insert(BTree* root, int data);


// Custom operations
void get_leaves_height(BTree root);

int main()
{
	int n;
	int data;
	BTree tree = NULL;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		BTree_Insert(&tree, data);
	}

	get_leaves_height(tree);

	return 0;
}

BTNode* _BTNode_Create()
{
	static BTNode* nextAlloc = BTNodePool;

	return BTNode_Init(nextAlloc++);
}

BTNode* BTNode_Init(BTNode* node)
{
	node->data = 0;
	node->depth = 1;
	node->left = node->right = NULL;

	return node;
}

int BTNode_IsLeaf(BTNode* node)
{
	return (!node->left) && (!node->right);
}


BTree* BTree_Insert(BTree* root, int data)
{
	if (!(*root))
	{
		*root = _BTNode_Create();
		(*root)->data = data;

		return root;
	}

	if (data < (*root)->data)
	{
		if (!((*root)->left))
		{
			(*root)->left = _BTNode_Create();
			(*root)->left->depth = (*root)->depth + 1;
			(*root)->left->data = data;
		}
		else
			BTree_Insert(&(*root)->left, data);
	}
	else
	{
		if (!((*root)->right))
		{
			(*root)->right = _BTNode_Create();
			(*root)->right->depth = (*root)->depth + 1;
			(*root)->right->data = data;
		}
		else
			BTree_Insert(&(*root)->right, data);
	}

	return root;
}


// Custom operations
void get_leaves_height(BTree root)
{
	if (!root)
		return;

	if (BTNode_IsLeaf(root))
	{
		printf("%d %d\n", root->data, root->depth);
		return;
	}

	if (root->left)
		get_leaves_height(root->left);
	if (root->right)
		get_leaves_height(root->right);
}

