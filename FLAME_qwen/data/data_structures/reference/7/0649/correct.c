#include<stdio.h>
#include<stdlib.h>
typedef struct bst
{
	int val;
	struct bst* left;
	struct bst*right;
}TreeNode;
int a[500];
TreeNode* iniNode(int value)
{
	TreeNode* x = (TreeNode*)malloc(sizeof(TreeNode));
	x->left = x->right = NULL;
	x->val = value;
	return x;
}
void preTravel(TreeNode* x, int depth)
{
	if (x->left == NULL && x->right == NULL)
	printf("%d %d\n", x->val, depth);
	if (x->left != NULL)
	preTravel(x->left, depth + 1);
	if (x->right != NULL)
	preTravel(x->right, depth + 1);
}
int main(void)
{
	int n;
	scanf("%d", &n);
	scanf("%d", &a[0]);
	TreeNode* root = iniNode(a[0]);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &a[i]);
		TreeNode* node = iniNode(a[i]);
		TreeNode* loc = root;
		while (1)
		{
			if (a[i] < loc->val)
			{
				if (loc->left == NULL)
				{
					loc->left = node;
					break;
				}
				else
				{
					loc = loc->left;
				}
			}
			else
			{
				if (loc->right == NULL)
				{
					loc->right = node;
					break;
				}
				else
				{
					loc = loc->right;
				}
			}
		}
		
	}
	preTravel(root, 1);
	return 0;

}

