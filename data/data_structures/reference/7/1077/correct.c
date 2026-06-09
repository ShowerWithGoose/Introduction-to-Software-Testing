#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
struct TNode
{
	struct TNode *lchild;
	int data;
	int height;
	struct TNode *rchild;
};
typedef struct TNode *PNode;

void preorder(PNode str)
{
	if(str->lchild!=NULL||str->rchild!=NULL)
	{
		if(str->lchild!=NULL)
		{
			preorder(str->lchild);
		}
		if(str->rchild!=NULL)
		{
			preorder(str->rchild);
		}
	}
	else
	{
		printf("%d %d\n",str->data,str->height);
	}
}
int treenum[500];
int main()
{
	int n;
	int height;
	int i,j;
	PNode root=(PNode)malloc(sizeof(struct TNode));
	PNode p=root;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&treenum[i]);
	}
	root->height=1;
	root->data=treenum[0];
	root->lchild=NULL;
	root->rchild=NULL;
	for(j=1;j<i;j++)
	{
		height=2;
		p=root;
		for(;(p->data>treenum[j]&&p->lchild!=NULL)||(p->data<=treenum[j]&&p->rchild!=NULL);height++)
		{
			if(p->data>treenum[j]) p=p->lchild;
			else p=p->rchild; 
		}
		PNode q=(PNode)malloc(sizeof(struct TNode));
		q->data=treenum[j];
		q->height=height;
		if(p->data>treenum[j])
		{
			p->lchild=q;
			p=q;
			p->lchild=NULL;
			p->rchild=NULL;
		}
		else
		{
			p->rchild=q;
			p=q;
			p->lchild=NULL;
			p->rchild=NULL;
		}
	}
	preorder(root);
	return 0;
}

