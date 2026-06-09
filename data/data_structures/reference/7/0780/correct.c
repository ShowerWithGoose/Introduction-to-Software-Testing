#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *lchild;
	struct Node *rchild;
	int val;
}NODE,*PNODE;

void insert(int val,PNODE *root)
{
	if(*root==NULL)
	{
		*root=(PNODE)malloc(sizeof(NODE));
		(*root)->val=val;
		(*root)->rchild=NULL;
		(*root)->lchild=NULL;
		return;
	}
	if(val>=(*root)->val)
		insert(val,&(*root)->rchild);
	else
		insert(val,&(*root)->lchild);
}
void clear(PNODE *root)
{
	if(*root==NULL)
		return;
	PNODE lchild=(*root)->lchild,rchild=(*root)->rchild;
	(*root)->lchild=NULL;
	(*root)->rchild=NULL;
	free(*root);
	*root=NULL;
	clear(&lchild);
	clear(&rchild);
}
void find(PNODE root,int height)
{
	if(root==NULL)
		return;
	if(root->lchild==NULL && root->rchild==NULL)
		printf("%d %d\n",root->val,height);
	find(root->lchild,height+1);
	find(root->rchild,height+1);
}

int main()
{
	PNODE root=NULL;
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		insert(x,&root);
	}
	find(root,1);
	clear(&root);
	return 0;
}

