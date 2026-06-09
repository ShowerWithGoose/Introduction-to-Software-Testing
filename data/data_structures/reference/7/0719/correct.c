#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
typedef struct n{
	int num;
	int depth;
	struct n* left, * right;
}tnode;
tnode * root, * p,* q;

tnode* createBST(tnode* q, int nn, int h)
{
	if (q == NULL)
	{
		q = (tnode*)malloc(sizeof(tnode));
		q->num = nn;
		q->depth = h;
		q->left = q->right = NULL;
	}
	else if (nn < q->num)
	{
		q->left=createBST((q->left), nn, h + 1);
	}
	else
	{
		q->right=createBST((q->right), nn, h + 1);
	}
	return q;
}

void visit(tnode *t)
{
	printf("%d %d\n", t->num, t->depth);
}

void midorder(tnode *t)
{
	if (t != NULL)
	{
		midorder(t->left);
		if(t->left==NULL&&t->right==NULL) visit(t);
		midorder(t->right);
	}
}

int main()
{
	int n,nuu;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &nuu);
		//遍历找到归处
		root=createBST(root, nuu, 1);
	}
	//遍历输出叶子节点及高度
	midorder(root);
	return 0;
}


