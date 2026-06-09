#include <string.h> 
#include <stdio.h>
typedef struct TREE{
	int data;
	int depth;
	struct TREE *lchild;
	struct TREE *rchild;
}*Treep;
Treep root=NULL;
int depth=1;
void inorder(Treep t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);
		if(t->lchild==NULL&&t->rchild==NULL)
		{
			printf("%d %d\n",t->data,t->depth);
		}
		inorder(t->rchild);
	}
}
void BST(Treep *t,int d,int depth)
{
	if(*t==NULL)
	{
		*t=(Treep)malloc(sizeof(Treep));
		(*t)->lchild=(*t)->rchild=NULL;
		(*t)->data=d;
		(*t)->depth=depth;
	}else if((*t)->data<=d)
	{
		BST(&((*t)->rchild),d,depth+1);
	}else{
		BST(&((*t)->lchild),d,depth+1);
	}
} 
int main()
{
	
	int i,m,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		BST(&root,m,1);
	}
	inorder(root);
	return 0;
}


