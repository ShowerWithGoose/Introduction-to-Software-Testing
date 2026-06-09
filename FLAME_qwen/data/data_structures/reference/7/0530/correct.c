#include <stdio.h>
#include <stdlib.h>
typedef struct t {
	int data;
	struct t* lchild, * rchild;
}bst,*bptr;
void searchleaf(bptr t,int depth);

int main()
{
	int n, i, ele;
	bptr root = NULL, p, q;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &ele);
		if (!i)
		{
			root = p = q = (bptr)malloc(sizeof(bst));
			root->data = ele; root->lchild = root->rchild = NULL;
		}
		else
		{
			q = (bptr)malloc(sizeof(bst)); q->data = ele; q->lchild = q->rchild = NULL;
			p = root;
			while (p!=NULL)//插入
			{
				if (ele < p->data)
				{
					if (p->lchild == NULL)
					{
						p->lchild = q; break;
					}
					else
						p = p->lchild;
				} 
				else if (ele >= p->data)
				{
					if (p->rchild == NULL)
					{
						p->rchild = q; break;
					}
					else
						p = p->rchild;
				}
			}
		}
	}//二叉树已经形成
	searchleaf(root,1);
	return 0;
}
void searchleaf(bptr t,int depth)
{
	if (t == NULL)
		return;
	if(t->lchild==NULL&&t->rchild==NULL)
		printf("%d %d\n", t->data, depth);
	else
	{
		searchleaf(t->lchild, depth + 1);
		searchleaf(t->rchild, depth + 1);
	}
}
