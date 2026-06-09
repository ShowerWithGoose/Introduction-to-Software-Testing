#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>
typedef struct Tree {
	struct Tree* left;
	int a;
	int depth;
	struct Tree* right;
}tree, * tri;
tri Create(int x)
{
	tri q = NULL;
	q = (tri)malloc(sizeof(tree));
	q->left = q->right = NULL;
	q->a = x;
	q->depth = 1;
	return q;
}
void Insert(tri p,int op,int x)
{
	tri q = NULL;
	q = (tri)malloc(sizeof(tree));
	q->depth = p->depth + 1;
	q->a = x;
	if (op == 1)
	{
		q->left = q->right = NULL;
		p->left = q;
	}
	else
	{
		q->left = q->right = NULL;
		p->right = q;
	}
}
void dfs(tri p)
{
	if (p->left == NULL && p->right == NULL)
	{
		printf("%d %d\n", p->a, p->depth);
		return;
	}
	if(p->left!=NULL)
	dfs(p->left);
	if(p->right!=NULL)
	dfs(p->right);
}
int main()
{
	int n;
	scanf("%d", &n);
	if (n == 0) return 0;
	else
	{
		int b = 0;
		scanf("%d", &b);
		tri list = Create(b);
		for (int i = 1;i < n;i++)
		{
			scanf("%d", &b);
			tri p = list;
			while (1)
			{
				if (b < p->a)
				{
					if (p->left == NULL)
					{
						Insert(p, 1, b);
						break;
					}
					else
					p = p->left;
				}
				else if (b >= p->a)
				{
					if (p->right == NULL)
					{
						Insert(p, 2, b);
						break;
					}
					else
						p = p->right;
				}
			}
		}
		dfs(list);
	}
}

