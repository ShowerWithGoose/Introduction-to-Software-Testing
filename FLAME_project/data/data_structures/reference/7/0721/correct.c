#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

typedef struct node{
	int data;
	int high;
	struct node *left, *right;
}bst;
bst *first;

bst *Create(bst *root, int temp, int len);
void Printleaf(bst *root);

int main()
{
	bst *root = NULL;
	int n, temp, i, len;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		len = 0;
		root = Create(root, temp, len);
	}
	Printleaf(root);
	return 0;
}

bst *Create(bst *root, int temp, int len)
{
	len++;
	if(root == NULL)
	{
		root = (bst *)malloc(sizeof(bst));
		root->data = temp;
		root->left = NULL;
		root->right = NULL;
		first = root;
		root->high = len; 
	}
	else if(temp < root->data)
		root->left = Create(root->left, temp, len);
	else if(temp >= root->data)
		root->right = Create(root->right, temp, len);
	return root;
}

void Printleaf(bst *root)
{
	if(root)
	{
		if(!(root->left) && !(root->right))
		{
			printf("%d %d\n", root->data , root->high);
		}
		Printleaf(root->left);
		Printleaf(root->right);
	}
}

