#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
	int data;
	int height;
	struct node* left;
	struct node* right;
};


void insert(struct node** root, int data)
{
	struct node* p = NULL;
	struct node* q = NULL;
	p = (struct node*)malloc(sizeof(struct node));
	p->data = data;
	p->height = 1;
	p->left = NULL;
	p->right = NULL;
	if (*root == NULL)
	{
		*root = p;
	}
	else
	{
		q = *root;
		while (1)
		{
			p->height++;
			if (data >= q->data)
			{
				if (q->right == NULL)
				{
					q->right = p;
					break;
				}
				else
				{
					q = q->right;
				}
			}
			else if (data < q->data)
			{
				if (q->left == NULL)
				{
					q->left = p;
					break;
				}
				else
				{
					q = q->left;
				}
			}
		}
	}
}



void search(struct node* root)
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
		{
			printf("%d %d\n", root->data, root->height);
		}
		search(root->left);
		search(root->right);
	}
}



void free_tree(struct node* p)
{
	if (NULL != p)
	{
		struct node* p_left = p->left;
		struct node* p_right = p->right;
		free_tree(p_left);
		free_tree(p_right);
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int data = 0;

	struct node* root = NULL;

	while (n--)
	{
		scanf("%d", &data);
		insert(&root, data);
	}

	struct node* ptmp = NULL;

	search(root);

	free_tree(root);

	return 0;
}
